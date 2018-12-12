
const int buzzer = 9;
int n = 0;

void setup() {
  
  pinMode(buzzer, OUTPUT);

}

void loop() {

  n++;
  tone(buzzer,100);
  delay(100);
  noTone(buzzer);
  delay(100);
  tone(buzzer,200);
  delay(200);
  tone(buzzer,n);
  delay(300);

}
