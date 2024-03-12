#include <Arduino.h>

#define RxPin 16
#define TxPin 17
#define BAUDRATE 115200
HardwareSerial SerialAT(2);


void setup()
{
  Serial.begin(115200);
  SerialAT.begin(BAUDRATE, SERIAL_8N1, RxPin, TxPin);
  //Serial2.begin(115200);

}

void loop()
{
  Serial.println("test port");
  //Serial1.println("test port 1");
  SerialAT.println("test port 2");
  delay(500); 
}