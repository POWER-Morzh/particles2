#include "particles/pidt/mappings/DropParticles.h"
#include "particles/pidt/mappings/MoveParticles.h"
#include "peano/utils/Loop.h"



peano::MappingSpecification   particles::pidt::mappings::DropParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::DropParticles::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::DropParticles::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::DropParticles::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::DropParticles::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::DropParticles::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidCoarseGridRaces,false);
}


tarch::logging::Log                particles::pidt::mappings::DropParticles::_log( "particles::pidt::mappings::DropParticles" ); 





void particles::pidt::mappings::DropParticles::createHangingVertex(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "createHangingVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

  const int vertexIndex = ParticleHeap::getInstance().createData();

  fineGridVertex.init(vertexIndex);

  logTraceOutWith1Argument( "createHangingVertex(...)", fineGridVertex );
}


void particles::pidt::mappings::DropParticles::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&   fineGridEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&   coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
  logTraceInWith2Arguments( "descend(...)", coarseGridCell.toString(), coarseGridVerticesEnumerator.toString() );

  double maxVComponentOfDroppedParticles = 0.0;

  dfor2(k)
    ParticleHeap::HeapEntries& currentCoarseGridParticles = ParticleHeap::getInstance().getData(
      coarseGridVertices[ coarseGridVerticesEnumerator(k) ].getVertexIndex()
    );

    for (
      ParticleHeap::HeapEntries::iterator p = currentCoarseGridParticles.begin();
      p!=currentCoarseGridParticles.end();
    ) {
      const bool particleIsContainedInCoarseCell = coarseGridVerticesEnumerator.overlaps(
        p->_persistentRecords._x,
        0.0
      );

      if (particleIsContainedInCoarseCell) {
        tarch::la::Vector<DIMENSIONS,int>  destinationVertex = Vertex::getDualCellOfParticleWithinNextFinerLevel(
          coarseGridVerticesEnumerator,
          p->_persistentRecords._x
        );

        logDebug(
          "descend(...)",
          "move particle " << p->toString() <<
          " from coarse vertex " << coarseGridVertices[ coarseGridVerticesEnumerator(k) ].toString() <<
          " at " << k <<
          "/" << coarseGridVerticesEnumerator.getVertexPosition(k) <<
          " into fine grid vertex " << destinationVertex
        );

        const double maxVComponentOfDroppedParticle = tarch::la::maxAbs( p->_persistentRecords._v );
        maxVComponentOfDroppedParticles = maxVComponentOfDroppedParticles > maxVComponentOfDroppedParticle ? maxVComponentOfDroppedParticles : maxVComponentOfDroppedParticle;

        #ifdef Parallel
        assertion3(
          !fineGridVertices[fineGridEnumerator(destinationVertex)].isRemote(
            _state,
            true,
            false
          ),
          fineGridVertices[fineGridEnumerator(destinationVertex)].toString(),
          p->toString(),
          fineGridEnumerator.toString()
        );
        #endif

        const int destinationIndex = fineGridVertices[ fineGridEnumerator(destinationVertex) ].getVertexIndex();
        ParticleHeap::getInstance().getData(destinationIndex).push_back(*p);
        p = currentCoarseGridParticles.erase(p);
      }
      else {
        p++;
      }
    }
  enddforx

  dfor3(l)
    fineGridCells[ fineGridEnumerator.cell(l) ].updateMaxVComponentDueToDrop(maxVComponentOfDroppedParticles);
  enddforx

  logTraceOut( "descend(...)" );
}


#ifdef Parallel
bool particles::pidt::mappings::DropParticles::prepareSendToWorker(
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
  int                                       worker
) {
  logTraceInWith3Arguments( "prepareSendToWorker(...)", fineGridCell.toString(), fineGridVerticesEnumerator.toString(), worker );

  dfor2(k)
    tarch::la::Vector<DIMENSIONS,int> influencingCoarseGridVertex;
    for (int d=0; d<DIMENSIONS; d++) {
      influencingCoarseGridVertex(d) = (fineGridPositionOfCell+k)(d)>1 ? 1 : 0;
    }

    assertion( !coarseGridVertices[coarseGridVerticesEnumerator(influencingCoarseGridVertex)].isRemote(
      _state,
      true,
      false
    ));

    ParticleHeap::HeapEntries  destinationParticles;

    if (!tarch::parallel::Node::getInstance().isGlobalMaster()) {
      destinationParticles = MoveParticles::extractAllParticlesFromDualCellBelongingToOneRank(
        coarseGridVertices[coarseGridVerticesEnumerator(influencingCoarseGridVertex)].getVertexIndex(),
        fineGridVertices[ fineGridVerticesEnumerator(k) ],
        worker,
        fineGridVerticesEnumerator.getVertexPosition(k),
        fineGridVerticesEnumerator.getCellSize()
      );
    }

    for (
      ParticleHeap::HeapEntries::const_iterator p = destinationParticles.begin();
      p != destinationParticles.end();
      p++
    ) {
      fineGridCell.updateMaxVComponentDueToDrop(
        tarch::la::maxAbs( p->_persistentRecords._v )
      );
    }

    ParticleHeap::getInstance().sendData(
      destinationParticles,
      worker,
      fineGridVerticesEnumerator.getVertexPosition(k),
      fineGridVerticesEnumerator.getLevel(),
      peano::heap::MasterWorkerCommunication
    );
  enddforx

  const bool result =
      fineGridCell.cellWillLiftParticleInNextTimeStep(_state.getTimeStepSize(),fineGridVerticesEnumerator.getCellSize())
      ||
      State::AlwaysReduceAlongMasterWorkers;

  fineGridCell.updateMaxVComponentDueToReductionSkip( _state.getTimeStepSize(),fineGridVerticesEnumerator.getCellSize());

  if (!result) {
    logInfo( "prepareSendToWorker(...)", "rank " << tarch::parallel::Node::getInstance().getRank() << " skips reduction from " << worker );
  }

  logTraceOutWith1Argument( "prepareSendToWorker(...)", result );

  return result;
}


