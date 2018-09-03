#include "LedControl.h"

LedControl lc = LedControl(12, 10, 11, 1);
byte bytes[9] = {B00000000,B10000000,B11000000,B11100000,B11110000,B11111000,B11111100,B11111110,B11111111};

void setup()
{
  lc.shutdown(0, false);
  Serial.begin(9600);
  Serial.setTimeout(5);
}

void loop()
{
  if (Serial.available() > 0) {
    long raw = Serial.parseInt();
    for (int i = 0; i < 8; i++) {
       int num = long(raw/pow(10,i)) % 10;
       lc.setRow(0,7-i,bytes[num]);
    }
  }
}
