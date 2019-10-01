
//Written by Finn Fonteijn 23-9-19

#ifndef LOOKUP_HPP
#define LOOKUP_HPP

#include <math.h>
#include <array>

const float DEGREESPERRAD = 57.2958;

// Calculate 2 decimal sine float, between 0 and 1.
constexpr float SineSingleAngle(u_int64_t hoek) {
  float rad = (hoek / DEGREESPERRAD);
  float sine = sin(rad);
  sine = roundf(100 * sine) / 100;
  return sine;
}

// Calculate 2 decimal Cos float, between 0 and 1.
constexpr float CoseSingleAngle(u_int64_t hoek) {
  float rad = (hoek / DEGREESPERRAD);
  float cose = cos(rad);
  cose = roundf(100 * cose) / 100;
  return cose;
}

// Intialize Array for each of the 360 degrees in a circle + /0 char.
const uint64_t arrSize = 361;

// Create std array, which we append the Sine of each of the 360 degrees to.
constexpr std::array<float, arrSize> fill_arraySine() {
  std::array<float, arrSize> SinArr{0};
  for (uint64_t i = 0; i < arrSize; i++) {
    SinArr[i] = SineSingleAngle(i);
  }
  return SinArr;
}

// Create std array, which we append the Cos of each of the 360 degrees to.
constexpr std::array<float, arrSize> fill_arrayCose() {
  std::array<float, arrSize> CosArr{0};
  for (uint64_t i = 0; i < arrSize; i++) {
    CosArr[i] = CoseSingleAngle(i);
  }
  return CosArr;
}

#endif  // LOOKUP_HPP
