#include <DS3231.h>
#include <Wire.h>
#define buz 10

RTClib RTC;
DateTime now;
DS3231 Clock;

bool alarming = false;

void setup() {
  pinMode(buz, OUTPUT);
  //  Serial.begin(9600);
  Wire.begin();

  //  SetTime();
}

void loop() {
  delay(1000);
  now = RTC.now();

  //  Serial.print(now.year(), DEC);
  //  Serial.print('/');
  //  Serial.print(now.month(), DEC);
  //  Serial.print('/');
  //  Serial.println(now.day(), DEC);
  //  Serial.setCursor(0, 1);
  //    Serial.print(now.hour(), DEC);
  //    Serial.print(':');
  //    Serial.print(now.minute(), DEC);
  //  Serial.print(':');
  //  Serial.print(now.second(), DEC);
  //  Serial.println();

  if ( now.hour() == 6 && now.minute() == 50 && now.second() == 0)
    alarming = true;

  //    Serial.println(analogRead(A0));

  if (alarming) {
    Buzzer();
    alarming = (analogRead(A0) < 160);
  }
}

void Buzzer() {
  //    Serial.println("buzzing!");
  //  tone(A1, 200, 500);
  //  delay(666);
  //  tone(A1, 350, 500);
  //  delay(667);
  //  tone(A1, 200, 500);
  //  delay(667);
  for (int i = 0; i < 2; i++) {
    tone(A1, 440, 200);
    delay(200);
    tone(A1, 493, 200);
    delay(200);
    tone(A1, 440, 200);
    delay(400);
  }
  tone(A1, 391, 400);
  delay(400);
  tone(A1, 415, 200);
  delay(200);
  tone(A1, 440, 400);
}

//void SetTime() {
//
//  byte Temp1, Temp2, Year, Month, Day, DoW, Hour, Minute, Second;
//
//  Temp1 = (byte)'2' - 48;
//  Temp2 = (byte)'0' - 48;
//  Year = Temp1 * 10 + Temp2;
//
//  Temp1 = (byte)'0' - 48;
//  Temp2 = (byte)'2' - 48;
//  Month = Temp1 * 10 + Temp2;
//
//  Temp1 = (byte)'0' - 48;
//  Temp2 = (byte)'1' - 48;
//  Day = Temp1 * 10 + Temp2;
//
//  //  DoW = (byte)InString[6] - 48;
//
//  Temp1 = (byte)__TIME__[0] - 48;
//  Temp2 = (byte)__TIME__[1] - 48;
//  Hour = Temp1 * 10 + Temp2;
//
//  Temp1 = (byte)__TIME__[3] - 48;
//  Temp2 = (byte)__TIME__[4] - 48;
//  Minute = Temp1 * 10 + Temp2;
//
//  Temp1 = (byte)__TIME__[6] - 48;
//  Temp2 = (byte)__TIME__[7] - 48;
//  Second = Temp1 * 10 + Temp2;
//
//  Clock.setYear(Year);
//  Clock.setMonth(Month);
//  Clock.setDate(Day);
//
//  Clock.setHour(Hour);
//  Clock.setMinute(Minute);
//  Clock.setSecond(Second);
//}
