// This file is part of the Peano project. For conditions of distribution and 
// use, please see the copyright notice at www.peano-framework.org
#ifndef _PARTICLES_PIDT_CELL_H_ 
#define _PARTICLES_PIDT_CELL_H_


#include "particles/pidt/records/Cell.h"
#include "peano/grid/Cell.h"


namespace particles { 
  namespace pidt { 
    class Cell;

    tarch::la::Vector<DIMENSIONS,int>  getDualVertexOfParticle(
      const tarch::la::Vector<DIMENSIONS,double>&  cellOffset,
      const tarch::la::Vector<DIMENSIONS,double>&  cellWidth,
      const tarch::la::Vector<DIMENSIONS,double>&  particlePosition
    );
  }
}


/**
 * PiDT Cell
 *
 * Is a pit cell with one exception: there's no index in this cell as heap data
 * is not associated with cells.
 * 
 * @author Tobias Weinzierl
 */
class particles::pidt::Cell: public peano::grid::Cell< particles::pidt::records::Cell > { 
  private: 
    typedef class peano::grid::Cell< particles::pidt::records::Cell >  Base;

    bool getThresholdVelocityForReductionSkip( double t, const tarch::la::Vector<DIMENSIONS,double>&  h ) const;
  public:
    /**
     * Default Constructor
     *
     * This constructor is required by the framework's data container. Do not 
     * remove it.
     */
    Cell();

    /**
     * This constructor should not set any attributes. It is used by the 
     * traversal algorithm whenever it allocates an array whose elements 
     * will be overwritten later anyway.  
     */
    Cell(const Base::DoNotCallStandardConstructor&);

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
    Cell(const Base::PersistentCell& argument);

    /**
     * Clear number of particles in children
     *
     * This transition function is used to analyse the number of particles
     * bottom-up along the tree. It resets the number of children particles.
     * If the cell is refined, this reset basically passes 0. If the
     * operation is called for an unrefined cell, the argument typically
     * equals the number of particles contained in the leaf cell.
     */
    void clearNumberOfParticlesInChildren(int particles);

    /**
     * Reduction
     *
     * For the passed child cell, tell the current object to take the
     * particles contained there into account. This is the operation
     * realising the accumulative reduction.
     */
    void incNumberOfParticlesInChildren(const Cell& childCell);

    /**
     * Return number of particles
     *
     * For a leaf, this operation returns the particles contained within
     * the leaf. For a refined cell, it returns the particles contained
     * within all children. The latter is a recursive definition.
     *
     * @return Number of particles contained in the present cell volume.
     */
    int getNumberOfParticlesInChildren() const;

    /**
     * We may do this only on the finest level.
     */
    void setMaxVComponent( double value );
    void clearMaxVComponent();
    void restrictMaxVComponent(const Cell& childCell);
    void updateMaxVComponentDueToDrop( double value );

    void updateMaxVComponentDueToReductionSkip(double t, const tarch::la::Vector<DIMENSIONS,double>&  h);
    bool cellWillLiftParticleInNextTimeStep( double t, const tarch::la::Vector<DIMENSIONS,double>&  h ) const;
};


#endif
