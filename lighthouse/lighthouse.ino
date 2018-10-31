
int sensorPin = A0;
int led1 = 2;
int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int inc = 738/9;
int val = 0; 

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(led1, OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  Serial.begin(9600);
}
                                                                           
void loop() {
  val = analogRead(sensorPin);
  Serial.println(val);
  digitalWrite(led1,LOW);
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  digitalWrite(led5,LOW);

  if (val < inc*1) {
    digitalWrite(led1,HIGH);
  }
  else if (val < inc*2) {
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
  }
  else if (val < inc*3) {
    digitalWrite(led2,HIGH);
  }
  else if (val < inc*4) {
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
  }
  else if (val < inc*5) {
    digitalWrite(led3,HIGH);
  }
  else if (val < inc*6) {
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
  else if (val < inc*7) {
    digitalWrite(led4,HIGH);
  }
  else if (val < inc*8) {
    digitalWrite(led4,HIGH);
    digitalWrite(led5,HIGH);
  }
  else if (val < inc*9) {
    digitalWrite(led5,HIGH);
  }
  
  
}
