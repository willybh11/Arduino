int potPin = 8;
int ledPin = 13;
int val = 0;

void setup() {
  pinMode(ledPin,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  val = analogRead(potPin);    // read the value from the sensor
  Serial.println("val:" + val);
  digitalWrite(ledPin, HIGH);  // turn the ledPin on
  delay(val*10);                  // stop the program for some time
  digitalWrite(ledPin, LOW);   // turn the ledPin off
  delay(val*10);                  // stop the program for some time
}
