#include "particles/pidt/mappings/AdoptGrid.h"
#include "peano/utils/Loop.h"


peano::MappingSpecification   particles::pidt::mappings::AdoptGrid::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::AdoptGrid::touchVertexFirstTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::AdoptGrid::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::AdoptGrid::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::AdoptGrid::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::AdoptGrid::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pidt::mappings::AdoptGrid::_log( "particles::pidt::mappings::AdoptGrid" );



//
// Implemented Events
// ==================
//
void particles::pidt::mappings::AdoptGrid::enterCell(
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "enterCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  if (fineGridCell.isRefined()) {
    fineGridCell.clearNumberOfParticlesInChildren( 0 );
  }
  else {
    int averageParticleNumberNumerator   = 0;
    int averageParticleNumberDenominator = 0;
    dfor2(k)
      if (!fineGridVertices[ fineGridVerticesEnumerator(k) ].isHangingNode()) {
        averageParticleNumberNumerator += ParticleHeap::getInstance().getData(
          fineGridVertices[ fineGridVerticesEnumerator(k) ].getVertexIndex()
        ).size();
        averageParticleNumberDenominator++;
      }
    enddforx

    assertion( averageParticleNumberDenominator>0 );

    fineGridCell.clearNumberOfParticlesInChildren( averageParticleNumberNumerator / averageParticleNumberDenominator );
  }

  logTraceOutWith1Argument( "enterCell(...)", fineGridCell );
}


void particles::pidt::mappings::AdoptGrid::leaveCell(
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "leaveCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  const int numberOfParticlesOfCell = fineGridCell.getNumberOfParticlesInChildren();

  if (
    fineGridCell.isRefined() &&
    numberOfParticlesOfCell<_state.getMinimalNumberOfParticlesPerCell()
  ) {
    dfor2(i)
      if (fineGridVertices[ fineGridVerticesEnumerator(i) ].getRefinementControl()==Vertex::Records::Refined) {
        logDebug(
          "leaveCell(...)",
          "erase " << fineGridVertices[ fineGridVerticesEnumerator(i) ].toString() <<
          " with " << fineGridVerticesEnumerator.toString() <<
          " and " << coarseGridVerticesEnumerator.toString() <<
          " with only " << numberOfParticlesOfCell << " particle(s)"
        );
        fineGridVertices[ fineGridVerticesEnumerator(i) ].incNumberOfEraseTriggers();
      }
    enddforx
  }
  else {
    if (
      numberOfParticlesOfCell>_state.getMinimalNumberOfParticlesPerCell()
    ) {
      dfor2(i)
        if (
          fineGridVertices[ fineGridVerticesEnumerator(i) ].getRefinementControl()==Vertex::Records::Unrefined &&
          !fineGridVertices[ fineGridVerticesEnumerator(i) ].isHangingNode()
        ) {
          fineGridVertices[ fineGridVerticesEnumerator(i) ].refine();
        }
      enddforx
    }
  }

  logTraceOutWith1Argument( "leaveCell(...)", fineGridCell );
}


void particles::pidt::mappings::AdoptGrid::beginIteration(
  particles::pidt::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  _state                      = solverState;

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void particles::pidt::mappings::AdoptGrid::ascend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&   fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&   coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
  logTraceIn( "ascend(...)" );
  dfor3(i)
    coarseGridCell.incNumberOfParticlesInChildren( fineGridCells[ fineGridVerticesEnumerator.cell(i) ] );
  enddforx
  logTraceOut( "ascend(...)" );
}


void particles::pidt::mappings::AdoptGrid::createInnerVertex(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "createInnerVertex(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

  const int vertexIndex = ParticleHeap::getInstance().createData();
  fineGridVertex.init(vertexIndex);

  logTraceOutWith1Argument( "createInnerVertex(...)", fineGridVertex );
}




void particles::pidt::mappings::AdoptGrid::destroyVertex(
  const particles::pidt::Vertex&               fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  // has been moved to LiftParticles. See header documentation.
}



#if defined(SharedMemoryParallelisation)
particles::pidt::mappings::AdoptGrid::AdoptGrid(const AdoptGrid&  masterThread):
  _state(masterThread._state) {
}
#endif




void particles::pidt::mappings::AdoptGrid::touchVertexFirstTime(
  particles::pidt::Vertex&                      fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  particles::pidt::Vertex * const               coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&                        coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&      fineGridPositionOfVertex
) {
  logTraceIn( "touchVertexFirstTime(...)" );
  fineGridVertex.clearNumberOfEraseTiggers();
  logTraceOut( "touchVertexFirstTime(...)" );
}


void particles::pidt::mappings::AdoptGrid::touchVertexLastTime(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  logTraceIn( "touchVertexLastTime(...)" );

  fineGridVertex.eraseIfAllAdjacentCellsWoldTriggeredErase();

  logTraceOut( "touchVertexLastTime(...)" );
}


