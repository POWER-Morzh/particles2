// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PITREPOSITORIES__REPOSITORY_H_ 
#define _PARTICLES_PITREPOSITORIES__REPOSITORY_H_


#include <string>
#include <vector>

#include "tarch/logging/Log.h"
#include "tarch/timing/Measurement.h"

#include "particles/pit/State.h"

#include "peano/grid/Checkpoint.h"


namespace particles { 
  namespace pit {
      namespace repositories {
        class Repository;
      } 
}
}



/**
 * Interface of all repositories
 */
class particles::pit::repositories::Repository {
  public:
    virtual ~Repository() {};
    
    /**
     * Iterate with current active event handle.
     */
    virtual void iterate() = 0;

    virtual particles::pit::State& getState() = 0;
    virtual const particles::pit::State& getState() const = 0;

    /**
     * Switch to another event handle.
     */
    virtual void switchToNop() = 0;    
    virtual void switchToInitGrid() = 0;    
    virtual void switchToInitGridAndPlot() = 0;    
    virtual void switchToSetupExperimentWithRandomParticleDistribution() = 0;    
    virtual void switchToSetupExperimentWithRandomParticleDistributionAndPlot() = 0;    
    virtual void switchToMoveParticles() = 0;    
    virtual void switchToMoveParticlesAndPlot() = 0;    

    virtual bool isActiveAdapterNop() const = 0;
    virtual bool isActiveAdapterInitGrid() const = 0;
    virtual bool isActiveAdapterInitGridAndPlot() const = 0;
    virtual bool isActiveAdapterSetupExperimentWithRandomParticleDistribution() const = 0;
    virtual bool isActiveAdapterSetupExperimentWithRandomParticleDistributionAndPlot() const = 0;
    virtual bool isActiveAdapterMoveParticles() const = 0;
    virtual bool isActiveAdapterMoveParticlesAndPlot() const = 0;


    /**
     * Give Some Statistics
     *
     * This operation gives you a table which tells you for each adapter how 
     * much time was spent in it. The result is written to the info log device. 
     */
    virtual void logIterationStatistics() const = 0;
        
    virtual void clearIterationStatistics() = 0;

    /**
     * Create a checkpoint.
     *
     * See createEmptyCheckpoint() before.
     */
    virtual void writeCheckpoint(peano::grid::Checkpoint<particles::pit::Vertex,particles::pit::Cell> * const checkpoint) = 0; 
    
    /**
     * Load a checkpoint
     * 
     * Does neither modify the checkpoint nor does it delete it. If you want to 
     * load a file from a checkpoint, see createEmptyCheckpoint() before.
     */
    virtual void readCheckpoint( peano::grid::Checkpoint<particles::pit::Vertex,particles::pit::Cell> const * const checkpoint ) = 0;
    
    /**
     * Create empty Checkpoint
     *
     * If you wanna read a checkpoint, implement the following four steps:
     * - Call createEmptyCheckpoint() on the repository. You receive a pointer 
     *   to a new checkpoint object. If you don't use this operation, your code 
     *   won't work in parallel and is not grid-independent.
     * - Invoke readFromFile() on the checkpoint object.
     * - Call readCheckpoint() on the repository and pass it your new checkpoint 
     *   object.
     * - Destroy the checkpoint object on the heap. 
     *
     * If you wanna write a checkpoint, implement the following four steps:
     * - Call createEmptyCheckpoint() on the repository. You receive a pointer 
     *   to a new checkpoint object. If you don't use this operation, your code 
     *   won't work in parallel and is not grid-independent.
     * - Call writeCheckpoint() on the repository and pass it your new checkpoint 
     *   object.
     * - Invoke writeToFile() on the checkpoint object.
     * - Destroy the checkpoint object on the heap. 
     */
    virtual peano::grid::Checkpoint<particles::pit::Vertex,particles::pit::Cell>* createEmptyCheckpoint() = 0;
    
    /**
     * Restart the repository with a different setup.
     *
     * This operation is only used by the parallel code. It itself derives from 
     * the new master node the new state and the adjacency information. Also 
     * the vertices with the adjacency information are taken from the master 
     * node, so the only interesting thing is how to traverse the adjacent 
     * elements and how the curve runs through the root element.
     */
    virtual void restart(
      const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
      const tarch::la::Vector<DIMENSIONS,double>&  domainOffset,
      int                                          domainLevel,
      const tarch::la::Vector<DIMENSIONS,int>&     positionOfCentralElementWithRespectToCoarserRemoteLevel
    ) = 0;     
    
    /**
     * Counterpart of restart(). However, terminate() also is to be called on  
     * the global master.
     */
    virtual void terminate() = 0;
    
    #ifdef Parallel
    enum ContinueCommand {
      Continue,
      Terminate,
      RunGlobalStep
    };
    
    /**
     * Shall a worker in the parallel cluster continue to iterate?
     *
     * This operation may be invoked on a worker node only, i.e. you are not 
     * allowed to trigger it on global rank 0. It waits for a wake-up call from 
     * the master node and then tells you whether to continue your work or not. 
     * If the result is false, you might do some additional iterations (plotting 
     * stuff or writing some statistics, e.g.), but then you should call
     * terminate() on the node and ask the node pool for a new job. If you 
     * invoke additional iterates() after this operation has returned false and 
     * and the terminate(), these iterations won't trigger any communication 
     * anymore.
     */
    virtual ContinueCommand continueToIterate() = 0;

    /**
     * Run one global step on all mpi ranks
     * 
     * This operation sends a marker to all nodes, i.e. 
     * both idle and working nodes, and calls their runGlobalStep() routine 
     * within the parallel runner. Afterwards, all idle nodes again register as 
     * idle on the node pool, all other nodes continue to run Peano. Should be 
     * used with care, as it might be expensive on massively parallel systems.  
     */
    virtual void runGlobalStep() = 0;
    #endif
    
    
    /**
     * Set maximum memory footprint spent on temporary data
     *
     * This value by default is infinity and, thus, no manual restriction on 
     * the maximum memory footprint spent on temporary data is posed. And, 
     * theoretically, the more memory you allow Peano to spend on temporary 
     * data the better the parallel shared memory scalability, as the 
     * concurrency level raises if more data is held temporary. However, due 
     * to NUMA effects, sometimes codes perform better if you restrict this 
     * value. Also, you might wanna run into swapping if this value is not 
     * set manually.
     */    
     virtual void setMaximumMemoryFootprintForTemporaryRegularGrids(double value) = 0;    
};


#endif
