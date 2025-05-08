//Suggested: import alma.<Module>.<Interface>Impl; //But anything, really
package acsws.SCHEDULER_MODULE.SchedulerImpl;
//Base component implementation, including container services and component lifecycle infrastructure
import alma.acs.component.ComponentImplBase;
import acsws.SCHEDULER_MODULE.SchedulerOperations;
import java.util.*;
//ClassName usually is <Interface>Impl, but can be anything
public class SchedulerImpl extends ComponentImplBase implements SchedulerOperations {
    private boolean running = false;
    final ArrayList<Proposal> proposals = new ArrayList<>();
    final int i = 0;
    private boolean stopflag = false;
    private int propex = -1;
    private Thread schedulerThread;
    private class Target {
        public int tid;
        public int coordinates;
        public int expTime;
        public Target(int tid, int coordinates, int expTime){
            this.tid = tid;
            this.coordinates = coordinates;
            this.expTime = expTime;
        }
    }
    private class Proposal {
        public int id;
        public ArrayList<Target> targetlist;
        public int status;
        public Proposal(int id, ArrayList<Target> target, int status){
            this.id = id;
            this.targetlist = target;
            this.status = status;
        }
    }
    public SchedulerImpl() {
        for(int i = 0; i < 5; i++){
            ArrayList<Target> targets = new ArrayList<>();
            for(int j = 0; j < 5; j++){
                targets.add(new Target(j, j, j));
            }
            Proposal pro = new Proposal(i, targets, i);
            proposals.add(pro);
        }
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
                propex = pro.id;
                for (Target target : pro.targetlist){
                    //Telescope.observe(target.coordinate, target.expTime)
                    Thread.sleep(1000);
                    }
                if (stopflag){
                    break;
                    }
            }
            propex = -1;
            running = false;
        }catch(InterruptedException e){

        }
        }
        );
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

