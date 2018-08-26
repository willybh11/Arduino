#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1); // Pins: DIN,CLK,CS, # of Display connected

void setup()
{
  lc.shutdown(0, false); // Wake up displays
  lc.setIntensity(0, 5); // Set intensity levels
  lc.clearDisplay(0);  // Clear Displays
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop()
{
  if (Serial.available() > 0) {
    long raw = Serial.parseInt();
    for (int i = 0; i < 8; i++) {
       int x = long(raw/pow(10,i)) % 10;
     switch (x) {
        case 0:
          lc.setRow(0,7-i, B00000000);
          break;
        case 1:
          lc.setRow(0, 7-i, B10000000);
          break;
        case 2:
          lc.setRow(0, 7-i, B11000000);
          break;
        case 3:
          lc.setRow(0, 7-i, B11100000);
          break;
        case 4:
          lc.setRow(0, 7-i, B11110000);
          break;
        case 5:
          lc.setRow(0, 7-i, B11111000);
          break;
        case 6:
          lc.setRow(0, 7-i, B11111100);
          break;
        case 7:
          lc.setRow(0, 7-i, B11111110);
          break;
        case 8:
          lc.setRow(0, 7-i, B11111111);
          break;
      }
    }
  }
}
