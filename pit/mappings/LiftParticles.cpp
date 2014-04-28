#include "particles/pit/mappings/LiftParticles.h"
#include "peano/utils/Loop.h"
#include "tarch/multicore/MulticoreDefinitions.h"



peano::MappingSpecification   particles::pit::mappings::LiftParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}

peano::MappingSpecification   particles::pit::mappings::LiftParticles::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}

peano::MappingSpecification   particles::pit::mappings::LiftParticles::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}

peano::MappingSpecification   particles::pit::mappings::LiftParticles::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}

peano::MappingSpecification   particles::pit::mappings::LiftParticles::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}

peano::MappingSpecification   particles::pit::mappings::LiftParticles::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pit::mappings::LiftParticles::_log( "particles::pit::mappings::LiftParticles" ); 



//
// Implemented Events
// ==================
//


bool particles::pit::mappings::LiftParticles::liftParticle(
  const particles::pit::records::Particle&     particle,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h
) const {
  bool result = false;
  for (int d=0; d<DIMENSIONS; d++) {
    result |= (particle._persistentRecords._x(d)<x(d));
    result |= (particle._persistentRecords._x(d)>x(d) + h(d) );
  }
  return result;
}



void particles::pit::mappings::LiftParticles::ascend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&  coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
  logTraceIn( "ascend(...)" );

  const int                                  coarseCellIndex  = coarseGridCell.getCellIndex();
  const tarch::la::Vector<DIMENSIONS,double> cellSize         = fineGridVerticesEnumerator.getCellSize();

  dfor3(k)
    const int                                  fineCellIndex = fineGridCells[ fineGridVerticesEnumerator.cell(k) ].getCellIndex();
    const tarch::la::Vector<DIMENSIONS,double> cellOffset    = fineGridVerticesEnumerator.getVertexPosition(k);

    for (
      std::vector<particles::pit::records::Particle>::iterator p = ParticleHeap::getInstance().getData(fineCellIndex).begin();
      p != ParticleHeap::getInstance().getData(fineCellIndex).end();
    ) {
      const bool lift = liftParticle(*p,cellOffset,cellSize);
      if (lift) {
        logDebug(
          "leaveCell(...)",
          "lift particle " << p->toString() <<
          " from cell " << fineCellIndex << " to cell " << coarseCellIndex <<
          ", i.e. up from level " << fineGridVerticesEnumerator.getLevel() <<
          " to " << coarseGridVerticesEnumerator.getLevel() <<
          "; fine cell=" << fineGridVerticesEnumerator.getVertexPosition() << "x" << fineGridVerticesEnumerator.getCellSize()
        );

        ParticleHeap::getInstance().getData(coarseCellIndex).push_back(*p);
        p=ParticleHeap::getInstance().getData(fineCellIndex).erase(p);

        _state.incNumberOfLifts( fineGridVerticesEnumerator.getLevel() );
      }
      else {
        p++;
      }
    }
  enddforx

  logTraceOut( "ascend(...)" );
}



#if defined(SharedMemoryParallelisation)
particles::pit::mappings::LiftParticles::LiftParticles(const LiftParticles&  masterThread):
  _state(masterThread._state),
  _clearStateAfterIteration(masterThread._clearStateAfterIteration) {
  logTraceIn( "LiftParticles(LiftParticles)" );

  _state.clearStatistics();

  logTraceOut( "LiftParticles(LiftParticles)" );
}


void particles::pit::mappings::LiftParticles::mergeWithWorkerThread(const LiftParticles& workerThread) {
  logTraceIn( "mergeWithWorkerThread(LiftParticles)" );

  _state.reduceStateStatistics( workerThread._state );

  logTraceOut( "mergeWithWorkerThread(LiftParticles)" );
}
#endif


void particles::pit::mappings::LiftParticles::beginIteration(
  particles::pit::State&  solverState
) {
  #ifdef Parallel
  _clearStateAfterIteration = solverState.reduceDataToMaster();
  #else
  _clearStateAfterIteration = true;
  #endif
}


void particles::pit::mappings::LiftParticles::endIteration(
  particles::pit::State&  solverState
) {
  logTraceInWith1Argument( "endIteration(State)", solverState );

  solverState.reduceStateStatistics( _state );
  if (_clearStateAfterIteration ) {
    _state.clearStatistics();
  }

  #ifdef Parallel
  if (tarch::parallel::Node::getInstance().isGlobalMaster()) {
    ParticleHeap::getInstance().finishedToSendSynchronousData();
    ParticleHeap::getInstance().plotStatistics();
  }
  #endif

  logTraceOutWith1Argument( "endIteration(State)", solverState);
}


particles::pit::mappings::LiftParticles::LiftParticles():
  _clearStateAfterIteration(false) {
  _state.clearStatistics();
}


