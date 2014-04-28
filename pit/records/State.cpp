#include "particles/pit/records/State.h"

#if defined(Parallel)
   particles::pit::records::State::PersistentRecords::PersistentRecords() {
      
   }
   
   
   particles::pit::records::State::PersistentRecords::PersistentRecords(const int& minimalNumberOfParticlesPerCell, const double& timeStepSize, const double& maximalNumberOfInitialParticlesPerUnitVolume, const double& maximalInitialVelocity, const double& breakingDamWidth, const double& numberOfLifts, const double& numberOfParticlesInLeaves, const tarch::la::Vector<MaxLevels,double>& liftsPerLevel, const double& accumulatedDensity, const double& nonEmptyLeaves, const double& particlesSentToMaster, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const double& numberOfInnerLeafVertices, const double& numberOfBoundaryLeafVertices, const double& numberOfOuterLeafVertices, const double& numberOfInnerLeafCells, const double& numberOfOuterLeafCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted, const bool& reduceStateAndCell, const bool& couldNotEraseDueToDecompositionFlag, const bool& subWorkerIsInvolvedInJoinOrFork):
   _minimalNumberOfParticlesPerCell(minimalNumberOfParticlesPerCell),
   _timeStepSize(timeStepSize),
   _maximalNumberOfInitialParticlesPerUnitVolume(maximalNumberOfInitialParticlesPerUnitVolume),
   _maximalInitialVelocity(maximalInitialVelocity),
   _breakingDamWidth(breakingDamWidth),
   _numberOfLifts(numberOfLifts),
   _numberOfParticlesInLeaves(numberOfParticlesInLeaves),
   _liftsPerLevel(liftsPerLevel),
   _accumulatedDensity(accumulatedDensity),
   _nonEmptyLeaves(nonEmptyLeaves),
   _particlesSentToMaster(particlesSentToMaster),
   _minMeshWidth(minMeshWidth),
   _maxMeshWidth(maxMeshWidth),
   _numberOfInnerVertices(numberOfInnerVertices),
   _numberOfBoundaryVertices(numberOfBoundaryVertices),
   _numberOfOuterVertices(numberOfOuterVertices),
   _numberOfInnerCells(numberOfInnerCells),
   _numberOfOuterCells(numberOfOuterCells),
   _numberOfInnerLeafVertices(numberOfInnerLeafVertices),
   _numberOfBoundaryLeafVertices(numberOfBoundaryLeafVertices),
   _numberOfOuterLeafVertices(numberOfOuterLeafVertices),
   _numberOfInnerLeafCells(numberOfInnerLeafCells),
   _numberOfOuterLeafCells(numberOfOuterLeafCells),
   _maxLevel(maxLevel),
   _hasRefined(hasRefined),
   _hasTriggeredRefinementForNextIteration(hasTriggeredRefinementForNextIteration),
   _hasErased(hasErased),
   _hasTriggeredEraseForNextIteration(hasTriggeredEraseForNextIteration),
   _hasChangedVertexOrCellState(hasChangedVertexOrCellState),
   _isTraversalInverted(isTraversalInverted),
   _reduceStateAndCell(reduceStateAndCell),
   _couldNotEraseDueToDecompositionFlag(couldNotEraseDueToDecompositionFlag),
   _subWorkerIsInvolvedInJoinOrFork(subWorkerIsInvolvedInJoinOrFork) {
      
   }
   
   particles::pit::records::State::State() {
      
   }
   
   
   particles::pit::records::State::State(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._minimalNumberOfParticlesPerCell, persistentRecords._timeStepSize, persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume, persistentRecords._maximalInitialVelocity, persistentRecords._breakingDamWidth, persistentRecords._numberOfLifts, persistentRecords._numberOfParticlesInLeaves, persistentRecords._liftsPerLevel, persistentRecords._accumulatedDensity, persistentRecords._nonEmptyLeaves, persistentRecords._particlesSentToMaster, persistentRecords._minMeshWidth, persistentRecords._maxMeshWidth, persistentRecords._numberOfInnerVertices, persistentRecords._numberOfBoundaryVertices, persistentRecords._numberOfOuterVertices, persistentRecords._numberOfInnerCells, persistentRecords._numberOfOuterCells, persistentRecords._numberOfInnerLeafVertices, persistentRecords._numberOfBoundaryLeafVertices, persistentRecords._numberOfOuterLeafVertices, persistentRecords._numberOfInnerLeafCells, persistentRecords._numberOfOuterLeafCells, persistentRecords._maxLevel, persistentRecords._hasRefined, persistentRecords._hasTriggeredRefinementForNextIteration, persistentRecords._hasErased, persistentRecords._hasTriggeredEraseForNextIteration, persistentRecords._hasChangedVertexOrCellState, persistentRecords._isTraversalInverted, persistentRecords._reduceStateAndCell, persistentRecords._couldNotEraseDueToDecompositionFlag, persistentRecords._subWorkerIsInvolvedInJoinOrFork) {
      
   }
   
   
   particles::pit::records::State::State(const int& minimalNumberOfParticlesPerCell, const double& timeStepSize, const double& maximalNumberOfInitialParticlesPerUnitVolume, const double& maximalInitialVelocity, const double& breakingDamWidth, const double& numberOfLifts, const double& numberOfParticlesInLeaves, const tarch::la::Vector<MaxLevels,double>& liftsPerLevel, const double& accumulatedDensity, const double& nonEmptyLeaves, const double& particlesSentToMaster, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const double& numberOfInnerLeafVertices, const double& numberOfBoundaryLeafVertices, const double& numberOfOuterLeafVertices, const double& numberOfInnerLeafCells, const double& numberOfOuterLeafCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted, const bool& reduceStateAndCell, const bool& couldNotEraseDueToDecompositionFlag, const bool& subWorkerIsInvolvedInJoinOrFork):
   _persistentRecords(minimalNumberOfParticlesPerCell, timeStepSize, maximalNumberOfInitialParticlesPerUnitVolume, maximalInitialVelocity, breakingDamWidth, numberOfLifts, numberOfParticlesInLeaves, liftsPerLevel, accumulatedDensity, nonEmptyLeaves, particlesSentToMaster, minMeshWidth, maxMeshWidth, numberOfInnerVertices, numberOfBoundaryVertices, numberOfOuterVertices, numberOfInnerCells, numberOfOuterCells, numberOfInnerLeafVertices, numberOfBoundaryLeafVertices, numberOfOuterLeafVertices, numberOfInnerLeafCells, numberOfOuterLeafCells, maxLevel, hasRefined, hasTriggeredRefinementForNextIteration, hasErased, hasTriggeredEraseForNextIteration, hasChangedVertexOrCellState, isTraversalInverted, reduceStateAndCell, couldNotEraseDueToDecompositionFlag, subWorkerIsInvolvedInJoinOrFork) {
      
   }
   
   
   particles::pit::records::State::~State() { }
   
   
   
   std::string particles::pit::records::State::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void particles::pit::records::State::toString (std::ostream& out) const {
      out << "("; 
      out << "minimalNumberOfParticlesPerCell:" << getMinimalNumberOfParticlesPerCell();
      out << ",";
      out << "timeStepSize:" << getTimeStepSize();
      out << ",";
      out << "maximalNumberOfInitialParticlesPerUnitVolume:" << getMaximalNumberOfInitialParticlesPerUnitVolume();
      out << ",";
      out << "maximalInitialVelocity:" << getMaximalInitialVelocity();
      out << ",";
      out << "breakingDamWidth:" << getBreakingDamWidth();
      out << ",";
      out << "numberOfLifts:" << getNumberOfLifts();
      out << ",";
      out << "numberOfParticlesInLeaves:" << getNumberOfParticlesInLeaves();
      out << ",";
      out << "liftsPerLevel:[";
   for (int i = 0; i < MaxLevels-1; i++) {
      out << getLiftsPerLevel(i) << ",";
   }
   out << getLiftsPerLevel(MaxLevels-1) << "]";
      out << ",";
      out << "accumulatedDensity:" << getAccumulatedDensity();
      out << ",";
      out << "nonEmptyLeaves:" << getNonEmptyLeaves();
      out << ",";
      out << "particlesSentToMaster:" << getParticlesSentToMaster();
      out << ",";
      out << "minMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMinMeshWidth(i) << ",";
   }
   out << getMinMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "maxMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMaxMeshWidth(i) << ",";
   }
   out << getMaxMeshWidth(DIMENSIONS-1) << "]";
      out << ",";
      out << "numberOfInnerVertices:" << getNumberOfInnerVertices();
      out << ",";
      out << "numberOfBoundaryVertices:" << getNumberOfBoundaryVertices();
      out << ",";
      out << "numberOfOuterVertices:" << getNumberOfOuterVertices();
      out << ",";
      out << "numberOfInnerCells:" << getNumberOfInnerCells();
      out << ",";
      out << "numberOfOuterCells:" << getNumberOfOuterCells();
      out << ",";
      out << "numberOfInnerLeafVertices:" << getNumberOfInnerLeafVertices();
      out << ",";
      out << "numberOfBoundaryLeafVertices:" << getNumberOfBoundaryLeafVertices();
      out << ",";
      out << "numberOfOuterLeafVertices:" << getNumberOfOuterLeafVertices();
      out << ",";
      out << "numberOfInnerLeafCells:" << getNumberOfInnerLeafCells();
      out << ",";
      out << "numberOfOuterLeafCells:" << getNumberOfOuterLeafCells();
      out << ",";
      out << "maxLevel:" << getMaxLevel();
      out << ",";
      out << "hasRefined:" << getHasRefined();
      out << ",";
      out << "hasTriggeredRefinementForNextIteration:" << getHasTriggeredRefinementForNextIteration();
      out << ",";
      out << "hasErased:" << getHasErased();
      out << ",";
      out << "hasTriggeredEraseForNextIteration:" << getHasTriggeredEraseForNextIteration();
      out << ",";
      out << "hasChangedVertexOrCellState:" << getHasChangedVertexOrCellState();
      out << ",";
      out << "isTraversalInverted:" << getIsTraversalInverted();
      out << ",";
      out << "reduceStateAndCell:" << getReduceStateAndCell();
      out << ",";
      out << "couldNotEraseDueToDecompositionFlag:" << getCouldNotEraseDueToDecompositionFlag();
      out << ",";
      out << "subWorkerIsInvolvedInJoinOrFork:" << getSubWorkerIsInvolvedInJoinOrFork();
      out <<  ")";
   }
   
   
   particles::pit::records::State::PersistentRecords particles::pit::records::State::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   particles::pit::records::StatePacked particles::pit::records::State::convert() const{
      return StatePacked(
         getMinimalNumberOfParticlesPerCell(),
         getTimeStepSize(),
         getMaximalNumberOfInitialParticlesPerUnitVolume(),
         getMaximalInitialVelocity(),
         getBreakingDamWidth(),
         getNumberOfLifts(),
         getNumberOfParticlesInLeaves(),
         getLiftsPerLevel(),
         getAccumulatedDensity(),
         getNonEmptyLeaves(),
         getParticlesSentToMaster(),
         getMinMeshWidth(),
         getMaxMeshWidth(),
         getNumberOfInnerVertices(),
         getNumberOfBoundaryVertices(),
         getNumberOfOuterVertices(),
         getNumberOfInnerCells(),
         getNumberOfOuterCells(),
         getNumberOfInnerLeafVertices(),
         getNumberOfBoundaryLeafVertices(),
         getNumberOfOuterLeafVertices(),
         getNumberOfInnerLeafCells(),
         getNumberOfOuterLeafCells(),
         getMaxLevel(),
         getHasRefined(),
         getHasTriggeredRefinementForNextIteration(),
         getHasErased(),
         getHasTriggeredEraseForNextIteration(),
         getHasChangedVertexOrCellState(),
         getIsTraversalInverted(),
         getReduceStateAndCell(),
         getCouldNotEraseDueToDecompositionFlag(),
         getSubWorkerIsInvolvedInJoinOrFork()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log particles::pit::records::State::_log( "particles::pit::records::State" );
      
      MPI_Datatype particles::pit::records::State::Datatype = 0;
      MPI_Datatype particles::pit::records::State::FullDatatype = 0;
      
      
      void particles::pit::records::State::initDatatype() {
         {
            State dummyState[2];
            
            const int Attributes = 34;
            MPI_Datatype subtypes[Attributes] = {
               MPI_INT,		 //minimalNumberOfParticlesPerCell
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //maximalNumberOfInitialParticlesPerUnitVolume
               MPI_DOUBLE,		 //maximalInitialVelocity
               MPI_DOUBLE,		 //breakingDamWidth
               MPI_DOUBLE,		 //numberOfLifts
               MPI_DOUBLE,		 //numberOfParticlesInLeaves
               MPI_DOUBLE,		 //liftsPerLevel
               MPI_DOUBLE,		 //accumulatedDensity
               MPI_DOUBLE,		 //nonEmptyLeaves
               MPI_DOUBLE,		 //particlesSentToMaster
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_DOUBLE,		 //numberOfInnerLeafVertices
               MPI_DOUBLE,		 //numberOfBoundaryLeafVertices
               MPI_DOUBLE,		 //numberOfOuterLeafVertices
               MPI_DOUBLE,		 //numberOfInnerLeafCells
               MPI_DOUBLE,		 //numberOfOuterLeafCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //hasRefined
               MPI_CHAR,		 //hasTriggeredRefinementForNextIteration
               MPI_CHAR,		 //hasErased
               MPI_CHAR,		 //hasTriggeredEraseForNextIteration
               MPI_CHAR,		 //hasChangedVertexOrCellState
               MPI_CHAR,		 //isTraversalInverted
               MPI_CHAR,		 //reduceStateAndCell
               MPI_CHAR,		 //couldNotEraseDueToDecompositionFlag
               MPI_CHAR,		 //subWorkerIsInvolvedInJoinOrFork
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //minimalNumberOfParticlesPerCell
               1,		 //timeStepSize
               1,		 //maximalNumberOfInitialParticlesPerUnitVolume
               1,		 //maximalInitialVelocity
               1,		 //breakingDamWidth
               1,		 //numberOfLifts
               1,		 //numberOfParticlesInLeaves
               MaxLevels,		 //liftsPerLevel
               1,		 //accumulatedDensity
               1,		 //nonEmptyLeaves
               1,		 //particlesSentToMaster
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //numberOfInnerLeafVertices
               1,		 //numberOfBoundaryLeafVertices
               1,		 //numberOfOuterLeafVertices
               1,		 //numberOfInnerLeafCells
               1,		 //numberOfOuterLeafCells
               1,		 //maxLevel
               1,		 //hasRefined
               1,		 //hasTriggeredRefinementForNextIteration
               1,		 //hasErased
               1,		 //hasTriggeredEraseForNextIteration
               1,		 //hasChangedVertexOrCellState
               1,		 //isTraversalInverted
               1,		 //reduceStateAndCell
               1,		 //couldNotEraseDueToDecompositionFlag
               1,		 //subWorkerIsInvolvedInJoinOrFork
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStepSize))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maximalInitialVelocity))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._breakingDamWidth))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfLifts))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfParticlesInLeaves))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._liftsPerLevel[0]))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._accumulatedDensity))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._nonEmptyLeaves))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._particlesSentToMaster))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minMeshWidth[0]))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterVertices))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerCells))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterCells))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerLeafVertices))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryLeafVertices))), 		&disp[19] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterLeafVertices))), 		&disp[20] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerLeafCells))), 		&disp[21] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterLeafCells))), 		&disp[22] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxLevel))), 		&disp[23] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasRefined))), 		&disp[24] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredRefinementForNextIteration))), 		&disp[25] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasErased))), 		&disp[26] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredEraseForNextIteration))), 		&disp[27] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasChangedVertexOrCellState))), 		&disp[28] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._isTraversalInverted))), 		&disp[29] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._reduceStateAndCell))), 		&disp[30] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._couldNotEraseDueToDecompositionFlag))), 		&disp[31] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._subWorkerIsInvolvedInJoinOrFork))), 		&disp[32] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[1]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[33] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &State::Datatype );
            MPI_Type_commit( &State::Datatype );
            
         }
         {
            State dummyState[2];
            
            const int Attributes = 34;
            MPI_Datatype subtypes[Attributes] = {
               MPI_INT,		 //minimalNumberOfParticlesPerCell
               MPI_DOUBLE,		 //timeStepSize
               MPI_DOUBLE,		 //maximalNumberOfInitialParticlesPerUnitVolume
               MPI_DOUBLE,		 //maximalInitialVelocity
               MPI_DOUBLE,		 //breakingDamWidth
               MPI_DOUBLE,		 //numberOfLifts
               MPI_DOUBLE,		 //numberOfParticlesInLeaves
               MPI_DOUBLE,		 //liftsPerLevel
               MPI_DOUBLE,		 //accumulatedDensity
               MPI_DOUBLE,		 //nonEmptyLeaves
               MPI_DOUBLE,		 //particlesSentToMaster
               MPI_DOUBLE,		 //minMeshWidth
               MPI_DOUBLE,		 //maxMeshWidth
               MPI_DOUBLE,		 //numberOfInnerVertices
               MPI_DOUBLE,		 //numberOfBoundaryVertices
               MPI_DOUBLE,		 //numberOfOuterVertices
               MPI_DOUBLE,		 //numberOfInnerCells
               MPI_DOUBLE,		 //numberOfOuterCells
               MPI_DOUBLE,		 //numberOfInnerLeafVertices
               MPI_DOUBLE,		 //numberOfBoundaryLeafVertices
               MPI_DOUBLE,		 //numberOfOuterLeafVertices
               MPI_DOUBLE,		 //numberOfInnerLeafCells
               MPI_DOUBLE,		 //numberOfOuterLeafCells
               MPI_INT,		 //maxLevel
               MPI_CHAR,		 //hasRefined
               MPI_CHAR,		 //hasTriggeredRefinementForNextIteration
               MPI_CHAR,		 //hasErased
               MPI_CHAR,		 //hasTriggeredEraseForNextIteration
               MPI_CHAR,		 //hasChangedVertexOrCellState
               MPI_CHAR,		 //isTraversalInverted
               MPI_CHAR,		 //reduceStateAndCell
               MPI_CHAR,		 //couldNotEraseDueToDecompositionFlag
               MPI_CHAR,		 //subWorkerIsInvolvedInJoinOrFork
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //minimalNumberOfParticlesPerCell
               1,		 //timeStepSize
               1,		 //maximalNumberOfInitialParticlesPerUnitVolume
               1,		 //maximalInitialVelocity
               1,		 //breakingDamWidth
               1,		 //numberOfLifts
               1,		 //numberOfParticlesInLeaves
               MaxLevels,		 //liftsPerLevel
               1,		 //accumulatedDensity
               1,		 //nonEmptyLeaves
               1,		 //particlesSentToMaster
               DIMENSIONS,		 //minMeshWidth
               DIMENSIONS,		 //maxMeshWidth
               1,		 //numberOfInnerVertices
               1,		 //numberOfBoundaryVertices
               1,		 //numberOfOuterVertices
               1,		 //numberOfInnerCells
               1,		 //numberOfOuterCells
               1,		 //numberOfInnerLeafVertices
               1,		 //numberOfBoundaryLeafVertices
               1,		 //numberOfOuterLeafVertices
               1,		 //numberOfInnerLeafCells
               1,		 //numberOfOuterLeafCells
               1,		 //maxLevel
               1,		 //hasRefined
               1,		 //hasTriggeredRefinementForNextIteration
               1,		 //hasErased
               1,		 //hasTriggeredEraseForNextIteration
               1,		 //hasChangedVertexOrCellState
               1,		 //isTraversalInverted
               1,		 //reduceStateAndCell
               1,		 //couldNotEraseDueToDecompositionFlag
               1,		 //subWorkerIsInvolvedInJoinOrFork
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStepSize))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maximalInitialVelocity))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._breakingDamWidth))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfLifts))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfParticlesInLeaves))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._liftsPerLevel[0]))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._accumulatedDensity))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._nonEmptyLeaves))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._particlesSentToMaster))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minMeshWidth[0]))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerVertices))), 		&disp[13] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[14] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterVertices))), 		&disp[15] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerCells))), 		&disp[16] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterCells))), 		&disp[17] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerLeafVertices))), 		&disp[18] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryLeafVertices))), 		&disp[19] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterLeafVertices))), 		&disp[20] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerLeafCells))), 		&disp[21] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterLeafCells))), 		&disp[22] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxLevel))), 		&disp[23] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasRefined))), 		&disp[24] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredRefinementForNextIteration))), 		&disp[25] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasErased))), 		&disp[26] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredEraseForNextIteration))), 		&disp[27] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasChangedVertexOrCellState))), 		&disp[28] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._isTraversalInverted))), 		&disp[29] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._reduceStateAndCell))), 		&disp[30] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._couldNotEraseDueToDecompositionFlag))), 		&disp[31] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._subWorkerIsInvolvedInJoinOrFork))), 		&disp[32] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[1]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[33] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &State::FullDatatype );
            MPI_Type_commit( &State::FullDatatype );
            
         }
         
      }
      
      
      void particles::pit::records::State::shutdownDatatype() {
         MPI_Type_free( &State::Datatype );
         MPI_Type_free( &State::FullDatatype );
         
      }
      
      void particles::pit::records::State::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
         _senderDestinationRank = destination;
         
         if (communicateBlocking) {
         
            const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
            if  (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "was not able to send message particles::pit::records::State "
               << toString()
               << " to node " << destination
               << ": " << tarch::parallel::MPIReturnValueToString(result);
               _log.error( "send(int)",msg.str() );
            }
            
         }
         else {
         
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Isend(
               this, 1, Datatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         else {
            result = MPI_Isend(
               this, 1, FullDatatype, destination,
               tag, tarch::parallel::Node::getInstance().getCommunicator(),
               sendRequestHandle
            );
            
         }
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pit::records::State "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished send task for particles::pit::records::State "
               << toString()
               << " sent to node " << destination
               << " failed: " << tarch::parallel::MPIReturnValueToString(result);
               _log.error("send(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "particles::pit::records::State",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pit::records::State",
               "send(int)", destination,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         #ifdef Debug
         _log.debug("send(int,int)", "sent " + toString() );
         #endif
         
      }
      
   }
   
   
   
   void particles::pit::records::State::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         MPI_Status  status;
         const int   result = MPI_Recv(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
         _senderDestinationRank = status.MPI_SOURCE;
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pit::records::State from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
      }
      else {
      
         MPI_Request* sendRequestHandle = new MPI_Request();
         MPI_Status   status;
         int          flag = 0;
         int          result;
         
         clock_t      timeOutWarning   = -1;
         clock_t      timeOutShutdown  = -1;
         bool         triggeredTimeoutWarning = false;
         
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            result = MPI_Irecv(
               this, 1, Datatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         else {
            result = MPI_Irecv(
               this, 1, FullDatatype, source, tag,
               tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
            );
            
         }
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pit::records::State from node "
            << source << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "receive(int)", msg.str() );
         }
         
         result = MPI_Test( sendRequestHandle, &flag, &status );
         while (!flag) {
            if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
            if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
            result = MPI_Test( sendRequestHandle, &flag, &status );
            if (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "testing for finished receive task for particles::pit::records::State failed: "
               << tarch::parallel::MPIReturnValueToString(result);
               _log.error("receive(int)", msg.str() );
            }
            
            // deadlock aspect
            if (
               tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
               (clock()>timeOutWarning) &&
               (!triggeredTimeoutWarning)
            ) {
               tarch::parallel::Node::getInstance().writeTimeOutWarning(
               "particles::pit::records::State",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pit::records::State",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         _senderDestinationRank = status.MPI_SOURCE;
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
   }
   
   
   
   bool particles::pit::records::State::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
      MPI_Status status;
      int  flag        = 0;
      MPI_Iprobe(
         MPI_ANY_SOURCE, tag,
         tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
      );
      if (flag) {
         int  messageCounter;
         if (exchangeOnlyAttributesMarkedWithParallelise) {
            MPI_Get_count(&status, Datatype, &messageCounter);
         }
         else {
            MPI_Get_count(&status, FullDatatype, &messageCounter);
         }
         return messageCounter > 0;
      }
      else return false;
      
   }
   
   int particles::pit::records::State::getSenderRank() const {
      assertion( _senderDestinationRank!=-1 );
      return _senderDestinationRank;
      
   }
#endif


particles::pit::records::StatePacked::PersistentRecords::PersistentRecords() {
   assertion((8 < (8 * sizeof(short int))));
   
}


particles::pit::records::StatePacked::PersistentRecords::PersistentRecords(const int& minimalNumberOfParticlesPerCell, const double& timeStepSize, const double& maximalNumberOfInitialParticlesPerUnitVolume, const double& maximalInitialVelocity, const double& breakingDamWidth, const double& numberOfLifts, const double& numberOfParticlesInLeaves, const tarch::la::Vector<MaxLevels,double>& liftsPerLevel, const double& accumulatedDensity, const double& nonEmptyLeaves, const double& particlesSentToMaster, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const double& numberOfInnerLeafVertices, const double& numberOfBoundaryLeafVertices, const double& numberOfOuterLeafVertices, const double& numberOfInnerLeafCells, const double& numberOfOuterLeafCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted, const bool& reduceStateAndCell, const bool& couldNotEraseDueToDecompositionFlag, const bool& subWorkerIsInvolvedInJoinOrFork):
_minimalNumberOfParticlesPerCell(minimalNumberOfParticlesPerCell),
_timeStepSize(timeStepSize),
_maximalNumberOfInitialParticlesPerUnitVolume(maximalNumberOfInitialParticlesPerUnitVolume),
_maximalInitialVelocity(maximalInitialVelocity),
_breakingDamWidth(breakingDamWidth),
_numberOfLifts(numberOfLifts),
_numberOfParticlesInLeaves(numberOfParticlesInLeaves),
_liftsPerLevel(liftsPerLevel),
_accumulatedDensity(accumulatedDensity),
_nonEmptyLeaves(nonEmptyLeaves),
_particlesSentToMaster(particlesSentToMaster),
_minMeshWidth(minMeshWidth),
_maxMeshWidth(maxMeshWidth),
_numberOfInnerVertices(numberOfInnerVertices),
_numberOfBoundaryVertices(numberOfBoundaryVertices),
_numberOfOuterVertices(numberOfOuterVertices),
_numberOfInnerCells(numberOfInnerCells),
_numberOfOuterCells(numberOfOuterCells),
_numberOfInnerLeafVertices(numberOfInnerLeafVertices),
_numberOfBoundaryLeafVertices(numberOfBoundaryLeafVertices),
_numberOfOuterLeafVertices(numberOfOuterLeafVertices),
_numberOfInnerLeafCells(numberOfInnerLeafCells),
_numberOfOuterLeafCells(numberOfOuterLeafCells),
_maxLevel(maxLevel),
_isTraversalInverted(isTraversalInverted) {
   setHasRefined(hasRefined);
   setHasTriggeredRefinementForNextIteration(hasTriggeredRefinementForNextIteration);
   setHasErased(hasErased);
   setHasTriggeredEraseForNextIteration(hasTriggeredEraseForNextIteration);
   setHasChangedVertexOrCellState(hasChangedVertexOrCellState);
   setReduceStateAndCell(reduceStateAndCell);
   setCouldNotEraseDueToDecompositionFlag(couldNotEraseDueToDecompositionFlag);
   setSubWorkerIsInvolvedInJoinOrFork(subWorkerIsInvolvedInJoinOrFork);
   assertion((8 < (8 * sizeof(short int))));
   
}

particles::pit::records::StatePacked::StatePacked() {
   assertion((8 < (8 * sizeof(short int))));
   
}


particles::pit::records::StatePacked::StatePacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._minimalNumberOfParticlesPerCell, persistentRecords._timeStepSize, persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume, persistentRecords._maximalInitialVelocity, persistentRecords._breakingDamWidth, persistentRecords._numberOfLifts, persistentRecords._numberOfParticlesInLeaves, persistentRecords._liftsPerLevel, persistentRecords._accumulatedDensity, persistentRecords._nonEmptyLeaves, persistentRecords._particlesSentToMaster, persistentRecords._minMeshWidth, persistentRecords._maxMeshWidth, persistentRecords._numberOfInnerVertices, persistentRecords._numberOfBoundaryVertices, persistentRecords._numberOfOuterVertices, persistentRecords._numberOfInnerCells, persistentRecords._numberOfOuterCells, persistentRecords._numberOfInnerLeafVertices, persistentRecords._numberOfBoundaryLeafVertices, persistentRecords._numberOfOuterLeafVertices, persistentRecords._numberOfInnerLeafCells, persistentRecords._numberOfOuterLeafCells, persistentRecords._maxLevel, persistentRecords.getHasRefined(), persistentRecords.getHasTriggeredRefinementForNextIteration(), persistentRecords.getHasErased(), persistentRecords.getHasTriggeredEraseForNextIteration(), persistentRecords.getHasChangedVertexOrCellState(), persistentRecords._isTraversalInverted, persistentRecords.getReduceStateAndCell(), persistentRecords.getCouldNotEraseDueToDecompositionFlag(), persistentRecords.getSubWorkerIsInvolvedInJoinOrFork()) {
   assertion((8 < (8 * sizeof(short int))));
   
}


particles::pit::records::StatePacked::StatePacked(const int& minimalNumberOfParticlesPerCell, const double& timeStepSize, const double& maximalNumberOfInitialParticlesPerUnitVolume, const double& maximalInitialVelocity, const double& breakingDamWidth, const double& numberOfLifts, const double& numberOfParticlesInLeaves, const tarch::la::Vector<MaxLevels,double>& liftsPerLevel, const double& accumulatedDensity, const double& nonEmptyLeaves, const double& particlesSentToMaster, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const double& numberOfInnerLeafVertices, const double& numberOfBoundaryLeafVertices, const double& numberOfOuterLeafVertices, const double& numberOfInnerLeafCells, const double& numberOfOuterLeafCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted, const bool& reduceStateAndCell, const bool& couldNotEraseDueToDecompositionFlag, const bool& subWorkerIsInvolvedInJoinOrFork):
_persistentRecords(minimalNumberOfParticlesPerCell, timeStepSize, maximalNumberOfInitialParticlesPerUnitVolume, maximalInitialVelocity, breakingDamWidth, numberOfLifts, numberOfParticlesInLeaves, liftsPerLevel, accumulatedDensity, nonEmptyLeaves, particlesSentToMaster, minMeshWidth, maxMeshWidth, numberOfInnerVertices, numberOfBoundaryVertices, numberOfOuterVertices, numberOfInnerCells, numberOfOuterCells, numberOfInnerLeafVertices, numberOfBoundaryLeafVertices, numberOfOuterLeafVertices, numberOfInnerLeafCells, numberOfOuterLeafCells, maxLevel, hasRefined, hasTriggeredRefinementForNextIteration, hasErased, hasTriggeredEraseForNextIteration, hasChangedVertexOrCellState, isTraversalInverted, reduceStateAndCell, couldNotEraseDueToDecompositionFlag, subWorkerIsInvolvedInJoinOrFork) {
   assertion((8 < (8 * sizeof(short int))));
   
}


particles::pit::records::StatePacked::~StatePacked() { }



std::string particles::pit::records::StatePacked::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void particles::pit::records::StatePacked::toString (std::ostream& out) const {
   out << "("; 
   out << "minimalNumberOfParticlesPerCell:" << getMinimalNumberOfParticlesPerCell();
   out << ",";
   out << "timeStepSize:" << getTimeStepSize();
   out << ",";
   out << "maximalNumberOfInitialParticlesPerUnitVolume:" << getMaximalNumberOfInitialParticlesPerUnitVolume();
   out << ",";
   out << "maximalInitialVelocity:" << getMaximalInitialVelocity();
   out << ",";
   out << "breakingDamWidth:" << getBreakingDamWidth();
   out << ",";
   out << "numberOfLifts:" << getNumberOfLifts();
   out << ",";
   out << "numberOfParticlesInLeaves:" << getNumberOfParticlesInLeaves();
   out << ",";
   out << "liftsPerLevel:[";
   for (int i = 0; i < MaxLevels-1; i++) {
      out << getLiftsPerLevel(i) << ",";
   }
   out << getLiftsPerLevel(MaxLevels-1) << "]";
   out << ",";
   out << "accumulatedDensity:" << getAccumulatedDensity();
   out << ",";
   out << "nonEmptyLeaves:" << getNonEmptyLeaves();
   out << ",";
   out << "particlesSentToMaster:" << getParticlesSentToMaster();
   out << ",";
   out << "minMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMinMeshWidth(i) << ",";
   }
   out << getMinMeshWidth(DIMENSIONS-1) << "]";
   out << ",";
   out << "maxMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMaxMeshWidth(i) << ",";
   }
   out << getMaxMeshWidth(DIMENSIONS-1) << "]";
   out << ",";
   out << "numberOfInnerVertices:" << getNumberOfInnerVertices();
   out << ",";
   out << "numberOfBoundaryVertices:" << getNumberOfBoundaryVertices();
   out << ",";
   out << "numberOfOuterVertices:" << getNumberOfOuterVertices();
   out << ",";
   out << "numberOfInnerCells:" << getNumberOfInnerCells();
   out << ",";
   out << "numberOfOuterCells:" << getNumberOfOuterCells();
   out << ",";
   out << "numberOfInnerLeafVertices:" << getNumberOfInnerLeafVertices();
   out << ",";
   out << "numberOfBoundaryLeafVertices:" << getNumberOfBoundaryLeafVertices();
   out << ",";
   out << "numberOfOuterLeafVertices:" << getNumberOfOuterLeafVertices();
   out << ",";
   out << "numberOfInnerLeafCells:" << getNumberOfInnerLeafCells();
   out << ",";
   out << "numberOfOuterLeafCells:" << getNumberOfOuterLeafCells();
   out << ",";
   out << "maxLevel:" << getMaxLevel();
   out << ",";
   out << "hasRefined:" << getHasRefined();
   out << ",";
   out << "hasTriggeredRefinementForNextIteration:" << getHasTriggeredRefinementForNextIteration();
   out << ",";
   out << "hasErased:" << getHasErased();
   out << ",";
   out << "hasTriggeredEraseForNextIteration:" << getHasTriggeredEraseForNextIteration();
   out << ",";
   out << "hasChangedVertexOrCellState:" << getHasChangedVertexOrCellState();
   out << ",";
   out << "isTraversalInverted:" << getIsTraversalInverted();
   out << ",";
   out << "reduceStateAndCell:" << getReduceStateAndCell();
   out << ",";
   out << "couldNotEraseDueToDecompositionFlag:" << getCouldNotEraseDueToDecompositionFlag();
   out << ",";
   out << "subWorkerIsInvolvedInJoinOrFork:" << getSubWorkerIsInvolvedInJoinOrFork();
   out <<  ")";
}


