#include "particles/pit/tests/TestCase.h"


#include "tarch/compiler/CompilerSpecificSettings.h"
#include "tarch/tests/TestCaseFactory.h"
registerTest(particles::pit::tests::TestCase)


#ifdef UseTestSpecificCompilerSettings
#pragma optimize("",off)
#endif

 
particles::pit::tests::TestCase::TestCase():
  tarch::tests::TestCase( "particles::pit::tests::TestCase" ) {
}


particles::pit::tests::TestCase::~TestCase() {
}


void particles::pit::tests::TestCase::run() {
  // @todo If you have further tests, add them here
  testMethod( test1 );
  testMethod( test2 );
  testMethod( test3 );
}


void particles::pit::tests::TestCase::test1() {
  // @todo Add your test here
  validateEquals(1,1);
}


void particles::pit::tests::TestCase::test2() {
  // @todo Add your test here
  validateEquals(2,2);
}


void particles::pit::tests::TestCase::test3() {
  // @todo Add your test here
  validateEquals(3,3);
}


#ifdef UseTestSpecificCompilerSettings
#pragma optimize("",on)
#endif
