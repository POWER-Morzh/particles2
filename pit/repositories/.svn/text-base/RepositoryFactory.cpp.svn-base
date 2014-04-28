#include "particles/pit/repositories/RepositoryFactory.h"

#include "particles/pit/repositories/RepositoryArrayStack.h"
#include "particles/pit/repositories/RepositorySTDStack.h"

#include "particles/pit/records/RepositoryState.h"

#ifdef Parallel
#include "tarch/parallel/NodePool.h"
#include "peano/parallel/Partitioner.h"
#endif


particles::pit::repositories::RepositoryFactory::RepositoryFactory() {
  #ifdef Parallel
  peano::parallel::Partitioner::initDatatypes();

  particles::pit::State::initDatatype();
  particles::pit::Vertex::initDatatype();
  particles::pit::Cell::initDatatype();

  if (particles::pit::records::RepositoryState::Datatype==0) {
    particles::pit::records::RepositoryState::initDatatype();
  }
  #endif
}


particles::pit::repositories::RepositoryFactory::~RepositoryFactory() {
}


void particles::pit::repositories::RepositoryFactory::shutdownAllParallelDatatypes() {
  #ifdef Parallel
  peano::parallel::Partitioner::shutdownDatatypes();

  particles::pit::State::shutdownDatatype();
  particles::pit::Vertex::shutdownDatatype();
  particles::pit::Cell::shutdownDatatype();

  if (particles::pit::records::RepositoryState::Datatype!=0) {
    particles::pit::records::RepositoryState::shutdownDatatype();
    particles::pit::records::RepositoryState::Datatype = 0;
  }
  #endif
}


particles::pit::repositories::RepositoryFactory& particles::pit::repositories::RepositoryFactory::getInstance() {
  static particles::pit::repositories::RepositoryFactory singleton;
  return singleton;
}

    
particles::pit::repositories::Repository* 
particles::pit::repositories::RepositoryFactory::createWithArrayStackImplementation(
  peano::geometry::Geometry&                   geometry,
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset,
  int                                          maxCellStackSize,    
  int                                          maxVertexStackSize,    
  int                                          maxTemporaryVertexStackSize    
) {
  #ifdef Parallel
  if (!tarch::parallel::Node::getInstance().isGlobalMaster()) {
    return new particles::pit::repositories::RepositoryArrayStack(geometry, domainSize, computationalDomainOffset,maxCellStackSize,maxVertexStackSize,maxTemporaryVertexStackSize);
  }
  else
  #endif
  return new particles::pit::repositories::RepositoryArrayStack(geometry, domainSize, computationalDomainOffset,maxCellStackSize,maxVertexStackSize,maxTemporaryVertexStackSize);
}    


particles::pit::repositories::Repository* 
particles::pit::repositories::RepositoryFactory::createWithSTDStackImplementation(
  peano::geometry::Geometry&                   geometry,
  const tarch::la::Vector<DIMENSIONS,double>&  domainSize,
  const tarch::la::Vector<DIMENSIONS,double>&  computationalDomainOffset
) {
  #ifdef Parallel
  if (!tarch::parallel::Node::getInstance().isGlobalMaster()) {
    return new particles::pit::repositories::RepositorySTDStack(geometry);
  }
  else
  #endif
  return new particles::pit::repositories::RepositorySTDStack(geometry, domainSize, computationalDomainOffset);
}
