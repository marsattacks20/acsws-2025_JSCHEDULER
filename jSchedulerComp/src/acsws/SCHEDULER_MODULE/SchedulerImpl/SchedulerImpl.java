//Suggested: import alma.<Module>.<Interface>Impl; //But anything, really
package acsws.SCHEDULER_MODULE.SchedulerImpl;
//Base component implementation, including container services and component lifecycle infrastructure
import alma.acs.component.ComponentImplBase;
import acsws.SCHEDULER_MODULE.SchedulerOperations;
import acsws.TELESCOPE_MODULE.TelescopeOperations;
//import acsws.TELESCOPE_MODULE.TelescopeComponentHelper;
import acsws.STORAGE_MODULE.StorageOperations;
//import acsws.STORAGE_MODULE.StorageComponentHelper;
import acsws.DATABASE_MODULE.DataBaseOperations;
//import acsws.DATABASE_MODULE.DataBaseComponentHelper;
import acsws.TYPES.Proposal;
import acsws.TYPES.Target;
import acsws.TYPES.Position;






import java.util.*;
//ClassName usually is <Interface>Impl, but can be anything
public class SchedulerImpl extends ComponentImplBase implements SchedulerOperations {
    private boolean running = false;
    final ArrayList<Proposal> proposals = new ArrayList<>();
    final int i = 0;
    private boolean stopflag = false;
    private int propex = -1;
    private Thread schedulerThread;


    public SchedulerImpl() {
        //By Name
        Telescope tel = TelescopeComponentHelper.narrow(this.m_containerServices.getComponent("<Name>"));
        //Release Components
        this.m_containerServies.releaseComponent(tel.name());
    }

    @Override
    public void start (){
        if (running){ //Exception
        }
        schedulerThread = new Thread( () -> {
            try{
                running = true;
                stopflag = false;
                for (Proposal pro : proposals){
                    byte[][] imageList = new byte[1024][1024];
                    propex = pro.pid;
                    int i = 0;
                    for (Target target : pro.targets){
                        byte[] image = Telescope.observe(target.coordinates, target.expTime);
                        imageList[i] = image;
                        Thread.sleep(1000);
                    }
                    storage.storeObservation(pro, imageList);

                    if (stopflag){
                        break;
                    }
                }
                propex = -1;
                running = false;
            }catch(InterruptedException e){

            }
        });
        schedulerThread.start();
    }
    @Override
    public void stop (){
            if (!stopflag){
                //EX
            }
        stopflag = true;
       };
    @Override
    public int proposalUnderExecution(){
        if (propex == -1){
            //EX
        }
        return propex;
    };
}

