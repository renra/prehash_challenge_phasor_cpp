#include "./testing_methods.cpp"

void run_tests(SimpleTest * test_wrapper){
  test_rect_init_real(test_wrapper);
  test_rect_init_imag(test_wrapper);
  test_pol_init_mag(test_wrapper);
  test_pol_init_phase(test_wrapper);
  test_rect2pol_mag(test_wrapper);;
  test_rect2pol_phase(test_wrapper);
  test_pol2rect_real(test_wrapper);
  test_pol2rect_imag(test_wrapper);
}
