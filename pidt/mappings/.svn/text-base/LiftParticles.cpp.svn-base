#include "particles/pidt/mappings/LiftParticles.h"
#include "particles/pidt/records/Particle.h"
#include "peano/utils/Loop.h"
#include "tarch/multicore/Lock.h"




#ifdef LIFT_PARTICLE_USES_SEMAPHORE
tarch::multicore::BooleanSemaphore  particles::pidt::mappings::LiftParticles::_semaphore;

peano::MappingSpecification   particles::pidt::mappings::LiftParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
#else
peano::MappingSpecification   particles::pidt::mappings::LiftParticles::touchVertexLastTimeSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::WholeTree,peano::MappingSpecification::AvoidCoarseGridRaces,false);
}
#endif


peano::MappingSpecification   particles::pidt::mappings::LiftParticles::touchVertexFirstTimeSpecification() { 
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::LiftParticles::enterCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::LiftParticles::leaveCellSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::AvoidFineGridRaces,false);
}
peano::MappingSpecification   particles::pidt::mappings::LiftParticles::ascendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}
peano::MappingSpecification   particles::pidt::mappings::LiftParticles::descendSpecification() {
  return peano::MappingSpecification(peano::MappingSpecification::Nop,peano::MappingSpecification::RunConcurrentlyOnFineGrid,false);
}


tarch::logging::Log                particles::pidt::mappings::LiftParticles::_log( "particles::pidt::mappings::LiftParticles" ); 



void particles::pidt::mappings::LiftParticles::liftParticles(
  particles::pidt::ParticleHeap::HeapEntries&  particles,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  logTraceInWith3Arguments( "liftParticles(...)", particles.size(), coarseGridVerticesEnumerator.toString(), fineGridPositionOfVertex );

  if (!particles.empty()) {
    tarch::la::Vector<DIMENSIONS,int> coarseGridVertex;
    for (int d=0; d<DIMENSIONS; d++) {
      coarseGridVertex(d) = fineGridPositionOfVertex(d)>1 ? 1 : 0;
    }

    logDebug(
      "liftParticles(...)",
      "move all particles to parent vertex " << coarseGridVertex <<
      ", i.e. vertex " << coarseGridVertices[ coarseGridVerticesEnumerator(coarseGridVertex) ].toString() <<
      ". first particles=" << particles.front().toString()
    );

    _state.incNumberOfLifts( coarseGridVerticesEnumerator.getLevel()+1, particles.size() );

    const int coarseGridVertexIndex = coarseGridVertices[ coarseGridVerticesEnumerator(coarseGridVertex) ].getVertexIndex();

    ParticleHeap::getInstance().addData( coarseGridVertexIndex, particles );
  }

  logTraceOut( "liftParticles(...)" );
}



