#include "particles/pidt/records/Vertex.h"

#if defined(Parallel) && defined(Asserts)
   particles::pidt::records::Vertex::PersistentRecords::PersistentRecords() {
      
   }
   
   
   particles::pidt::records::Vertex::PersistentRecords::PersistentRecords(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
   _vertexIndex(vertexIndex),
   _isHangingNode(isHangingNode),
   _refinementControl(refinementControl),
   _adjacentCellsHeight(adjacentCellsHeight),
   _insideOutsideDomain(insideOutsideDomain),
   _x(x),
   _level(level),
   _adjacentRanks(adjacentRanks),
   _adjacentSubtreeForksIntoOtherRank(adjacentSubtreeForksIntoOtherRank) {
      
   }
   
   particles::pidt::records::Vertex::Vertex() {
      
   }
   
   
   particles::pidt::records::Vertex::Vertex(const PersistentRecords& persistentRecords):
   _persistentRecords(persistentRecords._vertexIndex, persistentRecords._isHangingNode, persistentRecords._refinementControl, persistentRecords._adjacentCellsHeight, persistentRecords._insideOutsideDomain, persistentRecords._x, persistentRecords._level, persistentRecords._adjacentRanks, persistentRecords._adjacentSubtreeForksIntoOtherRank) {
      
   }
   
   
   particles::pidt::records::Vertex::Vertex(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
   _persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level, adjacentRanks, adjacentSubtreeForksIntoOtherRank) {
      
   }
   
   
   particles::pidt::records::Vertex::Vertex(const int& numberOfAdjacentEraseTriggers, const bool& particlesAddedToThisCell, const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
   _persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level, adjacentRanks, adjacentSubtreeForksIntoOtherRank),_numberOfAdjacentEraseTriggers(numberOfAdjacentEraseTriggers),
   _particlesAddedToThisCell(particlesAddedToThisCell),
   _adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
   _numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
      
   }
   
   particles::pidt::records::Vertex::~Vertex() { }
   
   std::string particles::pidt::records::Vertex::toString(const InsideOutsideDomain& param) {
      switch (param) {
         case Inside: return "Inside";
         case Boundary: return "Boundary";
         case Outside: return "Outside";
      }
      return "undefined";
   }
   
   std::string particles::pidt::records::Vertex::getInsideOutsideDomainMapping() {
      return "InsideOutsideDomain(Inside=0,Boundary=1,Outside=2)";
   }
   std::string particles::pidt::records::Vertex::toString(const RefinementControl& param) {
      switch (param) {
         case Unrefined: return "Unrefined";
         case Refined: return "Refined";
         case RefinementTriggered: return "RefinementTriggered";
         case Refining: return "Refining";
         case EraseTriggered: return "EraseTriggered";
         case Erasing: return "Erasing";
         case RefineDueToJoinThoughWorkerIsAlreadyErasing: return "RefineDueToJoinThoughWorkerIsAlreadyErasing";
      }
      return "undefined";
   }
   
   std::string particles::pidt::records::Vertex::getRefinementControlMapping() {
      return "RefinementControl(Unrefined=0,Refined=1,RefinementTriggered=2,Refining=3,EraseTriggered=4,Erasing=5,RefineDueToJoinThoughWorkerIsAlreadyErasing=6)";
   }
   
   
   std::string particles::pidt::records::Vertex::toString() const {
      std::ostringstream stringstr;
      toString(stringstr);
      return stringstr.str();
   }
   
   void particles::pidt::records::Vertex::toString (std::ostream& out) const {
      out << "("; 
      out << "numberOfAdjacentEraseTriggers:" << getNumberOfAdjacentEraseTriggers();
      out << ",";
      out << "particlesAddedToThisCell:" << getParticlesAddedToThisCell();
      out << ",";
      out << "vertexIndex:" << getVertexIndex();
      out << ",";
      out << "isHangingNode:" << getIsHangingNode();
      out << ",";
      out << "refinementControl:" << toString(getRefinementControl());
      out << ",";
      out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
      out << ",";
      out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
      out << ",";
      out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
      out << ",";
      out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
      out << ",";
      out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
      out << ",";
      out << "level:" << getLevel();
      out << ",";
      out << "adjacentRanks:[";
   for (int i = 0; i < TWO_POWER_D-1; i++) {
      out << getAdjacentRanks(i) << ",";
   }
   out << getAdjacentRanks(TWO_POWER_D-1) << "]";
      out << ",";
      out << "adjacentSubtreeForksIntoOtherRank:" << getAdjacentSubtreeForksIntoOtherRank();
      out <<  ")";
   }
   
   
   particles::pidt::records::Vertex::PersistentRecords particles::pidt::records::Vertex::getPersistentRecords() const {
      return _persistentRecords;
   }
   
   particles::pidt::records::VertexPacked particles::pidt::records::Vertex::convert() const{
      return VertexPacked(
         getNumberOfAdjacentEraseTriggers(),
         getParticlesAddedToThisCell(),
         getVertexIndex(),
         getIsHangingNode(),
         getRefinementControl(),
         getAdjacentCellsHeight(),
         getAdjacentCellsHeightOfPreviousIteration(),
         getNumberOfAdjacentRefinedCells(),
         getInsideOutsideDomain(),
         getX(),
         getLevel(),
         getAdjacentRanks(),
         getAdjacentSubtreeForksIntoOtherRank()
      );
   }
   
   #ifdef Parallel
      tarch::logging::Log particles::pidt::records::Vertex::_log( "particles::pidt::records::Vertex" );
      
      MPI_Datatype particles::pidt::records::Vertex::Datatype = 0;
      MPI_Datatype particles::pidt::records::Vertex::FullDatatype = 0;
      
      
      void particles::pidt::records::Vertex::initDatatype() {
         {
            Vertex dummyVertex[2];
            
            const int Attributes = 10;
            MPI_Datatype subtypes[Attributes] = {
               MPI_CHAR,		 //isHangingNode
               MPI_INT,		 //refinementControl
               MPI_INT,		 //insideOutsideDomain
               MPI_DOUBLE,		 //x
               MPI_INT,		 //level
               MPI_INT,		 //adjacentRanks
               MPI_CHAR,		 //adjacentSubtreeForksIntoOtherRank
               MPI_INT,		 //numberOfAdjacentEraseTriggers
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //isHangingNode
               1,		 //refinementControl
               1,		 //insideOutsideDomain
               DIMENSIONS,		 //x
               1,		 //level
               TWO_POWER_D,		 //adjacentRanks
               1,		 //adjacentSubtreeForksIntoOtherRank
               1,		 //numberOfAdjacentEraseTriggers
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._x[0]))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._level))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentRanks[0]))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentSubtreeForksIntoOtherRank))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentEraseTriggers))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._isHangingNode))), 		&disp[9] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::Datatype );
            MPI_Type_commit( &Vertex::Datatype );
            
         }
         {
            Vertex dummyVertex[2];
            
            const int Attributes = 14;
            MPI_Datatype subtypes[Attributes] = {
               MPI_INT,		 //vertexIndex
               MPI_CHAR,		 //isHangingNode
               MPI_INT,		 //refinementControl
               MPI_INT,		 //adjacentCellsHeight
               MPI_INT,		 //insideOutsideDomain
               MPI_DOUBLE,		 //x
               MPI_INT,		 //level
               MPI_INT,		 //adjacentRanks
               MPI_CHAR,		 //adjacentSubtreeForksIntoOtherRank
               MPI_INT,		 //numberOfAdjacentEraseTriggers
               MPI_CHAR,		 //particlesAddedToThisCell
               MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
               MPI_INT,		 //numberOfAdjacentRefinedCells
               MPI_UB		 // end/displacement flag
            };
            
            int blocklen[Attributes] = {
               1,		 //vertexIndex
               1,		 //isHangingNode
               1,		 //refinementControl
               1,		 //adjacentCellsHeight
               1,		 //insideOutsideDomain
               DIMENSIONS,		 //x
               1,		 //level
               TWO_POWER_D,		 //adjacentRanks
               1,		 //adjacentSubtreeForksIntoOtherRank
               1,		 //numberOfAdjacentEraseTriggers
               1,		 //particlesAddedToThisCell
               1,		 //adjacentCellsHeightOfPreviousIteration
               1,		 //numberOfAdjacentRefinedCells
               1		 // end/displacement flag
            };
            
            MPI_Aint     disp[Attributes];
            
            MPI_Aint base;
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._vertexIndex))), 		&disp[0] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[1] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[2] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentCellsHeight))), 		&disp[3] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[4] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._x[0]))), 		&disp[5] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._level))), 		&disp[6] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentRanks[0]))), 		&disp[7] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentSubtreeForksIntoOtherRank))), 		&disp[8] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentEraseTriggers))), 		&disp[9] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._particlesAddedToThisCell))), 		&disp[10] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[11] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[12] );
            MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._vertexIndex))), 		&disp[13] );
            
            for (int i=1; i<Attributes; i++) {
               assertion1( disp[i] > disp[i-1], i );
            }
            for (int i=0; i<Attributes; i++) {
               disp[i] -= base;
            }
            MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::FullDatatype );
            MPI_Type_commit( &Vertex::FullDatatype );
            
         }
         
      }
      
      
      void particles::pidt::records::Vertex::shutdownDatatype() {
         MPI_Type_free( &Vertex::Datatype );
         MPI_Type_free( &Vertex::FullDatatype );
         
      }
      
      void particles::pidt::records::Vertex::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
         _senderDestinationRank = destination;
         
         if (communicateBlocking) {
         
            const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
            if  (result!=MPI_SUCCESS) {
               std::ostringstream msg;
               msg << "was not able to send message particles::pidt::records::Vertex "
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
            msg << "was not able to send message particles::pidt::records::Vertex "
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
               msg << "testing for finished send task for particles::pidt::records::Vertex "
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
               "particles::pidt::records::Vertex",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pidt::records::Vertex",
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
   
   
   
   void particles::pidt::records::Vertex::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         MPI_Status  status;
         const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
         _senderDestinationRank = status.MPI_SOURCE;
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pidt::records::Vertex from node "
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
            msg << "failed to start to receive particles::pidt::records::Vertex from node "
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
               msg << "testing for finished receive task for particles::pidt::records::Vertex failed: "
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
               "particles::pidt::records::Vertex",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pidt::records::Vertex",
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
   
   
   
   bool particles::pidt::records::Vertex::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
   
   int particles::pidt::records::Vertex::getSenderRank() const {
      assertion( _senderDestinationRank!=-1 );
      return _senderDestinationRank;
      
   }
#endif


particles::pidt::records::VertexPacked::PersistentRecords::PersistentRecords() {
   assertion((7 < (8 * sizeof(short int))));
   
}


particles::pidt::records::VertexPacked::PersistentRecords::PersistentRecords(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_vertexIndex(vertexIndex),
_adjacentCellsHeight(adjacentCellsHeight),
_x(x),
_level(level),
_adjacentRanks(adjacentRanks) {
   setIsHangingNode(isHangingNode);
   setRefinementControl(refinementControl);
   setInsideOutsideDomain(insideOutsideDomain);
   setAdjacentSubtreeForksIntoOtherRank(adjacentSubtreeForksIntoOtherRank);
   assertion((7 < (8 * sizeof(short int))));
   
}

particles::pidt::records::VertexPacked::VertexPacked() {
   assertion((7 < (8 * sizeof(short int))));
   
}


particles::pidt::records::VertexPacked::VertexPacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._vertexIndex, persistentRecords.getIsHangingNode(), persistentRecords.getRefinementControl(), persistentRecords._adjacentCellsHeight, persistentRecords.getInsideOutsideDomain(), persistentRecords._x, persistentRecords._level, persistentRecords._adjacentRanks, persistentRecords.getAdjacentSubtreeForksIntoOtherRank()) {
   assertion((7 < (8 * sizeof(short int))));
   
}


particles::pidt::records::VertexPacked::VertexPacked(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level, adjacentRanks, adjacentSubtreeForksIntoOtherRank) {
   assertion((7 < (8 * sizeof(short int))));
   
}


particles::pidt::records::VertexPacked::VertexPacked(const int& numberOfAdjacentEraseTriggers, const bool& particlesAddedToThisCell, const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level, adjacentRanks, adjacentSubtreeForksIntoOtherRank),_numberOfAdjacentEraseTriggers(numberOfAdjacentEraseTriggers),
_particlesAddedToThisCell(particlesAddedToThisCell),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
   assertion((7 < (8 * sizeof(short int))));
   
}

particles::pidt::records::VertexPacked::~VertexPacked() { }

std::string particles::pidt::records::VertexPacked::toString(const InsideOutsideDomain& param) {
   return particles::pidt::records::Vertex::toString(param);
}

std::string particles::pidt::records::VertexPacked::getInsideOutsideDomainMapping() {
   return particles::pidt::records::Vertex::getInsideOutsideDomainMapping();
}

std::string particles::pidt::records::VertexPacked::toString(const RefinementControl& param) {
   return particles::pidt::records::Vertex::toString(param);
}

std::string particles::pidt::records::VertexPacked::getRefinementControlMapping() {
   return particles::pidt::records::Vertex::getRefinementControlMapping();
}



std::string particles::pidt::records::VertexPacked::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void particles::pidt::records::VertexPacked::toString (std::ostream& out) const {
   out << "("; 
   out << "numberOfAdjacentEraseTriggers:" << getNumberOfAdjacentEraseTriggers();
   out << ",";
   out << "particlesAddedToThisCell:" << getParticlesAddedToThisCell();
   out << ",";
   out << "vertexIndex:" << getVertexIndex();
   out << ",";
   out << "isHangingNode:" << getIsHangingNode();
   out << ",";
   out << "refinementControl:" << toString(getRefinementControl());
   out << ",";
   out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
   out << ",";
   out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
   out << ",";
   out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
   out << ",";
   out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
   out << ",";
   out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
   out << ",";
   out << "level:" << getLevel();
   out << ",";
   out << "adjacentRanks:[";
   for (int i = 0; i < TWO_POWER_D-1; i++) {
      out << getAdjacentRanks(i) << ",";
   }
   out << getAdjacentRanks(TWO_POWER_D-1) << "]";
   out << ",";
   out << "adjacentSubtreeForksIntoOtherRank:" << getAdjacentSubtreeForksIntoOtherRank();
   out <<  ")";
}


particles::pidt::records::VertexPacked::PersistentRecords particles::pidt::records::VertexPacked::getPersistentRecords() const {
   return _persistentRecords;
}

particles::pidt::records::Vertex particles::pidt::records::VertexPacked::convert() const{
   return Vertex(
      getNumberOfAdjacentEraseTriggers(),
      getParticlesAddedToThisCell(),
      getVertexIndex(),
      getIsHangingNode(),
      getRefinementControl(),
      getAdjacentCellsHeight(),
      getAdjacentCellsHeightOfPreviousIteration(),
      getNumberOfAdjacentRefinedCells(),
      getInsideOutsideDomain(),
      getX(),
      getLevel(),
      getAdjacentRanks(),
      getAdjacentSubtreeForksIntoOtherRank()
   );
}

#ifdef Parallel
   tarch::logging::Log particles::pidt::records::VertexPacked::_log( "particles::pidt::records::VertexPacked" );
   
   MPI_Datatype particles::pidt::records::VertexPacked::Datatype = 0;
   MPI_Datatype particles::pidt::records::VertexPacked::FullDatatype = 0;
   
   
   void particles::pidt::records::VertexPacked::initDatatype() {
      {
         VertexPacked dummyVertexPacked[2];
         
         const int Attributes = 7;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_INT,		 //level
            MPI_INT,		 //adjacentRanks
            MPI_SHORT,		 //_packedRecords0
            MPI_INT,		 //numberOfAdjacentEraseTriggers
            MPI_INT,		 //numberOfAdjacentRefinedCells
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            1,		 //level
            TWO_POWER_D,		 //adjacentRanks
            1,		 //_packedRecords0
            1,		 //numberOfAdjacentEraseTriggers
            1,		 //numberOfAdjacentRefinedCells
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._level))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentRanks[0]))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[3] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentEraseTriggers))), 		&disp[4] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[5] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyVertexPacked[1]._persistentRecords._x[0])), 		&disp[6] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::Datatype );
         MPI_Type_commit( &VertexPacked::Datatype );
         
      }
      {
         VertexPacked dummyVertexPacked[2];
         
         const int Attributes = 11;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //vertexIndex
            MPI_INT,		 //adjacentCellsHeight
            MPI_DOUBLE,		 //x
            MPI_INT,		 //level
            MPI_INT,		 //adjacentRanks
            MPI_SHORT,		 //_packedRecords0
            MPI_INT,		 //numberOfAdjacentEraseTriggers
            MPI_CHAR,		 //particlesAddedToThisCell
            MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
            MPI_INT,		 //numberOfAdjacentRefinedCells
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //vertexIndex
            1,		 //adjacentCellsHeight
            DIMENSIONS,		 //x
            1,		 //level
            TWO_POWER_D,		 //adjacentRanks
            1,		 //_packedRecords0
            1,		 //numberOfAdjacentEraseTriggers
            1,		 //particlesAddedToThisCell
            1,		 //adjacentCellsHeightOfPreviousIteration
            1,		 //numberOfAdjacentRefinedCells
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._vertexIndex))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentCellsHeight))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._x[0]))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._level))), 		&disp[3] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentRanks[0]))), 		&disp[4] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[5] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentEraseTriggers))), 		&disp[6] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._particlesAddedToThisCell))), 		&disp[7] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[8] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[9] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._vertexIndex))), 		&disp[10] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::FullDatatype );
         MPI_Type_commit( &VertexPacked::FullDatatype );
         
      }
      
   }
   
   
   void particles::pidt::records::VertexPacked::shutdownDatatype() {
      MPI_Type_free( &VertexPacked::Datatype );
      MPI_Type_free( &VertexPacked::FullDatatype );
      
   }
   
   void particles::pidt::records::VertexPacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      _senderDestinationRank = destination;
      
      if (communicateBlocking) {
      
         const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pidt::records::VertexPacked "
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
         msg << "was not able to send message particles::pidt::records::VertexPacked "
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
            msg << "testing for finished send task for particles::pidt::records::VertexPacked "
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
            "particles::pidt::records::VertexPacked",
            "send(int)", destination,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "particles::pidt::records::VertexPacked",
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



void particles::pidt::records::VertexPacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
   if (communicateBlocking) {
   
      MPI_Status  status;
      const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
      _senderDestinationRank = status.MPI_SOURCE;
      if ( result != MPI_SUCCESS ) {
         std::ostringstream msg;
         msg << "failed to start to receive particles::pidt::records::VertexPacked from node "
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
         msg << "failed to start to receive particles::pidt::records::VertexPacked from node "
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
            msg << "testing for finished receive task for particles::pidt::records::VertexPacked failed: "
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
            "particles::pidt::records::VertexPacked",
            "receive(int)", source,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "particles::pidt::records::VertexPacked",
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



bool particles::pidt::records::VertexPacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::VertexPacked::getSenderRank() const {
   assertion( _senderDestinationRank!=-1 );
   return _senderDestinationRank;
   
}
#endif



#elif !defined(Parallel) && !defined(Asserts)
particles::pidt::records::Vertex::PersistentRecords::PersistentRecords() {

}


particles::pidt::records::Vertex::PersistentRecords::PersistentRecords(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain):
_vertexIndex(vertexIndex),
_isHangingNode(isHangingNode),
_refinementControl(refinementControl),
_adjacentCellsHeight(adjacentCellsHeight),
_insideOutsideDomain(insideOutsideDomain) {

}

particles::pidt::records::Vertex::Vertex() {

}


particles::pidt::records::Vertex::Vertex(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._vertexIndex, persistentRecords._isHangingNode, persistentRecords._refinementControl, persistentRecords._adjacentCellsHeight, persistentRecords._insideOutsideDomain) {

}


particles::pidt::records::Vertex::Vertex(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain) {

}


particles::pidt::records::Vertex::Vertex(const int& numberOfAdjacentEraseTriggers, const bool& particlesAddedToThisCell, const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain),_numberOfAdjacentEraseTriggers(numberOfAdjacentEraseTriggers),
_particlesAddedToThisCell(particlesAddedToThisCell),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {

}

particles::pidt::records::Vertex::~Vertex() { }

std::string particles::pidt::records::Vertex::toString(const InsideOutsideDomain& param) {
switch (param) {
   case Inside: return "Inside";
   case Boundary: return "Boundary";
   case Outside: return "Outside";
}
return "undefined";
}

std::string particles::pidt::records::Vertex::getInsideOutsideDomainMapping() {
return "InsideOutsideDomain(Inside=0,Boundary=1,Outside=2)";
}
std::string particles::pidt::records::Vertex::toString(const RefinementControl& param) {
switch (param) {
   case Unrefined: return "Unrefined";
   case Refined: return "Refined";
   case RefinementTriggered: return "RefinementTriggered";
   case Refining: return "Refining";
   case EraseTriggered: return "EraseTriggered";
   case Erasing: return "Erasing";
   case RefineDueToJoinThoughWorkerIsAlreadyErasing: return "RefineDueToJoinThoughWorkerIsAlreadyErasing";
}
return "undefined";
}

std::string particles::pidt::records::Vertex::getRefinementControlMapping() {
return "RefinementControl(Unrefined=0,Refined=1,RefinementTriggered=2,Refining=3,EraseTriggered=4,Erasing=5,RefineDueToJoinThoughWorkerIsAlreadyErasing=6)";
}


std::string particles::pidt::records::Vertex::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pidt::records::Vertex::toString (std::ostream& out) const {
out << "("; 
out << "numberOfAdjacentEraseTriggers:" << getNumberOfAdjacentEraseTriggers();
out << ",";
out << "particlesAddedToThisCell:" << getParticlesAddedToThisCell();
out << ",";
out << "vertexIndex:" << getVertexIndex();
out << ",";
out << "isHangingNode:" << getIsHangingNode();
out << ",";
out << "refinementControl:" << toString(getRefinementControl());
out << ",";
out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
out << ",";
out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
out << ",";
out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
out << ",";
out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
out <<  ")";
}


particles::pidt::records::Vertex::PersistentRecords particles::pidt::records::Vertex::getPersistentRecords() const {
return _persistentRecords;
}

particles::pidt::records::VertexPacked particles::pidt::records::Vertex::convert() const{
return VertexPacked(
   getNumberOfAdjacentEraseTriggers(),
   getParticlesAddedToThisCell(),
   getVertexIndex(),
   getIsHangingNode(),
   getRefinementControl(),
   getAdjacentCellsHeight(),
   getAdjacentCellsHeightOfPreviousIteration(),
   getNumberOfAdjacentRefinedCells(),
   getInsideOutsideDomain()
);
}

#ifdef Parallel
tarch::logging::Log particles::pidt::records::Vertex::_log( "particles::pidt::records::Vertex" );

MPI_Datatype particles::pidt::records::Vertex::Datatype = 0;
MPI_Datatype particles::pidt::records::Vertex::FullDatatype = 0;


void particles::pidt::records::Vertex::initDatatype() {
   {
      Vertex dummyVertex[2];
      
      const int Attributes = 5;
      MPI_Datatype subtypes[Attributes] = {
         MPI_CHAR,		 //isHangingNode
         MPI_INT,		 //refinementControl
         MPI_INT,		 //numberOfAdjacentEraseTriggers
         MPI_INT,		 //numberOfAdjacentRefinedCells
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         1,		 //isHangingNode
         1,		 //refinementControl
         1,		 //numberOfAdjacentEraseTriggers
         1,		 //numberOfAdjacentRefinedCells
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[1] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentEraseTriggers))), 		&disp[2] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[3] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._isHangingNode))), 		&disp[4] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::Datatype );
      MPI_Type_commit( &Vertex::Datatype );
      
   }
   {
      Vertex dummyVertex[2];
      
      const int Attributes = 10;
      MPI_Datatype subtypes[Attributes] = {
         MPI_INT,		 //vertexIndex
         MPI_CHAR,		 //isHangingNode
         MPI_INT,		 //refinementControl
         MPI_INT,		 //adjacentCellsHeight
         MPI_INT,		 //insideOutsideDomain
         MPI_INT,		 //numberOfAdjacentEraseTriggers
         MPI_CHAR,		 //particlesAddedToThisCell
         MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
         MPI_INT,		 //numberOfAdjacentRefinedCells
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         1,		 //vertexIndex
         1,		 //isHangingNode
         1,		 //refinementControl
         1,		 //adjacentCellsHeight
         1,		 //insideOutsideDomain
         1,		 //numberOfAdjacentEraseTriggers
         1,		 //particlesAddedToThisCell
         1,		 //adjacentCellsHeightOfPreviousIteration
         1,		 //numberOfAdjacentRefinedCells
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._vertexIndex))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[1] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[2] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentCellsHeight))), 		&disp[3] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[4] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentEraseTriggers))), 		&disp[5] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._particlesAddedToThisCell))), 		&disp[6] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[7] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[8] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._vertexIndex))), 		&disp[9] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::FullDatatype );
      MPI_Type_commit( &Vertex::FullDatatype );
      
   }
   
}


