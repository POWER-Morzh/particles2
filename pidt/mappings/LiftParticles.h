// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIDT_MAPPINGS_LiftParticles_H_
#define PARTICLES_PIDT_MAPPINGS_LiftParticles_H_


#include "tarch/logging/Log.h"
#include "tarch/la/Vector.h"

#include "peano/grid/VertexEnumerator.h"
#include "peano/MappingSpecification.h"

#include "tarch/multicore/BooleanSemaphore.h"
#include "tarch/multicore/MulticoreDefinitions.h"

#include "particles/pidt/Vertex.h"
#include "particles/pidt/Cell.h"
#include "particles/pidt/State.h"

#include "particles/pidt/records/Particle.h"


namespace particles { 
  namespace pidt {
    namespace mappings {
      class LiftParticles;
    }
  }
}




/**
 * Lift particles
 *
 * We have to lift particles from level l to level l-1 in two cases:
 *
 * - If there is a hanging nodes, we have to take its particles and write them
 *   to the coarser grid.
 * - If there is a vertex holding particles that do not belong to its dual
 *   cell, these particles are not sorted correctly. We lift those.
 *
 * Following this description, this mapping works exclusively on vertices. And
 * it works throughout the steps up in the spacetree.
 * 
 * !!! Implementation variants
 *
 * The lifts move particles from the finer level to the coarser grid. They
 * hence demand for a treatment of data races. We provide two different solutions:
 *
 * - In variant A, we do a @f$ 7^d @f$ colouring and thus avoid data races a
 *   priori.
 * - In variant B, we use a semaphore for the lifts.
 *
 * While the semaphore introduces some synchronisation, it comes along with a
 * higher concurrency level. It is not clear a priori, which variant performs
 * better.
 *
 * In the paper's experiments, the two parallelisation variants didn't come
 * along with a big performance difference. They all yield the same particle
 * throughput.
 *
 * @author Bart Verleye, Tobias Weinzierl
 */
class particles::pidt::mappings::LiftParticles {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;

    typedef std::vector<particles::pidt::records::Particle>  ParticleContainer;

    #ifdef LIFT_PARTICLE_USES_SEMAPHORE
    static tarch::multicore::BooleanSemaphore  _semaphore;
    #endif

    State                       _state;

    /**
     * Clear the state
     *
     * Flag indicating whether the mapping shall clear the state after this
     * iteration. Becomes true if the state reduction is switched on.
     * Otherwise, we accumulate our state data throughout multiple traversals.
     */
    bool                        _clearStateAfterIteration;

    /**
     * Lift particles
     *
     * A hanging node corresponds to a dual cell of the grid that is not
     * persistent. As it is destroyed, we have to free the vertex's index
     * and have to reassign all of its vertices to the right place. In the
     * sketch below, we are talking about the green particles on the left.
     *
     * @image html LiftParticles.png
     *
     * Due to the three partitioning, all particles of a destroyed cell
     * have to be moved to one dual cell on the coarser grid: we have a
     * inclusion property also for the dual cells.
     *
     * When the operation terminates, all particles have been copied to the
     * coarser node. That implies that they still remain on the finer vertex.
     * Either you remove them from there or your delete the whole underlying
     * heap entry. However, it is up to the caller to do so.
     */
    void liftParticles(
      particles::pidt::ParticleHeap::HeapEntries&  particles,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
      const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
    );
  public:
    static peano::MappingSpecification   touchVertexLastTimeSpecification();
    static peano::MappingSpecification   touchVertexFirstTimeSpecification();
    static peano::MappingSpecification   enterCellSpecification();
    static peano::MappingSpecification   leaveCellSpecification();
    static peano::MappingSpecification   ascendSpecification();
    static peano::MappingSpecification   descendSpecification();


    /**
     * Nop
     */
    LiftParticles();

    #if defined(SharedMemoryParallelisation)
    /**
     * Copy constructor of forked thread
     *
     * Copy the attributes from the master thread and call clearStatistics()
     * on the state as the state afterwards will be reduced, i.e. we have to
     * start with 0 locally prior to the reduction of counters.
     */
    LiftParticles(const LiftParticles& masterThread);
    #endif

    /**
     * Nop
     */
    virtual ~LiftParticles();
  
    #if defined(SharedMemoryParallelisation)
    /**
     * Merge with master thread
     *
     * Merge with worker thread's statistics.
     */   
    void mergeWithWorkerThread(const LiftParticles& workerThread);
    #endif

