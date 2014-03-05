#include "./phasor.cpp"
#include "./tests.cpp"

void test_rect_init_real(SimpleTest * test_wrapper){
  Phasor p(20, 40);
  test_wrapper->identify(rect_init_real);

  //Test initiated real value
  test_wrapper->assert_equal(p.get_real(), 20, __LINE__, __FILE__);
}

void test_rect_init_imag(SimpleTest * test_wrapper){
  Phasor p(20, 40);
  test_wrapper->identify(rect_init_imag);

  //Test initiated imag value
  test_wrapper->assert_equal(p.get_imag(), 40, __LINE__, __FILE__);
}

void test_pol_init_mag(SimpleTest * test_wrapper){
  Phasor p(20, 40, true);
  test_wrapper->identify(pol_init_mag);

  //Test initiated magnitude
  test_wrapper->assert_equal(p.get_magnitude(), 20, __LINE__, __FILE__);
}

void test_pol_init_phase(SimpleTest * test_wrapper){
  Phasor p(20, 40, true);
  test_wrapper->identify(pol_init_phase);

  //Test initiated phase
  test_wrapper->assert_equal(p.get_phase(), 40, __LINE__, __FILE__);
}

void test_rect2pol_mag(SimpleTest * test_wrapper){
  Phasor p(1, 1);
  test_wrapper->identify(rect2pol_mag);

  //Magnitude must equal 1.41
  test_wrapper->assert_equal(p.get_magnitude(), 1.41, 2, __LINE__, __FILE__);
}

void test_rect2pol_phase(SimpleTest * test_wrapper){
  Phasor p(1, 1);
  test_wrapper->identify(rect2pol_phase);

  //Phase must equal 45 degrees
  test_wrapper->assert_equal(p.get_phase(), 45, __LINE__, __FILE__);
}

void test_pol2rect_real(SimpleTest * test_wrapper){
  Phasor p(10, 90, true);
  test_wrapper->identify(pol2rect_real);

  //The real value must equal 0
  test_wrapper->assert_equal(p.get_real(), 0, 2, __LINE__, __FILE__);
}

void test_pol2rect_imag(SimpleTest * test_wrapper){
  Phasor p(10, 90, true);
  test_wrapper->identify(pol2rect_imag);

  //The imaaginary part must equal 10
  test_wrapper->assert_equal(p.get_imag(), 10, __LINE__, __FILE__);
}