particles::pit::records::StatePacked::PersistentRecords particles::pit::records::StatePacked::getPersistentRecords() const {
   return _persistentRecords;
}

particles::pit::records::State particles::pit::records::StatePacked::convert() const{
   return State(
      getMinimalNumberOfParticlesPerCell(),
      getTimeStepSize(),
      getMaximalNumberOfInitialParticlesPerUnitVolume(),
      getMaximalInitialVelocity(),
      getBreakingDamWidth(),
      getNumberOfLifts(),
      getNumberOfParticlesInLeaves(),
      getLiftsPerLevel(),
      getAccumulatedDensity(),
      getNonEmptyLeaves(),
      getParticlesSentToMaster(),
      getMinMeshWidth(),
      getMaxMeshWidth(),
      getNumberOfInnerVertices(),
      getNumberOfBoundaryVertices(),
      getNumberOfOuterVertices(),
      getNumberOfInnerCells(),
      getNumberOfOuterCells(),
      getNumberOfInnerLeafVertices(),
      getNumberOfBoundaryLeafVertices(),
      getNumberOfOuterLeafVertices(),
      getNumberOfInnerLeafCells(),
      getNumberOfOuterLeafCells(),
      getMaxLevel(),
      getHasRefined(),
      getHasTriggeredRefinementForNextIteration(),
      getHasErased(),
      getHasTriggeredEraseForNextIteration(),
      getHasChangedVertexOrCellState(),
      getIsTraversalInverted(),
      getReduceStateAndCell(),
      getCouldNotEraseDueToDecompositionFlag(),
      getSubWorkerIsInvolvedInJoinOrFork()
   );
}

