#include "particles/pit/runners/Runner.h"


#ifdef Parallel
#include "peano/utils/Globals.h"
#include "tarch/parallel/NodePool.h"
#include "tarch/compiler/CompilerSpecificSettings.h"
#include "peano/parallel/messages/ForkMessage.h"
#include "particles/pit/repositories/Repository.h"
#include "tarch/logging/CommandLineLogger.h"


int particles::pit::runners::Runner::runAsWorker(particles::pit::repositories::Repository& repository) {
  int newMasterNode = tarch::parallel::NodePool::getInstance().waitForJob(); 
  while ( newMasterNode != tarch::parallel::NodePool::JobRequestMessageAnswerValues::Terminate ) {
    if ( newMasterNode >= tarch::parallel::NodePool::JobRequestMessageAnswerValues::NewMaster ) {
      peano::parallel::messages::ForkMessage forkMessage;
      forkMessage.receive(
        tarch::parallel::NodePool::getInstance().getMasterRank(),
        tarch::parallel::NodePool::getInstance().getTagForForkMessages(),
        true,
        ReceiveIterationControlMessagesBlocking
      );

      repository.restart(
        forkMessage.getH(),
        forkMessage.getDomainOffset(),
        forkMessage.getLevel(),
        forkMessage.getPositionOfFineGridCellRelativeToCoarseGridCell()
      );
  
      bool continueToIterate = true;
      while (continueToIterate) {
        switch (repository.continueToIterate()) {
          case particles::pit::repositories::Repository::Continue:
            tarch::logging::CommandLineLogger::getInstance().closeOutputStreamAndReopenNewOne();
            repository.iterate();  
            break;
          case particles::pit::repositories::Repository::Terminate:
            continueToIterate = false;  
            break;
          case particles::pit::repositories::Repository::RunGlobalStep:
            runGlobalStep();  
            break;
        }
      }
    
      // insert your postprocessing here
      // -------------------------------  

      // -------------------------------

      repository.terminate();
    }
    else if ( newMasterNode == tarch::parallel::NodePool::JobRequestMessageAnswerValues::RunAllNodes ) {
      runGlobalStep();  
    }
    newMasterNode = tarch::parallel::NodePool::getInstance().waitForJob(); 
  }
  return 0;
}


void particles::pit::runners::Runner::runGlobalStep() {
  peano::parallel::loadbalancing::Oracle::getInstance().activateLoadBalancing(false);
}
#endif
