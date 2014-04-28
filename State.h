// This file is part of the Peano project. For conditions of distribution and
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_STATE_H_
#define _PARTICLES_STATE_H_

#include "peano/grid/State.h"

#include "peano/grid/Checkpoint.h"

namespace particles { 
  template <class StateData>
  class State;
}


/**
 * Solver State.
 *
 * Both particle variants use exactly the same state but with a different
 * aggregate. Therefore,  I make the state a template.
 * 
 * @author Tobias Weinzierl
 */
template <class StateData>
class particles::State: public peano::grid::State< StateData > {
  protected:
    typedef class peano::grid::State< StateData >  Base;

  public:
    /**
     * Default Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it.
     */
    State();

    /**
     * Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it. It is kind of a copy constructor that converts an object which 
     * comprises solely persistent attributes into a full attribute. This very 
     * functionality is implemented within the super type, i.e. this constructor 
     * has to invoke the correponsing super type's constructor and not the super 
     * type standard constructor.
     */
    State(const typename Base::PersistentState& argument);


    void init(
      int     minimalNumberOfParticlesPerCell,
      double  timeStepSize,
      double  maximalNumberOfInitialParticlesPerUnitVolume,
      double  maximalInitialVelocity,
      double  breakingDamWidth
    );

    int     getMinimalNumberOfParticlesPerCell() const;
    double  getMaximalNumberOfInitialParticlesPerUnitVolume() const;
    double  getMaximalInitialVelocity() const;
    double  getTimeStepSize() const;
    double  getBreakingDamWidth() const;

    /**
     * Should be called in leaves to update the local statistics.
     */
    void updateParticleStatisticsInLeaf(
      double                                       numberOfParticles,
      const tarch::la::Vector<DIMENSIONS,double>&  cellSize
    );

    void incNumberOfLifts(int level, double increment = 1.0);

    /**
     * Delete all the local statistic variables
     */
    void clearStatistics();

    /**
     *
     *  Originally, I had a check in there such as. However, I now work a lot
     *  with non-reducing algorithmic parts. If there's no reduction however,
     *  the states all might hold invalid data.
     *
     \code
  assertionEquals2(
    _stateData.getMaximalNumberOfInitialParticlesPerUnitVolume(), remoteState._stateData.getMaximalNumberOfInitialParticlesPerUnitVolume(),
    toString(),
    remoteState.toString()
  );
     \endcode
     */
    void reduceStateStatistics( const State& remoteState );

    /**
     * Return total number of lifts
     */
    double getTotalNumberOfLifts() const;

    /**
     * Return total number of particles
     *
     * This is the total number of particles. However, some particles might be
     * bookkept twice if joins or forks are going on: Particles sent to a
     * different rank due to rebalancing are counted twice, once by the old
     * responsible rank and once by the new one.
     */
    double getNumberOfParticles() const;
    double getMeanParticleDensityInNonEmptyCells() const;
    double getAverageParticlesPerCell() const;
    double getNumberOfLifts(int level) const;
    double getNumberOfNonEmptyLeaves() const;

    double getNumberOfSendsToMaster() const;
    void incNumberOfSendsToMaster( int numberOfParticles );
};


#include "particles/State.cpph"

#endif
