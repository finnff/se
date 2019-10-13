#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "verzameling.hpp"


#include <array>
#include <iostream>
#include <sstream>
#include <vector>

// test if add function does not add items more
// than once.
TEST_CASE("geen dubble items") {
  verzameling<int, 10> verzameling;
  verzameling.add(1);
  verzameling.add(55);
  verzameling.add(20);
  verzameling.add(20);
  verzameling.add(5);
  verzameling.add(20);
  verzameling.add(100);
  std::stringstream out;
  out << verzameling;
  REQUIRE(out.str() == "1,5,20,100");
}

// test if removing items works
TEST_CASE("remove int item") {
  verzameling<int, 5> verzameling;
  for (int i = 100; i < 105; i++)
    verzameling.add(i);
  verzameling.remove(104);
  std::stringstream out;
  out << verzameling;
  REQUIRE(out.str() == "100,101,102,103");
}

// test if max() function works 
TEST_CASE("max works") {
  verzameling<int, 10> verzameling;
  verzameling.add(1);
  verzameling.add(-120);
  verzameling.add(100);
  auto max = verzameling.max();
  REQUIRE(max == 100);
}

// test if iterating over the size of the std::array is an issue
TEST_CASE("max size") {
  verzameling<int, 5> verzameling;
  for (int i = 100; i < 110; i++)
    verzameling.add(i);
  std::stringstream out;
  out << verzameling;
  REQUIRE(out.str() == "100,101,102,103,104");
}

//test if template works for strings
TEST_CASE("remove string item") {
  verzameling<std::string, 5> verzameling;
  verzameling.add("c++");
  verzameling.add("is");
  verzameling.add("leuk");
  verzameling.remove("is");
  verzameling.remove("stop");
  std::stringstream out;
  out << verzameling;
  REQUIRE(out.str() == "c++,leuk");
}


// test if max() works for std::char array
TEST_CASE("add std::arr char 3") {
  std::vector<std::array<char, 3>> temp = {
      std::array<char, 3>{'a', 'b', 'c'}, std::array<char, 3>{'d', 'e', 'f'},
      std::array<char, 3>{'g', 'h', 'i'}, std::array<char, 3>{'j', 'k', 'l'},
      std::array<char, 3>{'m', 'n', 'o'}, std::array<char, 3>{'p', 'q', 'r'},
  };

  verzameling<std::array<char, 3>, 10> verzameling;
  for (auto &char3 : temp) {
    verzameling.add(char3);
  }

  std::array<char, 3> charmax = verzameling.max();
  REQUIRE(charmax == std::array<char, 3>{'p', 'q', 'r'});
}

/*

All tests passed (6 assertions in 6 test cases)

*/
