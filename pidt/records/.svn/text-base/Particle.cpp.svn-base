#include "particles/pidt/records/Particle.h"

particles::pidt::records::Particle::PersistentRecords::PersistentRecords() {
   
}


particles::pidt::records::Particle::PersistentRecords::PersistentRecords(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& v, const MoveState& movedParticle):
_x(x),
_v(v),
_movedParticle(movedParticle) {
   
}


/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pidt::records::Particle::PersistentRecords::getX() const  {
   return _x;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pidt::records::Particle::PersistentRecords::setX(const tarch::la::Vector<DIMENSIONS,double>& x)  {
   _x = (x);
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pidt::records::Particle::PersistentRecords::getV() const  {
   return _v;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pidt::records::Particle::PersistentRecords::setV(const tarch::la::Vector<DIMENSIONS,double>& v)  {
   _v = (v);
}



 particles::pidt::records::Particle::MoveState particles::pidt::records::Particle::PersistentRecords::getMovedParticle() const  {
   return _movedParticle;
}



 void particles::pidt::records::Particle::PersistentRecords::setMovedParticle(const MoveState& movedParticle)  {
   _movedParticle = movedParticle;
}


particles::pidt::records::Particle::Particle() {
   
}


particles::pidt::records::Particle::Particle(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._x, persistentRecords._v, persistentRecords._movedParticle) {
   
}


particles::pidt::records::Particle::Particle(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& v, const MoveState& movedParticle):
_persistentRecords(x, v, movedParticle) {
   
}


particles::pidt::records::Particle::~Particle() { }


/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pidt::records::Particle::getX() const  {
   return _persistentRecords._x;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pidt::records::Particle::setX(const tarch::la::Vector<DIMENSIONS,double>& x)  {
   _persistentRecords._x = (x);
}



 double particles::pidt::records::Particle::getX(int elementIndex) const  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   return _persistentRecords._x[elementIndex];
   
}



 void particles::pidt::records::Particle::setX(int elementIndex, const double& x)  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   _persistentRecords._x[elementIndex]= x;
   
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pidt::records::Particle::getV() const  {
   return _persistentRecords._v;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pidt::records::Particle::setV(const tarch::la::Vector<DIMENSIONS,double>& v)  {
   _persistentRecords._v = (v);
}



 double particles::pidt::records::Particle::getV(int elementIndex) const  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   return _persistentRecords._v[elementIndex];
   
}



 void particles::pidt::records::Particle::setV(int elementIndex, const double& v)  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   _persistentRecords._v[elementIndex]= v;
   
}



 particles::pidt::records::Particle::MoveState particles::pidt::records::Particle::getMovedParticle() const  {
   return _persistentRecords._movedParticle;
}



 void particles::pidt::records::Particle::setMovedParticle(const MoveState& movedParticle)  {
   _persistentRecords._movedParticle = movedParticle;
}


std::string particles::pidt::records::Particle::toString(const MoveState& param) {
   switch (param) {
      case New: return "New";
      case NotMovedYet: return "NotMovedYet";
      case Moved: return "Moved";
   }
   return "undefined";
}

std::string particles::pidt::records::Particle::getMoveStateMapping() {
   return "MoveState(New=0,NotMovedYet=1,Moved=2)";
}


std::string particles::pidt::records::Particle::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void particles::pidt::records::Particle::toString (std::ostream& out) const {
   out << "("; 
   out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
   out << ",";
   out << "v:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getV(i) << ",";
   }
   out << getV(DIMENSIONS-1) << "]";
   out << ",";
   out << "movedParticle:" << toString(getMovedParticle());
   out <<  ")";
}


particles::pidt::records::Particle::PersistentRecords particles::pidt::records::Particle::getPersistentRecords() const {
   return _persistentRecords;
}

particles::pidt::records::ParticlePacked particles::pidt::records::Particle::convert() const{
   return ParticlePacked(
      getX(),
      getV(),
      getMovedParticle()
   );
}

#ifdef Parallel
   tarch::logging::Log particles::pidt::records::Particle::_log( "particles::pidt::records::Particle" );
   
   MPI_Datatype particles::pidt::records::Particle::Datatype = 0;
   MPI_Datatype particles::pidt::records::Particle::FullDatatype = 0;
   
   
   void particles::pidt::records::Particle::initDatatype() {
      {
         Particle dummyParticle[2];
         
         const int Attributes = 4;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_DOUBLE,		 //v
            MPI_INT,		 //movedParticle
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            DIMENSIONS,		 //v
            1,		 //movedParticle
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._v[0]))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._movedParticle))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyParticle[1]._persistentRecords._x[0])), 		&disp[3] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Particle::Datatype );
         MPI_Type_commit( &Particle::Datatype );
         
      }
      {
         Particle dummyParticle[2];
         
         const int Attributes = 4;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_DOUBLE,		 //v
            MPI_INT,		 //movedParticle
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            DIMENSIONS,		 //v
            1,		 //movedParticle
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._v[0]))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticle[0]._persistentRecords._movedParticle))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyParticle[1]._persistentRecords._x[0])), 		&disp[3] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &Particle::FullDatatype );
         MPI_Type_commit( &Particle::FullDatatype );
         
      }
      
   }
   
   
   void particles::pidt::records::Particle::shutdownDatatype() {
      MPI_Type_free( &Particle::Datatype );
      MPI_Type_free( &Particle::FullDatatype );
      
   }
   
   void particles::pidt::records::Particle::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pidt::records::Particle "
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
            msg << "was not able to send message particles::pidt::records::Particle "
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
               msg << "testing for finished send task for particles::pidt::records::Particle "
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
               "particles::pidt::records::Particle",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pidt::records::Particle",
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
   
   
   
   void particles::pidt::records::Particle::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         MPI_Status  status;
         const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pidt::records::Particle from node "
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
            msg << "failed to start to receive particles::pidt::records::Particle from node "
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
               msg << "testing for finished receive task for particles::pidt::records::Particle failed: "
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
               "particles::pidt::records::Particle",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pidt::records::Particle",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
   }
   
   
   
   bool particles::pidt::records::Particle::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
   
   
