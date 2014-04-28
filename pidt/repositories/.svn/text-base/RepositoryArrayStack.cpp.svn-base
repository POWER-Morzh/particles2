#include "particles/pidt/repositories/RepositoryArrayStack.h"

#include "tarch/Assertions.h"
#include "tarch/timing/Watch.h"

#include "tarch/compiler/CompilerSpecificSettings.h"

#ifdef Parallel
#include "tarch/parallel/Node.h"
#include "tarch/parallel/NodePool.h"
#include "peano/parallel/SendReceiveBufferPool.h"
#include "peano/parallel/loadbalancing/Oracle.h"
#endif

#include "peano/datatraversal/autotuning/Oracle.h"


tarch::logging::Log particles::pidt::repositories::RepositoryArrayStack::_log( "particles::pidt::repositories::RepositoryArrayStack" );


particles::pidt::repositories::RepositoryArrayStack::RepositoryArrayStack(
  peano::geometry::Geometry&                   geometry,
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  domainOffset,
  int                                          maximumSizeOfCellInOutStack,
  int                                          maximumSizeOfVertexInOutStack,
  int                                          maximumSizeOfVertexTemporaryStack
):
  _geometry(geometry),
  _cellStack(maximumSizeOfCellInOutStack),
  _vertexStack(maximumSizeOfVertexInOutStack, maximumSizeOfVertexTemporaryStack),
  _solverState(),
  _gridWithNop(_vertexStack,_cellStack,_geometry,_solverState,domainSize,domainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithInitGrid(_vertexStack,_cellStack,_geometry,_solverState,domainSize,domainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithInitGridAndPlot(_vertexStack,_cellStack,_geometry,_solverState,domainSize,domainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithSetupExperimentWithRandomParticleDistribution(_vertexStack,_cellStack,_geometry,_solverState,domainSize,domainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithSetupExperimentWithRandomParticleDistributionAndPlot(_vertexStack,_cellStack,_geometry,_solverState,domainSize,domainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithMoveParticles(_vertexStack,_cellStack,_geometry,_solverState,domainSize,domainOffset,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithMoveParticlesAndPlot(_vertexStack,_cellStack,_geometry,_solverState,domainSize,domainOffset,_regularGridContainer,_traversalOrderOnTopLevel),

  _repositoryState() {
  logTraceIn( "RepositoryArrayStack(...)" );
  
  _repositoryState.setAction( particles::pidt::records::RepositoryState::Terminate );

  peano::datatraversal::autotuning::Oracle::getInstance().setNumberOfOracles(particles::pidt::records::RepositoryState::NumberOfAdapters);
  #ifdef Parallel
  peano::parallel::loadbalancing::Oracle::getInstance().setNumberOfOracles(particles::pidt::records::RepositoryState::NumberOfAdapters);
  #endif
  
  logTraceOut( "RepositoryArrayStack(...)" );
}



particles::pidt::repositories::RepositoryArrayStack::RepositoryArrayStack(
  peano::geometry::Geometry&                   geometry,
  int                                          maximumSizeOfCellInOutStack,
  int                                          maximumSizeOfVertexInOutStack,
  int                                          maximumSizeOfVertexTemporaryStack
):
  _geometry(geometry),
  _cellStack(maximumSizeOfCellInOutStack),
  _vertexStack(maximumSizeOfVertexInOutStack,maximumSizeOfVertexTemporaryStack),
  _solverState(),
  _gridWithNop(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithInitGrid(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithInitGridAndPlot(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithSetupExperimentWithRandomParticleDistribution(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithSetupExperimentWithRandomParticleDistributionAndPlot(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithMoveParticles(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),
  _gridWithMoveParticlesAndPlot(_vertexStack,_cellStack,_geometry,_solverState,_regularGridContainer,_traversalOrderOnTopLevel),

  _repositoryState() {
  logTraceIn( "RepositoryArrayStack(Geometry&)" );
  
  _repositoryState.setAction( particles::pidt::records::RepositoryState::Terminate );

  peano::datatraversal::autotuning::Oracle::getInstance().setNumberOfOracles(particles::pidt::records::RepositoryState::NumberOfAdapters);
  #ifdef Parallel
  peano::parallel::loadbalancing::Oracle::getInstance().setNumberOfOracles(particles::pidt::records::RepositoryState::NumberOfAdapters);
  #endif
  
  logTraceOut( "RepositoryArrayStack(Geometry&)" );
}
    
   
particles::pidt::repositories::RepositoryArrayStack::~RepositoryArrayStack() {
  assertion( _repositoryState.getAction() == particles::pidt::records::RepositoryState::Terminate );
}


void particles::pidt::repositories::RepositoryArrayStack::restart(
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  domainOffset,
  int                                          domainLevel,
  const tarch::la::Vector<DIMENSIONS,int>&     positionOfCentralElementWithRespectToCoarserRemoteLevel
) {
  logTraceInWith4Arguments( "restart(...)", domainSize, domainOffset, domainLevel, positionOfCentralElementWithRespectToCoarserRemoteLevel );
  #ifdef Parallel
  assertion( !tarch::parallel::Node::getInstance().isGlobalMaster());
  #endif
  
  logInfo( "restart(...)", "start node for subdomain " << domainOffset << "x" << domainSize << " on level " << domainLevel );
  
  assertion( _repositoryState.getAction() == particles::pidt::records::RepositoryState::Terminate );

  _vertexStack.clear();
  _cellStack.clear();

  _gridWithNop.restart(domainSize,domainOffset,domainLevel,positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithInitGrid.restart(domainSize,domainOffset,domainLevel,positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithInitGridAndPlot.restart(domainSize,domainOffset,domainLevel,positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithSetupExperimentWithRandomParticleDistribution.restart(domainSize,domainOffset,domainLevel,positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithSetupExperimentWithRandomParticleDistributionAndPlot.restart(domainSize,domainOffset,domainLevel,positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithMoveParticles.restart(domainSize,domainOffset,domainLevel,positionOfCentralElementWithRespectToCoarserRemoteLevel);
  _gridWithMoveParticlesAndPlot.restart(domainSize,domainOffset,domainLevel,positionOfCentralElementWithRespectToCoarserRemoteLevel);

 
   _solverState.restart();
 
  logTraceOut( "restart(...)" );
}


void particles::pidt::repositories::RepositoryArrayStack::terminate() {
  logTraceIn( "terminate()" );
  
  _repositoryState.setAction( particles::pidt::records::RepositoryState::Terminate );
  
  #ifdef Parallel
  if (tarch::parallel::Node::getInstance().isGlobalMaster()) {
    tarch::parallel::NodePool::getInstance().broadcastToWorkingNodes(
      _repositoryState,
      peano::parallel::SendReceiveBufferPool::getInstance().getIterationManagementTag()
    );
  }
  peano::parallel::SendReceiveBufferPool::getInstance().terminate();
  #endif
  
  _gridWithNop.terminate();
  _gridWithInitGrid.terminate();
  _gridWithInitGridAndPlot.terminate();
  _gridWithSetupExperimentWithRandomParticleDistribution.terminate();
  _gridWithSetupExperimentWithRandomParticleDistributionAndPlot.terminate();
  _gridWithMoveParticles.terminate();
  _gridWithMoveParticlesAndPlot.terminate();

 
  logTraceOut( "terminate()" );
}


particles::pidt::State& particles::pidt::repositories::RepositoryArrayStack::getState() {
  return _solverState;
}


const particles::pidt::State& particles::pidt::repositories::RepositoryArrayStack::getState() const {
  return _solverState;
}

   
void particles::pidt::repositories::RepositoryArrayStack::iterate() {
  tarch::timing::Watch watch( "particles::pidt::repositories::RepositoryArrayStack", "iterate(bool)", false);
  
  #ifdef Parallel
  if (tarch::parallel::Node::getInstance().isGlobalMaster()) {
    tarch::parallel::NodePool::getInstance().broadcastToWorkingNodes(
      _repositoryState,
      peano::parallel::SendReceiveBufferPool::getInstance().getIterationManagementTag()
    );
  }
  #endif

  peano::datatraversal::autotuning::Oracle::getInstance().switchToOracle(_repositoryState.getAction());
  #ifdef Parallel
  peano::parallel::loadbalancing::Oracle::getInstance().switchToOracle(_repositoryState.getAction());
  #endif

  switch ( _repositoryState.getAction()) {
    case particles::pidt::records::RepositoryState::UseAdapterNop: watch.startTimer(); _gridWithNop.iterate(); watch.stopTimer(); _measureNopCPUTime.setValue( watch.getCPUTime() ); _measureNopCalendarTime.setValue( watch.getCalendarTime() ); break;
    case particles::pidt::records::RepositoryState::UseAdapterInitGrid: watch.startTimer(); _gridWithInitGrid.iterate(); watch.stopTimer(); _measureInitGridCPUTime.setValue( watch.getCPUTime() ); _measureInitGridCalendarTime.setValue( watch.getCalendarTime() ); break;
    case particles::pidt::records::RepositoryState::UseAdapterInitGridAndPlot: watch.startTimer(); _gridWithInitGridAndPlot.iterate(); watch.stopTimer(); _measureInitGridAndPlotCPUTime.setValue( watch.getCPUTime() ); _measureInitGridAndPlotCalendarTime.setValue( watch.getCalendarTime() ); break;
    case particles::pidt::records::RepositoryState::UseAdapterSetupExperimentWithRandomParticleDistribution: watch.startTimer(); _gridWithSetupExperimentWithRandomParticleDistribution.iterate(); watch.stopTimer(); _measureSetupExperimentWithRandomParticleDistributionCPUTime.setValue( watch.getCPUTime() ); _measureSetupExperimentWithRandomParticleDistributionCalendarTime.setValue( watch.getCalendarTime() ); break;
    case particles::pidt::records::RepositoryState::UseAdapterSetupExperimentWithRandomParticleDistributionAndPlot: watch.startTimer(); _gridWithSetupExperimentWithRandomParticleDistributionAndPlot.iterate(); watch.stopTimer(); _measureSetupExperimentWithRandomParticleDistributionAndPlotCPUTime.setValue( watch.getCPUTime() ); _measureSetupExperimentWithRandomParticleDistributionAndPlotCalendarTime.setValue( watch.getCalendarTime() ); break;
    case particles::pidt::records::RepositoryState::UseAdapterMoveParticles: watch.startTimer(); _gridWithMoveParticles.iterate(); watch.stopTimer(); _measureMoveParticlesCPUTime.setValue( watch.getCPUTime() ); _measureMoveParticlesCalendarTime.setValue( watch.getCalendarTime() ); break;
    case particles::pidt::records::RepositoryState::UseAdapterMoveParticlesAndPlot: watch.startTimer(); _gridWithMoveParticlesAndPlot.iterate(); watch.stopTimer(); _measureMoveParticlesAndPlotCPUTime.setValue( watch.getCPUTime() ); _measureMoveParticlesAndPlotCalendarTime.setValue( watch.getCalendarTime() ); break;

    case particles::pidt::records::RepositoryState::Terminate:
      assertionMsg( false, "this branch/state should never be reached" ); 
      break;
    case particles::pidt::records::RepositoryState::NumberOfAdapters:
      assertionMsg( false, "this branch/state should never be reached" ); 
      break;
    case particles::pidt::records::RepositoryState::RunOnAllNodes:
      assertionMsg( false, "this branch/state should never be reached" ); 
      break;
    case particles::pidt::records::RepositoryState::ReadCheckpoint:
      assertionMsg( false, "not implemented yet" );
      break;
    case particles::pidt::records::RepositoryState::WriteCheckpoint:
      assertionMsg( false, "not implemented yet" );
      break;
  }
  
  #ifdef Parallel
  if (_solverState.isJoiningWithMaster()) {
    _repositoryState.setAction( particles::pidt::records::RepositoryState::Terminate );
  }
  #endif
}

 void particles::pidt::repositories::RepositoryArrayStack::switchToNop() { _repositoryState.setAction(particles::pidt::records::RepositoryState::UseAdapterNop); }
 void particles::pidt::repositories::RepositoryArrayStack::switchToInitGrid() { _repositoryState.setAction(particles::pidt::records::RepositoryState::UseAdapterInitGrid); }
 void particles::pidt::repositories::RepositoryArrayStack::switchToInitGridAndPlot() { _repositoryState.setAction(particles::pidt::records::RepositoryState::UseAdapterInitGridAndPlot); }
 void particles::pidt::repositories::RepositoryArrayStack::switchToSetupExperimentWithRandomParticleDistribution() { _repositoryState.setAction(particles::pidt::records::RepositoryState::UseAdapterSetupExperimentWithRandomParticleDistribution); }
 void particles::pidt::repositories::RepositoryArrayStack::switchToSetupExperimentWithRandomParticleDistributionAndPlot() { _repositoryState.setAction(particles::pidt::records::RepositoryState::UseAdapterSetupExperimentWithRandomParticleDistributionAndPlot); }
 void particles::pidt::repositories::RepositoryArrayStack::switchToMoveParticles() { _repositoryState.setAction(particles::pidt::records::RepositoryState::UseAdapterMoveParticles); }
 void particles::pidt::repositories::RepositoryArrayStack::switchToMoveParticlesAndPlot() { _repositoryState.setAction(particles::pidt::records::RepositoryState::UseAdapterMoveParticlesAndPlot); }



 bool particles::pidt::repositories::RepositoryArrayStack::isActiveAdapterNop() const { return _repositoryState.getAction() == particles::pidt::records::RepositoryState::UseAdapterNop; }
 bool particles::pidt::repositories::RepositoryArrayStack::isActiveAdapterInitGrid() const { return _repositoryState.getAction() == particles::pidt::records::RepositoryState::UseAdapterInitGrid; }
 bool particles::pidt::repositories::RepositoryArrayStack::isActiveAdapterInitGridAndPlot() const { return _repositoryState.getAction() == particles::pidt::records::RepositoryState::UseAdapterInitGridAndPlot; }
 bool particles::pidt::repositories::RepositoryArrayStack::isActiveAdapterSetupExperimentWithRandomParticleDistribution() const { return _repositoryState.getAction() == particles::pidt::records::RepositoryState::UseAdapterSetupExperimentWithRandomParticleDistribution; }
 bool particles::pidt::repositories::RepositoryArrayStack::isActiveAdapterSetupExperimentWithRandomParticleDistributionAndPlot() const { return _repositoryState.getAction() == particles::pidt::records::RepositoryState::UseAdapterSetupExperimentWithRandomParticleDistributionAndPlot; }
 bool particles::pidt::repositories::RepositoryArrayStack::isActiveAdapterMoveParticles() const { return _repositoryState.getAction() == particles::pidt::records::RepositoryState::UseAdapterMoveParticles; }
 bool particles::pidt::repositories::RepositoryArrayStack::isActiveAdapterMoveParticlesAndPlot() const { return _repositoryState.getAction() == particles::pidt::records::RepositoryState::UseAdapterMoveParticlesAndPlot; }



peano::grid::Checkpoint<particles::pidt::Vertex, particles::pidt::Cell>* particles::pidt::repositories::RepositoryArrayStack::createEmptyCheckpoint() {
  return new peano::grid::Checkpoint<particles::pidt::Vertex, particles::pidt::Cell>();
} 


void particles::pidt::repositories::RepositoryArrayStack::writeCheckpoint(peano::grid::Checkpoint<particles::pidt::Vertex, particles::pidt::Cell> * const checkpoint) {
  _solverState.writeToCheckpoint( *checkpoint );
  _vertexStack.writeToCheckpoint( *checkpoint );
  _cellStack.writeToCheckpoint( *checkpoint );
} 


void particles::pidt::repositories::RepositoryArrayStack::setMaximumMemoryFootprintForTemporaryRegularGrids(double value) {
  _regularGridContainer.setMaximumMemoryFootprintForTemporaryRegularGrids(value);
}


void particles::pidt::repositories::RepositoryArrayStack::readCheckpoint( peano::grid::Checkpoint<particles::pidt::Vertex, particles::pidt::Cell> const * const checkpoint ) {
  assertionMsg( checkpoint->isValid(), "checkpoint has to be valid if you call this operation" );

  _solverState.readFromCheckpoint( *checkpoint );
  _vertexStack.readFromCheckpoint( *checkpoint );
  _cellStack.readFromCheckpoint( *checkpoint );
}


#ifdef Parallel
void particles::pidt::repositories::RepositoryArrayStack::runGlobalStep() {
  assertion(tarch::parallel::Node::getInstance().isGlobalMaster());

  particles::pidt::records::RepositoryState intermediateStateForWorkingNodes;
  intermediateStateForWorkingNodes.setAction( particles::pidt::records::RepositoryState::RunOnAllNodes );
  
  tarch::parallel::NodePool::getInstance().broadcastToWorkingNodes(
    intermediateStateForWorkingNodes,
    peano::parallel::SendReceiveBufferPool::getInstance().getIterationManagementTag()
  );
  tarch::parallel::NodePool::getInstance().activateIdleNodes();
}


particles::pidt::repositories::RepositoryArrayStack::ContinueCommand particles::pidt::repositories::RepositoryArrayStack::continueToIterate() {
  logTraceIn( "continueToIterate()" );

  assertion( !tarch::parallel::Node::getInstance().isGlobalMaster());

  ContinueCommand result;
  if ( _solverState.hasJoinedWithMaster() ) {
    result = Terminate;
  }
  else {
    int masterNode = tarch::parallel::Node::getInstance().getGlobalMasterRank();
    assertion( masterNode != -1 );

    _repositoryState.receive( masterNode, peano::parallel::SendReceiveBufferPool::getInstance().getIterationManagementTag(), true, ReceiveIterationControlMessagesBlocking );

    result = Continue;
    if (_repositoryState.getAction()==particles::pidt::records::RepositoryState::Terminate) {
      result = Terminate;
    } 
    if (_repositoryState.getAction()==particles::pidt::records::RepositoryState::RunOnAllNodes) {
      result = RunGlobalStep;
    } 
  }
   
  logTraceOutWith1Argument( "continueToIterate()", result );
  return result;
}
#endif


void particles::pidt::repositories::RepositoryArrayStack::logIterationStatistics() const {
  logInfo( "logIterationStatistics()", "|| adapter name \t || iterations \t || total CPU time [t]=s \t || average CPU time [t]=s \t || total user time [t]=s \t || average user time [t]=s  || CPU time properties  || user time properties " );  
   logInfo( "logIterationStatistics()", "| Nop \t |  " << _measureNopCPUTime.getNumberOfMeasurements() << " \t |  " << _measureNopCPUTime.getAccumulatedValue() << " \t |  " << _measureNopCPUTime.getValue()  << " \t |  " << _measureNopCalendarTime.getAccumulatedValue() << " \t |  " << _measureNopCalendarTime.getValue() << " \t |  " << _measureNopCPUTime.toString() << " \t |  " << _measureNopCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| InitGrid \t |  " << _measureInitGridCPUTime.getNumberOfMeasurements() << " \t |  " << _measureInitGridCPUTime.getAccumulatedValue() << " \t |  " << _measureInitGridCPUTime.getValue()  << " \t |  " << _measureInitGridCalendarTime.getAccumulatedValue() << " \t |  " << _measureInitGridCalendarTime.getValue() << " \t |  " << _measureInitGridCPUTime.toString() << " \t |  " << _measureInitGridCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| InitGridAndPlot \t |  " << _measureInitGridAndPlotCPUTime.getNumberOfMeasurements() << " \t |  " << _measureInitGridAndPlotCPUTime.getAccumulatedValue() << " \t |  " << _measureInitGridAndPlotCPUTime.getValue()  << " \t |  " << _measureInitGridAndPlotCalendarTime.getAccumulatedValue() << " \t |  " << _measureInitGridAndPlotCalendarTime.getValue() << " \t |  " << _measureInitGridAndPlotCPUTime.toString() << " \t |  " << _measureInitGridAndPlotCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| SetupExperimentWithRandomParticleDistribution \t |  " << _measureSetupExperimentWithRandomParticleDistributionCPUTime.getNumberOfMeasurements() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionCPUTime.getAccumulatedValue() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionCPUTime.getValue()  << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionCalendarTime.getAccumulatedValue() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionCalendarTime.getValue() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionCPUTime.toString() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| SetupExperimentWithRandomParticleDistributionAndPlot \t |  " << _measureSetupExperimentWithRandomParticleDistributionAndPlotCPUTime.getNumberOfMeasurements() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionAndPlotCPUTime.getAccumulatedValue() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionAndPlotCPUTime.getValue()  << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionAndPlotCalendarTime.getAccumulatedValue() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionAndPlotCalendarTime.getValue() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionAndPlotCPUTime.toString() << " \t |  " << _measureSetupExperimentWithRandomParticleDistributionAndPlotCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| MoveParticles \t |  " << _measureMoveParticlesCPUTime.getNumberOfMeasurements() << " \t |  " << _measureMoveParticlesCPUTime.getAccumulatedValue() << " \t |  " << _measureMoveParticlesCPUTime.getValue()  << " \t |  " << _measureMoveParticlesCalendarTime.getAccumulatedValue() << " \t |  " << _measureMoveParticlesCalendarTime.getValue() << " \t |  " << _measureMoveParticlesCPUTime.toString() << " \t |  " << _measureMoveParticlesCalendarTime.toString() );
   logInfo( "logIterationStatistics()", "| MoveParticlesAndPlot \t |  " << _measureMoveParticlesAndPlotCPUTime.getNumberOfMeasurements() << " \t |  " << _measureMoveParticlesAndPlotCPUTime.getAccumulatedValue() << " \t |  " << _measureMoveParticlesAndPlotCPUTime.getValue()  << " \t |  " << _measureMoveParticlesAndPlotCalendarTime.getAccumulatedValue() << " \t |  " << _measureMoveParticlesAndPlotCalendarTime.getValue() << " \t |  " << _measureMoveParticlesAndPlotCPUTime.toString() << " \t |  " << _measureMoveParticlesAndPlotCalendarTime.toString() );

}


void particles::pidt::repositories::RepositoryArrayStack::clearIterationStatistics() {
   _measureNopCPUTime.erase();
   _measureInitGridCPUTime.erase();
   _measureInitGridAndPlotCPUTime.erase();
   _measureSetupExperimentWithRandomParticleDistributionCPUTime.erase();
   _measureSetupExperimentWithRandomParticleDistributionAndPlotCPUTime.erase();
   _measureMoveParticlesCPUTime.erase();
   _measureMoveParticlesAndPlotCPUTime.erase();

   _measureNopCalendarTime.erase();
   _measureInitGridCalendarTime.erase();
   _measureInitGridAndPlotCalendarTime.erase();
   _measureSetupExperimentWithRandomParticleDistributionCalendarTime.erase();
   _measureSetupExperimentWithRandomParticleDistributionAndPlotCalendarTime.erase();
   _measureMoveParticlesCalendarTime.erase();
   _measureMoveParticlesAndPlotCalendarTime.erase();

}
