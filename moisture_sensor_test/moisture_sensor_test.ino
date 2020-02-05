#include <Servo.h>

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(2);
}

void loop() {
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
}

void printSensorOutputs() {
  Serial.print("Sensor 1:");
  Serial.println(analogRead(A1));
  Serial.print("Sensor 2:");
  Serial.println(analogRead(A2));
  Serial.print("Sensor 3:");
  Serial.println(analogRead(A3));
  Serial.println();
  delay(500);
}
