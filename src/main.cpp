#include <Arduino.h>

#define RxPin 16
#define TxPin 17
#define BAUDRATE 115200
HardwareSerial SerialAT(2);

//String SettdcAPN = "\""IP"\",nbiot.tdc.dk";

void setup()
{
  Serial.begin(115200);
  SerialAT.begin(BAUDRATE, SERIAL_8N1, RxPin, TxPin);
// Power up "recive"
// LoadVerifyImageHead read(len=272), Time(ms)->0.
// test:VerifyImageHead skip
// VerifyImageBody sha256 skip

// *ATREADY: 1

// SIM Ready

// +CEREG: 2

// lidt efter ca 10 til 20 sek.
// Network Available

// +CEREG: 1  // reg på hjemme netværk = 1 5 = Roaming

  // Run once
  
  SerialAT.println("AT+COPS?"); //(tdc= AT+COPS=1,2,"28301",9)
  delay(1000);
  SerialAT.println("AT+CGPADDR"); //Request the assigned IP address
  delay(5000);
  SerialAT.println("AT+VIOSET=2"); //Set Module to 2.8V
  delay(1000);
  // OK
  SerialAT.println("AT+CFUN=0"); //Switch off the radio module
  delay(1000); 
  // +CEREG: 0
  SerialAT.println("AT+QCBAND=0,20"); //Set the frequency band to 20 for TDC (think can read)
  delay(1000);
  // OK
  SerialAT.println("AT+CFUN=1,1"); //Switch on the radio again
  delay(5000);  
  SerialAT.println("AT+CGDCONT=0,\"IP\",\"internet\""); //Set APN AT+CGDCONT= 0 -> 10 også prævet med "IP"
  //SerialAT.println("AT+CGDCONT=1," + SettdcAPN); //Set APN AT+CGDCONT= 0 -> 10
  delay(5000);
  SerialAT.println("AT+CGCONTRDP"); //Auto connect !! vent på IP adr
  delay(10000);  
  SerialAT.println("AT+CGPADDR"); //Request the assigned IP address
  delay(1000);
  SerialAT.println("AT+COPS?"); //(tdc= AT+COPS=1,2,"28301",9)
  delay(5000);   

  SerialAT.println("AT+CGCONTRDP=?"); //check IP adr
  delay(5000);

  SerialAT.println("AT+CGDCONT?"); //check IP adr
  delay(5000);

}

void loop()
{

}