#endif


particles::pidt::records::ParticlePacked::PersistentRecords::PersistentRecords() {
   assertion((2 < (8 * sizeof(short int))));
   
}


particles::pidt::records::ParticlePacked::PersistentRecords::PersistentRecords(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& v, const MoveState& movedParticle):
_x(x),
_v(v) {
   setMovedParticle(movedParticle);
   assertion((2 < (8 * sizeof(short int))));
   
}


/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pidt::records::ParticlePacked::PersistentRecords::getX() const  {
   return _x;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pidt::records::ParticlePacked::PersistentRecords::setX(const tarch::la::Vector<DIMENSIONS,double>& x)  {
   _x = (x);
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pidt::records::ParticlePacked::PersistentRecords::getV() const  {
   return _v;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pidt::records::ParticlePacked::PersistentRecords::setV(const tarch::la::Vector<DIMENSIONS,double>& v)  {
   _v = (v);
}



 particles::pidt::records::Particle::MoveState particles::pidt::records::ParticlePacked::PersistentRecords::getMovedParticle() const  {
   short int mask =  (1 << (2)) - 1;
   mask = static_cast<short int>(mask << (0));
   short int tmp = static_cast<short int>(_packedRecords0 & mask);
   tmp = static_cast<short int>(tmp >> (0));
   assertion(( tmp >= 0 &&  tmp <= 2));
   return (MoveState) tmp;
}



 void particles::pidt::records::ParticlePacked::PersistentRecords::setMovedParticle(const MoveState& movedParticle)  {
   assertion((movedParticle >= 0 && movedParticle <= 2));
   short int mask =  (1 << (2)) - 1;
   mask = static_cast<short int>(mask << (0));
   _packedRecords0 = static_cast<short int>(_packedRecords0 & ~mask);
   _packedRecords0 = static_cast<short int>(_packedRecords0 | movedParticle << (0));
}


particles::pidt::records::ParticlePacked::ParticlePacked() {
   assertion((2 < (8 * sizeof(short int))));
   
}


particles::pidt::records::ParticlePacked::ParticlePacked(const PersistentRecords& persistentRecords):
_persistentRecords(persistentRecords._x, persistentRecords._v, persistentRecords.getMovedParticle()) {
   assertion((2 < (8 * sizeof(short int))));
   
}


particles::pidt::records::ParticlePacked::ParticlePacked(const tarch::la::Vector<DIMENSIONS,double>& x, const tarch::la::Vector<DIMENSIONS,double>& v, const MoveState& movedParticle):
_persistentRecords(x, v, movedParticle) {
   assertion((2 < (8 * sizeof(short int))));
   
}


particles::pidt::records::ParticlePacked::~ParticlePacked() { }


/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pidt::records::ParticlePacked::getX() const  {
   return _persistentRecords._x;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pidt::records::ParticlePacked::setX(const tarch::la::Vector<DIMENSIONS,double>& x)  {
   _persistentRecords._x = (x);
}



 double particles::pidt::records::ParticlePacked::getX(int elementIndex) const  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   return _persistentRecords._x[elementIndex];
   
}



 void particles::pidt::records::ParticlePacked::setX(int elementIndex, const double& x)  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   _persistentRecords._x[elementIndex]= x;
   
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 tarch::la::Vector<DIMENSIONS,double> particles::pidt::records::ParticlePacked::getV() const  {
   return _persistentRecords._v;
}



/**
 * Generated and optimized
 * 
 * If you realise a for loop using exclusively arrays (vectors) and compile 
 * with -DUseManualAlignment you may add 
 * \code
 #pragma vector aligned
 #pragma simd
 \endcode to this for loop to enforce your compiler to use SSE/AVX.
 * 
 * The alignment is tied to the unpacked records, i.e. for packed class
 * variants the machine's natural alignment is switched off to recude the  
 * memory footprint. Do not use any SSE/AVX operations or 
 * vectorisation on the result for the packed variants, as the data is misaligned. 
 * If you rely on vectorisation, convert the underlying record 
 * into the unpacked version first. 
 * 
 * @see convert()
 */
 void particles::pidt::records::ParticlePacked::setV(const tarch::la::Vector<DIMENSIONS,double>& v)  {
   _persistentRecords._v = (v);
}



 double particles::pidt::records::ParticlePacked::getV(int elementIndex) const  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   return _persistentRecords._v[elementIndex];
   
}



 void particles::pidt::records::ParticlePacked::setV(int elementIndex, const double& v)  {
   assertion(elementIndex>=0);
   assertion(elementIndex<DIMENSIONS);
   _persistentRecords._v[elementIndex]= v;
   
}



 particles::pidt::records::Particle::MoveState particles::pidt::records::ParticlePacked::getMovedParticle() const  {
   short int mask =  (1 << (2)) - 1;
   mask = static_cast<short int>(mask << (0));
   short int tmp = static_cast<short int>(_persistentRecords._packedRecords0 & mask);
   tmp = static_cast<short int>(tmp >> (0));
   assertion(( tmp >= 0 &&  tmp <= 2));
   return (MoveState) tmp;
}



 void particles::pidt::records::ParticlePacked::setMovedParticle(const MoveState& movedParticle)  {
   assertion((movedParticle >= 0 && movedParticle <= 2));
   short int mask =  (1 << (2)) - 1;
   mask = static_cast<short int>(mask << (0));
   _persistentRecords._packedRecords0 = static_cast<short int>(_persistentRecords._packedRecords0 & ~mask);
   _persistentRecords._packedRecords0 = static_cast<short int>(_persistentRecords._packedRecords0 | movedParticle << (0));
}


std::string particles::pidt::records::ParticlePacked::toString(const MoveState& param) {
   return particles::pidt::records::Particle::toString(param);
}

std::string particles::pidt::records::ParticlePacked::getMoveStateMapping() {
   return particles::pidt::records::Particle::getMoveStateMapping();
}



std::string particles::pidt::records::ParticlePacked::toString() const {
   std::ostringstream stringstr;
   toString(stringstr);
   return stringstr.str();
}

void particles::pidt::records::ParticlePacked::toString (std::ostream& out) const {
   out << "("; 
   out << "x:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getX(i) << ",";
   }
   out << getX(DIMENSIONS-1) << "]";
   out << ",";
   out << "v:[";
   for (int i = 0; i < DIMENSIONS-1; i++) {
      out << getV(i) << ",";
   }
   out << getV(DIMENSIONS-1) << "]";
   out << ",";
   out << "movedParticle:" << toString(getMovedParticle());
   out <<  ")";
}


particles::pidt::records::ParticlePacked::PersistentRecords particles::pidt::records::ParticlePacked::getPersistentRecords() const {
   return _persistentRecords;
}

particles::pidt::records::Particle particles::pidt::records::ParticlePacked::convert() const{
   return Particle(
      getX(),
      getV(),
      getMovedParticle()
   );
}

#ifdef Parallel
   tarch::logging::Log particles::pidt::records::ParticlePacked::_log( "particles::pidt::records::ParticlePacked" );
   
   MPI_Datatype particles::pidt::records::ParticlePacked::Datatype = 0;
   MPI_Datatype particles::pidt::records::ParticlePacked::FullDatatype = 0;
   
   
   void particles::pidt::records::ParticlePacked::initDatatype() {
      {
         ParticlePacked dummyParticlePacked[2];
         
         const int Attributes = 4;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_DOUBLE,		 //v
            MPI_SHORT,		 //_packedRecords0
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            DIMENSIONS,		 //v
            1,		 //_packedRecords0
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._v[0]))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._packedRecords0))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyParticlePacked[1]._persistentRecords._x[0])), 		&disp[3] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &ParticlePacked::Datatype );
         MPI_Type_commit( &ParticlePacked::Datatype );
         
      }
      {
         ParticlePacked dummyParticlePacked[2];
         
         const int Attributes = 4;
         MPI_Datatype subtypes[Attributes] = {
            MPI_DOUBLE,		 //x
            MPI_DOUBLE,		 //v
            MPI_SHORT,		 //_packedRecords0
            MPI_UB		 // end/displacement flag
         };
         
         int blocklen[Attributes] = {
            DIMENSIONS,		 //x
            DIMENSIONS,		 //v
            1,		 //_packedRecords0
            1		 // end/displacement flag
         };
         
         MPI_Aint     disp[Attributes];
         
         MPI_Aint base;
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]))), &base);
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._x[0]))), 		&disp[0] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._v[0]))), 		&disp[1] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&(dummyParticlePacked[0]._persistentRecords._packedRecords0))), 		&disp[2] );
         MPI_Address( const_cast<void*>(static_cast<const void*>(&dummyParticlePacked[1]._persistentRecords._x[0])), 		&disp[3] );
         
         for (int i=1; i<Attributes; i++) {
            assertion1( disp[i] > disp[i-1], i );
         }
         for (int i=0; i<Attributes; i++) {
            disp[i] -= base;
         }
         MPI_Type_struct( Attributes, blocklen, disp, subtypes, &ParticlePacked::FullDatatype );
         MPI_Type_commit( &ParticlePacked::FullDatatype );
         
      }
      
   }
   
   
   void particles::pidt::records::ParticlePacked::shutdownDatatype() {
      MPI_Type_free( &ParticlePacked::Datatype );
      MPI_Type_free( &ParticlePacked::FullDatatype );
      
   }
   
   void particles::pidt::records::ParticlePacked::send(int destination, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         const int result = MPI_Send(this, 1, exchangeOnlyAttributesMarkedWithParallelise ? Datatype : FullDatatype, destination, tag, tarch::parallel::Node::getInstance().getCommunicator());
         if  (result!=MPI_SUCCESS) {
            std::ostringstream msg;
            msg << "was not able to send message particles::pidt::records::ParticlePacked "
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
            msg << "was not able to send message particles::pidt::records::ParticlePacked "
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
               msg << "testing for finished send task for particles::pidt::records::ParticlePacked "
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
               "particles::pidt::records::ParticlePacked",
               "send(int)", destination,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pidt::records::ParticlePacked",
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
   
   
   
   void particles::pidt::records::ParticlePacked::receive(int source, int tag, bool exchangeOnlyAttributesMarkedWithParallelise, bool communicateBlocking) {
      if (communicateBlocking) {
      
         MPI_Status  status;
         const int   result = MPI_Recv(this, 1, communicateBlocking ? Datatype : FullDatatype, source, tag, tarch::parallel::Node::getInstance().getCommunicator(), &status);
         if ( result != MPI_SUCCESS ) {
            std::ostringstream msg;
            msg << "failed to start to receive particles::pidt::records::ParticlePacked from node "
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
            msg << "failed to start to receive particles::pidt::records::ParticlePacked from node "
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
               msg << "testing for finished receive task for particles::pidt::records::ParticlePacked failed: "
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
               "particles::pidt::records::ParticlePacked",
               "receive(int)", source,tag,1
               );
               triggeredTimeoutWarning = true;
            }
            if (
               tarch::parallel::Node::getInstance().isTimeOutDeadlockEnabled() &&
               (clock()>timeOutShutdown)
            ) {
               tarch::parallel::Node::getInstance().triggerDeadlockTimeOut(
               "particles::pidt::records::ParticlePacked",
               "receive(int)", source,tag,1
               );
            }
            tarch::parallel::Node::getInstance().receiveDanglingMessages();
         }
         
         delete sendRequestHandle;
         
         #ifdef Debug
         _log.debug("receive(int,int)", "received " + toString() ); 
         #endif
         
      }
      
   }
   
   
   
   bool particles::pidt::records::ParticlePacked::isMessageInQueue(int tag, bool exchangeOnlyAttributesMarkedWithParallelise) {
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
   
   
#endif



