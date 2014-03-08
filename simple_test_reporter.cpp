#include <ostream>

using namespace std;

class SimpleTestReporter{
  ostream * output = NULL;

  public:
  SimpleTestReporter(ostream * _output){
    output = _output;
  }

  ~SimpleTestReporter(){}

  void new_line(){
    *(output) << endl;
  }

  void print(string str){
    *(output) << str;
  }

  void print_success(string str){
    *(output) << "\e[32m" << str << "\e[0m";
  }

  void print_failure(string str){
    *(output) << "\e[31m" << str << "\e[0m";
  }
};
