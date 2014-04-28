#include "particles/pit/mappings/InitGrid.h"
#include "tarch/multicore/MulticoreDefinitions.h"
#include "tarch/parallel/Node.h"


peano::MappingSpecification   particles::pit::mappings::InitGrid::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::OnlyLeaves,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}

#ifdef Parallel
peano::MappingSpecification   particles::pit::mappings::InitGrid::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::OnlyLeaves,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
#else
peano::MappingSpecification   particles::pit::mappings::InitGrid::touchVertexFirstTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
#endif

peano::MappingSpecification   particles::pit::mappings::InitGrid::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pit::mappings::InitGrid::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pit::mappings::InitGrid::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pit::mappings::InitGrid::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log  particles::pit::mappings::InitGrid::_log( "particles::pit::mappings::InitGrid" );

bool                 particles::pit::mappings::InitGrid::_haveWrittenWarnings( false );


bool particles::pit::mappings::InitGrid::refineVertex(
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH
) const {
  const bool refineDueToParticles =
    getNumberOfParticles(fineGridH,_state.getMaximalNumberOfInitialParticlesPerUnitVolume())>_state.getMinimalNumberOfParticlesPerCell() &&
    controlPointIsInsideParticleDomain(fineGridX,_state.getBreakingDamWidth());

  const bool refineDueToMeshWidth =
    fineGridH(0)>=1.0/3.0;

  return refineDueToParticles || refineDueToMeshWidth;
}


void particles::pit::mappings::InitGrid::createInnerVertex(
  particles::pit::Vertex&                      fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pit::Vertex * const               coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pit::Cell&                        coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  #if !definedParallel
  if ( refineVertex(fineGridX,fineGridH)) {
    fineGridVertex.refine();
  }
  #endif
}


void particles::pit::mappings::InitGrid::touchVertexLastTime(
  particles::pit::Vertex&         fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
  #ifdef Parallel
  if (
    fineGridVertex.getRefinementControl()==Vertex::Records::Unrefined &&
    refineVertex(fineGridX,fineGridH)
  ) {
    fineGridVertex.refine();
  }
  #endif
}


void particles::pit::mappings::InitGrid::createBoundaryVertex(
  particles::pit::Vertex&                      fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pit::Vertex * const               coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pit::Cell&                        coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  bool refineDueToParticles =
    getNumberOfParticles(fineGridH,_state.getMaximalNumberOfInitialParticlesPerUnitVolume())>_state.getMinimalNumberOfParticlesPerCell() &&
    controlPointIsInsideParticleDomain(fineGridX, _state.getBreakingDamWidth());

  bool refineDueToMeshWidth =
    fineGridH(0)>=1.0/3.0;

  if (
    tarch::la::oneGreaterEquals(fineGridH,1.0/3.0) ||
    refineDueToParticles ||
    refineDueToMeshWidth
  ) {
    fineGridVertex.refine();
  }
}


void particles::pit::mappings::InitGrid::beginIteration(
  particles::pit::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  _state                  = solverState;

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}



#if defined(SharedMemoryParallelisation)
particles::pit::mappings::InitGrid::InitGrid(const InitGrid&  masterThread):
  _state( masterThread._state ) {
}


void particles::pit::mappings::InitGrid::mergeWithWorkerThread(const InitGrid& workerThread) {
}
#endif



void particles::pit::mappings::InitGrid::createCell(
  particles::pit::Cell&                 fineGridCell,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&  coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "createCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  #ifdef Parallel
  if (controlPointIsInsideParticleDomain(fineGridVerticesEnumerator.getCellCenter(), _state.getBreakingDamWidth())) {
    fineGridCell.setNodeWorkload(1.0);
  }
  else {
    fineGridCell.setNodeWorkload(0.0);
  }
  #endif

  logTraceOutWith1Argument( "createCell(...)", fineGridCell );
}



#ifdef Parallel
bool particles::pit::mappings::InitGrid::prepareSendToWorker(
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
#endif

//
// NOP
// ===
//
particles::pit::mappings::InitGrid::InitGrid() {
}


particles::pit::mappings::InitGrid::~InitGrid() {
}


void particles::pit::mappings::InitGrid::touchVertexFirstTime(
  particles::pit::Vertex&                      fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pit::Vertex * const               coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pit::Cell&                        coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
}


void particles::pit::mappings::InitGrid::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pit::mappings::InitGrid::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::InitGrid::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::InitGrid::destroyCell(
      const particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


#ifdef Parallel
void particles::pit::mappings::InitGrid::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pit::mappings::InitGrid::prepareSendToNeighbour(
  particles::pit::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pit::mappings::InitGrid::prepareCopyToRemoteNode(
  particles::pit::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pit::mappings::InitGrid::prepareCopyToRemoteNode(
  particles::pit::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}


void particles::pit::mappings::InitGrid::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pit::mappings::InitGrid::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
}


void particles::pit::mappings::InitGrid::prepareSendToMaster(
  particles::pit::Cell&                       localCell,
  particles::pit::Vertex *                    vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator, 
  const particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pit::mappings::InitGrid::mergeWithMaster(
  const particles::pit::Cell&           workerGridCell,
  particles::pit::Vertex * const        workerGridVertices,
 const peano::grid::VertexEnumerator& workerEnumerator,
  particles::pit::Cell&                 fineGridCell,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker,
  const particles::pit::State&          workerState,
  particles::pit::State&                masterState
) {
}


void particles::pit::mappings::InitGrid::receiveDataFromMaster(
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


void particles::pit::mappings::InitGrid::mergeWithWorker(
  particles::pit::Cell&           localCell, 
  const particles::pit::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}


void particles::pit::mappings::InitGrid::mergeWithWorker(
  particles::pit::Vertex&        localVertex,
  const particles::pit::Vertex&  receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
}
#endif


void particles::pit::mappings::InitGrid::enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pit::mappings::InitGrid::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void particles::pit::mappings::InitGrid::endIteration(
  particles::pit::State&  solverState
) {
}



void particles::pit::mappings::InitGrid::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
}


void particles::pit::mappings::InitGrid::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {
}
