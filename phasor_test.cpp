#include <iostream>
#include <sstream>
#include <queue>
#include "./phasor.cpp"

using namespace std;

void assert_equal();
void report_errors();
void test_rect2pol();
void test_pol2rect();

//OPTIMIZE
queue<string> error_messages;

int main(){
  test_rect2pol();
  test_pol2rect();
  report_errors();
  return 0;
}

void report_errors(){
  cout << endl;

  while(!error_messages.empty()){
    cout << error_messages.front() << endl;
    error_messages.pop();
  }
}

void assert_equal(double subject, double etalon, int line_number, double epsilon = 0.009){
  double diff = abs(subject - etalon);

  if(diff > epsilon){
    stringstream error;
    error << "Assert failed. Expected " << subject << " to equal " << etalon;
    error << " on line " << line_number << endl;
    error_messages.push(error.str());

    cout << "\e[31mF\e[0m";
  }
  else{
    cout << "\e[32m.\e[0m";
  }
}

void test_rect2pol(){
  Phasor p(1, 1);

  assert_equal(p.get_magnitude(), 1.41, __LINE__);
  assert_equal(p.get_phase(), 45, __LINE__);
}

void test_pol2rect(){
  Phasor p(10, 90, true);

  assert_equal(p.get_real(), 0, __LINE__);
  assert_equal(p.get_imag(), 10, __LINE__);
}
