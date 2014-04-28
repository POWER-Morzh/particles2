#include "particles/pit/mappings/MoveParticles.h"
#include "tarch/compiler/CompilerSpecificSettings.h"
#include "tarch/multicore/Loop.h"


peano::MappingSpecification   particles::pit::mappings::MoveParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


peano::MappingSpecification   particles::pit::mappings::MoveParticles::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


peano::MappingSpecification   particles::pit::mappings::MoveParticles::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::OnlyLeaves,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


peano::MappingSpecification   particles::pit::mappings::MoveParticles::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}


peano::MappingSpecification   particles::pit::mappings::MoveParticles::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


peano::MappingSpecification   particles::pit::mappings::MoveParticles::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pit::mappings::MoveParticles::_log( "particles::pit::mappings::MoveParticles" ); 


//
// Non-nop operations
// ==================
//
void particles::pit::mappings::MoveParticles::beginIteration(
  particles::pit::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  _state = solverState;
  _state.clearStatistics();

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void particles::pit::mappings::MoveParticles::endIteration(
  particles::pit::State&  solverState
) {
  logTraceInWith1Argument( "endIteration(State)", solverState );

  solverState.reduceStateStatistics( _state );

  logTraceOutWith1Argument( "endIteration(State)", solverState);
}


void particles::pit::mappings::MoveParticles::enterCell(
  particles::pit::Cell&                     fineGridCell,
  particles::pit::Vertex * const            fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pit::Vertex * const            coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pit::Cell&                     coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
) {
  logTraceInWith4Arguments( "enterCell(...)", fineGridCell, fineGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfCell );

  if ( !fineGridCell.isRefined() ) {
    const int cellIndex                    = fineGridCell.getCellIndex();
    const int numberOfParticles            = ParticleHeap::getInstance().getData(cellIndex).size();
    ParticleHeap::HeapEntries& heapEntries = ParticleHeap::getInstance().getData(cellIndex);

    // The 20 here is a heuristic
    pfor(i,0,numberOfParticles,20)
      particles::pit::records::Particle& particle = heapEntries.at(i);
      particle._persistentRecords._x += (_state.getTimeStepSize() * particle._persistentRecords._v);
    endpfor

    _state.updateParticleStatisticsInLeaf(
      numberOfParticles,
      fineGridVerticesEnumerator.getCellSize()
    );
  }

  logTraceOutWith1Argument( "enterCell(...)", fineGridCell );
}


#if defined(SharedMemoryParallelisation)
particles::pit::mappings::MoveParticles::MoveParticles(const MoveParticles&  masterThread):
  _state(masterThread._state) {
  _state.clearStatistics();
}


void particles::pit::mappings::MoveParticles::mergeWithWorkerThread(const MoveParticles& workerThread) {
  _state.reduceStateStatistics(workerThread._state);
}
#endif



//
// Nop
// ===
//
particles::pit::mappings::MoveParticles::MoveParticles() {
}


particles::pit::mappings::MoveParticles::~MoveParticles() {
}



void particles::pit::mappings::MoveParticles::createHangingVertex(
      particles::pit::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pit::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pit::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pit::mappings::MoveParticles::destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::MoveParticles::createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::MoveParticles::createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::MoveParticles::destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::MoveParticles::createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pit::mappings::MoveParticles::destroyCell(
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
void particles::pit::mappings::MoveParticles::mergeWithNeighbour(
  particles::pit::Vertex&  vertex,
  const particles::pit::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}

void particles::pit::mappings::MoveParticles::prepareSendToNeighbour(
    particles::pit::Vertex&  vertex,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}

void particles::pit::mappings::MoveParticles::prepareCopyToRemoteNode(
    particles::pit::Vertex&  localVertex,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}

void particles::pit::mappings::MoveParticles::prepareCopyToRemoteNode(
    particles::pit::Cell&  localCell,
    int                                           toRank,
    const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
    const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
    int                                           level
) {
}

void particles::pit::mappings::MoveParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Vertex&  localVertex,
  const particles::pit::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}

void particles::pit::mappings::MoveParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pit::Cell&  localCell,
  const particles::pit::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}

bool particles::pit::mappings::MoveParticles::prepareSendToWorker(
  particles::pit::Cell&                 fineGridCell,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell,
  int                                                                  worker
) {
  return false;
}

void particles::pit::mappings::MoveParticles::prepareSendToMaster(
    particles::pit::Cell&                       localCell,
    particles::pit::Vertex *                    vertices,
    const peano::grid::VertexEnumerator&       verticesEnumerator,
    const particles::pit::Vertex * const        coarseGridVertices,
    const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
    const particles::pit::Cell&                 coarseGridCell,
    const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
}


void particles::pit::mappings::MoveParticles::mergeWithMaster(
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


void particles::pit::mappings::MoveParticles::receiveDataFromMaster(
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


void particles::pit::mappings::MoveParticles::mergeWithWorker(
    particles::pit::Cell&           localCell,
    const particles::pit::Cell&     receivedMasterCell,
    const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
    const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
    int                                          level
) {
}


void particles::pit::mappings::MoveParticles::mergeWithWorker(
    particles::pit::Vertex&        localVertex,
    const particles::pit::Vertex&  receivedMasterVertex,
    const tarch::la::Vector<DIMENSIONS,double>&   x,
    const tarch::la::Vector<DIMENSIONS,double>&   h,
    int                                           level
) {
}
#endif

void particles::pit::mappings::MoveParticles::touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pit::mappings::MoveParticles::touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
) {
}


void particles::pit::mappings::MoveParticles::leaveCell(
      particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void particles::pit::mappings::MoveParticles::descend(
  particles::pit::Cell * const          fineGridCells,
  particles::pit::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pit::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pit::Cell&                 coarseGridCell
) {
}


void particles::pit::mappings::MoveParticles::ascend(
  particles::pit::Cell * const    fineGridCells,
  particles::pit::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pit::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pit::Cell&           coarseGridCell
) {
}