#ifdef Parallel
   tarch::logging::Log particles::pit::records::StatePacked::_log( "particles::pit::records::StatePacked" );
   
   MPI_Datatype particles::pit::records::StatePacked::Datatype = 0;
   MPI_Datatype particles::pit::records::StatePacked::FullDatatype = 0;
   
   
   void particles::pit::records::StatePacked::initDatatype() {
      {
         StatePacked dummyStatePacked[2];
         
         const int Attributes = 27;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //minimalNumberOfParticlesPerCell
            MPI_DOUBLE,		 //timeStepSize
            MPI_DOUBLE,		 //maximalNumberOfInitialParticlesPerUnitVolume
            MPI_DOUBLE,		 //maximalInitialVelocity
            MPI_DOUBLE,		 //breakingDamWidth
            MPI_DOUBLE,		 //numberOfLifts
            MPI_DOUBLE,		 //numberOfParticlesInLeaves
            MPI_DOUBLE,		 //liftsPerLevel
            MPI_DOUBLE,		 //accumulatedDensity
            MPI_DOUBLE,		 //nonEmptyLeaves
            MPI_DOUBLE,		 //particlesSentToMaster
            MPI_DOUBLE,		 //minMeshWidth
            MPI_DOUBLE,		 //maxMeshWidth
            MPI_DOUBLE,		 //numberOfInnerVertices
            MPI_DOUBLE,		 //numberOfBoundaryVertices
            MPI_DOUBLE,		 //numberOfOuterVertices
            MPI_DOUBLE,		 //numberOfInnerCells
            MPI_DOUBLE,		 //numberOfOuterCells
            MPI_DOUBLE,		 //numberOfInnerLeafVertices
            MPI_DOUBLE,		 //numberOfBoundaryLeafVertices
            MPI_DOUBLE,		 //numberOfOuterLeafVertices
            MPI_DOUBLE,		 //numberOfInnerLeafCells
            MPI_DOUBLE,		 //numberOfOuterLeafCells
            MPI_INT,		 //maxLevel
            MPI_CHAR,		 //isTraversalInverted
            MPI_SHORT,		 //_packedRecords0
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //minimalNumberOfParticlesPerCell
            1,		 //timeStepSize
            1,		 //maximalNumberOfInitialParticlesPerUnitVolume
            1,		 //maximalInitialVelocity
            1,		 //breakingDamWidth
            1,		 //numberOfLifts
            1,		 //numberOfParticlesInLeaves
            MaxLevels,		 //liftsPerLevel
            1,		 //accumulatedDensity
            1,		 //nonEmptyLeaves
            1,		 //particlesSentToMaster
            DIMENSIONS,		 //minMeshWidth
            DIMENSIONS,		 //maxMeshWidth
            1,		 //numberOfInnerVertices
            1,		 //numberOfBoundaryVertices
            1,		 //numberOfOuterVertices
            1,		 //numberOfInnerCells
            1,		 //numberOfOuterCells
            1,		 //numberOfInnerLeafVertices
            1,		 //numberOfBoundaryLeafVertices
            1,		 //numberOfOuterLeafVertices
            1,		 //numberOfInnerLeafCells
            1,		 //numberOfOuterLeafCells
            1,		 //maxLevel
            1,		 //isTraversalInverted
            1,		 //_packedRecords0
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStepSize))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maximalInitialVelocity))), 		&disp[3] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._breakingDamWidth))), 		&disp[4] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfLifts))), 		&disp[5] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfParticlesInLeaves))), 		&disp[6] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._liftsPerLevel[0]))), 		&disp[7] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._accumulatedDensity))), 		&disp[8] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._nonEmptyLeaves))), 		&disp[9] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._particlesSentToMaster))), 		&disp[10] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minMeshWidth[0]))), 		&disp[11] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[12] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerVertices))), 		&disp[13] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[14] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterVertices))), 		&disp[15] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerCells))), 		&disp[16] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterCells))), 		&disp[17] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerLeafVertices))), 		&disp[18] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryLeafVertices))), 		&disp[19] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterLeafVertices))), 		&disp[20] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerLeafCells))), 		&disp[21] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterLeafCells))), 		&disp[22] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxLevel))), 		&disp[23] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._isTraversalInverted))), 		&disp[24] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._packedRecords0))), 		&disp[25] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[1]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[26] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &StatePacked::Datatype );
         MPI_Type_commit( &StatePacked::Datatype );
         
      }
      {
         StatePacked dummyStatePacked[2];
         
         const int Attributes = 27;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //minimalNumberOfParticlesPerCell
            MPI_DOUBLE,		 //timeStepSize
            MPI_DOUBLE,		 //maximalNumberOfInitialParticlesPerUnitVolume
            MPI_DOUBLE,		 //maximalInitialVelocity
            MPI_DOUBLE,		 //breakingDamWidth
            MPI_DOUBLE,		 //numberOfLifts
            MPI_DOUBLE,		 //numberOfParticlesInLeaves
            MPI_DOUBLE,		 //liftsPerLevel
            MPI_DOUBLE,		 //accumulatedDensity
            MPI_DOUBLE,		 //nonEmptyLeaves
            MPI_DOUBLE,		 //particlesSentToMaster
            MPI_DOUBLE,		 //minMeshWidth
            MPI_DOUBLE,		 //maxMeshWidth
            MPI_DOUBLE,		 //numberOfInnerVertices
            MPI_DOUBLE,		 //numberOfBoundaryVertices
            MPI_DOUBLE,		 //numberOfOuterVertices
            MPI_DOUBLE,		 //numberOfInnerCells
            MPI_DOUBLE,		 //numberOfOuterCells
            MPI_DOUBLE,		 //numberOfInnerLeafVertices
            MPI_DOUBLE,		 //numberOfBoundaryLeafVertices
            MPI_DOUBLE,		 //numberOfOuterLeafVertices
            MPI_DOUBLE,		 //numberOfInnerLeafCells
            MPI_DOUBLE,		 //numberOfOuterLeafCells
            MPI_INT,		 //maxLevel
            MPI_CHAR,		 //isTraversalInverted
            MPI_SHORT,		 //_packedRecords0
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //minimalNumberOfParticlesPerCell
            1,		 //timeStepSize
            1,		 //maximalNumberOfInitialParticlesPerUnitVolume
            1,		 //maximalInitialVelocity
            1,		 //breakingDamWidth
            1,		 //numberOfLifts
            1,		 //numberOfParticlesInLeaves
            MaxLevels,		 //liftsPerLevel
            1,		 //accumulatedDensity
            1,		 //nonEmptyLeaves
            1,		 //particlesSentToMaster
            DIMENSIONS,		 //minMeshWidth
            DIMENSIONS,		 //maxMeshWidth
            1,		 //numberOfInnerVertices
            1,		 //numberOfBoundaryVertices
            1,		 //numberOfOuterVertices
            1,		 //numberOfInnerCells
            1,		 //numberOfOuterCells
            1,		 //numberOfInnerLeafVertices
            1,		 //numberOfBoundaryLeafVertices
            1,		 //numberOfOuterLeafVertices
            1,		 //numberOfInnerLeafCells
            1,		 //numberOfOuterLeafCells
            1,		 //maxLevel
            1,		 //isTraversalInverted
            1,		 //_packedRecords0
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStepSize))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maximalInitialVelocity))), 		&disp[3] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._breakingDamWidth))), 		&disp[4] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfLifts))), 		&disp[5] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfParticlesInLeaves))), 		&disp[6] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._liftsPerLevel[0]))), 		&disp[7] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._accumulatedDensity))), 		&disp[8] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._nonEmptyLeaves))), 		&disp[9] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._particlesSentToMaster))), 		&disp[10] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minMeshWidth[0]))), 		&disp[11] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[12] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerVertices))), 		&disp[13] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[14] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterVertices))), 		&disp[15] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerCells))), 		&disp[16] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterCells))), 		&disp[17] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerLeafVertices))), 		&disp[18] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryLeafVertices))), 		&disp[19] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterLeafVertices))), 		&disp[20] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerLeafCells))), 		&disp[21] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterLeafCells))), 		&disp[22] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxLevel))), 		&disp[23] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._isTraversalInverted))), 		&disp[24] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._packedRecords0))), 		&disp[25] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[1]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[26] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &StatePacked::FullDatatype );
         MPI_Type_commit( &StatePacked::FullDatatype );
         
      }
      
   }
   
   
   void particles::pit::records::StatePacked::shutdownDatatype() {
      MPI_Type_free( &StatePacked::Datatype );
      MPI_Type_free( &StatePacked::FullDatatype );
      
   }
   
   void particles::pit::records::StatePacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      _senderDestinationRank = destination;
      
      if (communicateBlocking) {
      
         const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pit::records::StatePacked "
            << toString()
            << " to node " << destination
            << ": " << tarch::parallel::MPIReturnValueToString(result);
            _log.error( "send(int)",msg.str() );
         }
         
      }
      else {
      
      MPI_Request* sendRequestHandle = new MPI_Request();
      MPI_Status   status;
      int          flag = 0;
      int          result;
      
      clock_t      timeOutWarning   = -1;
      clock_t      timeOutShutdown  = -1;
      bool         triggeredTimeoutWarning = false;
      
      if (exchangeOnlyAttributesMarkedWithParallelise) {
         result = MPI_Isend(
            this, 1, Datatype, destination,
            tag, tarch::parallel::Node::getInstance().getCommunicator(),
            sendRequestHandle
         );
         
      }
      else {
         result = MPI_Isend(
            this, 1, FullDatatype, destination,
            tag, tarch::parallel::Node::getInstance().getCommunicator(),
            sendRequestHandle
         );
         
      }
      if  (result!=MPI_SUCCESS) {
         std::ostringstream msg;
         msg << "was not able to send message particles::pit::records::StatePacked "
         << toString()
         << " to node " << destination
         << ": " << tarch::parallel::MPIReturnValueToString(result);
         _log.error( "send(int)",msg.str() );
      }
      result = MPI_Test( sendRequestHandle, &flag, &status );
      while (!flag) {
         if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
         if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
         result = MPI_Test( sendRequestHandle, &flag, &status );
         if (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "testing for finished send task for particles::pit::records::StatePacked "
            << toString()
            << " sent to node " << destination
            << " failed: " << tarch::parallel::MPIReturnValueToString(result);
            _log.error("send(int)", msg.str() );
         }
         
         // deadlock aspect
         if (
            tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
            (clock()>timeOutWarning) &&
            (!triggeredTimeoutWarning)
         ) {
            tarch::parallel::Node::getInstance().writeTimeOutWarning(
            "particles::pit::records::StatePacked",
            "send(int)", destination,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "particles::pit::records::StatePacked",
            "send(int)", destination,tag,1
            );
         }
         tarch::parallel::Node::getInstance().receiveDanglingMessages();
      }
      
      delete sendRequestHandle;
      #ifdef Debug
      _log.debug("send(int,int)", "sent " + toString() );
      #endif
      
   }
   
}