void particles::pidt::records::Vertex::shutdownDatatype() {
   MPI_Type_free( &Vertex::Datatype );
   MPI_Type_free( &Vertex::FullDatatype );
   
}

void particles::pidt::records::Vertex::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
   _senderDestinationRank = destination;
   
   if (communicateBlocking) {
   
      const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
      if  (result!=MPI_SUCCESS) {
         std::ostringstream msg;
         msg << "was not able to send message particles::pidt::records::Vertex "
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
      msg << "was not able to send message particles::pidt::records::Vertex "
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
         msg << "testing for finished send task for particles::pidt::records::Vertex "
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
         "particles::pidt::records::Vertex",
         "send(int)", destination,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "particles::pidt::records::Vertex",
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



void particles::pidt::records::Vertex::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

   MPI_Status  status;
   const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
   _senderDestinationRank = status.MPI_SOURCE;
   if ( result != MPI_SUCCESS ) {
      std::ostringstream msg;
      msg << "failed to start to receive particles::pidt::records::Vertex from node "
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
      msg << "failed to start to receive particles::pidt::records::Vertex from node "
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
         msg << "testing for finished receive task for particles::pidt::records::Vertex failed: "
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
         "particles::pidt::records::Vertex",
         "receive(int)", source,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "particles::pidt::records::Vertex",
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



bool particles::pidt::records::Vertex::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::Vertex::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif


particles::pidt::records::VertexPacked::PersistentRecords::PersistentRecords() {
assertion((6 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::PersistentRecords::PersistentRecords(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain):
_vertexIndex(vertexIndex),
_adjacentCellsHeight(adjacentCellsHeight) {
setIsHangingNode(isHangingNode);
setRefinementControl(refinementControl);
setInsideOutsideDomain(insideOutsideDomain);
assertion((6 < (8 * sizeof(short int))));

}

particles::pidt::records::VertexPacked::VertexPacked() {
assertion((6 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._vertexIndex, persistentRecords.getIsHangingNode(), persistentRecords.getRefinementControl(), persistentRecords._adjacentCellsHeight, persistentRecords.getInsideOutsideDomain()) {
assertion((6 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain) {
assertion((6 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const int& numberOfAdjacentEraseTriggers, const bool& particlesAddedToThisCell, const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain),_numberOfAdjacentEraseTriggers(numberOfAdjacentEraseTriggers),
_particlesAddedToThisCell(particlesAddedToThisCell),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
assertion((6 < (8 * sizeof(short int))));

}

particles::pidt::records::VertexPacked::~VertexPacked() { }

std::string particles::pidt::records::VertexPacked::toString(const InsideOutsideDomain& param) {
return particles::pidt::records::Vertex::toString(param);
}

std::string particles::pidt::records::VertexPacked::getInsideOutsideDomainMapping() {
return particles::pidt::records::Vertex::getInsideOutsideDomainMapping();
}

std::string particles::pidt::records::VertexPacked::toString(const RefinementControl& param) {
return particles::pidt::records::Vertex::toString(param);
}

std::string particles::pidt::records::VertexPacked::getRefinementControlMapping() {
return particles::pidt::records::Vertex::getRefinementControlMapping();
}



std::string particles::pidt::records::VertexPacked::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pidt::records::VertexPacked::toString (std::ostream& out) const {
out << "("; 
out << "numberOfAdjacentEraseTriggers:" << getNumberOfAdjacentEraseTriggers();
out << ",";
out << "particlesAddedToThisCell:" << getParticlesAddedToThisCell();
out << ",";
out << "vertexIndex:" << getVertexIndex();
out << ",";
out << "isHangingNode:" << getIsHangingNode();
out << ",";
out << "refinementControl:" << toString(getRefinementControl());
out << ",";
out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
out << ",";
out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
out << ",";
out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
out << ",";
out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
out <<  ")";
}


particles::pidt::records::VertexPacked::PersistentRecords particles::pidt::records::VertexPacked::getPersistentRecords() const {
return _persistentRecords;
}

particles::pidt::records::Vertex particles::pidt::records::VertexPacked::convert() const{
return Vertex(
getNumberOfAdjacentEraseTriggers(),
getParticlesAddedToThisCell(),
getVertexIndex(),
getIsHangingNode(),
getRefinementControl(),
getAdjacentCellsHeight(),
getAdjacentCellsHeightOfPreviousIteration(),
getNumberOfAdjacentRefinedCells(),
getInsideOutsideDomain()
);
}

#ifdef Parallel
tarch::logging::Log particles::pidt::records::VertexPacked::_log( "particles::pidt::records::VertexPacked" );

MPI_Datatype particles::pidt::records::VertexPacked::Datatype = 0;
MPI_Datatype particles::pidt::records::VertexPacked::FullDatatype = 0;


void particles::pidt::records::VertexPacked::initDatatype() {
{
   VertexPacked dummyVertexPacked[2];
   
   const int Attributes = 4;
   MPI_Datatype subtypes[Attributes] = {
      MPI_SHORT,		 //_packedRecords0
      MPI_INT,		 //numberOfAdjacentEraseTriggers
      MPI_INT,		 //numberOfAdjacentRefinedCells
      MPI_UB		 // end/displacement flag
   };
   
   int blocklen[Attributes] = {
      1,		 //_packedRecords0
      1,		 //numberOfAdjacentEraseTriggers
      1,		 //numberOfAdjacentRefinedCells
      1		 // end/displacement flag
   };
   
   MPI_Aint     disp[Attributes];
   
   MPI_Aint base;
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[0] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentEraseTriggers))), 		&disp[1] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[2] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._packedRecords0))), 		&disp[3] );
   
   for (int i=1; i<Attributes; i++) {
      assertion1( disp[i] > disp[i-1], i );
   }
   for (int i=0; i<Attributes; i++) {
      disp[i] -= base;
   }
   MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::Datatype );
   MPI_Type_commit( &VertexPacked::Datatype );
   
}
{
   VertexPacked dummyVertexPacked[2];
   
   const int Attributes = 8;
   MPI_Datatype subtypes[Attributes] = {
      MPI_INT,		 //vertexIndex
      MPI_INT,		 //adjacentCellsHeight
      MPI_SHORT,		 //_packedRecords0
      MPI_INT,		 //numberOfAdjacentEraseTriggers
      MPI_CHAR,		 //particlesAddedToThisCell
      MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
      MPI_INT,		 //numberOfAdjacentRefinedCells
      MPI_UB		 // end/displacement flag
   };
   
   int blocklen[Attributes] = {
      1,		 //vertexIndex
      1,		 //adjacentCellsHeight
      1,		 //_packedRecords0
      1,		 //numberOfAdjacentEraseTriggers
      1,		 //particlesAddedToThisCell
      1,		 //adjacentCellsHeightOfPreviousIteration
      1,		 //numberOfAdjacentRefinedCells
      1		 // end/displacement flag
   };
   
   MPI_Aint     disp[Attributes];
   
   MPI_Aint base;
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._vertexIndex))), 		&disp[0] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentCellsHeight))), 		&disp[1] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[2] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentEraseTriggers))), 		&disp[3] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._particlesAddedToThisCell))), 		&disp[4] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[5] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[6] );
   MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._vertexIndex))), 		&disp[7] );
   
   for (int i=1; i<Attributes; i++) {
      assertion1( disp[i] > disp[i-1], i );
   }
   for (int i=0; i<Attributes; i++) {
      disp[i] -= base;
   }
   MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::FullDatatype );
   MPI_Type_commit( &VertexPacked::FullDatatype );
   
}

}


