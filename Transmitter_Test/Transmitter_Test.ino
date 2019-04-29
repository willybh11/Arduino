#include <RH_ASK.h>
#include <SPI.h> // Not actually used but needed to compile

RH_ASK driver;

void setup()
{
  Serial.begin(9600);    // Debugging only
  if (!driver.init())
    Serial.println("init failed");
  Serial.println("XBOX ON");
  pinMode(11,INPUT);
  pinMode(12,OUTPUT);
}

void loop()
{
//  const char *msg = "Hello World!";
//  driver.send((uint8_t *)msg, strlen(msg));
//  driver.waitPacketSent();
//  Serial.println("Message sent");

//  while(1){
  uint8_t buf[12];
  uint8_t buflen = sizeof(buf);
  if (driver.recv(buf, &buflen)) // Non-blocking
  {
    int i;
    // Message with a good checksum received, dump it.
    Serial.print("Message: ");
    Serial.println((char*)buf);
  }
//  }

//  delay(1000);

}
