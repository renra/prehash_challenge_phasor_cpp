#include <iostream>
#include "simple_test.cpp"
#include "tests.cpp"
#include "test_opts.cpp"

using namespace std;

int main(){
  int rc = 0;
  SimpleTest * test_wrapper = new SimpleTest(&std::cout);

  test_wrapper->expect(
    16,
    pol_init_mag, pol_init_phase,
    rect_init_real, rect_init_imag,
    rect2pol_mag, rect2pol_phase,
    pol2rect_real, pol2rect_imag,
    addition_mag, addition_phase,
    subtraction_mag, subtraction_phase,
    multiplication_real, multiplication_imag,
    division_real, division_imag
  );

  run_tests(test_wrapper);

  test_wrapper->report();
  rc = test_wrapper->error_status();

  delete test_wrapper;
  return rc;
}
