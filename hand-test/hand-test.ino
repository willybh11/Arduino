int motorPin1 =  1;    //white wire
int motorPin2 =  2;    //black wire

void setup()   {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  //digitalWrite(motorPin1, LOW);
  //digitalWrite(motorPin2, LOW);

  Close();
  Open();

  Serial.begin(9600);
}

void loop()
{
  //Close();
  //Open();
}

void Close() {
  digitalWrite(motorPin1, HIGH); //rotates motor
  digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
  delay(2500); //waits
  digitalWrite(motorPin2, HIGH);    // set the Pin motorPin1 LOW
}

void Open() {
  digitalWrite(motorPin2, HIGH); //rotates motor
  digitalWrite(motorPin1, LOW);    // set the Pin motorPin1 LOW
  delay(2500); //waits
  //digitalWrite(motorPin2, LOW);    // set the Pin motorPin2 LOW
}
