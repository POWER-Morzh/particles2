// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIDT_MAPPINGS_DropParticles_H_
#define PARTICLES_PIDT_MAPPINGS_DropParticles_H_


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
      class DropParticles;
    }
  }
}


/**
 * Drop particles in the spacetree
 *
 * This mapping drops particles in the spacetree. It plugs into the events
 * called when the automaton steps down within the tree and moves the particles
 * successively to the fine grid. For this, it has to handle hanging nodes and
 * realise the touch first event.
 * 
 * @image html DropParticles.png
 *
 * If we study the sketch above, we recognise that we can do all these resort
 * operations in descend, if createHangingVertex() has assigned each hanging
 * vertex a heap entry before. The bright green vertices then are not moved
 * down within the grid (which would be impossible anyway), while the dark
 * green particle as well as the red particle are moved.
 *
 * @author Bart Verleye, Tobias Weinzierl
 */
class particles::pidt::mappings::DropParticles {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;

    /**
     * Copy from master rank
     */
    State                       _state;

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
    DropParticles();

    #if defined(SharedMemoryParallelisation)
    /**
     * Nop
     */
    DropParticles(const DropParticles& masterThread);
    #endif

    /**
     * Nop
     */
    virtual ~DropParticles();
  
    #if defined(SharedMemoryParallelisation)
    /**
     * Nop
     */   
    void mergeWithWorkerThread(const DropParticles& workerThread);
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
     * Create Hanging Vertex
     *
     * We assign the hanging vertices a valid heap index. That one is freed in
     * return by the lift mapping. The actual drop of the particles into hanging
     * vertices then is realised by the descend() event.
     *
     * !!! Tuning remark
     */
    void createHangingVertex(
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
      particles::pidt::Vertex&                      vertex,
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
     * Take particles that have to be handled by the worker and send them to worker
     *
     * @image html MasterWorker.png
     *
     * We take those particles that have to be handled by the worker and send
     * them to the worker. Afterwards those are deleted from the local data
     * structures. As the prepare is called directly after the load, no descend
     * has happened before, i.e. we have to drop particles manually from the
     * coarser grid.
     *
     * !!! Skip reductions
     *
     * In this operation, we also decide wheather we can skip the reduction or not.
     *
     * This operation evaluates the cell's cellWillLiftParticleInNextTimeStep()
     * property and thus controls whether subtrees are restricted or not.
     *
     * @see  descend() which is called after prepareSendToWorker().
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
     * Receive new particles from master
     *
     * This operation receives the 2^d particles from the master and stores
     * them into receivedVertices. receivedVertices in turn are temporary
     * vertices, so we have to allocate heap indices from them prior to any
     * assignment. The data then actually is merged into the worker's grid in
     * mergeWithWorker().
     */
    void receiveDataFromMaster(
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
    );


    /**
     * Nop
     */
    void mergeWithWorker(
      particles::pidt::Cell&                       localCell,
      const particles::pidt::Cell&                 receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Copy the received data into the local vertex.
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
     * Nop
     */
    void touchVertexLastTime(
      particles::pidt::Vertex&         fineGridVertex,
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
     * Nop
     */
    void beginIteration(
      particles::pidt::State&  solverState
    );


    /**
     * Nop
     */
    void endIteration(
      particles::pidt::State&  solverState
    );
    
    
    /**
     * Descend in the spacetree
     *
     * Take all the coarse grid particles and sort them into the fine grid dual
     * cells. The algorithm is a multiply nested loop:
     * 
     * - Loop over all 2^d coarse grid vertices v_c:
     *   - Loop over all particles p assigned to v_c:
     *     - If p is contained within the coarse cell:
     *       - Determine dual fine grid cell covering p's position and move it to there
     *
     * !!! Distributed memory parallelisation
     *
     * If we are in an mpi environment, it can happen that all adjacent cells
     * of a fine grid vertex are deployed to remote workers. In this case, this
     * vertex is remote and does not carry an heap index. For this operation,
     * this observation is irrelevant, as all the particles that might have to
     * be dropped into the respective worker should have been dropped before by
     * prepareSendToWorker(), as prepareSendToWorker() is called before descend().
     *
     * !!! Shared memory parallelisation
     *
     * The descend operation sorts the particles into vertices covered by the
     * coarse grid cell. If no to adjacent coarse grid cells are handled at the
     * same time, it consequently cannot induce any data race. We can thus tell
     * Peano just to avoid fine grid races, as the term fine grid for the
     * parallelisation always refers to the grid traversed by the operation.
     *
     * !!! Particle speed analysis
     *
     * Descend is called prior to enterCell() on the fine grid level. Otherwise
     * dropping particles would not work as the move mapping moves particles in
     * enterCell(). When we drop particles, we however also have to update the
     * fine grid cell's maximum speeds to make the maximum particles velocity
     * analysis consistent.
     *
     * This update is again a little bit too careful: Usually, we have to update
     * up to @f$ 2^d @f$ cells. But this analysis is too complex here, we can
     * just update all  @f$ 3^d @f$ cells which is a superset of the cells. We
     * then are on the safe side.
     *
     * !!! Performance analysis
     *
     * Cursory performance studies reveal that the MoveParticles adapter
     * dominates pidt's runtime if the grid is rather balanced. However, if we
     * have a very steep grid (similar to a breaking damn), immediately
     * DropParticle's descend() operation enters the top-10 of the most
     * expensive operations. This is an obvious fact if we remind ourselves
     * that lifts themselves are rare in pit whereas they occur frequently in
     * the pit variant.
     *
     * To resolve this problem, one has to carefully choose a grid that is
     * a priori configured such that no drops have to be done in the first
     * iteration - afterwards the grid adopts automatically such that no
     * rebalancing is required. It basically makes the refinement front
     * anticipate particle movements.
     */
    void descend(
      particles::pidt::Cell * const          fineGridCells,
      particles::pidt::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&   fineGridVerticesEnumerator,
      particles::pidt::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&   coarseGridVerticesEnumerator,
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
