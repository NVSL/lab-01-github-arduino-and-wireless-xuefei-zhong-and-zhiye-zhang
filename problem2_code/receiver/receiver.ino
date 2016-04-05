#include "RadioFunctions.h"

#define TIME_OUT 1000000

unsigned long tLastTrans;
unsigned long counter;

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(26);  // Initialize ATmega128RFA1 radio on channel 11 (can be 11-26)
  
  counter = 0;
  tLastTrans = micros();
}

void loop()
{  
  if (rfAvailable())
  {
    rfRead();
    counter++;
    tLastTrans = micros();
  }else if(counter == 0){
    
  }else if(micros()- tLastTrans >= TIME_OUT){
    Serial.print(counter);
    Serial.println("B recivied before timeout");
    counter = 0;
  }
}
