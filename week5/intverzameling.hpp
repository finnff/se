#ifndef INTVERZAMELING_HPP
#define INTVERZAMELING_HPP
#include <algorithm>
#include <array>
#include <iostream>

class intverzameling {
  std::array<int, 10> arr;
  unsigned int findex = 0;

public:
  void add(int x) {
    if (findex < 10 && !contains(x)) {
      arr[findex] = x;
      findex++;
    }
  };

  void remove(int x) {
    if (findex > 0 && contains(x)) {
      for (unsigned int i = 0; i < findex; i++) {
        if (arr[i] == x) {
          findex--;
          std::rotate(&arr[i], &arr[i + 1], &arr[findex + 1]);
        }
      }
    }
  };

  bool contains(int z) {
    for (size_t i = 0; i < findex; i++) {
      if (arr[i] == z) {
        return true;
      }
    }
    return false;
  };

  void yeet() {
    for (size_t i = 0; i < findex; i++) {
      std::cout << arr[i] << '\n';
    }
  }

  friend std::ostream &operator<<(std::ostream &os,
                                  const intverzameling &intverzameling) {
    for (size_t i = 0; i < intverzameling.findex; i++) {
      os << intverzameling.arr[i];
      os << ',';
    }
    return os;
  }

  // friend std::ostream& operator<<(std::ostream& os, const set& set) {
  //     // os << "ptr: " << set.ptr << "\n";

  //     for (size_t i = 0; i < set.ptr; i++) {
  //         os << set.arr[i];
  //         if (i != set.ptr - 1) os << ", ";
  //     }
  //     return os;
  // }
};

#endif // INTVERZAMELING_HPP