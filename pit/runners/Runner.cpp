#include "particles/pit/runners/Runner.h"


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
#include "particles/pit/records/Particle.h"
#include "particles/pit/repositories/Repository.h"
#include "particles/pit/repositories/RepositoryFactory.h"
#include "particles/pit/mappings/DropParticles.h"

#include "peano/parallel/loadbalancing/Oracle.h"


#include <sstream>


#ifdef SharedTBB
#include <tbb/parallel_for.h>
#endif


tarch::logging::Log particles::pit::runners::Runner::_log( "particles::pit::runners::Runner" );


particles::pit::runners::Runner::Runner() {
}


particles::pit::runners::Runner::~Runner() {
}


int particles::pit::runners::Runner::run() {
  logTraceIn( "run(...)" );

  peano::geometry::Hexahedron geometry(
    tarch::la::Vector<DIMENSIONS,double>(1.0),
    tarch::la::Vector<DIMENSIONS,double>(0.0)
   );
  particles::pit::repositories::Repository* repository = 
    particles::pit::repositories::RepositoryFactory::getInstance().createWithSTDStackImplementation(
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

  particles::pit::repositories::RepositoryFactory::getInstance().shutdownAllParallelDatatypes();

  #if defined( SharedMemoryParallelisation ) && !defined( Parallel )
  peano::datatraversal::autotuning::Oracle::getInstance().plotStatistics();
  #endif

  delete repository;
  
  logTraceOut( "run(...)" );

  return result;
}


int particles::pit::runners::Runner::runMemoryBenchmark() {
  peano::utils::UserInterface userInterface;

  const int numberOfParticles = tarch::la::round(particles::ExperimentSettings::chosenConfiguration->particleDensity);
  std::ostringstream experimentName;
  experimentName << "memory benchmark "
                 << "(#particles=" << numberOfParticles
                 << ",#t=" << particles::ExperimentSettings::chosenConfiguration->numberOfTimeSteps
                 << ")";
  userInterface.writeHeader( experimentName.str() );

  int particleArrayIndex = ParticleHeap::getInstance().createData(numberOfParticles);
  for (int i=0; i<numberOfParticles; i++) {
    particles::pit::records::Particle& newParticle = ParticleHeap::getInstance().getData(particleArrayIndex)[i];
    const double xScaling        = 1.0;
    const double velocityScaling = particles::ExperimentSettings::chosenConfiguration->maximalInitialVelocity;
    for (int d=0; d<DIMENSIONS; d++) {
      newParticle._persistentRecords._x(d) = static_cast<double>(rand())/static_cast<double>(RAND_MAX) * xScaling;
      newParticle._persistentRecords._v(d) = (static_cast<double>(rand())/static_cast<double>(RAND_MAX) * 2.0 - 1.0) * velocityScaling;
    }
  }

  int    gridPointsPerDimension = 1;
  gridPointsPerDimension++;

  tarch::timing::Watch watch( "particles::pit::runners::Runner", "runMemoryBenchmark", true );

  const double timeStepSize = particles::ExperimentSettings::chosenConfiguration->dt;
  for (int t=0; t<particles::ExperimentSettings::chosenConfiguration->numberOfTimeSteps; t++) {
    tarch::logging::CommandLineLogger::getInstance().closeOutputStreamAndReopenNewOne();

    #ifdef SharedTBB
    tbb::parallel_for(0,numberOfParticles,1,[=](int i){
    #else
    for (int i=0; i<numberOfParticles; i++) {
    #endif
      particles::pit::records::Particle& particle = ParticleHeap::getInstance().getData(particleArrayIndex).at(i);
      particle._persistentRecords._x += (timeStepSize * particle._persistentRecords._v);
      particles::pit::mappings::DropParticles::reflectParticle(particle);
    #ifdef SharedTBB
    });
    #else
    }
    #endif
  }

  ParticleHeap::getInstance().deleteAllData();

  return 0;
}


int particles::pit::runners::Runner::runAsMaster(particles::pit::repositories::Repository& repository) {
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
     tarch::logging::CommandLineLogger::getInstance().closeOutputStreamAndReopenNewOne();
     if (!tarch::parallel::NodePool::getInstance().areAllNodesWorking()) {
       repository.switchToNop();
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

  tarch::logging::CommandLineLogger::getInstance().closeOutputStreamAndReopenNewOne();
  repository.iterate();
  logInfo( "runAsMaster()", "grid initialisation done, max depth=" << repository.getState().getMaxLevel() );

  assertion1( repository.getState().isGridStationary(), repository.getState().toString() );

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

  #ifdef Parallel
  repository.runGlobalStep();
  #endif

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
    assertion1( repository.getState().getNumberOfParticles()>0, repository.getState().toString() );
  }

  repository.logIterationStatistics();
  repository.terminate();

  return 0;
}
