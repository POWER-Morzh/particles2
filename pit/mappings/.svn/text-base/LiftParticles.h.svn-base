// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef PARTICLES_PIT_MAPPINGS_LiftParticles_H_
#define PARTICLES_PIT_MAPPINGS_LiftParticles_H_


#include "tarch/logging/Log.h"
#include "tarch/la/Vector.h"

#include "peano/grid/VertexEnumerator.h"
#include "peano/MappingSpecification.h"

#include "tarch/multicore/MulticoreDefinitions.h"

#include "particles/Particles.h"
#include "particles/pit/Vertex.h"
#include "particles/pit/Cell.h"
#include "particles/pit/State.h"


#include "particles/pit/records/Particle.h"



namespace particles { 
  namespace pit {
    namespace mappings {
      class LiftParticles;
    }
  }
}


/**
 * This is a mapping from the spacetree traversal events to your user-defined activities.
 * The latter are realised within the mappings. 
 * 
 * @author Peano Development Toolkit (PDT) by  Tobias Weinzierl
 * @version $Revision: 1.10 $
 */
class particles::pit::mappings::LiftParticles {
  private:
    /**
     * Logging device for the trace macros.
     */
    static tarch::logging::Log  _log;

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
     * Decide whether to lift a particle
     *
     * @param particle   Particle to study
     * @param fineGridX  Left bottom vertex of the current cell
     * @param fineGridH  Size of current cell
     */
    bool liftParticle(
      const particles::pit::records::Particle&     particle,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&  fineGridH
    ) const;
  public:
    /**
     * These flags are used to inform Peano about your operation. It tells the 
     * framework whether the operation is empty, whether it works only on the 
     * spacetree leaves, whether the operation can restart if the thread 
     * crashes (resiliency), and so forth. This information allows Peano to
     * optimise the code.
     *
     * @see peano::MappingSpecification for information on thread safety.
     */
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
     * Copy Constructor for Shared Memory
     *
     * Copy the attributes and call clearStatistics() on this thread instance.
     *
     * @see clearStatistics()
     * @see mergeWithWorkerThread()
     */
    LiftParticles(const LiftParticles& masterThread);

    /**
     * Merge with worker thread
     *
     * This operation realises a reduction of the local fields.
     */
    void mergeWithWorkerThread(const LiftParticles& workerThread);
    #endif

    /**
     * Nop
     */
    virtual ~LiftParticles();
  

