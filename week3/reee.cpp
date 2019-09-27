// #include "hwlib.hpp"
// #include "wijzer.hpp"
#include <math.h>
#include <iostream>
#include "hwlib.hpp"




  constexpr float anglesingle(int & hoek){
    float rad = (hoek/57.296);
    // float sine = sin(rad);
    // sine = roundf(100 * sine) / 100;
    return rad;
  }




class hand {
 private:
  int oorsprong;
  int scale;
  int hoek;

 public:
  float xarr[62];
  float yarr[62];

  hand(const int &oorsprong, const int &scale, const int &hoek)
      : oorsprong(oorsprong), scale(scale), hoek(hoek) {}



  // constexpr float carr[]{anglesingle(0),anglesingle(1),anglesingle(2),}



  // constexpr void angle60() {
  //       for (int i = 0; i <= 360;) {
  //     float test = (sin(i / 57.296));
  //     test = roundf(100 * test) / 100;
  //     xarr[i / 6] = test;
  //     i = i + 6;
  //   }
  //   for (int i = 0; i <= 360;) {
  //     float test = (cos(i / 57.296));
  //     test = roundf(100 * test) / 100;
  //     yarr[i / 6] = test;
  //     i = i + 6;
  //   }
  // };

  // void printarr() {
  //   for (int i = 0; i < 61; i++) {
  //     std::cout << xarr[i] << "  " << yarr[i] << std::endl;
  //   }
  // };

  void draw() {}
};

int main() {
  hand uur(3, 7, 1);
  constexpr float carr[]{uur.anglesingle(0),uur.anglesingle(1),uur.anglesingle(2),}
  // uur.angle60();
  // uur.printarr();
}
