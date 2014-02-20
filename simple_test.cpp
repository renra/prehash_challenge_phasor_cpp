#include <ostream>
#include <vector>
#include <string>
#include <cmath>
#include "./simple_test_reporter.cpp"

using namespace std;

class SimpleTest{
  vector<string> error_messages;
  SimpleTestReporter * reporter = NULL;
  int count;

  public:
  SimpleTest(ostream * _p_output){
    count = 0;
    reporter = new SimpleTestReporter(_p_output);
  }

  ~SimpleTest(){
    delete reporter;
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
    this->reporter->new_line();

    for(
      vector<string>::iterator it = error_messages.begin();
      it != error_messages.end();
      ++it
    ){
      this->reporter->print_failure(*it);
    }

    //TODO: decouple - reporter is not reporter
    this->reporter->new_line();

    this->reporter->print(to_string(this->get_count()));
    this->reporter->print(" tests, ");
    this->reporter->print_success(to_string(this->get_passed()));
    this->reporter->print_success(" passed, ");
    this->reporter->print_failure(to_string(this->get_failed()));
    this->reporter->print_failure(" failed.");
    this->reporter->new_line();
  }

  int get_count() const{
    return this->count;
  }

  int get_passed() const{
    return this->count - this->error_messages.size();
  }

  int get_failed() const{
    return this->error_messages.size();
  }

  int error_status(){
    return error_messages.empty() ? 0 : 1;
  }
};