void particles::pidt::records::VertexPacked::shutdownDatatype() {
MPI_Type_free( &VertexPacked::Datatype );
MPI_Type_free( &VertexPacked::FullDatatype );

}

void particles::pidt::records::VertexPacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
_senderDestinationRank = destination;

if (communicateBlocking) {

   const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
   if  (result!=MPI_SUCCESS) {
      std::ostringstream msg;
      msg << "was not able to send message particles::pidt::records::VertexPacked "
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
   msg << "was not able to send message particles::pidt::records::VertexPacked "
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
      msg << "testing for finished send task for particles::pidt::records::VertexPacked "
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
      "particles::pidt::records::VertexPacked",
      "send(int)", destination,tag,1
      );
      triggeredTimeoutWarning = true;
   }
   if (
      tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
      (clock()>timeOutShutdown)
   ) {
      tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
      "particles::pidt::records::VertexPacked",
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



void particles::pidt::records::VertexPacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

MPI_Status  status;
const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
_senderDestinationRank = status.MPI_SOURCE;
if ( result != MPI_SUCCESS ) {
   std::ostringstream msg;
   msg << "failed to start to receive particles::pidt::records::VertexPacked from node "
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
   msg << "failed to start to receive particles::pidt::records::VertexPacked from node "
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
      msg << "testing for finished receive task for particles::pidt::records::VertexPacked failed: "
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
      "particles::pidt::records::VertexPacked",
      "receive(int)", source,tag,1
      );
      triggeredTimeoutWarning = true;
   }
   if (
      tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
      (clock()>timeOutShutdown)
   ) {
      tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
      "particles::pidt::records::VertexPacked",
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



bool particles::pidt::records::VertexPacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::VertexPacked::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif




#elif !defined(Parallel) && defined(Asserts)
particles::pidt::records::Vertex::PersistentRecords::PersistentRecords() {

}


particles::pidt::records::Vertex::PersistentRecords::PersistentRecords(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_vertexIndex(vertexIndex),
_isHangingNode(isHangingNode),
_refinementControl(refinementControl),
_adjacentCellsHeight(adjacentCellsHeight),
_insideOutsideDomain(insideOutsideDomain),
_x(x),
_level(level) {

}

particles::pidt::records::Vertex::Vertex() {

}


particles::pidt::records::Vertex::Vertex(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._vertexIndex, persistentRecords._isHangingNode, persistentRecords._refinementControl, persistentRecords._adjacentCellsHeight, persistentRecords._insideOutsideDomain, persistentRecords._x, persistentRecords._level) {

}


particles::pidt::records::Vertex::Vertex(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level) {

}


particles::pidt::records::Vertex::Vertex(const int& numberOfAdjacentEraseTriggers, const bool& particlesAddedToThisCell, const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level),_numberOfAdjacentEraseTriggers(numberOfAdjacentEraseTriggers),
_particlesAddedToThisCell(particlesAddedToThisCell),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {

}

particles::pidt::records::Vertex::~Vertex() { }

std::string particles::pidt::records::Vertex::toString(const InsideOutsideDomain& param) {
switch (param) {
case Inside: return "Inside";
case Boundary: return "Boundary";
case Outside: return "Outside";
}
return "undefined";
}

std::string particles::pidt::records::Vertex::getInsideOutsideDomainMapping() {
return "InsideOutsideDomain(Inside=0,Boundary=1,Outside=2)";
}
std::string particles::pidt::records::Vertex::toString(const RefinementControl& param) {
switch (param) {
case Unrefined: return "Unrefined";
case Refined: return "Refined";
case RefinementTriggered: return "RefinementTriggered";
case Refining: return "Refining";
case EraseTriggered: return "EraseTriggered";
case Erasing: return "Erasing";
case RefineDueToJoinThoughWorkerIsAlreadyErasing: return "RefineDueToJoinThoughWorkerIsAlreadyErasing";
}
return "undefined";
}

std::string particles::pidt::records::Vertex::getRefinementControlMapping() {
return "RefinementControl(Unrefined=0,Refined=1,RefinementTriggered=2,Refining=3,EraseTriggered=4,Erasing=5,RefineDueToJoinThoughWorkerIsAlreadyErasing=6)";
}


std::string particles::pidt::records::Vertex::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pidt::records::Vertex::toString (std::ostream& out) const {
out << "("; 
out << "numberOfAdjacentEraseTriggers:" << getNumberOfAdjacentEraseTriggers();
out << ",";
out << "particlesAddedToThisCell:" << getParticlesAddedToThisCell();
out << ",";
out << "vertexIndex:" << getVertexIndex();
out << ",";
out << "isHangingNode:" << getIsHangingNode();
out << ",";
out << "refinementControl:" << toString(getRefinementControl());
out << ",";
out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
out << ",";
out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
out << ",";
out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
out << ",";
out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
out << ",";
out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
out << ",";
out << "level:" << getLevel();
out <<  ")";
}


particles::pidt::records::Vertex::PersistentRecords particles::pidt::records::Vertex::getPersistentRecords() const {
return _persistentRecords;
}

particles::pidt::records::VertexPacked particles::pidt::records::Vertex::convert() const{
return VertexPacked(
getNumberOfAdjacentEraseTriggers(),
getParticlesAddedToThisCell(),
getVertexIndex(),
getIsHangingNode(),
getRefinementControl(),
getAdjacentCellsHeight(),
getAdjacentCellsHeightOfPreviousIteration(),
getNumberOfAdjacentRefinedCells(),
getInsideOutsideDomain(),
getX(),
getLevel()
);
}

#ifdef Parallel
tarch::logging::Log particles::pidt::records::Vertex::_log( "particles::pidt::records::Vertex" );

MPI_Datatype particles::pidt::records::Vertex::Datatype = 0;
MPI_Datatype particles::pidt::records::Vertex::FullDatatype = 0;


void particles::pidt::records::Vertex::initDatatype() {
{
Vertex dummyVertex[2];

const int Attributes = 8;
MPI_Datatype subtypes[Attributes] = {
MPI_CHAR,		 //isHangingNode
MPI_INT,		 //refinementControl
MPI_INT,		 //insideOutsideDomain
MPI_DOUBLE,		 //x
MPI_INT,		 //level
MPI_INT,		 //numberOfAdjacentEraseTriggers
MPI_INT,		 //numberOfAdjacentRefinedCells
MPI_UB		 // end/displacement flag
};

int blocklen[Attributes] = {
1,		 //isHangingNode
1,		 //refinementControl
1,		 //insideOutsideDomain
DIMENSIONS,		 //x
1,		 //level
1,		 //numberOfAdjacentEraseTriggers
1,		 //numberOfAdjacentRefinedCells
1		 // end/displacement flag
};

MPI_Aint     disp[Attributes];

MPI_Aint base;
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[0] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[1] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[2] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._x[0]))), 		&disp[3] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._level))), 		&disp[4] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentEraseTriggers))), 		&disp[5] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[6] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._isHangingNode))), 		&disp[7] );

