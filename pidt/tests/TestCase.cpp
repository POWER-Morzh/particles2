#include "particles/pidt/tests/TestCase.h"


#include "tarch/compiler/CompilerSpecificSettings.h"
#include "tarch/tests/TestCaseFactory.h"
registerTest(particles::pidt::tests::TestCase)


#ifdef UseTestSpecificCompilerSettings
#pragma optimize("",off)
#endif

 
particles::pidt::tests::TestCase::TestCase():
  tarch::tests::TestCase( "particles::pidt::tests::TestCase" ) {
}


particles::pidt::tests::TestCase::~TestCase() {
}


void particles::pidt::tests::TestCase::run() {
  // @todo If you have further tests, add them here
  testMethod( test1 );
  testMethod( test2 );
  testMethod( test3 );
}


void particles::pidt::tests::TestCase::test1() {
  // @todo Add your test here
  validateEquals(1,1);
}


void particles::pidt::tests::TestCase::test2() {
  // @todo Add your test here
  validateEquals(2,2);
}


void particles::pidt::tests::TestCase::test3() {
  // @todo Add your test here
  validateEquals(3,3);
}


#ifdef UseTestSpecificCompilerSettings
#pragma optimize("",on)
#endif
