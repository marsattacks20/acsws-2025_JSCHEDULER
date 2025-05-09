//Suggested: import alma.<Module>.<Interface>Impl; //But anything, really
package acsws.SCHEDULER_MODULE.SchedulerImpl;
//Base component implementation, including container services and component lifecycle infrastructure
import alma.acs.component.ComponentImplBase;
import acsws.SCHEDULER_MODULE.SchedulerOperations;
import acsws.DATABASE_MODULE.DataBaseHelper;
import acsws.TELESCOPE_MODULE.TelescopeHelper;
import acsws.STORAGE_MODULE.StorageHelper;
//
import acsws.TELESCOPE_MODULE.Telescope;
import acsws.STORAGE_MODULE.Storage;
import acsws.DATABASE_MODULE.DataBase;
import alma.acs.component.ComponentLifecycleException;
import alma.JavaContainerError.wrappers.AcsJContainerServicesEx;
import acsws.SYSTEMErr.*;
import acsws.SYSTEMErr.wrappers.AcsJSchedulerAlreadyRunningEx;
import acsws.SYSTEMErr.wrappers.AcsJSchedulerAlreadyStoppedEx;
import acsws.SYSTEMErr.wrappers.AcsJNoProposalExecutingEx;
import alma.acs.container.ContainerServices;
import alma.acs.component.ComponentLifecycleException;
//import acsws.DATABASE_MODULE.DataBaseComponentHelper;
import acsws.TYPES.Proposal;
import acsws.TYPES.Target;
import acsws.TYPES.Position;
import java.util.*;
//ClassName usually is <Interface>Impl, but can be anything
public class SchedulerImpl extends ComponentImplBase implements SchedulerOperations {
    private boolean running;
    private Proposal[] proposals;
    private boolean stopflag;
    private int propex;
    private Thread schedulerThread;
    private Telescope tel;
    //private Storage storage;
    private DataBase db;
    @Override
    public void initialize(ContainerServices containerServices) throws ComponentLifecycleException {
        super.initialize(containerServices);
        running = false;
        stopflag = false;
        propex = -1;
        schedulerThread = null;
    }
    @Override
    public void execute() throws ComponentLifecycleException{
        super.execute();
        try {
        tel = TelescopeHelper.narrow(this.m_containerServices.getComponent("TELESCOPE"));
        db = DataBaseHelper.narrow(this.m_containerServices.getComponent("DATABASE"));
        } catch (AcsJContainerServicesEx ex){m_logger.severe("Error in getting components");}
    }
    @Override
    public void cleanUp() {
        stopflag = true;
        m_containerServices.releaseComponent(tel.name());
        m_containerServices.releaseComponent(db.name());
    }
    @Override
    public void start () throws SchedulerAlreadyRunningEx {
        if (running){ throw new AcsJSchedulerAlreadyRunningEx("Scheduler already started").toSchedulerAlreadyRunningEx();
        }
        schedulerThread = new Thread( () -> {
            try{
                proposals = db.getProposals();
                running = true;
                stopflag = false;
                m_logger.info("Starting proposal poll");
                for (Proposal pro : proposals){
                    propex = pro.pid;
                    for (Target target : pro.targets){
                        try {
                            m_logger.info("Starting observation");
                            byte[] image = tel.observe(target.coordinates, target.expTime);
                            db.storeImage(propex,target.tid,image);
                            Thread.sleep(1000);
                        } catch (PositionOutOfLimitsEx po)
                        {m_logger.warning("Position out of limits");}
                    }
                    m_logger.info("Storing proposal");
                    if (stopflag){
                        break;
                    }
                }
                propex = -1;

                running = false;
                m_logger.info("All proposal executed");
            }catch(InterruptedException e){}
            catch(Exception ex){m_logger.severe("Fail in getting proposal");}
        });
        schedulerThread.start();
    }
    @Override
    public void stop () throws SchedulerAlreadyStoppedEx{
            if (!stopflag){ throw new AcsJSchedulerAlreadyStoppedEx("Scheduler already stopped").toSchedulerAlreadyStoppedEx();
            }
        stopflag = true;
       };
    @Override
    public int proposalUnderExecution() throws NoProposalExecutingEx{
        if (propex == -1){
            throw new AcsJNoProposalExecutingEx("No proposal under execution").toNoProposalExecutingEx();
        }
        return propex;
    };
}

