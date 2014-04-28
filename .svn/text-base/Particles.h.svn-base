#ifndef __PARTICLES__
#define __PARTICLES__


#include "tarch/la/Vector.h"
#include "peano/utils/Dimensions.h"


namespace particles {
  const int MaxLevels = 20;

  /**
   * In the parallel case, we sqeeze a small halo layer into the unit square
   * and reflect the particles at this halo layer. As a result, the particles
   * never collide with the unit square's boundary and there is no need to
   * resolve this boundary too fine. If rank 0 now deployes the domain to other
   * ranks, it does not have to resolve too much of the boundary and the
   * communication is reduced.
   */
  #ifdef Parallel
  const double SizeOfHaloLayer = 1.0/9.0;
  #else
  const double SizeOfHaloLayer = 0.0;
  #endif

  /**
   * @param x   Position of control point
   * @param d   Dam width
   */
  bool    controlPointIsInsideParticleDomain(
    const tarch::la::Vector<DIMENSIONS,double>&  x,
    const double&                                d
  );

  /**
   * Number of particles that fit into a cell of given mesh width.
   */
  int     getNumberOfParticles(const tarch::la::Vector<DIMENSIONS,double>&  h, double maximumParticlesPerUnitVolume);
}


#endif
