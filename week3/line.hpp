
// example:
// declaration of a line class

#ifndef LINE_HPP
#define LINE_HPP

#include "hwlib.hpp"

class line {
 private:
  hwlib::window& w;
  int start_x;
  int start_y;
  int end_x;
  int end_y;

 public:
  line(hwlib::window& w, int p_start_x, int p_start_y, int p_end_x, int p_end_y)
      : w(w) {
    start_x = p_start_x;
    start_y = p_start_y;
    end_x = p_end_x;
    end_y = p_end_y;
  }

  void print() {
    hwlib::line line(hwlib::xy(start_x, start_y), hwlib::xy(end_x, end_y));
    line.draw(w);
  }
};

#endif  // LINE_HPP
