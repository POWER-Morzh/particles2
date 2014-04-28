#include "particles/pidt/records/RepositoryState.h"

particles::pidt::records::RepositoryState::PersistentRecords::PersistentRecords() {
   
}


particles::pidt::records::RepositoryState::PersistentRecords::PersistentRecords(const Action& action):
_action(action) {
   
}

particles::pidt::records::RepositoryState::RepositoryState() {
   
}


particles::pidt::records::RepositoryState::RepositoryState(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._action) {
   
}


particles::pidt::records::RepositoryState::RepositoryState(const Action& action):
_persistentRecords(action) {
   
}


particles::pidt::records::RepositoryState::~RepositoryState() { }

std::string particles::pidt::records::RepositoryState::toString(const Action& param) {
   switch (param) {
      case WriteCheckpoint: return "WriteCheckpoint";
      case ReadCheckpoint: return "ReadCheckpoint";
      case Terminate: return "Terminate";
      case RunOnAllNodes: return "RunOnAllNodes";
      case UseAdapterNop: return "UseAdapterNop";
      case UseAdapterInitGrid: return "UseAdapterInitGrid";
      case UseAdapterInitGridAndPlot: return "UseAdapterInitGridAndPlot";
      case UseAdapterSetupExperimentWithRandomParticleDistribution: return "UseAdapterSetupExperimentWithRandomParticleDistribution";
      case UseAdapterSetupExperimentWithRandomParticleDistributionAndPlot: return "UseAdapterSetupExperimentWithRandomParticleDistributionAndPlot";
      case UseAdapterMoveParticles: return "UseAdapterMoveParticles";
      case UseAdapterMoveParticlesAndPlot: return "UseAdapterMoveParticlesAndPlot";
      case NumberOfAdapters: return "NumberOfAdapters";
   }
   return "undefined";
}

std::string particles::pidt::records::RepositoryState::getActionMapping() {
   return "Action(WriteCheckpoint=0,ReadCheckpoint=1,Terminate=2,RunOnAllNodes=3,UseAdapterNop=4,UseAdapterInitGrid=5,UseAdapterInitGridAndPlot=6,UseAdapterSetupExperimentWithRandomParticleDistribution=7,UseAdapterSetupExperimentWithRandomParticleDistributionAndPlot=8,UseAdapterMoveParticles=9,UseAdapterMoveParticlesAndPlot=10,NumberOfAdapters=11)";
}


std::string particles::pidt::records::RepositoryState::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void particles::pidt::records::RepositoryState::toString (std::ostream& out) const {
   out << "("; 
   out << "action:" << toString(getAction());
   out <<  ")";
}


particles::pidt::records::RepositoryState::PersistentRecords particles::pidt::records::RepositoryState::getPersistentRecords() const {
   return _persistentRecords;
}

particles::pidt::records::RepositoryStatePacked particles::pidt::records::RepositoryState::convert() const{
   return RepositoryStatePacked(
      getAction()
   );
}

