
#include "MeOrion.h"

MeJoystick joystick(PORT_8);
MeDCMotor motor1(M2);

int x = 0;
int y = 0;
int s = 0;
  
void setup() {
  Serial.begin(9600);

}

void loop() {
  x = joystick.readX();
  y = joystick.readY();
  s = ((y/10)*2)*2.5;

  motor1.run(s);
  delay(500);

  Serial.print("Joystick X = ");
  Serial.print(x);
  Serial.print("\t\t Joystick Y = ");
  Serial.println(y);
  Serial.print("Motor speed = ");
  Serial.println(s);
  motor1.stop();
  delay(100);

}
