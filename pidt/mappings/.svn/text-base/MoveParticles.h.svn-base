// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIDT_MAPPINGS_MoveParticles_H_
#define PARTICLES_PIDT_MAPPINGS_MoveParticles_H_


#include "tarch/logging/Log.h"
#include "tarch/la/Vector.h"

#include "peano/grid/VertexEnumerator.h"
#include "peano/MappingSpecification.h"

#include "tarch/multicore/MulticoreDefinitions.h"

#include "particles/pidt/Vertex.h"
#include "particles/pidt/Cell.h"
#include "particles/pidt/State.h"
#include "particles/pidt/records/Particle.h"


namespace particles { 
  namespace pidt {
    namespace mappings {
      class MoveParticles;
    }
  }
}


/**
 * Move particles in tree
 * 
 * Very simple algorithm. For each cell:
 * - Run over all particles.
 * - Check weather they are inside the cell.
 * - Check weather they hold the right move flag, i.e. wheather they have not been moved before.
 * - If both criteria hold: Move particle.
 *
 * !!! Parallelisation
 *
 * The mpi parallelisation of pidt is significantly more complicated than pit's
 * mpi version. While the master-worker communication is straightforward (see
 * lift and drop mappings), the neighbour exchange deserves some special attention.
 * We study it at hands of a simple sketch illustrating different particles after
 * enterCell() has terminated and when we jump into prepareSendToNeighbour().
 *
 * @image html NeighbourCommunication.png
 *
 * The light domain is the local domain. We see two ranks and study the left
 * rank first.
 *
 * - Green particles do not belong to the local domain. They are not moved.
 *   Such particles should never pop up (see discussion in drop and lift
 *   mappings).
 * - Light red particles have moved however remain in their dual cell. They
 *   are held by the vertex which is correct.
 * - Dark red particles have moved and moved to another dual cell. They have
 *   been reassigned to another vertex correctly.
 * - Yellow particles have tunneled locally, i.e. moved to another cell. They
 *   are treated by the lift mapping as, right now, they are assigned to the
 *   wrong dual cell.
 * - Blue particles have not tunneled but left the local partition.
 * - Grey particles have tunneled and left the local partition.
 *
 * To realise the parallel scheme, we have to ensure that prior to the next
 * iteration
 *
 * - all particles are assigned to the correct dual cells and
 * - to the correct partition.
 *
 * To do so, we make each node move the particles and afterwards send away
 * those particles that do not belong to the local partition anymore.
 * Afterwards, we delete the those particles. This way, we can handle the
 * blue particles. Prior to the next iteration, the right rank receives the
 * blue particle, checks whether it belongs to its local partition, and
 * inserts it into its vertex:
 *
 * - Particles moving from one partition to another but not tunneling are
 *   sent from their former owner to their new owner and then
 *   deleted at the former owner. The receiver integrates this particle into
 *   its local data structure.
 * - Particles moving to another partition due to tunneling are lifted to
 *   the next coarser level locally by the lift mapping automatically. We
 *   ignore then in send-to-neighbour and 'postpone' their treatment
 *   recursively.
 *
 * @author Bart Verleye, Tobias Weinzierl
 */
class particles::pidt::mappings::MoveParticles {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;

    State  _state;

    /**
     * Realises the reflecting boundaries. If you have a proper lift mechanism,
     * the reflection has to be evaluated on the root node of the tree only, i.e.
     * on the node having root as parent.
     */
    static void reflectParticle( particles::pidt::records::Particle& particle );

    /**
     * Move all particles within a cell that belong to a vertex
     *
     * Move all particles within a cell and return their cardinality. For
     * this, we have to loop over all the vertices (in parallel), check which
     * associated particles are covered by the cell (given by the enumerator),
     * and then update those whose flag is not set yet.
     */
    int moveParticlesOfOneVertexWithinCell(
      int                                  vertexIndex,
      const peano::grid::VertexEnumerator& fineGridVerticesEnumerator
    );

    /**
     * Would be great to have such a function, but then we run into race
     * conditions.
     */
    int  moveParticlesOfOneVertexWithinCellIfTheyAreSorted(
      int                                  vertexIndex,
      const peano::grid::VertexEnumerator& fineGridVerticesEnumerator
    );
  public:
    typedef std::vector<particles::pidt::records::Particle>  ParticleContainer;

    static peano::MappingSpecification   touchVertexLastTimeSpecification();

    /**
     * We set all particles states' to not moved yet. This operation is
     * embarassingly parallel.
     */
    static peano::MappingSpecification   touchVertexFirstTimeSpecification();


    /**
     * This is the actual particle movement and works with a red-black
     * colouring.
     */
    static peano::MappingSpecification   enterCellSpecification();
    static peano::MappingSpecification   leaveCellSpecification();
    static peano::MappingSpecification   ascendSpecification();
    static peano::MappingSpecification   descendSpecification();


    /**
     * Nop
     */
    MoveParticles();

    #if defined(SharedMemoryParallelisation)
    /**
     * Copy constructor for multithreaded code
     */
    MoveParticles(const MoveParticles& masterThread);
    #endif

