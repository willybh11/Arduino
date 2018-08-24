#include <Servo.h>
#include <string.h>

Servo myServo;
int servoPos = 1;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  Serial.begin(9600);
  myServo.write(270);

}

void loop() {
  // put your main code here, to run repeatedly:

}