#ifdef Parallel
void particles::pit::mappings::LiftParticles::prepareSendToMaster(
  particles::pit::Cell&                      localCell,
  particles::pit::Vertex *                   vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator,
  const particles::pit::Vertex * const       coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pit::Cell&                coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
  logTraceInWith2Arguments( "prepareSendToMaster(...)", localCell, verticesEnumerator.toString() );

  ParticleHeap::HeapEntries liftedParticles;

  const int fineCellIndex = localCell.getCellIndex();

  for (
    ParticleHeap::HeapEntries::iterator p = ParticleHeap::getInstance().getData(fineCellIndex).begin();
    p != ParticleHeap::getInstance().getData(fineCellIndex).end();
  ) {
    const bool lift = liftParticle(*p,verticesEnumerator.getVertexPosition(),verticesEnumerator.getCellSize());
    if (lift) {
      liftedParticles.push_back(*p);
      p=ParticleHeap::getInstance().getData(fineCellIndex).erase(p);
    }
    else {
      p++;
    }
  }

  ParticleHeap::getInstance().sendData(
    liftedParticles,
    tarch::parallel::NodePool::getInstance().getMasterRank(),
    verticesEnumerator.getCellCenter(),
    verticesEnumerator.getLevel(),
    peano::heap::MasterWorkerCommunication
  );

  ParticleHeap::getInstance().finishedToSendSynchronousData();
  ParticleHeap::getInstance().plotStatistics();

  logTraceOut( "prepareSendToMaster(...)" );
}


void particles::pit::mappings::LiftParticles::mergeWithMaster(
  const particles::pit::Cell&               workerGridCell,
  particles::pit::Vertex * const            workerGridVertices,
  const peano::grid::VertexEnumerator&      workerEnumerator,
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
  int                                       worker,
  const particles::pit::State&              workerState,
  particles::pit::State&                    masterState
) {
  logTraceIn( "mergeWithMaster(...)" );

  if (tarch::parallel::Node::getInstance().isGlobalMaster()) {
    ParticleHeap::HeapEntries receivedParticles =
      ParticleHeap::getInstance().receiveData(
        worker,
        fineGridVerticesEnumerator.getCellCenter(),
        fineGridVerticesEnumerator.getLevel(),
        peano::heap::MasterWorkerCommunication
      );

    assertion(receivedParticles.empty());
  }
  else {
    const int cellIndex = coarseGridCell.getCellIndex();

    const int numberOfReceivedParticles =
      ParticleHeap::getInstance().receiveData(
        cellIndex,
        worker,
        fineGridVerticesEnumerator.getCellCenter(),
        fineGridVerticesEnumerator.getLevel(),
        peano::heap::MasterWorkerCommunication
      );

    logInfo( "mergeWithMaster(...)", "received " << numberOfReceivedParticles << " particle(s) from worker " << worker );

    masterState.incNumberOfSendsToMaster( numberOfReceivedParticles );
  }

  masterState.reduceStateStatistics( workerState );

  logTraceOut( "mergeWithMaster(...)" );
}



void particles::pit::mappings::LiftParticles::receiveDataFromMaster(
  particles::pit::Cell&                       receivedCell,
  particles::pit::Vertex *                    receivedVertices,
  const peano::grid::VertexEnumerator&        receivedVerticesEnumerator,
  particles::pit::Vertex * const              receivedCoarseGridVertices,
  const peano::grid::VertexEnumerator&        receivedCoarseGridVerticesEnumerator,
  particles::pit::Cell&                       receivedCoarseGridCell,
  particles::pit::Vertex * const              workersCoarseGridVertices,
  const peano::grid::VertexEnumerator&        workersCoarseGridVerticesEnumerator,
  particles::pit::Cell&                       workersCoarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&    fineGridPositionOfCell
) {
}
#endif



//
// Nop
// ===
//
void particles::pit::mappings::LiftParticles::leaveCell(
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
}


#ifdef Parallel
void particles::pit::mappings::LiftParticles::prepareCopyToRemoteNode(
  particles::pit::Cell&                        localCell,
  int                                          toRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}



void particles::pit::mappings::LiftParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&                        localCell,
  const particles::pit::Cell&                  masterOrWorkerCell,
  int                                          fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}
#endif


void particles::pit::mappings::LiftParticles::destroyCell(
  const particles::pit::Cell&               fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
}


particles::pit::mappings::LiftParticles::~LiftParticles() {
}


void particles::pit::mappings::LiftParticles::enterCell(
  particles::pit::Cell&                 fineGridCell,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}



void particles::pit::mappings::LiftParticles::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pit::mappings::LiftParticles::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::LiftParticles::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::LiftParticles::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::LiftParticles::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::LiftParticles::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


#ifdef Parallel
void particles::pit::mappings::LiftParticles::mergeWithNeighbour(
    particles::pit::Vertex&  vertex,
    const particles::pit::Vertex&  neighbour,
    int                                           fromRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}



void particles::pit::mappings::LiftParticles::prepareSendToNeighbour(
    particles::pit::Vertex&  vertex,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}




void particles::pit::mappings::LiftParticles::prepareCopyToRemoteNode(
    particles::pit::Vertex&  localVertex,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}


void particles::pit::mappings::LiftParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


bool particles::pit::mappings::LiftParticles::prepareSendToWorker(
  particles::pit::Cell&                 fineGridCell,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {
  return true;
}


void particles::pit::mappings::LiftParticles::mergeWithWorker(
    particles::pit::Cell&           localCell,
    const particles::pit::Cell&     receivedMasterCell,
    const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
    const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
    int                                          level
) {
}


void particles::pit::mappings::LiftParticles::mergeWithWorker(
    particles::pit::Vertex&        localVertex,
    const particles::pit::Vertex&  receivedMasterVertex,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}
#endif

void particles::pit::mappings::LiftParticles::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::LiftParticles::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::LiftParticles::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
}
