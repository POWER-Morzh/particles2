#include "particles/pidt/runners/Runner.h"


#ifdef Parallel
#include "peano/utils/Globals.h"
#include "tarch/parallel/NodePool.h"
#include "tarch/compiler/CompilerSpecificSettings.h"
#include "peano/parallel/messages/ForkMessage.h"
#include "particles/pidt/repositories/Repository.h"
#include "tarch/logging/CommandLineLogger.h"


int particles::pidt::runners::Runner::runAsWorker(particles::pidt::repositories::Repository& repository) {
  int newMasterNode = tarch::parallel::NodePool::getInstance().waitForJob(); 
  while ( newMasterNode != tarch::parallel::NodePool::JobRequestMessageAnswerValues::Terminate ) {
    if ( newMasterNode >= tarch::parallel::NodePool::JobRequestMessageAnswerValues::NewMaster ) {
      peano::parallel::messages::ForkMessage forkMessage;
      forkMessage.receive(tarch::parallel::NodePool::getInstance().getMasterRank(),tarch::parallel::NodePool::getInstance().getTagForForkMessages(), true, ReceiveIterationControlMessagesBlocking);

      repository.restart(
        forkMessage.getH(),
        forkMessage.getDomainOffset(),
        forkMessage.getLevel(),
        forkMessage.getPositionOfFineGridCellRelativeToCoarseGridCell()
      );
  
      bool continueToIterate = true;
      while (continueToIterate) {
        tarch::logging::CommandLineLogger::getInstance().closeOutputStreamAndReopenNewOne();
        switch (repository.continueToIterate()) {
          case particles::pidt::repositories::Repository::Continue:
            tarch::logging::CommandLineLogger::getInstance().closeOutputStreamAndReopenNewOne();
            repository.iterate();  
            break;
          case particles::pidt::repositories::Repository::Terminate:
            continueToIterate = false;  
            break;
          case particles::pidt::repositories::Repository::RunGlobalStep:
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


void particles::pidt::runners::Runner::runGlobalStep() {
  peano::parallel::loadbalancing::Oracle::getInstance().activateLoadBalancing(false);
}
#endif
