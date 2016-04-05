/*
  ATmega128RFA1 Dev Board Basic Chat
  by: Jim Lindblom
      SparkFun Electronics
  date: July 3, 2012
  License: Beerware. Feel free to use, reuse, and modify this code
  as you please. If you find it useful, you can buy me a beer.

  This code sets up the ATmega128RFA1's wireless transciever in
  the most basic way possible to serve as a serial gateway.
  Serial into the ATmega128RFA1's UART0 will go out the RF radio.
  Data into the RF radio will go out the MCU's UART0.
*/

#include "RadioFunctions.h"

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(26);  // Initialize ATmega128RFA1 radio on channel 11 (can be 11-26)
  
  // Send a message to other RF boards on this channel
  //rfPrint("ATmega128RFA1 Dev Board Online!\r\n");
}

void loop()
{
  testSingleWayMax(10);
  delay(1000);
  //if (Serial.available())  // If serial comes in...
  
  while(true);
  /*{
    rfWrite(Serial.read()); // ...send it out the radio.
  }
  if (rfAvailable())  // If data receievd on radio...
  {
    Serial.print(rfRead());  // ... send it out serial.
  }*/
}


unsigned long testSingleWayMax (int runs)
{
  Serial.println("Max Single Way Bandwidth:");
  
  for(int i = 1; i <= 124; i++){
    unsigned long result = testSingleWayMax(runs, i);
    Serial.print(i);
    Serial.print(" | ");
    Serial.print((double)(runs * i) / ((double)result / 1000.0));
    Serial.println("KBps");
  }
}

unsigned long testSingleWayMax (int runs, int packetSize)
{
  String message = "f";
  for(int i=0; i<packetSize; i++)
    message += "X"; 
  unsigned long start = micros();
  for(int i = 0; i < runs; i++){
    rfPrint(message);
  }
  return (micros() - start);
}
