#include <ostream>

using namespace std;

class SimpleTestReporter{
  ostream * output = NULL;

  public:
  SimpleTestReporter(ostream * _output){
    this->output = _output;
  }

  ~SimpleTestReporter(){}

  void new_line(){
    *(this->output) << endl;
  }

  void print(string str){
    *(this->output) << str;
  }

  void print_success(string str){
    *(this->output) << "\e[32m" << str << "\e[0m";
  }

  void print_failure(string str){
    *(this->output) << "\e[31m" << str << "\e[0m";
  }
};