for (int i=1; i<Attributes; i++) {
assertion1( disp[i] > disp[i-1], i );
}
for (int i=0; i<Attributes; i++) {
disp[i] -= base;
}
MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::Datatype );
MPI_Type_commit( &Vertex::Datatype );

}
{
Vertex dummyVertex[2];

const int Attributes = 12;
MPI_Datatype subtypes[Attributes] = {
MPI_INT,		 //vertexIndex
MPI_CHAR,		 //isHangingNode
MPI_INT,		 //refinementControl
MPI_INT,		 //adjacentCellsHeight
MPI_INT,		 //insideOutsideDomain
MPI_DOUBLE,		 //x
MPI_INT,		 //level
MPI_INT,		 //numberOfAdjacentEraseTriggers
MPI_CHAR,		 //particlesAddedToThisCell
MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
MPI_INT,		 //numberOfAdjacentRefinedCells
MPI_UB		 // end/displacement flag
};

int blocklen[Attributes] = {
1,		 //vertexIndex
1,		 //isHangingNode
1,		 //refinementControl
1,		 //adjacentCellsHeight
1,		 //insideOutsideDomain
DIMENSIONS,		 //x
1,		 //level
1,		 //numberOfAdjacentEraseTriggers
1,		 //particlesAddedToThisCell
1,		 //adjacentCellsHeightOfPreviousIteration
1,		 //numberOfAdjacentRefinedCells
1		 // end/displacement flag
};

MPI_Aint     disp[Attributes];

MPI_Aint base;
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._vertexIndex))), 		&disp[0] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[1] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[2] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentCellsHeight))), 		&disp[3] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[4] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._x[0]))), 		&disp[5] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._level))), 		&disp[6] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentEraseTriggers))), 		&disp[7] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._particlesAddedToThisCell))), 		&disp[8] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[9] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[10] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._vertexIndex))), 		&disp[11] );