#ifdef Parallel
   tarch::logging::Log particles::pidt::records::RepositoryState::_log( "particles::pidt::records::RepositoryState" );
   
   MPI_Datatype particles::pidt::records::RepositoryState::Datatype = 0;
   MPI_Datatype particles::pidt::records::RepositoryState::FullDatatype = 0;
   
   
   void particles::pidt::records::RepositoryState::initDatatype() {
      {
         RepositoryState dummyRepositoryState[2];
         
         const int Attributes = 2;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //action
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //action
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]._persistentRecords._action))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[1]._persistentRecords._action))), 		&disp[1] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &RepositoryState::Datatype );
         MPI_Type_commit( &RepositoryState::Datatype );
         
      }
      {
         RepositoryState dummyRepositoryState[2];
         
         const int Attributes = 2;
         MPI_Datatype subtypes[Attributes] = {
            MPI_INT,		 //action
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            1,		 //action
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[0]._persistentRecords._action))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryState[1]._persistentRecords._action))), 		&disp[1] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &RepositoryState::FullDatatype );
         MPI_Type_commit( &RepositoryState::FullDatatype );
         
      }
      
   }
   
   
   void particles::pidt::records::RepositoryState::shutdownDatatype() {
      MPI_Type_free( &RepositoryState::Datatype );
      MPI_Type_free( &RepositoryState::FullDatatype );
      
   }
   
   void particles::pidt::records::RepositoryState::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      _senderDestinationRank = destination;
      
      if (communicateBlocking) {
      
         const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pidt::records::RepositoryState "
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
         msg << "was not able to send message particles::pidt::records::RepositoryState "
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
            msg << "testing for finished send task for particles::pidt::records::RepositoryState "
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
            "particles::pidt::records::RepositoryState",
            "send(int)", destination,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "particles::pidt::records::RepositoryState",
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



void particles::pidt::records::RepositoryState::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
   if (communicateBlocking) {
   
      MPI_Status  status;
      const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
      _senderDestinationRank = status.MPI_SOURCE;
      if ( result != MPI_SUCCESS ) {
         std::ostringstream msg;
         msg << "failed to start to receive particles::pidt::records::RepositoryState from node "
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
         msg << "failed to start to receive particles::pidt::records::RepositoryState from node "
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
            msg << "testing for finished receive task for particles::pidt::records::RepositoryState failed: "
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
            "particles::pidt::records::RepositoryState",
            "receive(int)", source,tag,1
            );
            triggeredTimeoutWarning = true;
         }
         if (
            tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
            (clock()>timeOutShutdown)
         ) {
            tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
            "particles::pidt::records::RepositoryState",
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



bool particles::pidt::records::RepositoryState::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::RepositoryState::getSenderRank() const {
   assertion( _senderDestinationRank!=-1 );
   return _senderDestinationRank;
   
}
#endif


particles::pidt::records::RepositoryStatePacked::PersistentRecords::PersistentRecords() {

}


particles::pidt::records::RepositoryStatePacked::PersistentRecords::PersistentRecords(const Action& action):
_action(action) {

}

particles::pidt::records::RepositoryStatePacked::RepositoryStatePacked() {

}


particles::pidt::records::RepositoryStatePacked::RepositoryStatePacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._action) {

}


particles::pidt::records::RepositoryStatePacked::RepositoryStatePacked(const Action& action):
_persistentRecords(action) {

}


particles::pidt::records::RepositoryStatePacked::~RepositoryStatePacked() { }

std::string particles::pidt::records::RepositoryStatePacked::toString(const Action& param) {
return particles::pidt::records::RepositoryState::toString(param);
}

std::string particles::pidt::records::RepositoryStatePacked::getActionMapping() {
return particles::pidt::records::RepositoryState::getActionMapping();
}



std::string particles::pidt::records::RepositoryStatePacked::toString() const {
std::ostringstream stringstr;
toString(stringstr);
return stringstr.str();
}

void particles::pidt::records::RepositoryStatePacked::toString (std::ostream& out) const {
out << "("; 
out << "action:" << toString(getAction());
out <<  ")";
}


particles::pidt::records::RepositoryStatePacked::PersistentRecords particles::pidt::records::RepositoryStatePacked::getPersistentRecords() const {
return _persistentRecords;
}

particles::pidt::records::RepositoryState particles::pidt::records::RepositoryStatePacked::convert() const{
return RepositoryState(
   getAction()
);
}

#ifdef Parallel
tarch::logging::Log particles::pidt::records::RepositoryStatePacked::_log( "particles::pidt::records::RepositoryStatePacked" );

MPI_Datatype particles::pidt::records::RepositoryStatePacked::Datatype = 0;
MPI_Datatype particles::pidt::records::RepositoryStatePacked::FullDatatype = 0;


void particles::pidt::records::RepositoryStatePacked::initDatatype() {
   {
      RepositoryStatePacked dummyRepositoryStatePacked[2];
      
      const int Attributes = 2;
      MPI_Datatype subtypes[Attributes] = {
         MPI_INT,		 //action
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         1,		 //action
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]._persistentRecords._action))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[1]._persistentRecords._action))), 		&disp[1] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &RepositoryStatePacked::Datatype );
      MPI_Type_commit( &RepositoryStatePacked::Datatype );
      
   }
   {
      RepositoryStatePacked dummyRepositoryStatePacked[2];
      
      const int Attributes = 2;
      MPI_Datatype subtypes[Attributes] = {
         MPI_INT,		 //action
         MPI_UB		 // end/displacement flag
      };
      
      int blocklen[Attributes] = {
         1,		 //action
         1		 // end/displacement flag
      };
      
      MPI_Aint     disp[Attributes];
      
      MPI_Aint base;
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]))), &base);
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[0]._persistentRecords._action))), 		&disp[0] );
      MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyRepositoryStatePacked[1]._persistentRecords._action))), 		&disp[1] );
      
      for (int i=1; i<Attributes; i++) {
         assertion1( disp[i] > disp[i-1], i );
      }
      for (int i=0; i<Attributes; i++) {
         disp[i] -= base;
      }
      MPI_Type_struct( Attributes, blocklen, disp, subtypes, &RepositoryStatePacked::FullDatatype );
      MPI_Type_commit( &RepositoryStatePacked::FullDatatype );
      
   }
   
}


void particles::pidt::records::RepositoryStatePacked::shutdownDatatype() {
   MPI_Type_free( &RepositoryStatePacked::Datatype );
   MPI_Type_free( &RepositoryStatePacked::FullDatatype );
   
}

void particles::pidt::records::RepositoryStatePacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
   _senderDestinationRank = destination;
   
   if (communicateBlocking) {
   
      const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
      if  (result!=MPI_SUCCESS) {
         std::ostringstream msg;
         msg << "was not able to send message particles::pidt::records::RepositoryStatePacked "
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
      msg << "was not able to send message particles::pidt::records::RepositoryStatePacked "
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
         msg << "testing for finished send task for particles::pidt::records::RepositoryStatePacked "
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
         "particles::pidt::records::RepositoryStatePacked",
         "send(int)", destination,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "particles::pidt::records::RepositoryStatePacked",
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



void particles::pidt::records::RepositoryStatePacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
if (communicateBlocking) {

   MPI_Status  status;
   const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
   _senderDestinationRank = status.MPI_SOURCE;
   if ( result != MPI_SUCCESS ) {
      std::ostringstream msg;
      msg << "failed to start to receive particles::pidt::records::RepositoryStatePacked from node "
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
      msg << "failed to start to receive particles::pidt::records::RepositoryStatePacked from node "
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
         msg << "testing for finished receive task for particles::pidt::records::RepositoryStatePacked failed: "
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
         "particles::pidt::records::RepositoryStatePacked",
         "receive(int)", source,tag,1
         );
         triggeredTimeoutWarning = true;
      }
      if (
         tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
         (clock()>timeOutShutdown)
      ) {
         tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
         "particles::pidt::records::RepositoryStatePacked",
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



bool particles::pidt::records::RepositoryStatePacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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

int particles::pidt::records::RepositoryStatePacked::getSenderRank() const {
assertion( _senderDestinationRank!=-1 );
return _senderDestinationRank;

}
#endif



