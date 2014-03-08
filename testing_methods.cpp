#include "./phasor.cpp"
#include "./tests.cpp"

void test_pol_init_mag(SimpleTest * test_wrapper){
  test_wrapper->identify(pol_init_mag);

  Phasor p(20, 40);

  //Test initiated magnitude
  test_wrapper->assert_equal(p.get_magnitude(), 20, __LINE__, __FILE__);
}

void test_pol_init_phase(SimpleTest * test_wrapper){
  test_wrapper->identify(pol_init_phase);

  Phasor p(20, 40);

  //Test initiated phase
  test_wrapper->assert_equal(p.get_phase(), 40, __LINE__, __FILE__);
}

void test_rect_init_real(SimpleTest * test_wrapper){
  test_wrapper->identify(rect_init_real);

  Phasor p(20, 40, true);

  //Test initiated real value
  test_wrapper->assert_equal(p.get_real(), 20, __LINE__, __FILE__);
}

void test_rect_init_imag(SimpleTest * test_wrapper){
  test_wrapper->identify(rect_init_imag);

  Phasor p(20, 40, true);

  //Test initiated imag value
  test_wrapper->assert_equal(p.get_imag(), 40, __LINE__, __FILE__);
}

void test_rect2pol_mag(SimpleTest * test_wrapper){
  test_wrapper->identify(rect2pol_mag);

  Phasor p(1, 1, true);

  //Magnitude must equal 1.41
  test_wrapper->assert_equal(p.get_magnitude(), 1.41, 2, __LINE__, __FILE__);
}

void test_rect2pol_phase(SimpleTest * test_wrapper){
  test_wrapper->identify(rect2pol_phase);

  Phasor p(1, 1, true);

  //Phase must equal 45 degrees
  test_wrapper->assert_equal(p.get_phase(), 45, __LINE__, __FILE__);
}

void test_pol2rect_real(SimpleTest * test_wrapper){
  test_wrapper->identify(pol2rect_real);

  Phasor p(10, 90);

  //The real value must equal 0
  test_wrapper->assert_equal(p.get_real(), 0, 2, __LINE__, __FILE__);
}

void test_pol2rect_imag(SimpleTest * test_wrapper){
  test_wrapper->identify(pol2rect_imag);

  Phasor p(10, 90);

  //The imaaginary part must equal 10
  test_wrapper->assert_equal(p.get_imag(), 10, __LINE__, __FILE__);
}

void test_addition_mag(SimpleTest * test_wrapper){
  test_wrapper->identify(addition_mag);

  Phasor p1(7.07107, 45);
  Phasor p2(25, 53.1301);

  Phasor result = p1 + p2;

  test_wrapper->assert_equal(
    result.get_magnitude(), 32.01, 2, __LINE__, __FILE__
  );
}

void test_addition_phase(SimpleTest * test_wrapper){
  test_wrapper->identify(addition_phase);

  Phasor p1(7.07107, 45);
  Phasor p2(25, 53.1301);

  Phasor result = p1 + p2;

  test_wrapper->assert_equal(
    result.get_phase(), 51.34, 2, __LINE__, __FILE__
  );
}

void test_subtraction_mag(SimpleTest * test_wrapper){
  test_wrapper->identify(subtraction_mag);

  Phasor p1(25, 53.1301);
  Phasor p2(7.07107, 45);

  Phasor result = p1 - p2;

  test_wrapper->assert_equal(
    result.get_magnitude(), 18.02, 2, __LINE__, __FILE__
  );
}

void test_subtraction_phase(SimpleTest * test_wrapper){
  test_wrapper->identify(subtraction_phase);

  Phasor p1(25, 53.1301);
  Phasor p2(7.07107, 45);

  Phasor result = p1 - p2;

  test_wrapper->assert_equal(
    result.get_phase(), 56.30, 2, __LINE__, __FILE__
  );
}

void test_multiplication_real(SimpleTest * test_wrapper){
  test_wrapper->identify(multiplication_real);

  Phasor p1(29.8858, 2.61467, true);
  Phasor p2(5, 8.66025, true);

  Phasor result = p1 * p2;

  test_wrapper->assert_equal(
    result.get_real(), 126.78, 2, __LINE__, __FILE__
  );
}

void test_multiplication_imag(SimpleTest * test_wrapper){
  test_wrapper->identify(multiplication_imag);

  Phasor p1(29.8858, 2.61467, true);
  Phasor p2(5, 8.66025, true);

  Phasor result = p1 * p2;

  test_wrapper->assert_equal(
    result.get_imag(), 271.89, 2, __LINE__, __FILE__
  );
}

void test_division_real(SimpleTest * test_wrapper){
  test_wrapper->identify(division_real);

  Phasor p1(29.8858, 2.61467, true);
  Phasor p2(5, 8.66025, true);

  Phasor result = p1 / p2;

  test_wrapper->assert_equal(
    result.get_real(), 1.72, 2, __LINE__, __FILE__);
}

void test_division_imag(SimpleTest * test_wrapper){
  test_wrapper->identify(division_imag);

  Phasor p1(29.8858, 2.61467, true);
  Phasor p2(5, 8.66025, true);

  Phasor result = p1 / p2;

  test_wrapper->assert_equal(
    result.get_imag(), -2.45, 2, __LINE__, __FILE__
  );
}