    /**
     * Nop
     */
    virtual ~MoveParticles();
  
    #if defined(SharedMemoryParallelisation)
    /**
     * Merge with mapping running on worker
     *
     * As the mapping maintains some statistics, we have to reduce these data
     * from the worker thread.
     */
    void mergeWithWorkerThread(const MoveParticles& workerThread);
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
     *
     * However, we expect that all hanging vertices are assigned a valid index
     * when we encounter enterCell(). This vertex initialisation (probably)
     * moves particles from a coarser grid to the hanging vertices. I hence
     * realised it within DropParticles.
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
     * Nop
     */
    void destroyHangingVertex(
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
     * Extract particles from a vertex (its dual cell)
     *
     * Run over all particles associated to vertex. Extract those where the
     * particle location is inside the intersection of the dual cell described
     * by x and h with the local domain of rank.
     * -
     * @param vertex   Vertex to be studied. This vertex holds the particles to
     *                 be extracted. It also encodes which ranks are adjacent
     *                 to the vertex.
     * @param rank     Rank to be taken into account.
     * @param x        Vertex position which is in turn the center of dual cell.
     * @param h        Size of dual cell.
     */
    static ParticleContainer  extractAllParticlesFromDualCellBelongingToOneRank(
      int                                           sourceHeapIndex,
      particles::pidt::Vertex&                      vertex,
      int                                           rank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h
    );

    /**
     * Merge with particles received from neighbour
     *
     * As all the filtering has been done before, we can merge the vertices
     * directly into the local data structure. Prior to this, we have to
     * ensure that the state of the particles is set to new. We don't do this
     * in the merge but directly in the prepareSendToNeighbour() routine.
     *
     * !!! Assertions
     *
     * If Peano is compiled with assertions, I run over all particles of the
     * vertex and analyse whether they are contained in vertex's dual cell.
     * This way, I in particular ensure that no particles were received from
     * the neighbour that harm the data consistency.
     *
     * @see RandomParticleDistribution::prepareSendToNeighbour()
     * @see prepareSendToNeighbour()
     */
    void mergeWithNeighbour(
      particles::pidt::Vertex&                      vertex,
      const particles::pidt::Vertex&                neighbour,
      int                                           fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Distribute all particles among the adjacent workers
     *
     * This operation realises the rationale described in the class
     * documentation. Furthermore, it resets the particles' state to
     * new before it sends the records away. See mergeWithNeighbour()
     * for further details as well.
     *
     * !!! Assertions
     *
     * All those particles sent away to the neighbour are contained
     * within vertex's dual cell.
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
      particles::pidt::Cell&                       fineGridCell,
      particles::pidt::Vertex * const              fineGridVertices,
      const peano::grid::VertexEnumerator&       fineGridVerticesEnumerator,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      particles::pidt::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell,
      int                                        worker
    );
    
    
    /**
     * Nop
     */
    void mergeWithMaster(
      const particles::pidt::Cell&                       workerGridCell,
      particles::pidt::Vertex * const                    workerGridVertices,
      const peano::grid::VertexEnumerator&             workerEnumerator,
      particles::pidt::Cell&                             fineGridCell,
      particles::pidt::Vertex * const                    fineGridVertices,
      const peano::grid::VertexEnumerator&             fineGridVerticesEnumerator,
      particles::pidt::Vertex * const                    coarseGridVertices,
      const peano::grid::VertexEnumerator&             coarseGridVerticesEnumerator,
      particles::pidt::Cell&                             coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&         fineGridPositionOfCell,
      int                                              worker,
      const particles::pidt::State&                      workerState,
      particles::pidt::State&                            masterState
    );


    /**
     * Nop
     */
    void prepareSendToMaster(
      particles::pidt::Cell&                       localCell,
      particles::pidt::Vertex *                    vertices,
      const peano::grid::VertexEnumerator&       verticesEnumerator, 
      const particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      const particles::pidt::Cell&                 coarseGridCell,
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
      particles::pidt::Vertex&        localVertex,
      const particles::pidt::Vertex&  receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    #endif


    /**
     * Read vertex the first time throughout one iteration
     * 
     * This operation is invoked only for persistent vertices. Each persistent
     * vertex corresponds to one dual cell. We run over all particles of this
     * cell and reset all particle states to 'not yet moved'.
     *
     * !!! Shared memory parallelisation
     *
     * This operation only accesses particles assigned to the vertex. It hence
     * is embarassingly parallel and we can use AvoidFineGridRaces and
     * parallelisation specification. Furthermore, as we assume that all
     * particles have been dropped before, we work exclusively on the leaves.
     */
    void touchVertexFirstTime(
      particles::pidt::Vertex&                     fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridH,
      particles::pidt::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&         coarseGridVerticesEnumerator,
      particles::pidt::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&     fineGridPositionOfVertex
    );



    /**
     * Nop (but checks in assert mode)
     *
     * If Peano invokes touch last, all adjacent cells have been visited
     * before. Hence, all particles have been moved now.
     *
     * !!! Distributed memory parallelisation
     *
     * touchVertexLastTime() is called prior to prepareSendToNeighbour().
     * Consequently, it can happen that some particles are outside of the local
     * computational domain, but those then just have left it.
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
     * Update all particles within cell
     *
     * As we are within a cell, we have @f$ 2^d @f$ adjacent vertices, i.e.
     * four dual cells that overlap with the current cell in 2d. In the event,
     * we update all particles of these dual cells that overlap with the
     * current cell and have not been updated before by another cell. The
     * latter criterion is encoded within the particle state. In the sketch
     * below, the red particles consequently are not moved.
     *
     * @image html MoveParticles.png
     *
     * After we've moved a particle, we first set its state to moved.
     * Afterwards, we check its state and reassign it to a different vertex
     * if necessary. This operation is moved to leaveCell() as we apply it
     * recursively on all grid levels.
     *
     * !!! Adaptive meshes
     *
     * As we are working on adaptive meshes, it can happen that we are handling
     * enterCell for a refined cell. To illustrate this, we take a sketch from
     * the lift mapping and study the right case:
     *
     * @image html LiftParticles.png
     *
     * The upper left cell is refined once. Here, we also can skip the
     * evaluation as the dark green particle has to be dropped to a finer grid
     * in this traversal.
     *
     * !!! Shared memory parallelisation
     *
     * This mapping only handles particles that are covered by the local cell.
     * And it exclusively shuffels around particles among the adjacent vertices
     * of this very cell. As a consequence, a simple red-black type colouring
     * on the finest grid here avoids any data races. Furthermore, we can work
     * on leaves only, as we drop all particles to the finest level prior to a
     * position update.
     *
     * !!! Velocity analysis
     *
     * If we are on the finest grid, we loop over all particles and update the
     * position of those that are contained in the cell (and haven't been
     * updated before). Besides, we also study the velocity components in the
     * maximum norm for this cell. The analysis here takes all particles into
     * account independent whether they've moved before or are really covered
     * by the cell. The analysis hence computes a maximum value for all dual
     * cells intersecting with the current one taking into account particles
     * that will not reside within the cell in this iteration.
     *
     * This way, the analysis is correct as it yields only too high maximum
     * velocities - never too low. The other way round, it however seems not to
     * be stable: There might be particles that tunnel into the present cell
     * and change its maximum velocities. This tunneling is handled by the drop
     * mechanism and not by the move mapping.
     *
     * If a cell is refined, we clear its maximum value and restrict this
     * information later in ascend.
     */
    void enterCell(
      particles::pidt::Cell&                    fineGridCell,
      particles::pidt::Vertex * const           fineGridVertices,
      const peano::grid::VertexEnumerator&      fineGridVerticesEnumerator,
      particles::pidt::Vertex * const           coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      particles::pidt::Cell&                    coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
    );


    /**
     * Leave a cell and reassign particles to vertices if necessary
     *
     * Run through all particles of all vertices and study them. There are
     * three different cases to be taken into account:
     *
     * @image html MoveParticles.png
     *
     * - Particle remains within their current dual cell (yellow).
     * - Particle moves to another dual cell that overlaps with the currently
     *   handled cell as well (blue). In this case, remove the particle from
     *   its former dual cell/vertex and append it to the particles managed by
     *   the other vertex.
     * - Particles move to a dual cell that does not overlap with the current
     *   cell (green). This is a case we cannot handle. We call this tunneling.
     *
     * If particles tunnel, we assign them to the dual cell that is closest to
     * their destination cell. In the sketch above, this would be the upper left
     * dual cell. The treatment of tunneling particles is realised within the
     * lift mapping. This might be inefficient, i.e. it might be cleverer to
     * realise this all in this mapping to avoid multiple tunnel checks, but I
     * preferred to have a clear separation of concern.
     *
     * Hanging nodes might hold particles as well when this operation
     * terminates. As hanging nodes are destroyed the latest after this
     * traversal, we have to move particles assigned to hanging nodes to other
     * vertices. This is also a lift operation and thus realised in the lift
     * mapping.
     *
     * If we updated all particles of the adjacent cells with the right state,
     * i.e. if we did not check whether they are within the current cell, we
     * could skip one case distinction. However, we then probably can not handle
     * case two from the list above, as we do not have access to the vertices
     * one cell away from the current cell.
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
     * Copy state from master and clear its statistics. Different to the lift
     * statistics, these statistics mainly count the number of particles in the
     * system, i.e. independent of whether the data is used, we can clear them.
     */
    void beginIteration(
      particles::pidt::State&  solverState
    );


    /**
     * Iteration is done
     * 
     * Merge local state holding updated statistics into the master state.
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
     * Restrict maximum velocity properties.
     */
    void ascend(
      particles::pidt::Cell * const         fineGridCells,
      particles::pidt::Vertex * const       fineGridVertices,
      const peano::grid::VertexEnumerator&  fineGridVerticesEnumerator,
      particles::pidt::Vertex * const       coarseGridVertices,
      const peano::grid::VertexEnumerator&  coarseGridVerticesEnumerator,
      particles::pidt::Cell&                coarseGridCell
    );    
};


#endif
