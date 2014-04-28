#include "particles/Particles.h"


int particles::getNumberOfParticles(
  const tarch::la::Vector<DIMENSIONS,double>&  h,
  double maximumParticlesPerUnitVolume
) {
  const double result = tarch::la::volume(h) * maximumParticlesPerUnitVolume;
  return static_cast<int>( std::floor(result+0.5) );
}


bool particles::controlPointIsInsideParticleDomain(
  const tarch::la::Vector<DIMENSIONS,double>&  x,
  const double&                                d
) {
  return
    tarch::la::allGreaterEquals(x,SizeOfHaloLayer) &&
    tarch::la::allSmallerEquals(x,1.0-SizeOfHaloLayer) &&
    tarch::la::allSmallerEquals(x,d+ SizeOfHaloLayer);
}
