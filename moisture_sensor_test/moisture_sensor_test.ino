
void setup() {
  Serial.begin(9600);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Moisture Sensor Value:");
  Serial.println(analogRead(A0));
  delay(100);
}