void particles::pidt::mappings::LiftParticles::touchVertexLastTime(
  particles::pidt::Vertex&                     fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  logTraceInWith6Arguments( "touchVertexLastTime(...)", fineGridVertex, fineGridX, fineGridH, coarseGridVerticesEnumerator.toString(), coarseGridCell, fineGridPositionOfVertex );

  if (!coarseGridCell.isRoot() && fineGridVertex.wereParticlesAddedToThisVertex() ) {
    ParticleContainer& sourceVertexParticles = ParticleHeap::getInstance().getData(fineGridVertex.getVertexIndex());

    for (
      ParticleContainer::iterator p = sourceVertexParticles.begin();
      p!=sourceVertexParticles.end();
    ) {
      if (Vertex::isContainedInDualCell(fineGridX,fineGridH,p->_persistentRecords._x)) {
        p++;
      }
      else {
        const tarch::la::Vector<DIMENSIONS,int> newDualCellOfParticle = Vertex::getDualCellOfParticle(
          coarseGridVerticesEnumerator,
          p->_persistentRecords._x
        );

        #ifdef Parallel
        const bool coarseDestinationCellIsLocal = !coarseGridVertices[ coarseGridVerticesEnumerator(newDualCellOfParticle) ].isRemote(_state,true,false);
        #else
        const bool coarseDestinationCellIsLocal = true;
        #endif

        if (coarseDestinationCellIsLocal) {
          logDebug(
            "touchVertexLastTime(...)",
            "lift of particle " << p->toString() << " to coarse grid vertex " << newDualCellOfParticle <<
            " from fine grid patch position " << fineGridPositionOfVertex <<
            "; vertex=" << coarseGridVertices[ coarseGridVerticesEnumerator(newDualCellOfParticle) ].toString()
          );

          const int destinationIndex = coarseGridVertices[ coarseGridVerticesEnumerator(newDualCellOfParticle) ].getVertexIndex();
          coarseGridVertices[ coarseGridVerticesEnumerator(newDualCellOfParticle) ].particlesWereAddedToThisVertex();

          #ifdef LIFT_PARTICLE_USES_SEMAPHORE
          tarch::multicore::Lock lock(_semaphore);

          ParticleHeap::getInstance().getData(destinationIndex).push_back(*p);
          #else
          ParticleHeap::getInstance().getData(destinationIndex).push_back(*p);
          #endif
          p = sourceVertexParticles.erase(p);
          _state.incNumberOfLifts( coarseGridVerticesEnumerator.getLevel()+1 );
        }
        else {
          const tarch::la::Vector<DIMENSIONS,int> localDualCellOfParticle = Vertex::getDualCellOfParticle(
            coarseGridVerticesEnumerator,
            fineGridX
          );

          logDebug(
            "touchVertexLastTime(...)",
            "skip lift of particle " << p->toString() << " to coarse grid vertex " << newDualCellOfParticle <<
            " at fine grid patch position " << fineGridPositionOfVertex <<
            " from coarse grid dual cell is remote; lift locally instead into vertex at " << localDualCellOfParticle <<
            "; vertex=" << coarseGridVertices[ coarseGridVerticesEnumerator(localDualCellOfParticle) ].toString()
          );

          #ifdef Parallel
          assertion4(
            !coarseGridVertices[ coarseGridVerticesEnumerator(localDualCellOfParticle) ].isRemote(_state,true,false),
            coarseGridVertices[ coarseGridVerticesEnumerator(localDualCellOfParticle) ].toString(),
            fineGridX,
            p->toString(),
            localDualCellOfParticle
          );
          #endif

          const int destinationIndex = coarseGridVertices[ coarseGridVerticesEnumerator(localDualCellOfParticle) ].getVertexIndex();
          coarseGridVertices[ coarseGridVerticesEnumerator(newDualCellOfParticle) ].particlesWereAddedToThisVertex();

          #ifdef LIFT_PARTICLE_USES_SEMAPHORE
          tarch::multicore::Lock lock(_semaphore);
          ParticleHeap::getInstance().getData(destinationIndex).push_back(*p);
          #else
          ParticleHeap::getInstance().getData(destinationIndex).push_back(*p);
          #endif
          p = sourceVertexParticles.erase(p);
          _state.incNumberOfLifts( coarseGridVerticesEnumerator.getLevel()+1 );
        }
      }
    }
  }

  logTraceOutWith1Argument( "touchVertexLastTime(...)", fineGridVertex );
}


void particles::pidt::mappings::LiftParticles::beginIteration(
  particles::pidt::State&  solverState
) {
  logTraceInWith1Argument( "beginIteration(State)", solverState );

  #ifdef Parallel
  _clearStateAfterIteration = solverState.reduceDataToMaster() || tarch::parallel::Node::getInstance().isGlobalMaster();
  #else
  _clearStateAfterIteration = true;
  #endif

  _state.copyTimeStepSize( solverState );

  logTraceOutWith1Argument( "beginIteration(State)", solverState);
}