for (int i=1; i<Attributes; i++) {
assertion1( disp[i] > disp[i-1], i );
}
for (int i=0; i<Attributes; i++) {
disp[i] -= base;
}
MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::FullDatatype );
MPI_Type_commit( &Vertex::FullDatatype );

}

}


void particles::pidt::records::Vertex::shutdownDatatype() {
MPI_Type_free( &Vertex::Datatype );
MPI_Type_free( &Vertex::FullDatatype );

}

void particles::pidt::records::Vertex::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
_senderDestinationRank = destination;

if (communicateBlocking) {

const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
if  (result!=MPI_SUCCESS) {
std::ostringstream msg;
msg << "was not able to send message particles::pidt::records::Vertex "
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
msg << "was not able to send message particles::pidt::records::Vertex "
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
msg << "testing for finished send task for particles::pidt::records::Vertex "
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
"particles::pidt::records::Vertex",
"send(int)", destination,tag,1
);
triggeredTimeoutWarning = true;
}
if (
tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
(clock()>timeOutShutdown)
) {
tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
"particles::pidt::records::Vertex",
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



void particles::pidt::records::Vertex::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

MPI_Status  status;
const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
_senderDestinationRank = status.MPI_SOURCE;
if ( result != MPI_SUCCESS ) {
std::ostringstream msg;
msg << "failed to start to receive particles::pidt::records::Vertex from node "
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
msg << "failed to start to receive particles::pidt::records::Vertex from node "
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
msg << "testing for finished receive task for particles::pidt::records::Vertex failed: "
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
"particles::pidt::records::Vertex",
"receive(int)", source,tag,1
);
triggeredTimeoutWarning = true;
}
if (
tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
(clock()>timeOutShutdown)
) {
tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
"particles::pidt::records::Vertex",
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



bool particles::pidt::records::Vertex::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::Vertex::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif


particles::pidt::records::VertexPacked::PersistentRecords::PersistentRecords() {
assertion((6 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::PersistentRecords::PersistentRecords(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_vertexIndex(vertexIndex),
_adjacentCellsHeight(adjacentCellsHeight),
_x(x),
_level(level) {
setIsHangingNode(isHangingNode);
setRefinementControl(refinementControl);
setInsideOutsideDomain(insideOutsideDomain);
assertion((6 < (8 * sizeof(short int))));

}

particles::pidt::records::VertexPacked::VertexPacked() {
assertion((6 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._vertexIndex, persistentRecords.getIsHangingNode(), persistentRecords.getRefinementControl(), persistentRecords._adjacentCellsHeight, persistentRecords.getInsideOutsideDomain(), persistentRecords._x, persistentRecords._level) {
assertion((6 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level) {
assertion((6 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const int& numberOfAdjacentEraseTriggers, const bool& particlesAddedToThisCell, const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<DIMENSIONS,double>& x, const int& level):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, x, level),_numberOfAdjacentEraseTriggers(numberOfAdjacentEraseTriggers),
_particlesAddedToThisCell(particlesAddedToThisCell),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
assertion((6 < (8 * sizeof(short int))));

}

particles::pidt::records::VertexPacked::~VertexPacked() { }

std::string particles::pidt::records::VertexPacked::toString(const InsideOutsideDomain& param) {
return particles::pidt::records::Vertex::toString(param);
}

std::string particles::pidt::records::VertexPacked::getInsideOutsideDomainMapping() {
return particles::pidt::records::Vertex::getInsideOutsideDomainMapping();
}

std::string particles::pidt::records::VertexPacked::toString(const RefinementControl& param) {
return particles::pidt::records::Vertex::toString(param);
}

std::string particles::pidt::records::VertexPacked::getRefinementControlMapping() {
return particles::pidt::records::Vertex::getRefinementControlMapping();
}



std::string particles::pidt::records::VertexPacked::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pidt::records::VertexPacked::toString (std::ostream& out) const {
out << "("; 
out << "numberOfAdjacentEraseTriggers:" << getNumberOfAdjacentEraseTriggers();
out << ",";
out << "particlesAddedToThisCell:" << getParticlesAddedToThisCell();
out << ",";
out << "vertexIndex:" << getVertexIndex();
out << ",";
out << "isHangingNode:" << getIsHangingNode();
out << ",";
out << "refinementControl:" << toString(getRefinementControl());
out << ",";
out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
out << ",";
out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
out << ",";
out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
out << ",";
out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
out << ",";
out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
out << ",";
out << "level:" << getLevel();
out <<  ")";
}


particles::pidt::records::VertexPacked::PersistentRecords particles::pidt::records::VertexPacked::getPersistentRecords() const {
return _persistentRecords;
}

particles::pidt::records::Vertex particles::pidt::records::VertexPacked::convert() const{
return Vertex(
getNumberOfAdjacentEraseTriggers(),
getParticlesAddedToThisCell(),
getVertexIndex(),
getIsHangingNode(),
getRefinementControl(),
getAdjacentCellsHeight(),
getAdjacentCellsHeightOfPreviousIteration(),
getNumberOfAdjacentRefinedCells(),
getInsideOutsideDomain(),
getX(),
getLevel()
);
}

#ifdef Parallel
tarch::logging::Log particles::pidt::records::VertexPacked::_log( "particles::pidt::records::VertexPacked" );

MPI_Datatype particles::pidt::records::VertexPacked::Datatype = 0;
MPI_Datatype particles::pidt::records::VertexPacked::FullDatatype = 0;


void particles::pidt::records::VertexPacked::initDatatype() {
{
VertexPacked dummyVertexPacked[2];

const int Attributes = 6;
MPI_Datatype subtypes[Attributes] = {
MPI_DOUBLE,		 //x
MPI_INT,		 //level
MPI_SHORT,		 //_packedRecords0
MPI_INT,		 //numberOfAdjacentEraseTriggers
MPI_INT,		 //numberOfAdjacentRefinedCells
MPI_UB		 // end/displacement flag
};

int blocklen[Attributes] = {
DIMENSIONS,		 //x
1,		 //level
1,		 //_packedRecords0
1,		 //numberOfAdjacentEraseTriggers
1,		 //numberOfAdjacentRefinedCells
1		 // end/displacement flag
};

MPI_Aint     disp[Attributes];

MPI_Aint base;
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._x[0]))), 		&disp[0] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._level))), 		&disp[1] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[2] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentEraseTriggers))), 		&disp[3] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[4] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyVertexPacked[1]._persistentRecords._x[0])), 		&disp[5] );