void particles::pit::records::StatePacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
   if (communicateBlocking) {
   
      MPI_Status  status;
      const int   result = MPI_Recv(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
      _senderDestinationRank = status.MPI_SOURCE;
      if ( result != MPI_SUCCESS ) {
         std::ostringstream msg;
         msg << "failed to start to receive particles::pit::records::StatePacked from node "
         << source << ": " << tarch::parallel::MPIReturnValueToString(result);
         _log.error( "receive(int)", msg.str() );
      }
      
   }
   else {
   
      MPI_Request* sendRequestHandle = new MPI_Request();
      MPI_Status   status;
      int          flag = 0;
      int          result;
      
      clock_t      timeOutWarning   = -1;
      clock_t      timeOutShutdown  = -1;
      bool         triggeredTimeoutWarning = false;
      
      if (exchangeOnlyAttributesMarkedWithParallelise) {
         result = MPI_Irecv(
            this, 1, Datatype, source, tag,
            tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
         );
         
      }
      else {
         result = MPI_Irecv(
            this, 1, FullDatatype, source, tag,
            tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
         );
         
      }
      if ( result != MPI_SUCCESS ) {
         std::ostringstream msg;
         msg << "failed to start to receive particles::pit::records::StatePacked from node "
         << source << ": " << tarch::parallel::MPIReturnValueToString(result);
         _log.error( "receive(int)", msg.str() );
      }
      
      result = MPI_Test( sendRequestHandle, &flag, &status );
      while (!flag) {
         if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
         if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
         result = MPI_Test( sendRequestHandle, &flag, &status );
         if (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "testing for finished receive task for particles::pit::records::StatePacked failed: "
            << tarch::parallel::MPIReturnValueToString(result);
            _log.error("receive(int)", msg.str() );
         }
         
         // deadlock aspect
         if (
            tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
            (clock()>timeOutWarning) &&
            (!triggeredTimeoutWarning)
         ) {
            tarch::parallel::Node::getInstance().writeTimeOutWarning(
            "particles::pit::records::StatePacked",
            "receive(int)", source,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "particles::pit::records::StatePacked",
            "receive(int)", source,tag,1
            );
         }
         tarch::parallel::Node::getInstance().receiveDanglingMessages();
      }
      
      delete sendRequestHandle;
      
      _senderDestinationRank = status.MPI_SOURCE;
      #ifdef Debug
      _log.debug("receive(int,int)", "received " + toString() ); 
      #endif
      
   }
   
}



bool particles::pit::records::StatePacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
   MPI_Status status;
   int  flag        = 0;
   MPI_Iprobe(
      MPI_ANY_SOURCE, tag,
      tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
   );
   if (flag) {
      int  messageCounter;
      if (exchangeOnlyAttributesMarkedWithParallelise) {
         MPI_Get_count(&status, Datatype, &messageCounter);
      }
      else {
         MPI_Get_count(&status, FullDatatype, &messageCounter);
      }
      return messageCounter > 0;
   }
   else return false;
   
}

int particles::pit::records::StatePacked::getSenderRank() const {
   assertion( _senderDestinationRank!=-1 );
   return _senderDestinationRank;
   
}
#endif



#elif !defined(Parallel)
particles::pit::records::State::PersistentRecords::PersistentRecords() {

}


