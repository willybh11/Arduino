
void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Sensor 1:");
  Serial.println(analogRead(A1));
  Serial.print("Sensor 2:");
  Serial.println(analogRead(A2));
  Serial.print("Sensor 3:");
  Serial.println(analogRead(A3));
  Serial.println();
  delay(500);
}
