#include "particles/pit/mappings/AdoptGrid.h"
#include "peano/utils/Loop.h"


peano::MappingSpecification   particles::pit::mappings::AdoptGrid::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pit::mappings::AdoptGrid::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pit::mappings::AdoptGrid::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pit::mappings::AdoptGrid::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pit::mappings::AdoptGrid::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pit::mappings::AdoptGrid::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pit::mappings::AdoptGrid::_log( "particles::pit::mappings::AdoptGrid" ); 


//
// Implemented Events
// ==================
//
void particles::pit::mappings::AdoptGrid::enterCell(
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "enterCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  fineGridCell.clearNumberOfParticlesInChildren(
    fineGridCell.isRefined() ? 0 :
    ParticleHeap::getInstance().getData( fineGridCell.getCellIndex() ).size()
  );

  logTraceOutWith1Argument( "enterCell(...)", fineGridCell );
}


void particles::pit::mappings::AdoptGrid::leaveCell(
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
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
    if (numberOfParticlesOfCell>_state.getMinimalNumberOfParticlesPerCell()) {
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


void particles::pit::mappings::AdoptGrid::beginIteration(
  particles::pit::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  _state = solverState;

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void particles::pit::mappings::AdoptGrid::ascend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&  coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
  logTraceIn( "ascend(...)" );
  dfor3(i)
    coarseGridCell.incNumberOfParticlesInChildren( fineGridCells[ fineGridVerticesEnumerator.cell(i) ] );
  enddforx
  logTraceOut( "ascend(...)" );
}


void particles::pit::mappings::AdoptGrid::createCell(
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "createCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  const int cellIndex = ParticleHeap::getInstance().createData();
  fineGridCell.init(cellIndex);

  logTraceOutWith1Argument( "createCell(...)", fineGridCell );
}


void particles::pit::mappings::AdoptGrid::destroyCell(
  const particles::pit::Cell&               fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "destroyCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  const int fineCellNumber   = fineGridCell.getCellIndex();
  const int coarseCellNumber = coarseGridCell.getCellIndex();

  #ifdef Debug
  const int NumberOfMovedParticles = ParticleHeap::getInstance().getData(fineCellNumber).size();
  if (NumberOfMovedParticles>0) {
    logDebug( "destroyCell(...)", "moved " << NumberOfMovedParticles << " particle(s) " );
  }
  #endif

  ParticleHeap::getInstance().moveData(coarseCellNumber,fineCellNumber);
  ParticleHeap::getInstance().deleteData(fineCellNumber);

  logTraceOutWith1Argument( "destroyCell(...)", fineGridCell );
}


particles::pit::mappings::AdoptGrid::AdoptGrid() {
}


#if defined(SharedMemoryParallelisation)
particles::pit::mappings::AdoptGrid::AdoptGrid(const AdoptGrid&  masterThread):
  _state(masterThread._state) {
}
#endif




void particles::pit::mappings::AdoptGrid::touchVertexFirstTime(
  particles::pit::Vertex&                       fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  particles::pit::Vertex * const                coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&                         coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&      fineGridPositionOfVertex
) {
  logTraceIn( "touchVertexFirstTime(...)" );
  fineGridVertex.clearNumberOfEraseTiggers();
  logTraceOut( "touchVertexFirstTime(...)" );
}


void particles::pit::mappings::AdoptGrid::touchVertexLastTime(
  particles::pit::Vertex&                      fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pit::Vertex * const               coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pit::Cell&                        coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  logTraceIn( "touchVertexLastTime(...)" );

  fineGridVertex.eraseIfAllAdjacentCellsWoldTriggeredErase();

  logTraceOut( "touchVertexLastTime(...)" );
}


#ifdef Parallel
void particles::pit::mappings::AdoptGrid::mergeWithMaster(
  const particles::pit::Cell&                       workerGridCell,
  particles::pit::Vertex * const                    workerGridVertices,
  const peano::grid::VertexEnumerator&              workerEnumerator,
  particles::pit::Cell&                             fineGridCell,
  particles::pit::Vertex * const                    fineGridVertices,
  const peano::grid::VertexEnumerator&              fineGridVerticesEnumerator,
  particles::pit::Vertex * const                    coarseGridVertices,
  const peano::grid::VertexEnumerator&              coarseGridVerticesEnumerator,
  particles::pit::Cell&                             coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&          fineGridPositionOfCell,
  int                                               worker,
  const particles::pit::State&                      workerState,
  particles::pit::State&                            masterState
) {
  logTraceIn( "mergeWithMaster(...)" );

  fineGridCell.clearNumberOfParticlesInChildren(
    workerGridCell.getNumberOfParticlesInChildren()
  );

  logTraceOut( "mergeWithMaster(...)" );
}


bool particles::pit::mappings::AdoptGrid::prepareSendToWorker(
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
  int                                       worker
) {
  logTraceIn( "prepareSendToWorker(...)" );

  fineGridCell.clearNumberOfParticlesInChildren(0);

  logTraceOut( "prepareSendToWorker(...)" );

  return true;
}


void particles::pit::mappings::AdoptGrid::prepareSendToMaster(
  particles::pit::Cell&                      localCell,
  particles::pit::Vertex *                   vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator,
  const particles::pit::Vertex * const       coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pit::Cell&                coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
  logTraceIn( "prepareSendToMaster(...)" );

  assertion2(localCell.getNumberOfParticlesInChildren()>=0, localCell.toString(), coarseGridCell.toString() );

  logTraceOut( "prepareSendToMaster(...)" );
}
#endif


//
// Nop
// ===
//
particles::pit::mappings::AdoptGrid::~AdoptGrid() {
}


#if defined(SharedMemoryParallelisation)
void particles::pit::mappings::AdoptGrid::mergeWithWorkerThread(const AdoptGrid& workerThread) {
}
#endif


void particles::pit::mappings::AdoptGrid::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pit::mappings::AdoptGrid::destroyHangingVertex(
  const particles::pit::Vertex&                fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pit::Vertex * const               coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pit::Cell&                        coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
}


void particles::pit::mappings::AdoptGrid::createInnerVertex(
  particles::pit::Vertex&                      fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pit::Vertex * const               coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pit::Cell&                        coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
}


void particles::pit::mappings::AdoptGrid::createBoundaryVertex(
  particles::pit::Vertex&                       fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  particles::pit::Vertex * const                coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&                         coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&      fineGridPositionOfVertex
) {
}


void particles::pit::mappings::AdoptGrid::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


#ifdef Parallel
void particles::pit::mappings::AdoptGrid::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pit::mappings::AdoptGrid::prepareSendToNeighbour(
    particles::pit::Vertex&  vertex,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}


void particles::pit::mappings::AdoptGrid::prepareCopyToRemoteNode(
    particles::pit::Vertex&                       localVertex,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}


void particles::pit::mappings::AdoptGrid::prepareCopyToRemoteNode(
    particles::pit::Cell&  localCell,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
    const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
    int                                           level
) {
}


void particles::pit::mappings::AdoptGrid::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pit::mappings::AdoptGrid::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pit::mappings::AdoptGrid::receiveDataFromMaster(
    particles::pit::Cell&                        receivedCell,
    particles::pit::Vertex *                     receivedVertices,
    const peano::grid::VertexEnumerator&        receivedVerticesEnumerator,
    particles::pit::Vertex * const               receivedCoarseGridVertices,
    const peano::grid::VertexEnumerator&        receivedCoarseGridVerticesEnumerator,
    particles::pit::Cell&                        receivedCoarseGridCell,
    particles::pit::Vertex * const               workersCoarseGridVertices,
    const peano::grid::VertexEnumerator&        workersCoarseGridVerticesEnumerator,
    particles::pit::Cell&                        workersCoarseGridCell,
    const tarch::la::Vector<DIMENSIONS,int>&    fineGridPositionOfCell
) {
}


void particles::pit::mappings::AdoptGrid::mergeWithWorker(
    particles::pit::Cell&           localCell,
    const particles::pit::Cell&     receivedMasterCell,
    const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
    const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
    int                                          level
) {
}


void particles::pit::mappings::AdoptGrid::mergeWithWorker(
    particles::pit::Vertex&        localVertex,
    const particles::pit::Vertex&  receivedMasterVertex,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}
#endif



void particles::pit::mappings::AdoptGrid::endIteration(
  particles::pit::State&  solverState
) {
}



void particles::pit::mappings::AdoptGrid::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
}

