#include "particles/pidt/runners/Runner.h"


#include "tarch/Assertions.h"

#include "tarch/parallel/Node.h"
#include "tarch/parallel/NodePool.h"

#include "tarch/multicore/MulticoreDefinitions.h"

#include "tarch/logging/CommandLineLogger.h"

#include "tarch/la/ScalarOperations.h"

#include "peano/utils/UserInterface.h"
#include "peano/utils/Loop.h"

#include "peano/geometry/Hexahedron.h"

#include "peano/datatraversal/autotuning/Oracle.h"
#include "peano/datatraversal/autotuning/OracleForOnePhaseDummy.h"

#include "peano/heap/Heap.h"

#include "particles/ExperimentSettings.h"
#include "particles/pidt/records/Particle.h"
#include "particles/pidt/repositories/Repository.h"
#include "particles/pidt/repositories/RepositoryFactory.h"
#include "particles/pidt/mappings/DropParticles.h"


#include "peano/parallel/loadbalancing/Oracle.h"


tarch::logging::Log particles::pidt::runners::Runner::_log( "particles::pidt::runners::Runner" );


particles::pidt::runners::Runner::Runner() {
}


particles::pidt::runners::Runner::~Runner() {
}


int particles::pidt::runners::Runner::run() {
  logTraceIn( "run(...)" );

  peano::geometry::Hexahedron geometry(
    tarch::la::Vector<DIMENSIONS,double>(1.0),
    tarch::la::Vector<DIMENSIONS,double>(0.0)
   );
  particles::pidt::repositories::Repository* repository = 
    particles::pidt::repositories::RepositoryFactory::getInstance().createWithSTDStackImplementation(
      geometry,
      tarch::la::Vector<DIMENSIONS,double>(1.0),   // domainSize,
      tarch::la::Vector<DIMENSIONS,double>(0.0)    // computationalDomainOffset
    );
  
  int result = 0;
  if (tarch::parallel::Node::getInstance().isGlobalMaster()) {
    result = runAsMaster( *repository );
    tarch::parallel::NodePool::getInstance().terminate();
  }
  #ifdef Parallel
  else {
    result = runAsWorker( *repository );
  }
  #endif
  
  particles::pidt::repositories::RepositoryFactory::getInstance().shutdownAllParallelDatatypes();

  #if defined( SharedMemoryParallelisation ) && !defined( Parallel )
  peano::datatraversal::autotuning::Oracle::getInstance().plotStatistics();
  #endif

  delete repository;
  
  logTraceOut( "run(...)" );

  return result;
}


