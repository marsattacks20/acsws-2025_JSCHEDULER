package acsws.SCHEDULER_MODULE.SchedulerImpl;
  
//Base component implementation, including container services and component lifecycle infrastructure
import alma.acs.component.ComponentImplBase;
//Skeleton interface for server implementation
import acsws.SCHEDULER_MODULE.SchedulerOperations;
import acsws.DATABASE_MODULE.DataBaseOperations; 
//ClassName usually is <Interface>Impl, but can be anything
public class SchedulerImpl extends ComponentImplBase implements SchedulerOperations {


    public SchedulerImpl() {

    }

    @Override
    public void start() {
    }

    @Override
    public void stop() {

    }

    @Override
    public int proposalUnderExecution() {
        return 1;
    }

    
}

