#include <iostream>
#include "simple_test.cpp"
#include "tests.cpp"
#include "test_opts.cpp"

using namespace std;

int main(){
  int rc = 0;
  SimpleTest * test_wrapper = new SimpleTest(&std::cout);

  test_wrapper->expect(
    8,
    rect_init_real, rect_init_imag,
    pol_init_mag, pol_init_phase,
    rect2pol_mag, rect2pol_phase,
    pol2rect_real, pol2rect_imag
  );

  run_tests(test_wrapper);

  test_wrapper->report();
  rc = test_wrapper->error_status();

  delete test_wrapper;
  return rc;
}
