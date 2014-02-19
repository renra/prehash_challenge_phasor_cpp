#include <cmath>

class Phasor{
  double real;
  double imag;
  double magnitude;
  double phase;

  void compute_magnitude_and_phase(){
    this->magnitude = sqrt(pow(this->real, 2) + pow(this->imag, 2));

    double phase_rad = atan(this->imag/this->real);
    this->phase = phase_rad * 180/M_PI;
  }

  void compute_real_and_imag(){
    this->real = this->magnitude * cos(phase_in_radians());
    this->imag = this->magnitude * sin(phase_in_radians());
  }

  double phase_in_radians() const{
    return this->phase * M_PI / 180;
  }

  public:
  Phasor(double param1, double param2, bool polar = false){
    if(polar){
      this->magnitude = param1;
      this->phase = param2;
      compute_real_and_imag();
    }
    else{
      this->real = param1;
      this->imag = param2;
      compute_magnitude_and_phase();
    }
  }

  double get_real() const {
    return this->real;
  }

  double get_imag() const {
    return this->imag;
  }

  double get_magnitude() const{
    return this->magnitude;
  }

  double get_phase() const{
    return this->phase;
  }
};
