#include <Servo.h>

Servo YAW;
Servo JIB;
Servo BOOM;
Servo CLAW;

int boomPos = 80;
int jibPos = 130;
int yawPos = 90;
int clawPos = 145;

int last = 1;

const int SW_pin = 2;
const int X_pin = 0;
const int Y_pin = 1;

bool toggle = true;

void setup() {
  pinMode(SW_pin, INPUT);
  digitalWrite(SW_pin, HIGH);
  Serial.begin(9600);

  YAW.attach(3);
  JIB.attach(4);
  BOOM.attach(5);
  CLAW.attach(6);

}

void loop() {


  if (digitalRead(SW_pin) == 1 && last == 0)
    toggle = !toggle;

  int xLess = analogRead(X_pin) < 500;
  int xMore = analogRead(X_pin) > 600;
  int yLess = analogRead(Y_pin) < 500;
  int yMore = analogRead(Y_pin) > 600;

  if (toggle) {

    yawPos  += 4 * (xLess) - 4 * (xMore) * (xLess + 1);
    boomPos += 4 * (yLess) - 4 * (yMore) * (yLess + 1);

    yawPos = min(max(yawPos, 0), 180);
    boomPos = min(max(boomPos, 30), 120);

  } else {

    clawPos += 5 * (xLess) - 5 * (xMore) * (xLess + 1);
    jibPos  += 4 * (yLess) - 4 * (yMore) * (yLess + 1);

    clawPos = min(max(clawPos, 130), 180);
    jibPos = min(max(jibPos, 30), 150);
  }

  last = digitalRead(SW_pin);

  YAW.write(yawPos); //(0 - 180)
  JIB.write(jibPos); //(55 - 150)
  BOOM.write(boomPos); //(30 - 120)
  CLAW.write(clawPos); //(130 - 180)

  delay(50);
}
