#include <iostream>
#include <sstream>
#include <queue>
#include "./phasor.cpp"
#include "./simple_test.cpp"

using namespace std;

void test_rect2pol(SimpleTest*);
void test_pol2rect(SimpleTest*);

int main(){
  bool rc;
  SimpleTest * test = new SimpleTest(&std::cout);

  test_rect2pol(test);
  test_pol2rect(test);

  test->report();
  rc = test->error_status();

  delete test;
  return rc;
}


void test_rect2pol(SimpleTest * test){
  Phasor p(1, 1);

  test->assert_equal(p.get_magnitude(), 1.41, 2, __LINE__, __FILE__);
  test->assert_equal(p.get_phase(), 45, __LINE__, __FILE__);
}

void test_pol2rect(SimpleTest * test){
  Phasor p(10, 90, true);

  test->assert_equal(p.get_real(), 0, 2, __LINE__, __FILE__);
  test->assert_equal(p.get_imag(), 10, __LINE__, __FILE__);
}
