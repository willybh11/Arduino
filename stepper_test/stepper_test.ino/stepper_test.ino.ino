#include <Stepper.h>

#define STEPS 192 //max 192

Stepper stepper(STEPS, 8, 10, 9, 11);

//total steps 2048

int n = 0;
int pattern[] = {2048,-2048};

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(200);
}

void loop() {

  n %= 2;
  stepper.step(pattern[n]);
  n++;

}