int particles::pidt::runners::Runner::runAsMaster( particles::pidt::repositories::Repository& repository ) {
  peano::utils::UserInterface userInterface;
  userInterface.writeHeader();

  repository.getState().init(
    particles::ExperimentSettings::chosenConfiguration->ppc,
    particles::ExperimentSettings::chosenConfiguration->dt,
    particles::ExperimentSettings::chosenConfiguration->particleDensity,
    particles::ExperimentSettings::chosenConfiguration->maximalInitialVelocity,
    particles::ExperimentSettings::chosenConfiguration->breakingDamWidth
  );

  tarch::parallel::NodePool::getInstance().waitForAllNodesToBecomeIdle();
  logInfo(
    "runAsMaster()",
    "number of working ranks=" << tarch::parallel::NodePool::getInstance().getNumberOfWorkingNodes()
  );
  logInfo(
    "runAsMaster()",
    "number of idle ranks=" << tarch::parallel::NodePool::getInstance().getNumberOfIdleNodes()
  );

  repository.switchToInitGrid();
  repository.iterate();
  repository.iterate();
  logInfo(
    "runAsMaster()",
    "built up start grid with max depth=" << repository.getState().getMaxLevel() << ", vertices=" << repository.getState().getNumberOfInnerVertices()
  );

   while (!repository.getState().isGridBalanced()) {
     if (!tarch::parallel::NodePool::getInstance().areAllNodesWorking()) {
       repository.switchToNop();
       repository.iterate();
       repository.iterate();
       repository.iterate();
     }
     #if defined(Asserts) || defined(Debug)
     repository.switchToInitGridAndPlot();
     #else
     repository.switchToInitGrid();
     #endif
     repository.iterate();
     logDebug("runAsMaster()","still balancing grid with max depth=" << repository.getState().getMaxLevel() << ", vertices=" << repository.getState().getNumberOfInnerVertices());
   }

  logInfo(
    "runAsMaster()",
    "quit grid construction with max depth=" << repository.getState().getMaxLevel() << ", vertices=" << repository.getState().getNumberOfInnerVertices()
  );
  logInfo(
    "runAsMaster()",
    "number of working ranks=" << tarch::parallel::NodePool::getInstance().getNumberOfWorkingNodes()
  );

  switch (particles::ExperimentSettings::chosenConfiguration->timeSteppingAdapter) {
    case particles::ExperimentSettings::PureGrid:
      repository.switchToSetupExperimentWithRandomParticleDistribution();
      break;
    case particles::ExperimentSettings::ExplicitEulerWithPlot:
      repository.switchToSetupExperimentWithRandomParticleDistributionAndPlot();
      break;
    case particles::ExperimentSettings::ExplicitEuler:
      #if defined(Asserts) || defined(Debug)
      repository.switchToSetupExperimentWithRandomParticleDistributionAndPlot();
      #else
      repository.switchToSetupExperimentWithRandomParticleDistribution();
      #endif
      break;
  }

  repository.iterate();
  logInfo( "runAsMaster()", "grid initialisation done, max depth=" << repository.getState().getMaxLevel() );

  assertion1( repository.getState().isGridStationary(), repository.getState().toString() );

  #ifdef Parallel
  repository.runGlobalStep();
  #endif

  switch (particles::ExperimentSettings::chosenConfiguration->timeSteppingAdapter) {
    case particles::ExperimentSettings::PureGrid:
      repository.switchToNop();
      break;
    case particles::ExperimentSettings::ExplicitEulerWithPlot:
      repository.switchToMoveParticlesAndPlot();
      break;
    case particles::ExperimentSettings::ExplicitEuler:
      repository.switchToMoveParticles();
      break;
  }


  assertion(particles::ExperimentSettings::chosenConfiguration->numberOfTimeSteps>0);


  for (int i=0; i<particles::ExperimentSettings::chosenConfiguration->numberOfTimeSteps; i++) {
    tarch::logging::CommandLineLogger::getInstance().closeOutputStreamAndReopenNewOne();

    repository.getState().clearStatistics();

    repository.iterate();

    logInfo( "runAsMaster()", "#lifts=" << repository.getState().getTotalNumberOfLifts() );
    logInfo( "runAsMaster()", "#particles=" << repository.getState().getNumberOfParticles() << " (particles plus temporary duplicates of destroyed cells)" );
    logInfo( "runAsMaster()", "#lifts per particle=" << repository.getState().getTotalNumberOfLifts() / repository.getState().getNumberOfParticles() );
    logInfo( "runAsMaster()", "mean density of non-empty cells=" << repository.getState().getMeanParticleDensityInNonEmptyCells() );
    logInfo( "runAsMaster()", "inner leaves=" << repository.getState().getNumberOfInnerLeafCells() );
    logInfo( "runAsMaster()", "inner vertices=" << repository.getState().getNumberOfInnerVertices() );
    logInfo( "runAsMaster()", "non-empty leaves=" << repository.getState().getNumberOfNonEmptyLeaves() );
    logInfo( "runAsMaster()", "particles per cell=" << repository.getState().getAverageParticlesPerCell() );
    logInfo( "runAsMaster()", "grid stationary=" << repository.getState().isGridStationary() );

    #ifdef Parallel
    logInfo( "runAsMaster()", "particles sent to master=" << repository.getState().getNumberOfSendsToMaster() );
    #endif

    for (int j=0; j<MaxLevels; j++) {
      logInfo( "runAsMaster()", "#lifts(" << j << ")=" << repository.getState().getNumberOfLifts(j) );
    }

    logInfo( "runAsMaster(...)", "finished iteration " << i );
    assertion1(
      !State::AlwaysReduceAlongMasterWorkers
      ||
      repository.getState().getNumberOfParticles()>0, repository.getState().toString()
    );
  }

  repository.logIterationStatistics();
  repository.terminate();
  return 0;
}