    /**
     * Nop
     */
    void createInnerVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createBoundaryVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createHangingVertex(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void destroyHangingVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void destroyVertex(
      const particles::pit::Vertex&   fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );


    /**
     * Nop
     */
    void createCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const         fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void destroyCell(
      const particles::pit::Cell&           fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );
        
        
    #ifdef Parallel
    /**
     * Nop
     *
     * All information exchange is done via cells. No (particle) data is
     * exchanged via vertices, only grid data structure such as refinement
     * information. As such data is handled by the kernel, this operation
     * reduces to nop.
     */
    void mergeWithNeighbour(
      particles::pit::Vertex&  vertex,
      const particles::pit::Vertex&  neighbour,
      int                                           fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Nop
     */
    void prepareSendToNeighbour(
      particles::pit::Vertex&  vertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );


    /**
     * Nop
     */
    void prepareCopyToRemoteNode(
      particles::pit::Vertex&  localVertex,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    

    /**
     * Nop
     */
    void prepareCopyToRemoteNode(
      particles::pit::Cell&  localCell,
      int                                           toRank,
      const tarch::la::Vector<DIMENSIONS,double>&   cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&   cellSize,
      int                                           level
    );


    /**
     * Nop
     */
    void mergeWithRemoteDataDueToForkOrJoin(
      particles::pit::Vertex&  localVertex,
      const particles::pit::Vertex&  masterOrWorkerVertex,
      int                                          fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&  x,
      const tarch::la::Vector<DIMENSIONS,double>&  h,
      int                                          level
    );


    /**
     * Counterpart of prepareCopyToRemoteNode()
     */
    void mergeWithRemoteDataDueToForkOrJoin(
      particles::pit::Cell&  localCell,
      const particles::pit::Cell&  masterOrWorkerCell,
      int                                          fromRank,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Nop
     *
     * Nothing can happen here, as we are only lifting particles. However, we
     * return true as the lift are inherently tied to a permanent reduction.
     */
    bool prepareSendToWorker(
      particles::pit::Cell&                       fineGridCell,
      particles::pit::Vertex * const              fineGridVertices,
      const peano::grid::VertexEnumerator&       fineGridVerticesEnumerator,
      particles::pit::Vertex * const              coarseGridVertices,
      const peano::grid::VertexEnumerator&       coarseGridVerticesEnumerator,
      particles::pit::Cell&                       coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&   fineGridPositionOfCell,
      int                                        worker
    );
    
    
    /**
     * Merge with Master Cell
     *
     * t.b.d
     *
     * This operation takes the data received from the worker and adds it to
     * the coarse cell. The fine grid cell is remote and passive, i.e. the
     * worker is responsible for this one. And we know that the worker has
     * sent back to the master exclusively particles that would leave the
     * fine grid cell anyway. So we copy the stuff directly into the master.
     *
     * An exception to the latter rule is the global master in parallel mode.
     * Here, we assign all particles to the fine cell, as this one is the
     * cell @f$ (0,0,...)^T \times (1,1,1,...)^T @f$. The particles won't do
     * anything on the global master, they will be sent back right next
     * iteration when we then appy reflecting boundary conditions due to the
     * drop mapping. We hence might skip the particle exchange with node 0
     * completely. However, this would imply further ifs in other routines.
     * For sake of simplicity, I hence decided to add an if only here.
     *
     * Also the states are merged in this operation. For this, we use the
     * reduceState() operation.
     *
     * @todo wir koennten natuerlich alles gleich auf coarse schmeissen, aber
     *       das machen wir nicht, weil dann die Statistik manuell nachgezogen
     *       werden muss
     */
    void mergeWithMaster(
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
    );


    /**
     * Prepare send to master
     *
     * Check which particles will be lifted and send those to the master.
     * Afterwards, remove them from local containers. Remove means that the
     * particles are removed from the container associated to the cell. Even
     * if all particles leave the cell, the cell index and container remain.
     */
    void prepareSendToMaster(
      particles::pit::Cell&                     localCell,
      particles::pit::Vertex *                  vertices,
      const peano::grid::VertexEnumerator&      verticesEnumerator,
      const particles::pit::Vertex * const      coarseGridVertices,
      const peano::grid::VertexEnumerator&      coarseGridVerticesEnumerator,
      const particles::pit::Cell&               coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&  fineGridPositionOfCell
    );


    /**
     * Clear the attribute _mastersParticles.
     */
    void receiveDataFromMaster(
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
    );


    /**
     * Nop
     */
    void mergeWithWorker(
      particles::pit::Cell&           localCell, 
      const particles::pit::Cell&     receivedMasterCell,
      const tarch::la::Vector<DIMENSIONS,double>&  cellCentre,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize,
      int                                          level
    );


    /**
     * Nop
     */
    void mergeWithWorker(
      particles::pit::Vertex&        localVertex,
      const particles::pit::Vertex&  receivedMasterVertex,
      const tarch::la::Vector<DIMENSIONS,double>&   x,
      const tarch::la::Vector<DIMENSIONS,double>&   h,
      int                                           level
    );
    #endif


    /**
     * Nop
     */
    void touchVertexFirstTime(
      particles::pit::Vertex&               fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                          fineGridH,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfVertex
    );


    /**
     * Nop
     */

    void touchVertexLastTime(
      particles::pit::Vertex&         fineGridVertex,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridX,
      const tarch::la::Vector<DIMENSIONS,double>&                    fineGridH,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                       fineGridPositionOfVertex
    );
    

    /**
     * Nop
     */
    void enterCell(
      particles::pit::Cell&                 fineGridCell,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&                             fineGridPositionOfCell
    );


    /**
     * Nop
     */
    void leaveCell(
      particles::pit::Cell&                          fineGridCell,
      particles::pit::Vertex * const                 fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const                 coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&                          coarseGridCell,
      const tarch::la::Vector<DIMENSIONS,int>&      fineGridPositionOfCell
    );


    /**
     * Begin an iteration
     * 
     * @todo Application-specific docu is missing
     *
     *
     * This operation is called whenever the algorithm tells Peano that the grid 
     * is to be traversed, i.e. this operation is called before any creational 
     * mapping operation or touchVertexFirstTime() or handleCell() is called.
     * The operation receives a solver state that has to 
     * encode the solver's state. Take this attribute to set the mapping's 
     * attributes. This class' attributes will remain valid until endIteration()
     * is called. Afterwards they might contain garbage.
     *
     * !!! Parallelisation
     *
     * If you run your code in parallel, beginIteration() and endIteration() 
     * realise the following lifecycle together with the state object:
     *
     * - Receive the state from the master if there is a master.
     * - beginIteration()
     * - Distribute the state among the workers if there are workers.
     * - Merge the states from the workers (if they exist) into the own state. 
     * - endIteration()
     * - Send the state to the master if there is a master.
     *
     * @see LiftParticles()
     */
    void beginIteration(
      particles::pit::State&  solverState
    );


    /**
     * Iteration is done
     * 
     * This operation is called at the very end, i.e. after all the
     * handleCell() and touchVertexLastTime() operations have been invoked.
     *
     * We take the local copy of the state (_state) and merge it into the
     * argument solverState. The solver's merge operation is a reduction
     * which is exactly the method implementing this behaviour.
     *
     * !!! Parallelisation
     *
     * If you run your code in parallel, beginIteration() and endIteration() 
     * realise the following lifecycle together with the state object:
     *
     * - Receive the state from the master if there is a master.
     * - beginIteration()
     * - Distribute the state among the workers if there are workers.
     * - Merge the states from the workers (if they exist) into the own state. 
     * - endIteration()
     * - Send the state to the master if there is a master.
     *
     * As a consequence, the ...
     *
     * @see LiftParticles()
     */
    void endIteration(
      particles::pit::State&  solverState
    );
    
    
    /**
     * Nop
     */
    void descend(
      particles::pit::Cell * const          fineGridCells,
      particles::pit::Vertex * const        fineGridVertices,
      const peano::grid::VertexEnumerator&                fineGridVerticesEnumerator,
      particles::pit::Vertex * const        coarseGridVertices,
      const peano::grid::VertexEnumerator&                coarseGridVerticesEnumerator,
      particles::pit::Cell&                 coarseGridCell
    );


    /**
     * Ascend in the spacetree
     *
     * @todo Application-specific docu is missing
     */
    void ascend(
      particles::pit::Cell * const    fineGridCells,
      particles::pit::Vertex * const  fineGridVertices,
      const peano::grid::VertexEnumerator&          fineGridVerticesEnumerator,
      particles::pit::Vertex * const  coarseGridVertices,
      const peano::grid::VertexEnumerator&          coarseGridVerticesEnumerator,
      particles::pit::Cell&           coarseGridCell
    );    
};


#endif
