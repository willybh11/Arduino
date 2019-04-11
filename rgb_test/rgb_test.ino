
#define pinR 8
#define pinG 9
#define pinB 10

void setup() {
  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {
  digitalWrite(pinR, HIGH);
}
