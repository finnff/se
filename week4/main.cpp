// Made by @finnff 2-10-19
#include "compressor.hpp"
#include "decompressor.hpp"
#include <fstream>
#include <iostream>

extern "C" void armdecomp();

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

  // compressor.compress(
  //     [&f1]() -> int {
  //       auto c = f1.get();
  //       return f1.eof() ? '\0' : c;
  //     },
  //     [&f2](char c) { f2.put(c); });

  std::ofstream fa;
  fa.open("output.asm");
  if (!fa.is_open()) {
    std::cerr << "output ASM file not opened";
    return -1;
  }
  if (fa.is_open()) {
    fa << ".cpu cortex-m0 \n";
    fa << ".text\n";
    fa << ".align 1\n";
    fa << ".global encoded\n";
    fa << ".asciz\"";
  }

  /*
  1. Coderen(comprimeren)
  naar een file Pas de lambda aanroep van de LZ compressor /
  encoder aan zodat er een assembler file wordt gegenereerd die de
  gecodeerde characters bevat(en die in een volgende stap meegenomen kan worden
  in een Due applicatie.
  */

  compressor.compress(
      [&f1]() -> int {
        auto c = f1.get();
        return f1.eof() ? '\0' : c;
      },
      [&fa](char c) { fa.put(c); });
  fa << "\"";

  f1.close();
  f2.close();
  fa.close();

  std::ifstream f3;
  f3.open("output.txt");
  if (!f3.is_open()) {
    std::cerr << "reopening compressed failed";
    return -1;
  };

  /*     2. Decoderen naar std::cout
  Neem de LZ encoder (code staat in de examples) en breidt die uit met een
  decompressor/decoder (in C++, op de PC) die zijn uitvoer (via en lambda
  parameter) naar std::cout schrijft.
  */

  lz_decompressor decomp;
  decomp.decompress(
      [&f3]() -> int {
        auto c = f3.get();
        return f3.eof() ? '\0' : c;
      },
      [&f3](char c) { std::cout << c; });

  f3.close();
  std::cout << "\n";
}