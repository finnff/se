// written by @finnff on 23-9-19

#include "hwlib.hpp"
#include "markers.hpp"

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

  // Uncomment for Native Window : ->
  // hwlib::target::window w(hwlib::xy(128, 64));

  hwlib::now_us();
  u_int16_t hour;
  u_int16_t min;
  w.clear();

  for (;;) {
    // Set hours to 0 after 60 mins, reset min counter to mins 0;
    hour = 0;
    // after 60 mins, reset min counter to mins 0;
    while (hour < 60) {
      min = 0;
      // Create start time, which later allows us to determine when a minute has
      // passed.
      auto starttime = hwlib::now_us();
      while (min < 60) {
        // Print Markers for hour every 30 degrees
        // Create  and print Minute hand + Hour hand, with respective min and
        // Hour values
        DrawMarkers(w);
        line minhand(w, 64, 32, 64 + (Carr[min * 6] * 25),
                     32 + (Sarr[min * 6] * 25));
        line hourhand(w, 64, 32, 64 + (Carr[hour * 6] * 18),
                      32 + (Sarr[hour * 6] * 18));
        minhand.print();
        hourhand.print();

        // Interupts for buttons that offset Minute or hour but +1;
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

        // requests new time after exectuting earlier parts of the loop.
        auto nowtime = hwlib::now_us();
        w.flush();

        // If the timer difference is 60 Million us(60 seconds), a minute has
        // passed. this increments the minute counter.
        if (nowtime >= (starttime + (60 * 1000 * 1000))) {
          starttime = hwlib::now_us();
          min++;
          w.clear();
        }
        // Couts for Digital readout on Console.
        hwlib::cout << "Time: " << hour / 5 << " : " << min << hwlib::endl;
        hwlib::cout << ((nowtime - starttime) / 1000 / 1000) << hwlib::endl;
      }
      // Increment hour by 5 degrees(1 hour), each time 60 minutes have passed.
      hour = hour + 5;
    }
  }
}
