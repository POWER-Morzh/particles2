// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PIT_RUNNERS_RUNNER_H_ 
#define _PARTICLES_PIT_RUNNERS_RUNNER_H_ 


#include "tarch/logging/Log.h"


namespace particles { 
  namespace pit {
    namespace runners {
      class Runner;
    }

    namespace repositories {
      class Repository;
    }
  }
}



/**
 * Runner
 *
 */
class particles::pit::runners::Runner {
  private:
    static tarch::logging::Log _log;


    int runAsMaster(
      particles::pit::repositories::Repository& repository
    );
    
    #ifdef Parallel
    int runAsWorker(particles::pit::repositories::Repository& repository);

    /**
     * I use this collective operation on all ranks only to switch off the
     * load balancing once the grid is set up.
     */
    void runGlobalStep();
    #endif
  public:
    Runner();
    virtual ~Runner();

    /**
     * Run
     */
    int run();

    /**
     * @param h If the mesh size equals 0.0, no particle sorting is done.
     */
    int runMemoryBenchmark();
};

#endif