particles::pit::records::State::PersistentRecords::PersistentRecords(const int& minimalNumberOfParticlesPerCell, const double& timeStepSize, const double& maximalNumberOfInitialParticlesPerUnitVolume, const double& maximalInitialVelocity, const double& breakingDamWidth, const double& numberOfLifts, const double& numberOfParticlesInLeaves, const tarch::la::Vector<MaxLevels,double>& liftsPerLevel, const double& accumulatedDensity, const double& nonEmptyLeaves, const double& particlesSentToMaster, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const double& numberOfInnerLeafVertices, const double& numberOfBoundaryLeafVertices, const double& numberOfOuterLeafVertices, const double& numberOfInnerLeafCells, const double& numberOfOuterLeafCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted):
_minimalNumberOfParticlesPerCell(minimalNumberOfParticlesPerCell),
_timeStepSize(timeStepSize),
_maximalNumberOfInitialParticlesPerUnitVolume(maximalNumberOfInitialParticlesPerUnitVolume),
_maximalInitialVelocity(maximalInitialVelocity),
_breakingDamWidth(breakingDamWidth),
_numberOfLifts(numberOfLifts),
_numberOfParticlesInLeaves(numberOfParticlesInLeaves),
_liftsPerLevel(liftsPerLevel),
_accumulatedDensity(accumulatedDensity),
_nonEmptyLeaves(nonEmptyLeaves),
_particlesSentToMaster(particlesSentToMaster),
_minMeshWidth(minMeshWidth),
_maxMeshWidth(maxMeshWidth),
_numberOfInnerVertices(numberOfInnerVertices),
_numberOfBoundaryVertices(numberOfBoundaryVertices),
_numberOfOuterVertices(numberOfOuterVertices),
_numberOfInnerCells(numberOfInnerCells),
_numberOfOuterCells(numberOfOuterCells),
_numberOfInnerLeafVertices(numberOfInnerLeafVertices),
_numberOfBoundaryLeafVertices(numberOfBoundaryLeafVertices),
_numberOfOuterLeafVertices(numberOfOuterLeafVertices),
_numberOfInnerLeafCells(numberOfInnerLeafCells),
_numberOfOuterLeafCells(numberOfOuterLeafCells),
_maxLevel(maxLevel),
_hasRefined(hasRefined),
_hasTriggeredRefinementForNextIteration(hasTriggeredRefinementForNextIteration),
_hasErased(hasErased),
_hasTriggeredEraseForNextIteration(hasTriggeredEraseForNextIteration),
_hasChangedVertexOrCellState(hasChangedVertexOrCellState),
_isTraversalInverted(isTraversalInverted) {

}

particles::pit::records::State::State() {

}


particles::pit::records::State::State(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._minimalNumberOfParticlesPerCell, persistentRecords._timeStepSize, persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume, persistentRecords._maximalInitialVelocity, persistentRecords._breakingDamWidth, persistentRecords._numberOfLifts, persistentRecords._numberOfParticlesInLeaves, persistentRecords._liftsPerLevel, persistentRecords._accumulatedDensity, persistentRecords._nonEmptyLeaves, persistentRecords._particlesSentToMaster, persistentRecords._minMeshWidth, persistentRecords._maxMeshWidth, persistentRecords._numberOfInnerVertices, persistentRecords._numberOfBoundaryVertices, persistentRecords._numberOfOuterVertices, persistentRecords._numberOfInnerCells, persistentRecords._numberOfOuterCells, persistentRecords._numberOfInnerLeafVertices, persistentRecords._numberOfBoundaryLeafVertices, persistentRecords._numberOfOuterLeafVertices, persistentRecords._numberOfInnerLeafCells, persistentRecords._numberOfOuterLeafCells, persistentRecords._maxLevel, persistentRecords._hasRefined, persistentRecords._hasTriggeredRefinementForNextIteration, persistentRecords._hasErased, persistentRecords._hasTriggeredEraseForNextIteration, persistentRecords._hasChangedVertexOrCellState, persistentRecords._isTraversalInverted) {

}


particles::pit::records::State::State(const int& minimalNumberOfParticlesPerCell, const double& timeStepSize, const double& maximalNumberOfInitialParticlesPerUnitVolume, const double& maximalInitialVelocity, const double& breakingDamWidth, const double& numberOfLifts, const double& numberOfParticlesInLeaves, const tarch::la::Vector<MaxLevels,double>& liftsPerLevel, const double& accumulatedDensity, const double& nonEmptyLeaves, const double& particlesSentToMaster, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const double& numberOfInnerLeafVertices, const double& numberOfBoundaryLeafVertices, const double& numberOfOuterLeafVertices, const double& numberOfInnerLeafCells, const double& numberOfOuterLeafCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted):
_persistentRecords(minimalNumberOfParticlesPerCell, timeStepSize, maximalNumberOfInitialParticlesPerUnitVolume, maximalInitialVelocity, breakingDamWidth, numberOfLifts, numberOfParticlesInLeaves, liftsPerLevel, accumulatedDensity, nonEmptyLeaves, particlesSentToMaster, minMeshWidth, maxMeshWidth, numberOfInnerVertices, numberOfBoundaryVertices, numberOfOuterVertices, numberOfInnerCells, numberOfOuterCells, numberOfInnerLeafVertices, numberOfBoundaryLeafVertices, numberOfOuterLeafVertices, numberOfInnerLeafCells, numberOfOuterLeafCells, maxLevel, hasRefined, hasTriggeredRefinementForNextIteration, hasErased, hasTriggeredEraseForNextIteration, hasChangedVertexOrCellState, isTraversalInverted) {

}


particles::pit::records::State::~State() { }



std::string particles::pit::records::State::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pit::records::State::toString (std::ostream& out) const {
out << "("; 
out << "minimalNumberOfParticlesPerCell:" << getMinimalNumberOfParticlesPerCell();
out << ",";
out << "timeStepSize:" << getTimeStepSize();
out << ",";
out << "maximalNumberOfInitialParticlesPerUnitVolume:" << getMaximalNumberOfInitialParticlesPerUnitVolume();
out << ",";
out << "maximalInitialVelocity:" << getMaximalInitialVelocity();
out << ",";
out << "breakingDamWidth:" << getBreakingDamWidth();
out << ",";
out << "numberOfLifts:" << getNumberOfLifts();
out << ",";
out << "numberOfParticlesInLeaves:" << getNumberOfParticlesInLeaves();
out << ",";
out << "liftsPerLevel:[";
   for (int i = 0; i < MaxLevels-1; i++) {
      out << getLiftsPerLevel(i) << ",";
   }
   out << getLiftsPerLevel(MaxLevels-1) << "]";
out << ",";
out << "accumulatedDensity:" << getAccumulatedDensity();
out << ",";
out << "nonEmptyLeaves:" << getNonEmptyLeaves();
out << ",";
out << "particlesSentToMaster:" << getParticlesSentToMaster();
out << ",";
out << "minMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMinMeshWidth(i) << ",";
   }
   out << getMinMeshWidth(DIMENSIONS-1) << "]";
out << ",";
out << "maxMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMaxMeshWidth(i) << ",";
   }
   out << getMaxMeshWidth(DIMENSIONS-1) << "]";
out << ",";
out << "numberOfInnerVertices:" << getNumberOfInnerVertices();
out << ",";
out << "numberOfBoundaryVertices:" << getNumberOfBoundaryVertices();
out << ",";
out << "numberOfOuterVertices:" << getNumberOfOuterVertices();
out << ",";
out << "numberOfInnerCells:" << getNumberOfInnerCells();
out << ",";
out << "numberOfOuterCells:" << getNumberOfOuterCells();
out << ",";
out << "numberOfInnerLeafVertices:" << getNumberOfInnerLeafVertices();
out << ",";
out << "numberOfBoundaryLeafVertices:" << getNumberOfBoundaryLeafVertices();
out << ",";
out << "numberOfOuterLeafVertices:" << getNumberOfOuterLeafVertices();
out << ",";
out << "numberOfInnerLeafCells:" << getNumberOfInnerLeafCells();
out << ",";
out << "numberOfOuterLeafCells:" << getNumberOfOuterLeafCells();
out << ",";
out << "maxLevel:" << getMaxLevel();
out << ",";
out << "hasRefined:" << getHasRefined();
out << ",";
out << "hasTriggeredRefinementForNextIteration:" << getHasTriggeredRefinementForNextIteration();
out << ",";
out << "hasErased:" << getHasErased();
out << ",";
out << "hasTriggeredEraseForNextIteration:" << getHasTriggeredEraseForNextIteration();
out << ",";
out << "hasChangedVertexOrCellState:" << getHasChangedVertexOrCellState();
out << ",";
out << "isTraversalInverted:" << getIsTraversalInverted();
out <<  ")";
}


particles::pit::records::State::PersistentRecords particles::pit::records::State::getPersistentRecords() const {
return _persistentRecords;
}

particles::pit::records::StatePacked particles::pit::records::State::convert() const{
return StatePacked(
   getMinimalNumberOfParticlesPerCell(),
   getTimeStepSize(),
   getMaximalNumberOfInitialParticlesPerUnitVolume(),
   getMaximalInitialVelocity(),
   getBreakingDamWidth(),
   getNumberOfLifts(),
   getNumberOfParticlesInLeaves(),
   getLiftsPerLevel(),
   getAccumulatedDensity(),
   getNonEmptyLeaves(),
   getParticlesSentToMaster(),
   getMinMeshWidth(),
   getMaxMeshWidth(),
   getNumberOfInnerVertices(),
   getNumberOfBoundaryVertices(),
   getNumberOfOuterVertices(),
   getNumberOfInnerCells(),
   getNumberOfOuterCells(),
   getNumberOfInnerLeafVertices(),
   getNumberOfBoundaryLeafVertices(),
   getNumberOfOuterLeafVertices(),
   getNumberOfInnerLeafCells(),
   getNumberOfOuterLeafCells(),
   getMaxLevel(),
   getHasRefined(),
   getHasTriggeredRefinementForNextIteration(),
   getHasErased(),
   getHasTriggeredEraseForNextIteration(),
   getHasChangedVertexOrCellState(),
   getIsTraversalInverted()
);
}

#ifdef Parallel
tarch::logging::Log particles::pit::records::State::_log( "particles::pit::records::State" );

MPI_Datatype particles::pit::records::State::Datatype = 0;
MPI_Datatype particles::pit::records::State::FullDatatype = 0;