#ifdef Parallel
void particles::pidt::mappings::AdoptGrid::mergeWithMaster(
  const particles::pidt::Cell&                      workerGridCell,
  particles::pidt::Vertex * const                   workerGridVertices,
  const peano::grid::VertexEnumerator&              workerEnumerator,
  particles::pidt::Cell&                            fineGridCell,
  particles::pidt::Vertex * const                   fineGridVertices,
  const peano::grid::VertexEnumerator&              fineGridVerticesEnumerator,
  particles::pidt::Vertex * const                   coarseGridVertices,
  const peano::grid::VertexEnumerator&              coarseGridVerticesEnumerator,
  particles::pidt::Cell&                            coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&          fineGridPositionOfCell,
  int                                               worker,
  const particles::pidt::State&                     workerState,
  particles::pidt::State&                           masterState
) {
  logTraceIn( "mergeWithMaster(...)" );

  fineGridCell.clearNumberOfParticlesInChildren(
    workerGridCell.getNumberOfParticlesInChildren()
  );

  logTraceOut( "mergeWithMaster(...)" );
}


bool particles::pidt::mappings::AdoptGrid::prepareSendToWorker(
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
  int                                       worker
) {
  logTraceIn( "prepareSendToWorker(...)" );

  if ( fineGridCell.cellWillLiftParticleInNextTimeStep(
    _state.getTimeStepSize(),
    fineGridVerticesEnumerator.getCellSize()
  )) {
    fineGridCell.clearNumberOfParticlesInChildren(0);
  }
  else {
    fineGridCell.clearNumberOfParticlesInChildren(_state.getMinimalNumberOfParticlesPerCell());
  }

  logTraceOut( "prepareSendToWorker(...)" );

  return false;
}


void particles::pidt::mappings::AdoptGrid::prepareSendToMaster(
  particles::pidt::Cell&                     localCell,
  particles::pidt::Vertex *                  vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator,
  const particles::pidt::Vertex * const      coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pidt::Cell&               coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
  logTraceIn( "prepareSendToMaster(...)" );

  assertion2(localCell.getNumberOfParticlesInChildren()>=0, localCell.toString(), coarseGridCell.toString() );

  logTraceOut( "prepareSendToMaster(...)" );
}
#endif




void particles::pidt::mappings::AdoptGrid::createBoundaryVertex(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  const int vertexIndex = ParticleHeap::getInstance().createData();
  fineGridVertex.init(vertexIndex);
}


//
// Nop
// ===
//
particles::pidt::mappings::AdoptGrid::AdoptGrid() {
}


particles::pidt::mappings::AdoptGrid::~AdoptGrid() {
}


#if defined(SharedMemoryParallelisation)
void particles::pidt::mappings::AdoptGrid::mergeWithWorkerThread(const AdoptGrid& workerThread) {
}
#endif


void particles::pidt::mappings::AdoptGrid::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::AdoptGrid::destroyHangingVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::AdoptGrid::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::AdoptGrid::destroyCell(
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
void particles::pidt::mappings::AdoptGrid::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}

void particles::pidt::mappings::AdoptGrid::prepareSendToNeighbour(
  particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}

void particles::pidt::mappings::AdoptGrid::prepareCopyToRemoteNode(
  particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}

void particles::pidt::mappings::AdoptGrid::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}

void particles::pidt::mappings::AdoptGrid::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}

void particles::pidt::mappings::AdoptGrid::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
}


void particles::pidt::mappings::AdoptGrid::receiveDataFromMaster(
      particles::pidt::Cell&                        receivedCell, 
      particles::pidt::Vertex *                     receivedVertices,
      const peano::grid::VertexEnumerator&        receivedVerticesEnumerator,
      particles::pidt::Vertex * const               receivedCoarseGridVertices,
      const peano::grid::VertexEnumerator&        receivedCoarseGridVerticesEnumerator,
      particles::pidt::Cell&                        receivedCoarseGridCell,
      particles::pidt::Vertex * const               workersCoarseGridVertices,
      const peano::grid::VertexEnumerator&        workersCoarseGridVerticesEnumerator,
      particles::pidt::Cell&                        workersCoarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&    fineGridPositionOfCell
) {
}


void particles::pidt::mappings::AdoptGrid::mergeWithWorker(
  particles::pidt::Cell&           localCell, 
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}


void particles::pidt::mappings::AdoptGrid::mergeWithWorker(
  particles::pidt::Vertex&        localVertex,
  const particles::pidt::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
}
#endif


void particles::pidt::mappings::AdoptGrid::endIteration(
  particles::pidt::State&  solverState
) {
}



void particles::pidt::mappings::AdoptGrid::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
}
