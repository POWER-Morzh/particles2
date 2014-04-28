// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PIDT_RUNNERS_RUNNER_H_ 
#define _PARTICLES_PIDT_RUNNERS_RUNNER_H_ 


#include "tarch/logging/Log.h"


namespace particles { 
  namespace pidt {
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
 * @author Tobias Weinzierl
 */
class particles::pidt::runners::Runner {
  private:
    static tarch::logging::Log _log;


    int runAsMaster( particles::pidt::repositories::Repository& repository );
    
    #ifdef Parallel
    int runAsWorker(particles::pidt::repositories::Repository& repository);
    
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
};

#endif