for (int i=1; i<Attributes; i++) {
assertion1( disp[i] > disp[i-1], i );
}
for (int i=0; i<Attributes; i++) {
disp[i] -= base;
}
MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::Datatype );
MPI_Type_commit( &VertexPacked::Datatype );

}
{
VertexPacked dummyVertexPacked[2];

const int Attributes = 10;
MPI_Datatype subtypes[Attributes] = {
MPI_INT,		 //vertexIndex
MPI_INT,		 //adjacentCellsHeight
MPI_DOUBLE,		 //x
MPI_INT,		 //level
MPI_SHORT,		 //_packedRecords0
MPI_INT,		 //numberOfAdjacentEraseTriggers
MPI_CHAR,		 //particlesAddedToThisCell
MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
MPI_INT,		 //numberOfAdjacentRefinedCells
MPI_UB		 // end/displacement flag
};

int blocklen[Attributes] = {
1,		 //vertexIndex
1,		 //adjacentCellsHeight
DIMENSIONS,		 //x
1,		 //level
1,		 //_packedRecords0
1,		 //numberOfAdjacentEraseTriggers
1,		 //particlesAddedToThisCell
1,		 //adjacentCellsHeightOfPreviousIteration
1,		 //numberOfAdjacentRefinedCells
1		 // end/displacement flag
};

MPI_Aint     disp[Attributes];

MPI_Aint base;
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._vertexIndex))), 		&disp[0] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentCellsHeight))), 		&disp[1] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._x[0]))), 		&disp[2] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._level))), 		&disp[3] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[4] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentEraseTriggers))), 		&disp[5] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._particlesAddedToThisCell))), 		&disp[6] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[7] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[8] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._vertexIndex))), 		&disp[9] );

for (int i=1; i<Attributes; i++) {
assertion1( disp[i] > disp[i-1], i );
}
for (int i=0; i<Attributes; i++) {
disp[i] -= base;
}
MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::FullDatatype );
MPI_Type_commit( &VertexPacked::FullDatatype );

}

}


void particles::pidt::records::VertexPacked::shutdownDatatype() {
MPI_Type_free( &VertexPacked::Datatype );
MPI_Type_free( &VertexPacked::FullDatatype );

}

void particles::pidt::records::VertexPacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
_senderDestinationRank = destination;

if (communicateBlocking) {

const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
if  (result!=MPI_SUCCESS) {
std::ostringstream msg;
msg << "was not able to send message particles::pidt::records::VertexPacked "
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
msg << "was not able to send message particles::pidt::records::VertexPacked "
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
msg << "testing for finished send task for particles::pidt::records::VertexPacked "
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
"particles::pidt::records::VertexPacked",
"send(int)", destination,tag,1
);
triggeredTimeoutWarning = true;
}
if (
tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
(clock()>timeOutShutdown)
) {
tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
"particles::pidt::records::VertexPacked",
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



void particles::pidt::records::VertexPacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

MPI_Status  status;
const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
_senderDestinationRank = status.MPI_SOURCE;
if ( result != MPI_SUCCESS ) {
std::ostringstream msg;
msg << "failed to start to receive particles::pidt::records::VertexPacked from node "
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
msg << "failed to start to receive particles::pidt::records::VertexPacked from node "
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
msg << "testing for finished receive task for particles::pidt::records::VertexPacked failed: "
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
"particles::pidt::records::VertexPacked",
"receive(int)", source,tag,1
);
triggeredTimeoutWarning = true;
}
if (
tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
(clock()>timeOutShutdown)
) {
tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
"particles::pidt::records::VertexPacked",
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



bool particles::pidt::records::VertexPacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::VertexPacked::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif




#elif defined(Parallel) && !defined(Asserts)
particles::pidt::records::Vertex::PersistentRecords::PersistentRecords() {

}


particles::pidt::records::Vertex::PersistentRecords::PersistentRecords(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_vertexIndex(vertexIndex),
_isHangingNode(isHangingNode),
_refinementControl(refinementControl),
_adjacentCellsHeight(adjacentCellsHeight),
_insideOutsideDomain(insideOutsideDomain),
_adjacentRanks(adjacentRanks),
_adjacentSubtreeForksIntoOtherRank(adjacentSubtreeForksIntoOtherRank) {

}

particles::pidt::records::Vertex::Vertex() {

}


particles::pidt::records::Vertex::Vertex(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._vertexIndex, persistentRecords._isHangingNode, persistentRecords._refinementControl, persistentRecords._adjacentCellsHeight, persistentRecords._insideOutsideDomain, persistentRecords._adjacentRanks, persistentRecords._adjacentSubtreeForksIntoOtherRank) {

}


particles::pidt::records::Vertex::Vertex(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, adjacentRanks, adjacentSubtreeForksIntoOtherRank) {

}


particles::pidt::records::Vertex::Vertex(const int& numberOfAdjacentEraseTriggers, const bool& particlesAddedToThisCell, const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, adjacentRanks, adjacentSubtreeForksIntoOtherRank),_numberOfAdjacentEraseTriggers(numberOfAdjacentEraseTriggers),
_particlesAddedToThisCell(particlesAddedToThisCell),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {

}

particles::pidt::records::Vertex::~Vertex() { }

std::string particles::pidt::records::Vertex::toString(const InsideOutsideDomain& param) {
switch (param) {
case Inside: return "Inside";
case Boundary: return "Boundary";
case Outside: return "Outside";
}
return "undefined";
}

std::string particles::pidt::records::Vertex::getInsideOutsideDomainMapping() {
return "InsideOutsideDomain(Inside=0,Boundary=1,Outside=2)";
}
std::string particles::pidt::records::Vertex::toString(const RefinementControl& param) {
switch (param) {
case Unrefined: return "Unrefined";
case Refined: return "Refined";
case RefinementTriggered: return "RefinementTriggered";
case Refining: return "Refining";
case EraseTriggered: return "EraseTriggered";
case Erasing: return "Erasing";
case RefineDueToJoinThoughWorkerIsAlreadyErasing: return "RefineDueToJoinThoughWorkerIsAlreadyErasing";
}
return "undefined";
}

std::string particles::pidt::records::Vertex::getRefinementControlMapping() {
return "RefinementControl(Unrefined=0,Refined=1,RefinementTriggered=2,Refining=3,EraseTriggered=4,Erasing=5,RefineDueToJoinThoughWorkerIsAlreadyErasing=6)";
}


std::string particles::pidt::records::Vertex::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pidt::records::Vertex::toString (std::ostream& out) const {
out << "("; 
out << "numberOfAdjacentEraseTriggers:" << getNumberOfAdjacentEraseTriggers();
out << ",";
out << "particlesAddedToThisCell:" << getParticlesAddedToThisCell();
out << ",";
out << "vertexIndex:" << getVertexIndex();
out << ",";
out << "isHangingNode:" << getIsHangingNode();
out << ",";
out << "refinementControl:" << toString(getRefinementControl());
out << ",";
out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
out << ",";
out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
out << ",";
out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
out << ",";
out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
out << ",";
out << "adjacentRanks:[";
   for (int i = 0; i < TWO_POWER_D-1; i++) {
      out << getAdjacentRanks(i) << ",";
   }
   out << getAdjacentRanks(TWO_POWER_D-1) << "]";
out << ",";
out << "adjacentSubtreeForksIntoOtherRank:" << getAdjacentSubtreeForksIntoOtherRank();
out <<  ")";
}


particles::pidt::records::Vertex::PersistentRecords particles::pidt::records::Vertex::getPersistentRecords() const {
return _persistentRecords;
}

particles::pidt::records::VertexPacked particles::pidt::records::Vertex::convert() const{
return VertexPacked(
getNumberOfAdjacentEraseTriggers(),
getParticlesAddedToThisCell(),
getVertexIndex(),
getIsHangingNode(),
getRefinementControl(),
getAdjacentCellsHeight(),
getAdjacentCellsHeightOfPreviousIteration(),
getNumberOfAdjacentRefinedCells(),
getInsideOutsideDomain(),
getAdjacentRanks(),
getAdjacentSubtreeForksIntoOtherRank()
);
}

#ifdef Parallel
tarch::logging::Log particles::pidt::records::Vertex::_log( "particles::pidt::records::Vertex" );

MPI_Datatype particles::pidt::records::Vertex::Datatype = 0;
MPI_Datatype particles::pidt::records::Vertex::FullDatatype = 0;


void particles::pidt::records::Vertex::initDatatype() {
{
Vertex dummyVertex[2];

const int Attributes = 7;
MPI_Datatype subtypes[Attributes] = {
MPI_CHAR,		 //isHangingNode
MPI_INT,		 //refinementControl
MPI_INT,		 //adjacentRanks
MPI_CHAR,		 //adjacentSubtreeForksIntoOtherRank
MPI_INT,		 //numberOfAdjacentEraseTriggers
MPI_INT,		 //numberOfAdjacentRefinedCells
MPI_UB		 // end/displacement flag
};

int blocklen[Attributes] = {
1,		 //isHangingNode
1,		 //refinementControl
TWO_POWER_D,		 //adjacentRanks
1,		 //adjacentSubtreeForksIntoOtherRank
1,		 //numberOfAdjacentEraseTriggers
1,		 //numberOfAdjacentRefinedCells
1		 // end/displacement flag
};

MPI_Aint     disp[Attributes];

MPI_Aint base;
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[0] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[1] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentRanks[0]))), 		&disp[2] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentSubtreeForksIntoOtherRank))), 		&disp[3] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentEraseTriggers))), 		&disp[4] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[5] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._isHangingNode))), 		&disp[6] );

