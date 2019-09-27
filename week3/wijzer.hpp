#ifndef __WIJZER_HPP
#define __WIJZER_HPP
#include <iostream>

class hand {
 private:
  int oorsprong;
  int scale;
  int hoek;

 public:
  hand(const int &oorsprong, const int &scale, const int &hoek)
      : oorsprong(oorsprong), scale(scale), hoek(hoek){}

  void angle() { std::cout << "ajsdjajsdja" << std::endl; }
}

#endif  //__WIJZER_HPP