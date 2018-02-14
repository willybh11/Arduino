// Define Pins
#define BLUE 3
#define GREEN 5
#define RED 6

void setup() {
  // put your setup code here, to run once:
  pinMode(RED, OUTPUT);
pinMode(GREEN, OUTPUT);
pinMode(BLUE, OUTPUT);
digitalWrite(RED, HIGH);
digitalWrite(GREEN, LOW);
digitalWrite(BLUE, LOW);
analogWrite(RED, 0);
analogWrite(BLUE,0);  //enter RGB variables here
analogWrite(GREEN, 0);

}

void loop() {
  // put your main code here, to run repeatedly:

}
