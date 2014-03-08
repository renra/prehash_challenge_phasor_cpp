#include <cmath>

class Phasor{
  public:

  //These methods are stubs to prevent compilation errors
  // make sure you tweak their prototypes too, where appropriate
  // make sure to add new methods that you think should be here
  Phasor(double param1, double param2, bool rectangular = false) {}
  double get_magnitude() {return -1;}
  double get_phase() {return -1;}
  double get_real() {return -1;}
  double get_imag() {return -1;}

  Phasor operator+(Phasor operand) { return Phasor(1,1); }
  Phasor operator-(Phasor operand) { return Phasor(1,1); }
  Phasor operator*(Phasor operand) { return Phasor(1,1); }
  Phasor operator/(Phasor& operand) { return Phasor(1,1); }
};
