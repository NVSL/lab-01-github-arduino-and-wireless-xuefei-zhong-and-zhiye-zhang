#include "RadioFunctions.h"

#define TIME_OUT 1000000

unsigned long counter;

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(26);  // Initialize ATmega128RFA1 radio on channel 11 (can be 11-26)
}

unsigned long t_start, t_end;
String testString = "ZzzzzzzzzzZzzzzzzzzzZzzzzzzzzzZzzzzzzzzzZzzzzzzzzz";

void loop()
{  
  counter = 0;
  t_start = micros();
  while(counter < 1000000)
  {
    while (rfAvailable())
    {
      rfRead();
      counter++;
    }
    rfPrint(testString);
    counter += testString.length();
  }
  t_end = micros();
  double result = 1000000.0 * 1000000.0/(double)(t_end - t_start);
  Serial.print(result);
  Serial.println("Bps");
  
  delayMicroseconds(10000000);

  while(true);
}
