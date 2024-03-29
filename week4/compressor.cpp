#include <fstream>
#include <iostream>

#include "compressor.hpp"

int main(void) {
  lz_compressor<4096> compressor;

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

  std::ofstream f3;
  f3.open("encoded.asm");
  f3 << ".cpu cortex-m0 \n";
  f3 << ".align 2 \n";
  f3 << ".text \n";
  f3 << ".global encoded \n \n";
  f3 << "encoded: .asciz \"";
  if (!f3.is_open()) {
    std::cerr << "output file not opened";
    return -1;
  }

  compressor.compress(
      [&f1]() -> int {
        auto c = f1.get();
        return f1.eof() ? '\0' : c;
      },
      [&f2, &f3](char c) {
        f2.put(c);
        f3.put(c);
      });

  f3 << "\"";

  f1.close();
  f2.close();
  f3.close();

}