void particles::pidt::mappings::DropParticles::receiveDataFromMaster(
  particles::pidt::Cell&                      receivedCell,
  particles::pidt::Vertex *                   receivedVertices,
  const peano::grid::VertexEnumerator&        receivedVerticesEnumerator,
  particles::pidt::Vertex * const             receivedCoarseGridVertices,
  const peano::grid::VertexEnumerator&        receivedCoarseGridVerticesEnumerator,
  particles::pidt::Cell&                      receivedCoarseGridCell,
  particles::pidt::Vertex * const             workersCoarseGridVertices,
  const peano::grid::VertexEnumerator&        workersCoarseGridVerticesEnumerator,
  particles::pidt::Cell&                      workersCoarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&    fineGridPositionOfCell
) {
  logTraceIn( "receiveDataFromMaster(...)" );

  dfor2(k)
    const int temporaryHeapIndex = ParticleHeap::getInstance().createData();

    receivedVertices[receivedCoarseGridVerticesEnumerator(k)].init(temporaryHeapIndex);
    ParticleHeap::getInstance().receiveData(
      temporaryHeapIndex,
      tarch::parallel::NodePool::getInstance().getMasterRank(),
      receivedVerticesEnumerator.getVertexPosition(k),
      receivedVerticesEnumerator.getLevel(),
      peano::heap::MasterWorkerCommunication
    );

    #ifdef Asserts
    for (
      ParticleHeap::HeapEntries::const_iterator p = ParticleHeap::getInstance().getData(temporaryHeapIndex).begin();
      p != ParticleHeap::getInstance().getData(temporaryHeapIndex).end();
      p++
    ) {
      assertion4(
        p->getMovedParticle() == particles::pidt::records::Particle::NotMovedYet,
        p->toString(), receivedVertices[ receivedVerticesEnumerator(k) ].toString(),
        receivedVerticesEnumerator.toString(), k
      );
      assertion4(
        receivedVerticesEnumerator.overlaps(p->_persistentRecords._x,0.0),
        p->toString(), receivedVertices[ receivedVerticesEnumerator(k) ].toString(),
        receivedVerticesEnumerator.toString(), k
      );
    }
    #endif
  enddforx

  logTraceOut( "receiveDataFromMaster(...)" );
}


void particles::pidt::mappings::DropParticles::mergeWithWorker(
  particles::pidt::Vertex&                      localVertex,
  const particles::pidt::Vertex&                receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
  logTraceInWith2Arguments( "mergeWithWorker(...)", localVertex.toString(), receivedMasterVertex.toString() );

  ParticleHeap::getInstance().moveData(
    localVertex.getVertexIndex(),
    receivedMasterVertex.getVertexIndex()
  );

  assertion(
    ParticleHeap::getInstance().getData(receivedMasterVertex.getVertexIndex()).empty()
  );

  ParticleHeap::getInstance().deleteData(receivedMasterVertex.getVertexIndex());

  logTraceOutWith1Argument( "mergeWithWorker(...)", localVertex.toString() );
}
#endif


void particles::pidt::mappings::DropParticles::beginIteration(
  particles::pidt::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  ParticleHeap::getInstance().clearStatistics();
  ParticleHeap::getInstance().startToSendSynchronousData();

  _state = solverState;

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


//
// NOP
//=====
//
particles::pidt::mappings::DropParticles::DropParticles() {
}


particles::pidt::mappings::DropParticles::~DropParticles() {
}


#if defined(SharedMemoryParallelisation)
particles::pidt::mappings::DropParticles::DropParticles(const DropParticles&  masterThread) {
}


void particles::pidt::mappings::DropParticles::mergeWithWorkerThread(const DropParticles& workerThread) {
}
#endif


void particles::pidt::mappings::DropParticles::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::DropParticles::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::DropParticles::destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::DropParticles::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::DropParticles::destroyCell(
      const particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}

#ifdef Parallel
void particles::pidt::mappings::DropParticles::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pidt::mappings::DropParticles::prepareSendToNeighbour(
  particles::pidt::Vertex&  vertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
}


void particles::pidt::mappings::DropParticles::prepareCopyToRemoteNode(
  particles::pidt::Vertex&  localVertex,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
}


void particles::pidt::mappings::DropParticles::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
  int                                           toRank,
  const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
  int                                           level
) {
}


void particles::pidt::mappings::DropParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pidt::mappings::DropParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
}


void particles::pidt::mappings::DropParticles::prepareSendToMaster(
  particles::pidt::Cell&                       localCell,
  particles::pidt::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pidt::mappings::DropParticles::mergeWithMaster(
  const particles::pidt::Cell&           workerGridCell,
  particles::pidt::Vertex * const        workerGridVertices,
 const peano::grid::VertexEnumerator& workerEnumerator,
  particles::pidt::Cell&                 fineGridCell,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker,
  const particles::pidt::State&          workerState,
  particles::pidt::State&                masterState
) {
}


void particles::pidt::mappings::DropParticles::mergeWithWorker(
  particles::pidt::Cell&           localCell, 
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}
#endif


void particles::pidt::mappings::DropParticles::touchVertexFirstTime(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::DropParticles::touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::DropParticles::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::DropParticles::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::DropParticles::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void particles::pidt::mappings::DropParticles::endIteration(
  particles::pidt::State&  solverState
) {
}


void particles::pidt::mappings::DropParticles::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {
}
