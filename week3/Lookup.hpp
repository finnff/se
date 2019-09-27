#ifndef LOOKUP_HPP
#define LOOKUP_HPP

#include <math.h>
#include <array>

constexpr float SineSingleAngle(u_int64_t hoek) {
  float rad = (hoek / 57.296);
  float sine = sin(rad);
  sine = roundf(100 * sine) / 100;
  return sine;
}

constexpr float CoseSingleAngle(u_int64_t hoek) {
  float rad = (hoek / 57.296);
  float cose = cos(rad);
  cose = roundf(100 * cose) / 100;
  return cose;
}

const uint64_t arrSize = 361;

constexpr std::array<float, arrSize> fill_arraySine() {
  std::array<float, arrSize> SinArr{0};
  for (uint64_t i = 0; i < arrSize; i++) {
    SinArr[i] = SineSingleAngle(i);
  }
  return SinArr;
}

constexpr std::array<float, arrSize> fill_arrayCose() {
  std::array<float, arrSize> CosArr{0};
  for (uint64_t i = 0; i < arrSize; i++) {
    CosArr[i] = CoseSingleAngle(i);
  }
  return CosArr;
}

#endif  // LOOKUP_HPP