void particles::pit::records::State::initDatatype() {
   {
      State dummyState[2];
      
      const int Attributes = 31;
      MPI_Datatype subtypes[Attributes] = {
         MPI_INT,		 //minimalNumberOfParticlesPerCell
         MPI_DOUBLE,		 //timeStepSize
         MPI_DOUBLE,		 //maximalNumberOfInitialParticlesPerUnitVolume
         MPI_DOUBLE,		 //maximalInitialVelocity
         MPI_DOUBLE,		 //breakingDamWidth
         MPI_DOUBLE,		 //numberOfLifts
         MPI_DOUBLE,		 //numberOfParticlesInLeaves
         MPI_DOUBLE,		 //liftsPerLevel
         MPI_DOUBLE,		 //accumulatedDensity
         MPI_DOUBLE,		 //nonEmptyLeaves
         MPI_DOUBLE,		 //particlesSentToMaster
         MPI_DOUBLE,		 //minMeshWidth
         MPI_DOUBLE,		 //maxMeshWidth
         MPI_DOUBLE,		 //numberOfInnerVertices
         MPI_DOUBLE,		 //numberOfBoundaryVertices
         MPI_DOUBLE,		 //numberOfOuterVertices
         MPI_DOUBLE,		 //numberOfInnerCells
         MPI_DOUBLE,		 //numberOfOuterCells
         MPI_DOUBLE,		 //numberOfInnerLeafVertices
         MPI_DOUBLE,		 //numberOfBoundaryLeafVertices
         MPI_DOUBLE,		 //numberOfOuterLeafVertices
         MPI_DOUBLE,		 //numberOfInnerLeafCells
         MPI_DOUBLE,		 //numberOfOuterLeafCells
         MPI_INT,		 //maxLevel
         MPI_CHAR,		 //hasRefined
         MPI_CHAR,		 //hasTriggeredRefinementForNextIteration
         MPI_CHAR,		 //hasErased
         MPI_CHAR,		 //hasTriggeredEraseForNextIteration
         MPI_CHAR,		 //hasChangedVertexOrCellState
         MPI_CHAR,		 //isTraversalInverted
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         1,		 //minimalNumberOfParticlesPerCell
         1,		 //timeStepSize
         1,		 //maximalNumberOfInitialParticlesPerUnitVolume
         1,		 //maximalInitialVelocity
         1,		 //breakingDamWidth
         1,		 //numberOfLifts
         1,		 //numberOfParticlesInLeaves
         MaxLevels,		 //liftsPerLevel
         1,		 //accumulatedDensity
         1,		 //nonEmptyLeaves
         1,		 //particlesSentToMaster
         DIMENSIONS,		 //minMeshWidth
         DIMENSIONS,		 //maxMeshWidth
         1,		 //numberOfInnerVertices
         1,		 //numberOfBoundaryVertices
         1,		 //numberOfOuterVertices
         1,		 //numberOfInnerCells
         1,		 //numberOfOuterCells
         1,		 //numberOfInnerLeafVertices
         1,		 //numberOfBoundaryLeafVertices
         1,		 //numberOfOuterLeafVertices
         1,		 //numberOfInnerLeafCells
         1,		 //numberOfOuterLeafCells
         1,		 //maxLevel
         1,		 //hasRefined
         1,		 //hasTriggeredRefinementForNextIteration
         1,		 //hasErased
         1,		 //hasTriggeredEraseForNextIteration
         1,		 //hasChangedVertexOrCellState
         1,		 //isTraversalInverted
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStepSize))), 		&disp[1] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume))), 		&disp[2] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maximalInitialVelocity))), 		&disp[3] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._breakingDamWidth))), 		&disp[4] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfLifts))), 		&disp[5] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfParticlesInLeaves))), 		&disp[6] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._liftsPerLevel[0]))), 		&disp[7] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._accumulatedDensity))), 		&disp[8] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._nonEmptyLeaves))), 		&disp[9] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._particlesSentToMaster))), 		&disp[10] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minMeshWidth[0]))), 		&disp[11] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[12] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerVertices))), 		&disp[13] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[14] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterVertices))), 		&disp[15] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerCells))), 		&disp[16] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterCells))), 		&disp[17] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerLeafVertices))), 		&disp[18] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryLeafVertices))), 		&disp[19] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterLeafVertices))), 		&disp[20] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerLeafCells))), 		&disp[21] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterLeafCells))), 		&disp[22] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxLevel))), 		&disp[23] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasRefined))), 		&disp[24] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredRefinementForNextIteration))), 		&disp[25] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasErased))), 		&disp[26] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredEraseForNextIteration))), 		&disp[27] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasChangedVertexOrCellState))), 		&disp[28] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._isTraversalInverted))), 		&disp[29] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[1]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[30] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &State::Datatype );
      MPI_Type_commit( &State::Datatype );
      
   }
   {
      State dummyState[2];
      
      const int Attributes = 31;
      MPI_Datatype subtypes[Attributes] = {
         MPI_INT,		 //minimalNumberOfParticlesPerCell
         MPI_DOUBLE,		 //timeStepSize
         MPI_DOUBLE,		 //maximalNumberOfInitialParticlesPerUnitVolume
         MPI_DOUBLE,		 //maximalInitialVelocity
         MPI_DOUBLE,		 //breakingDamWidth
         MPI_DOUBLE,		 //numberOfLifts
         MPI_DOUBLE,		 //numberOfParticlesInLeaves
         MPI_DOUBLE,		 //liftsPerLevel
         MPI_DOUBLE,		 //accumulatedDensity
         MPI_DOUBLE,		 //nonEmptyLeaves
         MPI_DOUBLE,		 //particlesSentToMaster
         MPI_DOUBLE,		 //minMeshWidth
         MPI_DOUBLE,		 //maxMeshWidth
         MPI_DOUBLE,		 //numberOfInnerVertices
         MPI_DOUBLE,		 //numberOfBoundaryVertices
         MPI_DOUBLE,		 //numberOfOuterVertices
         MPI_DOUBLE,		 //numberOfInnerCells
         MPI_DOUBLE,		 //numberOfOuterCells
         MPI_DOUBLE,		 //numberOfInnerLeafVertices
         MPI_DOUBLE,		 //numberOfBoundaryLeafVertices
         MPI_DOUBLE,		 //numberOfOuterLeafVertices
         MPI_DOUBLE,		 //numberOfInnerLeafCells
         MPI_DOUBLE,		 //numberOfOuterLeafCells
         MPI_INT,		 //maxLevel
         MPI_CHAR,		 //hasRefined
         MPI_CHAR,		 //hasTriggeredRefinementForNextIteration
         MPI_CHAR,		 //hasErased
         MPI_CHAR,		 //hasTriggeredEraseForNextIteration
         MPI_CHAR,		 //hasChangedVertexOrCellState
         MPI_CHAR,		 //isTraversalInverted
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         1,		 //minimalNumberOfParticlesPerCell
         1,		 //timeStepSize
         1,		 //maximalNumberOfInitialParticlesPerUnitVolume
         1,		 //maximalInitialVelocity
         1,		 //breakingDamWidth
         1,		 //numberOfLifts
         1,		 //numberOfParticlesInLeaves
         MaxLevels,		 //liftsPerLevel
         1,		 //accumulatedDensity
         1,		 //nonEmptyLeaves
         1,		 //particlesSentToMaster
         DIMENSIONS,		 //minMeshWidth
         DIMENSIONS,		 //maxMeshWidth
         1,		 //numberOfInnerVertices
         1,		 //numberOfBoundaryVertices
         1,		 //numberOfOuterVertices
         1,		 //numberOfInnerCells
         1,		 //numberOfOuterCells
         1,		 //numberOfInnerLeafVertices
         1,		 //numberOfBoundaryLeafVertices
         1,		 //numberOfOuterLeafVertices
         1,		 //numberOfInnerLeafCells
         1,		 //numberOfOuterLeafCells
         1,		 //maxLevel
         1,		 //hasRefined
         1,		 //hasTriggeredRefinementForNextIteration
         1,		 //hasErased
         1,		 //hasTriggeredEraseForNextIteration
         1,		 //hasChangedVertexOrCellState
         1,		 //isTraversalInverted
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._timeStepSize))), 		&disp[1] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume))), 		&disp[2] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maximalInitialVelocity))), 		&disp[3] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._breakingDamWidth))), 		&disp[4] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfLifts))), 		&disp[5] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfParticlesInLeaves))), 		&disp[6] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._liftsPerLevel[0]))), 		&disp[7] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._accumulatedDensity))), 		&disp[8] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._nonEmptyLeaves))), 		&disp[9] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._particlesSentToMaster))), 		&disp[10] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._minMeshWidth[0]))), 		&disp[11] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[12] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerVertices))), 		&disp[13] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[14] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterVertices))), 		&disp[15] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerCells))), 		&disp[16] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterCells))), 		&disp[17] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerLeafVertices))), 		&disp[18] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfBoundaryLeafVertices))), 		&disp[19] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterLeafVertices))), 		&disp[20] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfInnerLeafCells))), 		&disp[21] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._numberOfOuterLeafCells))), 		&disp[22] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._maxLevel))), 		&disp[23] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasRefined))), 		&disp[24] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredRefinementForNextIteration))), 		&disp[25] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasErased))), 		&disp[26] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasTriggeredEraseForNextIteration))), 		&disp[27] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._hasChangedVertexOrCellState))), 		&disp[28] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[0]._persistentRecords._isTraversalInverted))), 		&disp[29] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyState[1]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[30] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &State::FullDatatype );
      MPI_Type_commit( &State::FullDatatype );
      
   }
   
}


void particles::pit::records::State::shutdownDatatype() {
   MPI_Type_free( &State::Datatype );
   MPI_Type_free( &State::FullDatatype );
   
}

void particles::pit::records::State::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
   _senderDestinationRank = destination;
   
   if (communicateBlocking) {
   
      const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
      if  (result!=MPI_SUCCESS) {
         std::ostringstream msg;
         msg << "was not able to send message particles::pit::records::State "
         << toString()
         << " to node " << destination
         << ": " << tarch::parallel::MPIReturnValueToString(result);
         _log.error( "send(int)",msg.str() );
      }
      
   }
   else {
   
   MPI_Request* sendRequestHandle = new MPI_Request();
   MPI_Status   status;
   int          flag = 0;
   int          result;
   
   clock_t      timeOutWarning   = -1;
   clock_t      timeOutShutdown  = -1;
   bool         triggeredTimeoutWarning = false;
   
   if (exchangeOnlyAttributesMarkedWithParallelise) {
      result = MPI_Isend(
         this, 1, Datatype, destination,
         tag, tarch::parallel::Node::getInstance().getCommunicator(),
         sendRequestHandle
      );
      
   }
   else {
      result = MPI_Isend(
         this, 1, FullDatatype, destination,
         tag, tarch::parallel::Node::getInstance().getCommunicator(),
         sendRequestHandle
      );
      
   }
   if  (result!=MPI_SUCCESS) {
      std::ostringstream msg;
      msg << "was not able to send message particles::pit::records::State "
      << toString()
      << " to node " << destination
      << ": " << tarch::parallel::MPIReturnValueToString(result);
      _log.error( "send(int)",msg.str() );
   }
   result = MPI_Test( sendRequestHandle, &flag, &status );
   while (!flag) {
      if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
      if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
      result = MPI_Test( sendRequestHandle, &flag, &status );
      if (result!=MPI_SUCCESS) {
         std::ostringstream msg;
         msg << "testing for finished send task for particles::pit::records::State "
         << toString()
         << " sent to node " << destination
         << " failed: " << tarch::parallel::MPIReturnValueToString(result);
         _log.error("send(int)", msg.str() );
      }
      
      // deadlock aspect
      if (
         tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
         (clock()>timeOutWarning) &&
         (!triggeredTimeoutWarning)
      ) {
         tarch::parallel::Node::getInstance().writeTimeOutWarning(
         "particles::pit::records::State",
         "send(int)", destination,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "particles::pit::records::State",
         "send(int)", destination,tag,1
         );
      }
      tarch::parallel::Node::getInstance().receiveDanglingMessages();
   }
   
   delete sendRequestHandle;
   #ifdef Debug
   _log.debug("send(int,int)", "sent " + toString() );
   #endif
   
}

}



void particles::pit::records::State::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

   MPI_Status  status;
   const int   result = MPI_Recv(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
   _senderDestinationRank = status.MPI_SOURCE;
   if ( result != MPI_SUCCESS ) {
      std::ostringstream msg;
      msg << "failed to start to receive particles::pit::records::State from node "
      << source << ": " << tarch::parallel::MPIReturnValueToString(result);
      _log.error( "receive(int)", msg.str() );
   }
   
}
else {

   MPI_Request* sendRequestHandle = new MPI_Request();
   MPI_Status   status;
   int          flag = 0;
   int          result;
   
   clock_t      timeOutWarning   = -1;
   clock_t      timeOutShutdown  = -1;
   bool         triggeredTimeoutWarning = false;
   
   if (exchangeOnlyAttributesMarkedWithParallelise) {
      result = MPI_Irecv(
         this, 1, Datatype, source, tag,
         tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
      );
      
   }
   else {
      result = MPI_Irecv(
         this, 1, FullDatatype, source, tag,
         tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
      );
      
   }
   if ( result != MPI_SUCCESS ) {
      std::ostringstream msg;
      msg << "failed to start to receive particles::pit::records::State from node "
      << source << ": " << tarch::parallel::MPIReturnValueToString(result);
      _log.error( "receive(int)", msg.str() );
   }
   
   result = MPI_Test( sendRequestHandle, &flag, &status );
   while (!flag) {
      if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
      if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
      result = MPI_Test( sendRequestHandle, &flag, &status );
      if (result!=MPI_SUCCESS) {
         std::ostringstream msg;
         msg << "testing for finished receive task for particles::pit::records::State failed: "
         << tarch::parallel::MPIReturnValueToString(result);
         _log.error("receive(int)", msg.str() );
      }
      
      // deadlock aspect
      if (
         tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
         (clock()>timeOutWarning) &&
         (!triggeredTimeoutWarning)
      ) {
         tarch::parallel::Node::getInstance().writeTimeOutWarning(
         "particles::pit::records::State",
         "receive(int)", source,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "particles::pit::records::State",
         "receive(int)", source,tag,1
         );
      }
      tarch::parallel::Node::getInstance().receiveDanglingMessages();
   }
   
   delete sendRequestHandle;
   
   _senderDestinationRank = status.MPI_SOURCE;
   #ifdef Debug
   _log.debug("receive(int,int)", "received " + toString() ); 
   #endif
   
}

}



bool particles::pit::records::State::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
MPI_Status status;
int  flag        = 0;
MPI_Iprobe(
   MPI_ANY_SOURCE, tag,
   tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
);
if (flag) {
   int  messageCounter;
   if (exchangeOnlyAttributesMarkedWithParallelise) {
      MPI_Get_count(&status, Datatype, &messageCounter);
   }
   else {
      MPI_Get_count(&status, FullDatatype, &messageCounter);
   }
   return messageCounter > 0;
}
else return false;

}

int particles::pit::records::State::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif


particles::pit::records::StatePacked::PersistentRecords::PersistentRecords() {
assertion((5 < (8 * sizeof(short int))));

}


