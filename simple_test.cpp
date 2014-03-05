#include <ostream>
#include <sstream>
#include <vector>
#include <set>
#include <string>
#include <cmath>
#include <cstdarg>
#include "simple_test_reporter.cpp"

using namespace std;

class SimpleTest{
  vector<string> error_messages;
  set<int> expected_tests;

  SimpleTestReporter * reporter = NULL;
  int count;

  public:
  SimpleTest(ostream * _p_output){
    this->count = 0;
    this->reporter = new SimpleTestReporter(_p_output);
  }

  ~SimpleTest(){
    delete reporter;
  }

  void expect(int test_count, ...){
    va_list tests;
    va_start(tests, test_count);

    for(int i = 0; i < test_count; i++){
      expected_tests.insert((int)va_arg(tests, int));
    }

    va_end(tests);
  }

  void identify(int test_id){
    expected_tests.erase(expected_tests.find(test_id));
  }

  void assert_equal(double subject, double etalon, int precision, int line_number, string file){
    double modifier = pow(10, precision);

    subject = trunc(subject*modifier)/modifier;
    etalon = trunc(etalon*modifier)/modifier;

    assert_equal(subject, etalon, line_number, file);
  }

  template<typename SUBJECT_TYPE, typename ETALON_TYPE>
  void assert_equal(SUBJECT_TYPE subject, ETALON_TYPE etalon, int line_number, string file){
    count++;

    if(subject!=etalon){
      stringstream error;
      error << "Assert failed. Expected " << subject << " to equal " << etalon;
      error << " in file " << file  << ":" << line_number << endl;
      error_messages.push_back(error.str());

      this->reporter->print_failure("F");
    }
    else{
      this->reporter->print_success(".");
    }
  }

  void report(){
    int yet_expected = expected_tests.size();

    reporter->new_line();

    for(
      vector<string>::iterator it = error_messages.begin();
      it != error_messages.end();
      ++it
    ){
      reporter->print_failure(*it);
    }

    //TODO: decouple test and reporter
    reporter->new_line();

    reporter->print(to_string(get_count()));
    reporter->print(" tests run, ");
    reporter->print_success(to_string(get_passed()));
    reporter->print_success(" passed, ");
    reporter->print_failure(to_string(get_failed()));
    reporter->print_failure(" failed.");
    reporter->new_line();

    if(yet_expected > 0){
      reporter->print_failure(to_string(yet_expected));
      reporter->print_failure(" more test(s) expected");
      reporter->new_line();
    }
  }

  int get_count() const{
    return count;
  }

  int get_passed() const{
    return count - error_messages.size();
  }

  int get_failed() const{
    return error_messages.size();
  }

  int error_status(){
    return (error_messages.empty() && expected_tests.size() == 0) ? 0 : 1;
  }
};
