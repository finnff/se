// written by @finnff on 1-10-19

#ifndef MARKERS_HPP
#define MARKERS_HPP

#include "Lookup.hpp"
#include "hwlib.hpp"
#include "line.hpp"
constexpr std::array<float, arrSize> Carr = fill_arrayCose();  // x
constexpr std::array<float, arrSize> Sarr = fill_arraySine();  // y

const void DrawMarkers(hwlib::window &w) {
  line one(w, 64 + (Carr[0 * 6] * 29), 32 + (Sarr[0 * 6] * 29),
           64 + (Carr[0 * 6] * 30), 32 + (Sarr[0 * 6] * 30));
  line two(w, 64 + (Carr[5 * 6] * 29), 32 + (Sarr[5 * 6] * 29),
           64 + (Carr[5 * 6] * 30), 32 + (Sarr[5 * 6] * 30));
  line three(w, 64 + (Carr[10 * 6] * 29), 32 + (Sarr[10 * 6] * 29),
             64 + (Carr[10 * 6] * 30), 32 + (Sarr[10 * 6] * 30));
  line four(w, 64 + (Carr[15 * 6] * 29), 32 + (Sarr[15 * 6] * 29),
            64 + (Carr[15 * 6] * 30), 32 + (Sarr[15 * 6] * 30));
  line five(w, 64 + (Carr[20 * 6] * 29), 32 + (Sarr[20 * 6] * 29),
            64 + (Carr[20 * 6] * 30), 32 + (Sarr[20 * 6] * 30));
  line six(w, 64 + (Carr[25 * 6] * 29), 32 + (Sarr[25 * 6] * 29),
           64 + (Carr[25 * 6] * 30), 32 + (Sarr[25 * 6] * 30));
  line seven(w, 64 + (Carr[30 * 6] * 29), 32 + (Sarr[30 * 6] * 29),
             64 + (Carr[30 * 6] * 30), 32 + (Sarr[30 * 6] * 30));
  line eight(w, 64 + (Carr[35 * 6] * 29), 32 + (Sarr[35 * 6] * 29),
             64 + (Carr[35 * 6] * 30), 32 + (Sarr[35 * 6] * 30));
  line nine(w, 64 + (Carr[40 * 6] * 29), 32 + (Sarr[40 * 6] * 29),
            64 + (Carr[40 * 6] * 30), 32 + (Sarr[40 * 6] * 30));
  line ten(w, 64 + (Carr[45 * 6] * 29), 32 + (Sarr[45 * 6] * 29),
           64 + (Carr[45 * 6] * 30), 32 + (Sarr[45 * 6] * 30));
  line eleven(w, 64 + (Carr[50 * 6] * 29), 32 + (Sarr[50 * 6] * 29),
              64 + (Carr[50 * 6] * 30), 32 + (Sarr[50 * 6] * 30));
  line twelve(w, 64 + (Carr[55 * 6] * 29), 32 + (Sarr[55 * 6] * 29),
              64 + (Carr[55 * 6] * 30), 32 + (Sarr[55 * 6] * 30));

  std::array<line *, 12> markers = {&one,  &two, &three,  &four,
                                    &five, &six, &seven,  &eight,
                                    &nine, &ten, &eleven, &twelve};

  for (auto &p : markers) {
    p->print();
  }
}

#endif  // MARKERS_HPP
