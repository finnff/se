// Made by @finnff 2-10-19
#include <fstream>
#include <iostream>
#include "compressor.hpp"
#include "decompressor.hpp"
int main() {
  lz_compressor<(16 * 4096)> compressor;

  std::ifstream f1;
  f1.open("cookies.txt");
  if (!f1.is_open()) {
    std::cerr << "input file not opened";
    return -1;
  }

  std::ofstream f2;
  f2.open("output.txt");
  if (!f2.is_open()) {
    std::cerr << "output file not opened";
    return -1;
  }

  compressor.compress(
      [&f1]() -> int {
        auto c = f1.get();
        return f1.eof() ? '\0' : c;
      },
      [&f2](char c) { f2.put(c); });

  f1.close();
  f2.close();
}