void particles::pidt::mappings::LiftParticles::endIteration(
  particles::pidt::State&  solverState
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


#if defined(SharedMemoryParallelisation)
particles::pidt::mappings::LiftParticles::LiftParticles(const LiftParticles&  masterThread):
  _state(masterThread._state),
  _clearStateAfterIteration(masterThread._clearStateAfterIteration) {
  logTraceIn( "LiftParticles(LiftParticles)" );

  _state.clearStatistics();

  logTraceOut( "LiftParticles(LiftParticles)" );
}


void particles::pidt::mappings::LiftParticles::mergeWithWorkerThread(const LiftParticles& workerThread) {
  logTraceIn( "mergeWithWorkerThread(LiftParticles)" );

  _state.reduceStateStatistics( workerThread._state );

  logTraceOut( "mergeWithWorkerThread(LiftParticles)" );
}
#endif


void particles::pidt::mappings::LiftParticles::destroyHangingVertex(
  const particles::pidt::Vertex&               fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  liftParticles(
    ParticleHeap::getInstance().getData(fineGridVertex.getVertexIndex()),
    coarseGridVertices,
    coarseGridVerticesEnumerator,
    fineGridPositionOfVertex
  );
  ParticleHeap::getInstance().deleteData(fineGridVertex.getVertexIndex());
}


void particles::pidt::mappings::LiftParticles::destroyVertex(
  const particles::pidt::Vertex&               fineGridVertex,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
  particles::pidt::Vertex * const              coarseGridVertices,
  const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
  particles::pidt::Cell&                       coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
) {
  liftParticles(
    ParticleHeap::getInstance().getData(fineGridVertex.getVertexIndex()),
    coarseGridVertices,
    coarseGridVerticesEnumerator,
    fineGridPositionOfVertex
  );
  // @todo Has been a clear before. Shoulds be a clear but a delete.
  ParticleHeap::getInstance().deleteData(fineGridVertex.getVertexIndex());
}


#ifdef Parallel
void particles::pidt::mappings::LiftParticles::prepareSendToMaster(
  particles::pidt::Cell&                     localCell,
  particles::pidt::Vertex *                  vertices,
  const peano::grid::VertexEnumerator&       verticesEnumerator,
  const particles::pidt::Vertex * const      coarseGridVertices,
  const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
  const particles::pidt::Cell&               coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
) {
  logTraceIn( "prepareSendToMaster(...)" );

  dfor2(k)
    ParticleHeap::HeapEntries particlesLiftedToMaster;
    ParticleContainer&        sourceVertexParticles = ParticleHeap::getInstance().getData(
      vertices[ verticesEnumerator(k) ].getVertexIndex()
    );

    for (
      ParticleContainer::iterator p = sourceVertexParticles.begin();
      p!=sourceVertexParticles.end();
    ) {
      if (Vertex::isContainedInDualCell(
        verticesEnumerator.getVertexPosition(k),
        verticesEnumerator.getCellSize(),
        p->_persistentRecords._x)
      ) {
        p++;
      }
      else {
        particlesLiftedToMaster.push_back(*p);
        p = sourceVertexParticles.erase(p);
      }
    }
    ParticleHeap::getInstance().sendData(
      particlesLiftedToMaster,
      tarch::parallel::NodePool::getInstance().getMasterRank(),
      verticesEnumerator.getVertexPosition(k),
      verticesEnumerator.getLevel(),
      peano::heap::MasterWorkerCommunication
    );
  enddforx

  ParticleHeap::getInstance().finishedToSendSynchronousData();

  logTraceOut( "prepareSendToMaster(...)" );
}


void particles::pidt::mappings::LiftParticles::mergeWithMaster(
  const particles::pidt::Cell&              workerGridCell,
  particles::pidt::Vertex * const           workerGridVertices,
  const peano::grid::VertexEnumerator&      workerEnumerator,
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
  int                                       worker,
  const particles::pidt::State&             workerState,
  particles::pidt::State&                   masterState
) {
  logTraceInWith2Arguments( "mergeWithMaster(...)", worker, workerEnumerator.toString() );

  int totalNumberOfParticles = 0;
  dfor2(k)
    logDebug( "mergeWithMaster(...)", "study vertex " << k );

    ParticleHeap::HeapEntries receivedParticles =
      ParticleHeap::getInstance().receiveData(
        worker,
        fineGridVerticesEnumerator.getVertexPosition(k),
        fineGridVerticesEnumerator.getLevel(),
        peano::heap::MasterWorkerCommunication
      );

    totalNumberOfParticles += static_cast<int>( receivedParticles.size() );

    assertion(
      !tarch::parallel::Node::getInstance().isGlobalMaster()
      ||
      receivedParticles.empty()
    );

    assertion(
      fineGridCell.cellWillLiftParticleInNextTimeStep(_state.getTimeStepSize(),fineGridVerticesEnumerator.getCellSize())
      ||
      receivedParticles.empty()
    );

    liftParticles(receivedParticles,coarseGridVertices,coarseGridVerticesEnumerator,fineGridPositionOfCell+k);
  enddforx

  if (totalNumberOfParticles>0) {
    logInfo( "mergeWithMaster(...)", "received " << totalNumberOfParticles << " particle(s) from worker " << worker );
    masterState.incNumberOfSendsToMaster( totalNumberOfParticles );
  }
  // We may not reduce twice and MoveParticles already does the merge, so
  // we skip it here.
  // masterState.reduceStateStatistics(workerState);

  logTraceOut( "mergeWithMaster(...)" );
}
#endif


//
// NOP
//=====
//
particles::pidt::mappings::LiftParticles::LiftParticles():
  _clearStateAfterIteration(false) {
  _state.clearStatistics();
}


particles::pidt::mappings::LiftParticles::~LiftParticles() {
}


void particles::pidt::mappings::LiftParticles::createHangingVertex(
      particles::pidt::Vertex&     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                fineGridH,
      particles::pidt::Vertex * const   coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                   fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::LiftParticles::createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::LiftParticles::createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::LiftParticles::createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::LiftParticles::destroyCell(
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
bool particles::pidt::mappings::LiftParticles::prepareSendToWorker(
  particles::pidt::Cell&                    fineGridCell,
  particles::pidt::Vertex * const           fineGridVertices,
  const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
  particles::pidt::Vertex * const           coarseGridVertices,
  const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
  particles::pidt::Cell&                    coarseGridCell,
  const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell,
  int                                       worker
) {
  return false;
}


void particles::pidt::mappings::LiftParticles::mergeWithNeighbour(
  particles::pidt::Vertex&  vertex,
  const particles::pidt::Vertex&  neighbour,
  int                                           fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridX,
  const tarch::la::Vector<DIMENSIONS,double>&   fineGridH,
  int                                           level
) {
}


void particles::pidt::mappings::LiftParticles::prepareSendToNeighbour(
  particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pidt::mappings::LiftParticles::prepareCopyToRemoteNode(
  particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
) {
}


void particles::pidt::mappings::LiftParticles::prepareCopyToRemoteNode(
  particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
) {
}


void particles::pidt::mappings::LiftParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Vertex&  localVertex,
  const particles::pidt::Vertex&  masterOrWorkerVertex,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  int                                       level
) {
}


void particles::pidt::mappings::LiftParticles::mergeWithRemoteDataDueToForkOrJoin(
  particles::pidt::Cell&  localCell,
  const particles::pidt::Cell&  masterOrWorkerCell,
  int                                       fromRank,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                       level
) {
}


void particles::pidt::mappings::LiftParticles::receiveDataFromMaster(
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


void particles::pidt::mappings::LiftParticles::mergeWithWorker(
  particles::pidt::Cell&           localCell,
  const particles::pidt::Cell&     receivedMasterCell,
  const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
  const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
  int                                          level
) {
}


void particles::pidt::mappings::LiftParticles::mergeWithWorker(
  particles::pidt::Vertex&                      localVertex,
  const particles::pidt::Vertex&                receivedMasterVertex,
  const tarch::la::Vector<DIMENSIONS,double>&   x,
  const tarch::la::Vector<DIMENSIONS,double>&   h,
  int                                           level
) {
}
#endif


void particles::pidt::mappings::LiftParticles::touchVertexFirstTime(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
) {
}


void particles::pidt::mappings::LiftParticles::enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
) {
}


void particles::pidt::mappings::LiftParticles::leaveCell(
      particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfCell
) {
}


void particles::pidt::mappings::LiftParticles::descend(
  particles::pidt::Cell * const          fineGridCells,
  particles::pidt::Vertex * const        fineGridVertices,
  const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
  particles::pidt::Vertex * const        coarseGridVertices,
  const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
  particles::pidt::Cell&                 coarseGridCell
) {
}


void particles::pidt::mappings::LiftParticles::ascend(
  particles::pidt::Cell * const    fineGridCells,
  particles::pidt::Vertex * const  fineGridVertices,
  const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
  particles::pidt::Vertex * const  coarseGridVertices,
  const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
  particles::pidt::Cell&           coarseGridCell
) {
}
