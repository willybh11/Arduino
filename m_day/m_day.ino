#include <Servo.h>

Servo servo1;
Servo servo2;

int pos1 = 60;
int pos2 = 120;


void setup() {
  servo1.attach(9);
  servo2.attach(8); 
}

void loop() {
  for (pos1 = 60; pos1 <= 120; pos1 += 1) {
    pos2 -= 1;
    // in steps of 1 degree
    servo1.write(pos1);
    servo2.write(pos2);
    delay(15);                      
  }
  for (pos1 = 120; pos1 >= 60; pos1 -= 1) {
    pos2 += 1;
    servo1.write(pos1);   
    servo2.write(pos2);          
    delay(15);                      
  }
}

