// Made by Finn Fonteijn


#include "hwlib.hpp"

extern "C" void uart_put_char(char c) { hwlib::cout << c; }

extern "C" void print_asciz(const char* s);

extern "C" void application();

extern "C" char toggle_case(char* s);


// extern "C" char toggle_case(char* s) {
//   if (*s >= 'a' && *s <= 'z') {
//     return (char(*s = *s - 32));
//   } else if (*s >= 'A' && *s <= 'Z') {
//     return (char(*s = *s + 32));
//   } else {
//     return (char(*s));
//   }
// };


int main(void) {
  namespace target = hwlib::target;

  // wait for the PC console to start
  hwlib::wait_ms(2000);

  application();
}