for (int i=1; i<Attributes; i++) {
assertion1( disp[i] > disp[i-1], i );
}
for (int i=0; i<Attributes; i++) {
disp[i] -= base;
}
MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::Datatype );
MPI_Type_commit( &Vertex::Datatype );

}
{
Vertex dummyVertex[2];

const int Attributes = 12;
MPI_Datatype subtypes[Attributes] = {
MPI_INT,		 //vertexIndex
MPI_CHAR,		 //isHangingNode
MPI_INT,		 //refinementControl
MPI_INT,		 //adjacentCellsHeight
MPI_INT,		 //insideOutsideDomain
MPI_INT,		 //adjacentRanks
MPI_CHAR,		 //adjacentSubtreeForksIntoOtherRank
MPI_INT,		 //numberOfAdjacentEraseTriggers
MPI_CHAR,		 //particlesAddedToThisCell
MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
MPI_INT,		 //numberOfAdjacentRefinedCells
MPI_UB		 // end/displacement flag
};

int blocklen[Attributes] = {
1,		 //vertexIndex
1,		 //isHangingNode
1,		 //refinementControl
1,		 //adjacentCellsHeight
1,		 //insideOutsideDomain
TWO_POWER_D,		 //adjacentRanks
1,		 //adjacentSubtreeForksIntoOtherRank
1,		 //numberOfAdjacentEraseTriggers
1,		 //particlesAddedToThisCell
1,		 //adjacentCellsHeightOfPreviousIteration
1,		 //numberOfAdjacentRefinedCells
1		 // end/displacement flag
};

MPI_Aint     disp[Attributes];

MPI_Aint base;
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]))), &base);
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._vertexIndex))), 		&disp[0] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._isHangingNode))), 		&disp[1] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._refinementControl))), 		&disp[2] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentCellsHeight))), 		&disp[3] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._insideOutsideDomain))), 		&disp[4] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentRanks[0]))), 		&disp[5] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._persistentRecords._adjacentSubtreeForksIntoOtherRank))), 		&disp[6] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentEraseTriggers))), 		&disp[7] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._particlesAddedToThisCell))), 		&disp[8] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[9] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[0]._numberOfAdjacentRefinedCells))), 		&disp[10] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertex[1]._persistentRecords._vertexIndex))), 		&disp[11] );

for (int i=1; i<Attributes; i++) {
assertion1( disp[i] > disp[i-1], i );
}
for (int i=0; i<Attributes; i++) {
disp[i] -= base;
}
MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Vertex::FullDatatype );
MPI_Type_commit( &Vertex::FullDatatype );

}

}


void particles::pidt::records::Vertex::shutdownDatatype() {
MPI_Type_free( &Vertex::Datatype );
MPI_Type_free( &Vertex::FullDatatype );

}

void particles::pidt::records::Vertex::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
_senderDestinationRank = destination;