    /**
     * Nop
     */
    void createInnerVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createBoundaryVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createHangingVertex(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Destroy hanging node
     *
     * Invoke liftParticles().
     *
     * @see liftParticles()
     */
    void destroyHangingVertex(
      const particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
      particles::pidt::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
    );


    /**
     * Invoke liftParticles().
     *
     * @see liftParticles()
     */
    void destroyVertex(
      const particles::pidt::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const         fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );


    /**
     * Nop
     */

    void destroyCell(
      const particles::pidt::Cell&           fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );
        
        
    #ifdef Parallel
    /**
     * Nop
     */

    void mergeWithNeighbour(
      particles::pidt::Vertex&  vertex,
      const particles::pidt::Vertex&  neighbour,
      int                                           fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Nop
     */
    void prepareSendToNeighbour(
      particles::pidt::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Nop
     */
    void prepareCopyToRemoteNode(
      particles::pidt::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    

    /**
     * Nop
     */
    void prepareCopyToRemoteNode(
      particles::pidt::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
    );


    /**
     * Nop
     */
    void mergeWithRemoteDataDueToForkOrJoin(
      particles::pidt::Vertex&  localVertex,
      const particles::pidt::Vertex&  masterOrWorkerVertex,
      int                                          fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&  x,
      const tarch::la::Vector<DIMENSIONS,double>&  h,
      int                                          level
    );


    /**
     * Nop
     */
    void mergeWithRemoteDataDueToForkOrJoin(
      particles::pidt::Cell&  localCell,
      const particles::pidt::Cell&  masterOrWorkerCell,
      int                                          fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Nop
     */
    bool prepareSendToWorker(
      particles::pidt::Cell&                     fineGridCell,
      particles::pidt::Vertex * const            fineGridVertices,
      const peano::grid::VertexEnumerator&       fineGridVerticesEnumerator,
      particles::pidt::Vertex * const            coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      particles::pidt::Cell&                     coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell,
      int                                        worker
    );
    
    
    /**
     * Counterpart of prepareSendToMaster()
     *
     * Please consult prepareSendToMaster() for a description which particles
     * are sent to the master at all. According to the reasoning there, all
     * particles received immediately have to be lifted.
     *
     * We may not receive anything into the fine grid
     * vertices anyway, as it could happen that all adjacent cells of a vertex on the
     * master are deployed to other ranks, i.e. those vertices are remote,
     * outside, and destroyed. Such vertices then neither have a vertex index
     * nor are they handled by the touch last event lifting particles further.
     *
     * !!! Avoid reductions
     *
     * If reductions are switched off, this operation is not called at all.
     * However, if the reduction is switched on though the analysis says that
     * there is no reduction required (it is globally switched on), we can
     * validate that relly no single particle is sent up along the tree.
     */
    void mergeWithMaster(
      const particles::pidt::Cell&                     workerGridCell,
      particles::pidt::Vertex * const                  workerGridVertices,
      const peano::grid::VertexEnumerator&             workerEnumerator,
      particles::pidt::Cell&                           fineGridCell,
      particles::pidt::Vertex * const                  fineGridVertices,
      const peano::grid::VertexEnumerator&             fineGridVerticesEnumerator,
      particles::pidt::Vertex * const                  coarseGridVertices,
      const peano::grid::VertexEnumerator&             coarseGridVerticesEnumerator,
      particles::pidt::Cell&                           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&         fineGridPositionOfCell,
      int                                              worker,
      const particles::pidt::State&                    workerState,
      particles::pidt::State&                          masterState
    );


    /**
     * Prepare the send to master and remove particles from local grid
     *
     * The dual grid on the worker's top level, i.e. those 2^d cells
     * intersecting with the coarsest cell and its adjacent vertices, is owned
     * by up to @f$ 3^d @f$ different ranks. There are three different types of
     * particles:
     *
     * - Particles residing within the coarsest cell. Those are fine, we
     *   do not have to lift them (red).
     * - Particles belonging to one of the 2^d dual cells intersecting with
     *   the coarsest cell that are not contained within the local spacetree's
     *   root. Those are handled by the neighbour communication. (green)
     * - Particles not falling into one of the first two classes. (blue)
     *
     * The latter ones are to be lifted.
     *
     * @image html MasterWorker.png
     *
     * As the send to the master is the last thing we do, we afterwards
     * inform the master that we have finished all synchronous data exchange.
     *
     * There is a special case that has to be studied in prepareSend
     * separately. We study in the sketch above the particles and assume
     * that (due to the move mapping) all these particles are assigned to
     * the upper right vertex. In the serial code, the dark red particle and
     * the blue one are lifted by this mapping. In the parallel code, we
     * furthermore have a special treatment for the green particles.
     *
     * Obviously, it is now not a good idea to send the dark red particle to
     * the master - we could reassign it to the right bottom vertex locally
     * and avoid the communication. However, we know that move has moved this
     * particle to the bottom right vertex already, i.e. such a case cannot
     * happen.
     */
    void prepareSendToMaster(
      particles::pidt::Cell&                     localCell,
      particles::pidt::Vertex *                  vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const particles::pidt::Vertex * const      coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const particles::pidt::Cell&               coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void receiveDataFromMaster(
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
    );


    /**
     * Nop
     */
    void mergeWithWorker(
      particles::pidt::Cell&           localCell, 
      const particles::pidt::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Nop
     */
    void mergeWithWorker(
      particles::pidt::Vertex&                      localVertex,
      const particles::pidt::Vertex&                receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    #endif


    /**
     * Nop
     */
    void touchVertexFirstTime(
      particles::pidt::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );



    /**
     * Lift particles not belonging to vertex
     *
     * This operation runs over all particles assigned to fineGridVertex. These
     * particles have to be in the dual cell defined by the vertex. If they are
     * not, the move mapping was not able to assign them to the correct vertex.
     * We take those and lift them to the next coarser level. As this might
     * induce a cascade of lifts along the grid hierarchy, this operation has to
     * work on the whole tree.
     *
     * !!! Shared memory parallelisation
     *
     * The fine grid vertices in principle can be studied embarassingly parallel.
     * However, they might modify their coarse grid vertices. Consequently, it
     * is important to avoid coarse grid data races.
     *
     * !!! Distributed memory parallelisation
     *
     * We may not lift particles if the coarse grid cell is the root cell. In
     * this case, we have to move the data to the master node. The latter is
     * realised within prepareSendToMaster().
     *
     * We know that touchVertexLastTime() is called before Peano calls
     * prepareSendToNeighbour(). Consequently, we have three types of particles
     * at hand:
     *
     * - Particles that reside in this vertex, i.e. in its dual cell. Those
     *   particles already are at the right place and can be skipped here.
     * - Particles that have to be moved one level up as they do not fall into
     *   the vertex's dual cell. The coarse grid dual cell fitting best to the
     *   particle is on the local node. Lift these particles.
     * - Particles that do not fit to the vertex's dual cell but have to be
     *   moved to another rank.
     *
     * Only the latter particles are tricky to use: We have to lift them one
     * level. However, we may not lift them to the best dual cell as this one
     * is remote as well - see the definition of the problem. Therefore, we
     * lift it to the coarser dual cell belonging to the vertex itself. This
     * one is always local.
     */
    void touchVertexLastTime(
      particles::pidt::Vertex&                     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
      particles::pidt::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
    );
    

    /**
     * Nop
     */
    void enterCell(
      particles::pidt::Cell&                 fineGridCell,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void leaveCell(
      particles::pidt::Cell&                          fineGridCell,
      particles::pidt::Vertex * const                 fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const                 coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&                          coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&      fineGridPositionOfCell
    );


    /**
     * Begin an iteration
     * 
     * The lift mapping does some statistics on how many lifts have happened
     * on which levels. These statistics are valid if and only if the
     * restriction is switched on - otherwise the data are not reduced. In
     * beginIteration() the mapping evaluates the restriction, and memorises
     * whether a restriction happens in the end, i.e. whether the local
     * statistics can be cleared.
     *
     *
     * !!! State Copying
     *
     * The lift holds its own state that is basically just a container for the
     * statistics. However, we also need the valid time step at hand to be able
     * to validate reduction skips. If we'd copy the whole state, we'd loose
     * the statistics. So we copy the time step size manually.
     */
    void beginIteration(
      particles::pidt::State&  solverState
    );


    /**
     * Iteration is done
     * 
     * @see beginIteration()
     */
    void endIteration(
      particles::pidt::State&  solverState
    );
    
    
    /**
     * Nop
     */
    void descend(
      particles::pidt::Cell * const          fineGridCells,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pidt::Cell&                 coarseGridCell
    );


    /**
     * Nop
     */
    void ascend(
      particles::pidt::Cell * const    fineGridCells,
      particles::pidt::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pidt::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pidt::Cell&           coarseGridCell
    );    
};


#endif