particles::pit::records::StatePacked::PersistentRecords::PersistentRecords(const int& minimalNumberOfParticlesPerCell, const double& timeStepSize, const double& maximalNumberOfInitialParticlesPerUnitVolume, const double& maximalInitialVelocity, const double& breakingDamWidth, const double& numberOfLifts, const double& numberOfParticlesInLeaves, const tarch::la::Vector<MaxLevels,double>& liftsPerLevel, const double& accumulatedDensity, const double& nonEmptyLeaves, const double& particlesSentToMaster, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const double& numberOfInnerLeafVertices, const double& numberOfBoundaryLeafVertices, const double& numberOfOuterLeafVertices, const double& numberOfInnerLeafCells, const double& numberOfOuterLeafCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted):
_minimalNumberOfParticlesPerCell(minimalNumberOfParticlesPerCell),
_timeStepSize(timeStepSize),
_maximalNumberOfInitialParticlesPerUnitVolume(maximalNumberOfInitialParticlesPerUnitVolume),
_maximalInitialVelocity(maximalInitialVelocity),
_breakingDamWidth(breakingDamWidth),
_numberOfLifts(numberOfLifts),
_numberOfParticlesInLeaves(numberOfParticlesInLeaves),
_liftsPerLevel(liftsPerLevel),
_accumulatedDensity(accumulatedDensity),
_nonEmptyLeaves(nonEmptyLeaves),
_particlesSentToMaster(particlesSentToMaster),
_minMeshWidth(minMeshWidth),
_maxMeshWidth(maxMeshWidth),
_numberOfInnerVertices(numberOfInnerVertices),
_numberOfBoundaryVertices(numberOfBoundaryVertices),
_numberOfOuterVertices(numberOfOuterVertices),
_numberOfInnerCells(numberOfInnerCells),
_numberOfOuterCells(numberOfOuterCells),
_numberOfInnerLeafVertices(numberOfInnerLeafVertices),
_numberOfBoundaryLeafVertices(numberOfBoundaryLeafVertices),
_numberOfOuterLeafVertices(numberOfOuterLeafVertices),
_numberOfInnerLeafCells(numberOfInnerLeafCells),
_numberOfOuterLeafCells(numberOfOuterLeafCells),
_maxLevel(maxLevel),
_isTraversalInverted(isTraversalInverted) {
setHasRefined(hasRefined);
setHasTriggeredRefinementForNextIteration(hasTriggeredRefinementForNextIteration);
setHasErased(hasErased);
setHasTriggeredEraseForNextIteration(hasTriggeredEraseForNextIteration);
setHasChangedVertexOrCellState(hasChangedVertexOrCellState);
assertion((5 < (8 * sizeof(short int))));

}

particles::pit::records::StatePacked::StatePacked() {
assertion((5 < (8 * sizeof(short int))));

}


particles::pit::records::StatePacked::StatePacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._minimalNumberOfParticlesPerCell, persistentRecords._timeStepSize, persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume, persistentRecords._maximalInitialVelocity, persistentRecords._breakingDamWidth, persistentRecords._numberOfLifts, persistentRecords._numberOfParticlesInLeaves, persistentRecords._liftsPerLevel, persistentRecords._accumulatedDensity, persistentRecords._nonEmptyLeaves, persistentRecords._particlesSentToMaster, persistentRecords._minMeshWidth, persistentRecords._maxMeshWidth, persistentRecords._numberOfInnerVertices, persistentRecords._numberOfBoundaryVertices, persistentRecords._numberOfOuterVertices, persistentRecords._numberOfInnerCells, persistentRecords._numberOfOuterCells, persistentRecords._numberOfInnerLeafVertices, persistentRecords._numberOfBoundaryLeafVertices, persistentRecords._numberOfOuterLeafVertices, persistentRecords._numberOfInnerLeafCells, persistentRecords._numberOfOuterLeafCells, persistentRecords._maxLevel, persistentRecords.getHasRefined(), persistentRecords.getHasTriggeredRefinementForNextIteration(), persistentRecords.getHasErased(), persistentRecords.getHasTriggeredEraseForNextIteration(), persistentRecords.getHasChangedVertexOrCellState(), persistentRecords._isTraversalInverted) {
assertion((5 < (8 * sizeof(short int))));

}


particles::pit::records::StatePacked::StatePacked(const int& minimalNumberOfParticlesPerCell, const double& timeStepSize, const double& maximalNumberOfInitialParticlesPerUnitVolume, const double& maximalInitialVelocity, const double& breakingDamWidth, const double& numberOfLifts, const double& numberOfParticlesInLeaves, const tarch::la::Vector<MaxLevels,double>& liftsPerLevel, const double& accumulatedDensity, const double& nonEmptyLeaves, const double& particlesSentToMaster, const tarch::la::Vector<DIMENSIONS,double>& minMeshWidth, const tarch::la::Vector<DIMENSIONS,double>& maxMeshWidth, const double& numberOfInnerVertices, const double& numberOfBoundaryVertices, const double& numberOfOuterVertices, const double& numberOfInnerCells, const double& numberOfOuterCells, const double& numberOfInnerLeafVertices, const double& numberOfBoundaryLeafVertices, const double& numberOfOuterLeafVertices, const double& numberOfInnerLeafCells, const double& numberOfOuterLeafCells, const int& maxLevel, const bool& hasRefined, const bool& hasTriggeredRefinementForNextIteration, const bool& hasErased, const bool& hasTriggeredEraseForNextIteration, const bool& hasChangedVertexOrCellState, const bool& isTraversalInverted):
_persistentRecords(minimalNumberOfParticlesPerCell, timeStepSize, maximalNumberOfInitialParticlesPerUnitVolume, maximalInitialVelocity, breakingDamWidth, numberOfLifts, numberOfParticlesInLeaves, liftsPerLevel, accumulatedDensity, nonEmptyLeaves, particlesSentToMaster, minMeshWidth, maxMeshWidth, numberOfInnerVertices, numberOfBoundaryVertices, numberOfOuterVertices, numberOfInnerCells, numberOfOuterCells, numberOfInnerLeafVertices, numberOfBoundaryLeafVertices, numberOfOuterLeafVertices, numberOfInnerLeafCells, numberOfOuterLeafCells, maxLevel, hasRefined, hasTriggeredRefinementForNextIteration, hasErased, hasTriggeredEraseForNextIteration, hasChangedVertexOrCellState, isTraversalInverted) {
assertion((5 < (8 * sizeof(short int))));

}


particles::pit::records::StatePacked::~StatePacked() { }



std::string particles::pit::records::StatePacked::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pit::records::StatePacked::toString (std::ostream& out) const {
out << "("; 
out << "minimalNumberOfParticlesPerCell:" << getMinimalNumberOfParticlesPerCell();
out << ",";
out << "timeStepSize:" << getTimeStepSize();
out << ",";
out << "maximalNumberOfInitialParticlesPerUnitVolume:" << getMaximalNumberOfInitialParticlesPerUnitVolume();
out << ",";
out << "maximalInitialVelocity:" << getMaximalInitialVelocity();
out << ",";
out << "breakingDamWidth:" << getBreakingDamWidth();
out << ",";
out << "numberOfLifts:" << getNumberOfLifts();
out << ",";
out << "numberOfParticlesInLeaves:" << getNumberOfParticlesInLeaves();
out << ",";
out << "liftsPerLevel:[";
   for (int i = 0; i < MaxLevels-1; i++) {
      out << getLiftsPerLevel(i) << ",";
   }
   out << getLiftsPerLevel(MaxLevels-1) << "]";
out << ",";
out << "accumulatedDensity:" << getAccumulatedDensity();
out << ",";
out << "nonEmptyLeaves:" << getNonEmptyLeaves();
out << ",";
out << "particlesSentToMaster:" << getParticlesSentToMaster();
out << ",";
out << "minMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMinMeshWidth(i) << ",";
   }
   out << getMinMeshWidth(DIMENSIONS-1) << "]";
out << ",";
out << "maxMeshWidth:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getMaxMeshWidth(i) << ",";
   }
   out << getMaxMeshWidth(DIMENSIONS-1) << "]";
out << ",";
out << "numberOfInnerVertices:" << getNumberOfInnerVertices();
out << ",";
out << "numberOfBoundaryVertices:" << getNumberOfBoundaryVertices();
out << ",";
out << "numberOfOuterVertices:" << getNumberOfOuterVertices();
out << ",";
out << "numberOfInnerCells:" << getNumberOfInnerCells();
out << ",";
out << "numberOfOuterCells:" << getNumberOfOuterCells();
out << ",";
out << "numberOfInnerLeafVertices:" << getNumberOfInnerLeafVertices();
out << ",";
out << "numberOfBoundaryLeafVertices:" << getNumberOfBoundaryLeafVertices();
out << ",";
out << "numberOfOuterLeafVertices:" << getNumberOfOuterLeafVertices();
out << ",";
out << "numberOfInnerLeafCells:" << getNumberOfInnerLeafCells();
out << ",";
out << "numberOfOuterLeafCells:" << getNumberOfOuterLeafCells();
out << ",";
out << "maxLevel:" << getMaxLevel();
out << ",";
out << "hasRefined:" << getHasRefined();
out << ",";
out << "hasTriggeredRefinementForNextIteration:" << getHasTriggeredRefinementForNextIteration();
out << ",";
out << "hasErased:" << getHasErased();
out << ",";
out << "hasTriggeredEraseForNextIteration:" << getHasTriggeredEraseForNextIteration();
out << ",";
out << "hasChangedVertexOrCellState:" << getHasChangedVertexOrCellState();
out << ",";
out << "isTraversalInverted:" << getIsTraversalInverted();
out <<  ")";
}


particles::pit::records::StatePacked::PersistentRecords particles::pit::records::StatePacked::getPersistentRecords() const {
return _persistentRecords;
}

particles::pit::records::State particles::pit::records::StatePacked::convert() const{
return State(
getMinimalNumberOfParticlesPerCell(),
getTimeStepSize(),
getMaximalNumberOfInitialParticlesPerUnitVolume(),
getMaximalInitialVelocity(),
getBreakingDamWidth(),
getNumberOfLifts(),
getNumberOfParticlesInLeaves(),
getLiftsPerLevel(),
getAccumulatedDensity(),
getNonEmptyLeaves(),
getParticlesSentToMaster(),
getMinMeshWidth(),
getMaxMeshWidth(),
getNumberOfInnerVertices(),
getNumberOfBoundaryVertices(),
getNumberOfOuterVertices(),
getNumberOfInnerCells(),
getNumberOfOuterCells(),
getNumberOfInnerLeafVertices(),
getNumberOfBoundaryLeafVertices(),
getNumberOfOuterLeafVertices(),
getNumberOfInnerLeafCells(),
getNumberOfOuterLeafCells(),
getMaxLevel(),
getHasRefined(),
getHasTriggeredRefinementForNextIteration(),
getHasErased(),
getHasTriggeredEraseForNextIteration(),
getHasChangedVertexOrCellState(),
getIsTraversalInverted()
);
}

#ifdef Parallel
tarch::logging::Log particles::pit::records::StatePacked::_log( "particles::pit::records::StatePacked" );

MPI_Datatype particles::pit::records::StatePacked::Datatype = 0;
MPI_Datatype particles::pit::records::StatePacked::FullDatatype = 0;