if (communicateBlocking) {

const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
if  (result!=MPI_SUCCESS) {
std::ostringstream msg;
msg << "was not able to send message particles::pidt::records::Vertex "
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
msg << "was not able to send message particles::pidt::records::Vertex "
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
msg << "testing for finished send task for particles::pidt::records::Vertex "
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
"particles::pidt::records::Vertex",
"send(int)", destination,tag,1
);
triggeredTimeoutWarning = true;
}
if (
tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
(clock()>timeOutShutdown)
) {
tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
"particles::pidt::records::Vertex",
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



void particles::pidt::records::Vertex::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

MPI_Status  status;
const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
_senderDestinationRank = status.MPI_SOURCE;
if ( result != MPI_SUCCESS ) {
std::ostringstream msg;
msg << "failed to start to receive particles::pidt::records::Vertex from node "
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
msg << "failed to start to receive particles::pidt::records::Vertex from node "
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
msg << "testing for finished receive task for particles::pidt::records::Vertex failed: "
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
"particles::pidt::records::Vertex",
"receive(int)", source,tag,1
);
triggeredTimeoutWarning = true;
}
if (
tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
(clock()>timeOutShutdown)
) {
tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
"particles::pidt::records::Vertex",
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



bool particles::pidt::records::Vertex::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::Vertex::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif


particles::pidt::records::VertexPacked::PersistentRecords::PersistentRecords() {
assertion((7 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::PersistentRecords::PersistentRecords(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_vertexIndex(vertexIndex),
_adjacentCellsHeight(adjacentCellsHeight),
_adjacentRanks(adjacentRanks) {
setIsHangingNode(isHangingNode);
setRefinementControl(refinementControl);
setInsideOutsideDomain(insideOutsideDomain);
setAdjacentSubtreeForksIntoOtherRank(adjacentSubtreeForksIntoOtherRank);
assertion((7 < (8 * sizeof(short int))));

}

particles::pidt::records::VertexPacked::VertexPacked() {
assertion((7 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._vertexIndex, persistentRecords.getIsHangingNode(), persistentRecords.getRefinementControl(), persistentRecords._adjacentCellsHeight, persistentRecords.getInsideOutsideDomain(), persistentRecords._adjacentRanks, persistentRecords.getAdjacentSubtreeForksIntoOtherRank()) {
assertion((7 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, adjacentRanks, adjacentSubtreeForksIntoOtherRank) {
assertion((7 < (8 * sizeof(short int))));

}


particles::pidt::records::VertexPacked::VertexPacked(const int& numberOfAdjacentEraseTriggers, const bool& particlesAddedToThisCell, const int& vertexIndex, const bool& isHangingNode, const RefinementControl& refinementControl, const int& adjacentCellsHeight, const int& adjacentCellsHeightOfPreviousIteration, const int& numberOfAdjacentRefinedCells, const InsideOutsideDomain& insideOutsideDomain, const tarch::la::Vector<TWO_POWER_D,int>& adjacentRanks, const bool& adjacentSubtreeForksIntoOtherRank):
_persistentRecords(vertexIndex, isHangingNode, refinementControl, adjacentCellsHeight, insideOutsideDomain, adjacentRanks, adjacentSubtreeForksIntoOtherRank),_numberOfAdjacentEraseTriggers(numberOfAdjacentEraseTriggers),
_particlesAddedToThisCell(particlesAddedToThisCell),
_adjacentCellsHeightOfPreviousIteration(adjacentCellsHeightOfPreviousIteration),
_numberOfAdjacentRefinedCells(numberOfAdjacentRefinedCells) {
assertion((7 < (8 * sizeof(short int))));

}

particles::pidt::records::VertexPacked::~VertexPacked() { }

std::string particles::pidt::records::VertexPacked::toString(const InsideOutsideDomain& param) {
return particles::pidt::records::Vertex::toString(param);
}

std::string particles::pidt::records::VertexPacked::getInsideOutsideDomainMapping() {
return particles::pidt::records::Vertex::getInsideOutsideDomainMapping();
}

std::string particles::pidt::records::VertexPacked::toString(const RefinementControl& param) {
return particles::pidt::records::Vertex::toString(param);
}

std::string particles::pidt::records::VertexPacked::getRefinementControlMapping() {
return particles::pidt::records::Vertex::getRefinementControlMapping();
}



std::string particles::pidt::records::VertexPacked::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pidt::records::VertexPacked::toString (std::ostream& out) const {
out << "("; 
out << "numberOfAdjacentEraseTriggers:" << getNumberOfAdjacentEraseTriggers();
out << ",";
out << "particlesAddedToThisCell:" << getParticlesAddedToThisCell();
out << ",";
out << "vertexIndex:" << getVertexIndex();
out << ",";
out << "isHangingNode:" << getIsHangingNode();
out << ",";
out << "refinementControl:" << toString(getRefinementControl());
out << ",";
out << "adjacentCellsHeight:" << getAdjacentCellsHeight();
out << ",";
out << "adjacentCellsHeightOfPreviousIteration:" << getAdjacentCellsHeightOfPreviousIteration();
out << ",";
out << "numberOfAdjacentRefinedCells:" << getNumberOfAdjacentRefinedCells();
out << ",";
out << "insideOutsideDomain:" << toString(getInsideOutsideDomain());
out << ",";
out << "adjacentRanks:[";
   for (int i = 0; i < TWO_POWER_D-1; i++) {
      out << getAdjacentRanks(i) << ",";
   }
   out << getAdjacentRanks(TWO_POWER_D-1) << "]";
out << ",";
out << "adjacentSubtreeForksIntoOtherRank:" << getAdjacentSubtreeForksIntoOtherRank();
out <<  ")";
}


particles::pidt::records::VertexPacked::PersistentRecords particles::pidt::records::VertexPacked::getPersistentRecords() const {
return _persistentRecords;
}

particles::pidt::records::Vertex particles::pidt::records::VertexPacked::convert() const{
return Vertex(
getNumberOfAdjacentEraseTriggers(),
getParticlesAddedToThisCell(),
getVertexIndex(),
getIsHangingNode(),
getRefinementControl(),
getAdjacentCellsHeight(),
getAdjacentCellsHeightOfPreviousIteration(),
getNumberOfAdjacentRefinedCells(),
getInsideOutsideDomain(),
getAdjacentRanks(),
getAdjacentSubtreeForksIntoOtherRank()
);
}

#ifdef Parallel
tarch::logging::Log particles::pidt::records::VertexPacked::_log( "particles::pidt::records::VertexPacked" );

MPI_Datatype particles::pidt::records::VertexPacked::Datatype = 0;
MPI_Datatype particles::pidt::records::VertexPacked::FullDatatype = 0;


void particles::pidt::records::VertexPacked::initDatatype() {
{
VertexPacked dummyVertexPacked[2];

const int Attributes = 5;
MPI_Datatype subtypes[Attributes] = {
MPI_INT,		 //adjacentRanks
MPI_SHORT,		 //_packedRecords0
MPI_INT,		 //numberOfAdjacentEraseTriggers
MPI_INT,		 //numberOfAdjacentRefinedCells
MPI_UB		 // end/displacement flag
};

int blocklen[Attributes] = {
TWO_POWER_D,		 //adjacentRanks
1,		 //_packedRecords0
1,		 //numberOfAdjacentEraseTriggers
1,		 //numberOfAdjacentRefinedCells
1		 // end/displacement flag
};

MPI_Aint     disp[Attributes];

MPI_Aint base;
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentRanks[0]))), 		&disp[0] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[1] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentEraseTriggers))), 		&disp[2] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[3] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyVertexPacked[1]._persistentRecords._adjacentRanks[0])), 		&disp[4] );

for (int i=1; i<Attributes; i++) {
assertion1( disp[i] > disp[i-1], i );
}
for (int i=0; i<Attributes; i++) {
disp[i] -= base;
}
MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::Datatype );
MPI_Type_commit( &VertexPacked::Datatype );

}
{
VertexPacked dummyVertexPacked[2];

const int Attributes = 9;
MPI_Datatype subtypes[Attributes] = {
MPI_INT,		 //vertexIndex
MPI_INT,		 //adjacentCellsHeight
MPI_INT,		 //adjacentRanks
MPI_SHORT,		 //_packedRecords0
MPI_INT,		 //numberOfAdjacentEraseTriggers
MPI_CHAR,		 //particlesAddedToThisCell
MPI_INT,		 //adjacentCellsHeightOfPreviousIteration
MPI_INT,		 //numberOfAdjacentRefinedCells
MPI_UB		 // end/displacement flag
};

int blocklen[Attributes] = {
1,		 //vertexIndex
1,		 //adjacentCellsHeight
TWO_POWER_D,		 //adjacentRanks
1,		 //_packedRecords0
1,		 //numberOfAdjacentEraseTriggers
1,		 //particlesAddedToThisCell
1,		 //adjacentCellsHeightOfPreviousIteration
1,		 //numberOfAdjacentRefinedCells
1		 // end/displacement flag
};

MPI_Aint     disp[Attributes];

MPI_Aint base;
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]))), &base);
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._vertexIndex))), 		&disp[0] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentCellsHeight))), 		&disp[1] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._adjacentRanks[0]))), 		&disp[2] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._persistentRecords._packedRecords0))), 		&disp[3] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentEraseTriggers))), 		&disp[4] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._particlesAddedToThisCell))), 		&disp[5] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._adjacentCellsHeightOfPreviousIteration))), 		&disp[6] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[0]._numberOfAdjacentRefinedCells))), 		&disp[7] );
MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyVertexPacked[1]._persistentRecords._vertexIndex))), 		&disp[8] );

for (int i=1; i<Attributes; i++) {
assertion1( disp[i] > disp[i-1], i );
}
for (int i=0; i<Attributes; i++) {
disp[i] -= base;
}
MPI_Type_struct( Attributes, blocklen, disp, subtypes, &VertexPacked::FullDatatype );
MPI_Type_commit( &VertexPacked::FullDatatype );

}

}


void particles::pidt::records::VertexPacked::shutdownDatatype() {
MPI_Type_free( &VertexPacked::Datatype );
MPI_Type_free( &VertexPacked::FullDatatype );

}

void particles::pidt::records::VertexPacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
_senderDestinationRank = destination;

if (communicateBlocking) {

const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
if  (result!=MPI_SUCCESS) {
std::ostringstream msg;
msg << "was not able to send message particles::pidt::records::VertexPacked "
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
msg << "was not able to send message particles::pidt::records::VertexPacked "
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
msg << "testing for finished send task for particles::pidt::records::VertexPacked "
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
"particles::pidt::records::VertexPacked",
"send(int)", destination,tag,1
);
triggeredTimeoutWarning = true;
}
if (
tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
(clock()>timeOutShutdown)
) {
tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
"particles::pidt::records::VertexPacked",
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



void particles::pidt::records::VertexPacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

MPI_Status  status;
const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
_senderDestinationRank = status.MPI_SOURCE;
if ( result != MPI_SUCCESS ) {
std::ostringstream msg;
msg << "failed to start to receive particles::pidt::records::VertexPacked from node "
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
msg << "failed to start to receive particles::pidt::records::VertexPacked from node "
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
msg << "testing for finished receive task for particles::pidt::records::VertexPacked failed: "
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
"particles::pidt::records::VertexPacked",
"receive(int)", source,tag,1
);
triggeredTimeoutWarning = true;
}
if (
tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
(clock()>timeOutShutdown)
) {
tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
"particles::pidt::records::VertexPacked",
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



bool particles::pidt::records::VertexPacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::VertexPacked::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif




#endif


