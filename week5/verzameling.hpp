#ifndef VERZAMELING_HPP
#define VERZAMELING_HPP
#include <algorithm>
#include <array>
#include <iostream>

template <typename T, unsigned int S>

class verzameling {
  std::array<T, S> arr;
  unsigned int findex = 0;

public:
  void add(T x) {
    if (findex < S && !contains(x)) {
      arr[findex] = x;
      findex++;
    }
  };

  void remove(T x) {
    if (findex > 0 && contains(x)) {
      for (unsigned int i = 0; i < findex; i++) {
        if (arr[i] == x) {
          findex--;
          std::rotate(&arr[i], &arr[i + 1], &arr[findex + 1]);
        }
      }
    }
  };
  T max() {
    T currmax = arr[0];
    for (unsigned i = 1; i < findex; i++) {
      if (arr[i] > currmax)
        currmax = arr[i];
    }
    return currmax;
  }

  bool contains(T z) {
    for (unsigned int i = 0; i < findex; i++) {
      if (arr[i] == z) {
        return true;
      }
    }
    return false;
  };

  void yeet() {
    for (unsigned int i = 0; i < findex; i++) {
      std::cout << arr[i] << '\n';
    }
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const verzameling &verzameling) {
    for (unsigned int i = 0; i < verzameling.findex; i++) {
      os << verzameling.arr[i];
      if (i != verzameling.findex - 1) {
        os << ',';
      }
    }
    return os;
  }
};

#endif // VERZAMELING_HPP