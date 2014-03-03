#include <cmath>

class Phasor{
  double real;
  double imag;
  double magnitude;
  double phase;

  void compute_magnitude_and_phase(){
  }

  void compute_real_and_imag(){
  }

  double phase_in_radians() const{
    return 0;
  }

  public:
  Phasor(double param1, double param2, bool polar = false){
  }

  double get_real() const {
    return -1;
  }

  double get_imag() const {
    return -1;
  }

  double get_magnitude() const{
    return -1;
  }

  double get_phase() const{
    return -1;
  }
};
