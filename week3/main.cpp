#include "Lookup.hpp"
#include "hwlib.hpp"
#include "line.hpp"

int main() {
  namespace target = hwlib::target;

  // Intialize OLED display
  auto scl = target::pin_oc(target::pins::d22);
  auto sda = target::pin_oc(target::pins::d23);
  auto i2c_bus = hwlib::i2c_bus_bit_banged_scl_sda(scl, sda);
  auto w = hwlib::glcd_oled(i2c_bus, 0x3c);

  auto but1 = hwlib::target::pin_in(target::pins::d42);
  auto but2 = hwlib::target::pin_in(target::pins::d44);

  constexpr std::array<float, arrSize> Carr = fill_arrayCose();  // x
  constexpr std::array<float, arrSize> Sarr = fill_arraySine();  // y

  // the window in which we want to print the line
  // hwlib::target::window w(hwlib::xy(128, 64));

  hwlib::now_us();

  w.clear();

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

  for (;;) {
    u_int16_t hour = 0;
    while (hour < 60) {
      u_int16_t min = 0;
      auto starttime = hwlib::now_us();
      while (min < 60) {
        one.print();
        two.print();
        three.print();
        four.print();
        five.print();
        six.print();
        seven.print();
        eight.print();
        nine.print();
        ten.print();
        eleven.print();
        twelve.print();

        line minhand(w, 64, 32, 64 + (Carr[min * 6] * 25),
                     32 + (Sarr[min * 6] * 25));
        line hourhand(w, 64, 32, 64 + (Carr[hour * 6] * 18),
                      32 + (Sarr[hour * 6] * 18));
        minhand.print();
        hourhand.print();

        if (!but1.read()) {
          min++;
          w.clear();
        };
        if (!but2.read()) {
          hour += 5;
          if (hour >= 60) {
            hour = 0;
          };
          w.clear();
        };

        auto nowtime = hwlib::now_us();
        w.flush();
        if (nowtime >= (starttime + (60 * 1000 * 1000))) {
          starttime = hwlib::now_us();
          min++;
          w.clear();
        }

        hwlib::cout << "Time: " << hour / 5 << " : " << min << hwlib::endl;
        hwlib::cout << ((nowtime - starttime) / 1000 / 1000) << hwlib::endl;
      }
      hour = hour + 5;
    }
    hour = 0;
  }
}