void particles::pit::records::StatePacked::initDatatype() {
{
   StatePacked dummyStatePacked[2];
   
   const int Attributes = 27;
   MPI_Datatype subtypes[Attributes] = {
      MPI_INT,		 //minimalNumberOfParticlesPerCell
      MPI_DOUBLE,		 //timeStepSize
      MPI_DOUBLE,		 //maximalNumberOfInitialParticlesPerUnitVolume
      MPI_DOUBLE,		 //maximalInitialVelocity
      MPI_DOUBLE,		 //breakingDamWidth
      MPI_DOUBLE,		 //numberOfLifts
      MPI_DOUBLE,		 //numberOfParticlesInLeaves
      MPI_DOUBLE,		 //liftsPerLevel
      MPI_DOUBLE,		 //accumulatedDensity
      MPI_DOUBLE,		 //nonEmptyLeaves
      MPI_DOUBLE,		 //particlesSentToMaster
      MPI_DOUBLE,		 //minMeshWidth
      MPI_DOUBLE,		 //maxMeshWidth
      MPI_DOUBLE,		 //numberOfInnerVertices
      MPI_DOUBLE,		 //numberOfBoundaryVertices
      MPI_DOUBLE,		 //numberOfOuterVertices
      MPI_DOUBLE,		 //numberOfInnerCells
      MPI_DOUBLE,		 //numberOfOuterCells
      MPI_DOUBLE,		 //numberOfInnerLeafVertices
      MPI_DOUBLE,		 //numberOfBoundaryLeafVertices
      MPI_DOUBLE,		 //numberOfOuterLeafVertices
      MPI_DOUBLE,		 //numberOfInnerLeafCells
      MPI_DOUBLE,		 //numberOfOuterLeafCells
      MPI_INT,		 //maxLevel
      MPI_CHAR,		 //isTraversalInverted
      MPI_SHORT,		 //_packedRecords0
      MPI_UB		 // end/displacement flag
   };
   
   int blocklen[Attributes] = {
      1,		 //minimalNumberOfParticlesPerCell
      1,		 //timeStepSize
      1,		 //maximalNumberOfInitialParticlesPerUnitVolume
      1,		 //maximalInitialVelocity
      1,		 //breakingDamWidth
      1,		 //numberOfLifts
      1,		 //numberOfParticlesInLeaves
      MaxLevels,		 //liftsPerLevel
      1,		 //accumulatedDensity
      1,		 //nonEmptyLeaves
      1,		 //particlesSentToMaster
      DIMENSIONS,		 //minMeshWidth
      DIMENSIONS,		 //maxMeshWidth
      1,		 //numberOfInnerVertices
      1,		 //numberOfBoundaryVertices
      1,		 //numberOfOuterVertices
      1,		 //numberOfInnerCells
      1,		 //numberOfOuterCells
      1,		 //numberOfInnerLeafVertices
      1,		 //numberOfBoundaryLeafVertices
      1,		 //numberOfOuterLeafVertices
      1,		 //numberOfInnerLeafCells
      1,		 //numberOfOuterLeafCells
      1,		 //maxLevel
      1,		 //isTraversalInverted
      1,		 //_packedRecords0
      1		 // end/displacement flag
   };
   
   MPI_Aint     disp[Attributes];
   
   MPI_Aint base;
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]))), &base);
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[0] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStepSize))), 		&disp[1] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume))), 		&disp[2] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maximalInitialVelocity))), 		&disp[3] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._breakingDamWidth))), 		&disp[4] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfLifts))), 		&disp[5] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfParticlesInLeaves))), 		&disp[6] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._liftsPerLevel[0]))), 		&disp[7] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._accumulatedDensity))), 		&disp[8] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._nonEmptyLeaves))), 		&disp[9] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._particlesSentToMaster))), 		&disp[10] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minMeshWidth[0]))), 		&disp[11] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[12] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerVertices))), 		&disp[13] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[14] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterVertices))), 		&disp[15] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerCells))), 		&disp[16] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterCells))), 		&disp[17] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerLeafVertices))), 		&disp[18] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryLeafVertices))), 		&disp[19] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterLeafVertices))), 		&disp[20] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerLeafCells))), 		&disp[21] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterLeafCells))), 		&disp[22] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxLevel))), 		&disp[23] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._isTraversalInverted))), 		&disp[24] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._packedRecords0))), 		&disp[25] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[1]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[26] );
   
   for (int i=1; i<Attributes; i++) {
      assertion1( disp[i] > disp[i-1], i );
   }
   for (int i=0; i<Attributes; i++) {
      disp[i] -= base;
   }
   MPI_Type_struct( Attributes, blocklen, disp, subtypes, &StatePacked::Datatype );
   MPI_Type_commit( &StatePacked::Datatype );
   
}
{
   StatePacked dummyStatePacked[2];
   
   const int Attributes = 27;
   MPI_Datatype subtypes[Attributes] = {
      MPI_INT,		 //minimalNumberOfParticlesPerCell
      MPI_DOUBLE,		 //timeStepSize
      MPI_DOUBLE,		 //maximalNumberOfInitialParticlesPerUnitVolume
      MPI_DOUBLE,		 //maximalInitialVelocity
      MPI_DOUBLE,		 //breakingDamWidth
      MPI_DOUBLE,		 //numberOfLifts
      MPI_DOUBLE,		 //numberOfParticlesInLeaves
      MPI_DOUBLE,		 //liftsPerLevel
      MPI_DOUBLE,		 //accumulatedDensity
      MPI_DOUBLE,		 //nonEmptyLeaves
      MPI_DOUBLE,		 //particlesSentToMaster
      MPI_DOUBLE,		 //minMeshWidth
      MPI_DOUBLE,		 //maxMeshWidth
      MPI_DOUBLE,		 //numberOfInnerVertices
      MPI_DOUBLE,		 //numberOfBoundaryVertices
      MPI_DOUBLE,		 //numberOfOuterVertices
      MPI_DOUBLE,		 //numberOfInnerCells
      MPI_DOUBLE,		 //numberOfOuterCells
      MPI_DOUBLE,		 //numberOfInnerLeafVertices
      MPI_DOUBLE,		 //numberOfBoundaryLeafVertices
      MPI_DOUBLE,		 //numberOfOuterLeafVertices
      MPI_DOUBLE,		 //numberOfInnerLeafCells
      MPI_DOUBLE,		 //numberOfOuterLeafCells
      MPI_INT,		 //maxLevel
      MPI_CHAR,		 //isTraversalInverted
      MPI_SHORT,		 //_packedRecords0
      MPI_UB		 // end/displacement flag
   };
   
   int blocklen[Attributes] = {
      1,		 //minimalNumberOfParticlesPerCell
      1,		 //timeStepSize
      1,		 //maximalNumberOfInitialParticlesPerUnitVolume
      1,		 //maximalInitialVelocity
      1,		 //breakingDamWidth
      1,		 //numberOfLifts
      1,		 //numberOfParticlesInLeaves
      MaxLevels,		 //liftsPerLevel
      1,		 //accumulatedDensity
      1,		 //nonEmptyLeaves
      1,		 //particlesSentToMaster
      DIMENSIONS,		 //minMeshWidth
      DIMENSIONS,		 //maxMeshWidth
      1,		 //numberOfInnerVertices
      1,		 //numberOfBoundaryVertices
      1,		 //numberOfOuterVertices
      1,		 //numberOfInnerCells
      1,		 //numberOfOuterCells
      1,		 //numberOfInnerLeafVertices
      1,		 //numberOfBoundaryLeafVertices
      1,		 //numberOfOuterLeafVertices
      1,		 //numberOfInnerLeafCells
      1,		 //numberOfOuterLeafCells
      1,		 //maxLevel
      1,		 //isTraversalInverted
      1,		 //_packedRecords0
      1		 // end/displacement flag
   };
   
   MPI_Aint     disp[Attributes];
   
   MPI_Aint base;
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]))), &base);
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[0] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._timeStepSize))), 		&disp[1] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maximalNumberOfInitialParticlesPerUnitVolume))), 		&disp[2] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maximalInitialVelocity))), 		&disp[3] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._breakingDamWidth))), 		&disp[4] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfLifts))), 		&disp[5] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfParticlesInLeaves))), 		&disp[6] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._liftsPerLevel[0]))), 		&disp[7] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._accumulatedDensity))), 		&disp[8] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._nonEmptyLeaves))), 		&disp[9] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._particlesSentToMaster))), 		&disp[10] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._minMeshWidth[0]))), 		&disp[11] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxMeshWidth[0]))), 		&disp[12] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerVertices))), 		&disp[13] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryVertices))), 		&disp[14] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterVertices))), 		&disp[15] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerCells))), 		&disp[16] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterCells))), 		&disp[17] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerLeafVertices))), 		&disp[18] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfBoundaryLeafVertices))), 		&disp[19] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterLeafVertices))), 		&disp[20] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfInnerLeafCells))), 		&disp[21] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._numberOfOuterLeafCells))), 		&disp[22] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._maxLevel))), 		&disp[23] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._isTraversalInverted))), 		&disp[24] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[0]._persistentRecords._packedRecords0))), 		&disp[25] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyStatePacked[1]._persistentRecords._minimalNumberOfParticlesPerCell))), 		&disp[26] );
   
   for (int i=1; i<Attributes; i++) {
      assertion1( disp[i] > disp[i-1], i );
   }
   for (int i=0; i<Attributes; i++) {
      disp[i] -= base;
   }
   MPI_Type_struct( Attributes, blocklen, disp, subtypes, &StatePacked::FullDatatype );
   MPI_Type_commit( &StatePacked::FullDatatype );
   
}

}


void particles::pit::records::StatePacked::shutdownDatatype() {
MPI_Type_free( &StatePacked::Datatype );
MPI_Type_free( &StatePacked::FullDatatype );

}

void particles::pit::records::StatePacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
_senderDestinationRank = destination;

if (communicateBlocking) {

   const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
   if  (result!=MPI_SUCCESS) {
      std::ostringstream msg;
      msg << "was not able to send message particles::pit::records::StatePacked "
      << toString()
      << " to node " << destination
      << ": " << tarch::parallel::MPIReturnValueToString(result);
      _log.error( "send(int)",msg.str() );
   }
   
}
else {

MPI_Request* sendRequestHandle = new MPI_Request();
MPI_Status   status;
int          flag = 0;
int          result;

clock_t      timeOutWarning   = -1;
clock_t      timeOutShutdown  = -1;
bool         triggeredTimeoutWarning = false;

if (exchangeOnlyAttributesMarkedWithParallelise) {
   result = MPI_Isend(
      this, 1, Datatype, destination,
      tag, tarch::parallel::Node::getInstance().getCommunicator(),
      sendRequestHandle
   );
   
}
else {
   result = MPI_Isend(
      this, 1, FullDatatype, destination,
      tag, tarch::parallel::Node::getInstance().getCommunicator(),
      sendRequestHandle
   );
   
}
if  (result!=MPI_SUCCESS) {
   std::ostringstream msg;
   msg << "was not able to send message particles::pit::records::StatePacked "
   << toString()
   << " to node " << destination
   << ": " << tarch::parallel::MPIReturnValueToString(result);
   _log.error( "send(int)",msg.str() );
}
result = MPI_Test( sendRequestHandle, &flag, &status );
while (!flag) {
   if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
   if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
   result = MPI_Test( sendRequestHandle, &flag, &status );
   if (result!=MPI_SUCCESS) {
      std::ostringstream msg;
      msg << "testing for finished send task for particles::pit::records::StatePacked "
      << toString()
      << " sent to node " << destination
      << " failed: " << tarch::parallel::MPIReturnValueToString(result);
      _log.error("send(int)", msg.str() );
   }
   
   // deadlock aspect
   if (
      tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
      (clock()>timeOutWarning) &&
      (!triggeredTimeoutWarning)
   ) {
      tarch::parallel::Node::getInstance().writeTimeOutWarning(
      "particles::pit::records::StatePacked",
      "send(int)", destination,tag,1
      );
      triggeredTimeoutWarning = true;
   }
   if (
      tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
      (clock()>timeOutShutdown)
   ) {
      tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
      "particles::pit::records::StatePacked",
      "send(int)", destination,tag,1
      );
   }
   tarch::parallel::Node::getInstance().receiveDanglingMessages();
}

delete sendRequestHandle;
#ifdef Debug
_log.debug("send(int,int)", "sent " + toString() );
#endif

}

}



void particles::pit::records::StatePacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

MPI_Status  status;
const int   result = MPI_Recv(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
_senderDestinationRank = status.MPI_SOURCE;
if ( result != MPI_SUCCESS ) {
   std::ostringstream msg;
   msg << "failed to start to receive particles::pit::records::StatePacked from node "
   << source << ": " << tarch::parallel::MPIReturnValueToString(result);
   _log.error( "receive(int)", msg.str() );
}

}
else {

MPI_Request* sendRequestHandle = new MPI_Request();
MPI_Status   status;
int          flag = 0;
int          result;

clock_t      timeOutWarning   = -1;
clock_t      timeOutShutdown  = -1;
bool         triggeredTimeoutWarning = false;

if (exchangeOnlyAttributesMarkedWithParallelise) {
   result = MPI_Irecv(
      this, 1, Datatype, source, tag,
      tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
   );
   
}
else {
   result = MPI_Irecv(
      this, 1, FullDatatype, source, tag,
      tarch::parallel::Node::getInstance().getCommunicator(), sendRequestHandle
   );
   
}
if ( result != MPI_SUCCESS ) {
   std::ostringstream msg;
   msg << "failed to start to receive particles::pit::records::StatePacked from node "
   << source << ": " << tarch::parallel::MPIReturnValueToString(result);
   _log.error( "receive(int)", msg.str() );
}

result = MPI_Test( sendRequestHandle, &flag, &status );
while (!flag) {
   if (timeOutWarning==-1)   timeOutWarning   = tarch::parallel::Node::getInstance().getDeadlockWarningTimeStamp();
   if (timeOutShutdown==-1)  timeOutShutdown  = tarch::parallel::Node::getInstance().getDeadlockTimeOutTimeStamp();
   result = MPI_Test( sendRequestHandle, &flag, &status );
   if (result!=MPI_SUCCESS) {
      std::ostringstream msg;
      msg << "testing for finished receive task for particles::pit::records::StatePacked failed: "
      << tarch::parallel::MPIReturnValueToString(result);
      _log.error("receive(int)", msg.str() );
   }
   
   // deadlock aspect
   if (
      tarch::parallel::Node::getInstance().isTimeOutWarningEnabled() &&
      (clock()>timeOutWarning) &&
      (!triggeredTimeoutWarning)
   ) {
      tarch::parallel::Node::getInstance().writeTimeOutWarning(
      "particles::pit::records::StatePacked",
      "receive(int)", source,tag,1
      );
      triggeredTimeoutWarning = true;
   }
   if (
      tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
      (clock()>timeOutShutdown)
   ) {
      tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
      "particles::pit::records::StatePacked",
      "receive(int)", source,tag,1
      );
   }
   tarch::parallel::Node::getInstance().receiveDanglingMessages();
}

delete sendRequestHandle;

_senderDestinationRank = status.MPI_SOURCE;
#ifdef Debug
_log.debug("receive(int,int)", "received " + toString() ); 
#endif

}

}



bool particles::pit::records::StatePacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
MPI_Status status;
int  flag        = 0;
MPI_Iprobe(
MPI_ANY_SOURCE, tag,
tarch::parallel::Node::getInstance().getCommunicator(), &flag, &status
);
if (flag) {
int  messageCounter;
if (exchangeOnlyAttributesMarkedWithParallelise) {
   MPI_Get_count(&status, Datatype, &messageCounter);
}
else {
   MPI_Get_count(&status, FullDatatype, &messageCounter);
}
return messageCounter > 0;
}
else return false;

}

int particles::pit::records::StatePacked::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif




#endif


