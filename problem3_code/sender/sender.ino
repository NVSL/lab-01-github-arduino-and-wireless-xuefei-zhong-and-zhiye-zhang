#include "RadioFunctions.h"

#define TIME_OUT 100000

void setup()
{
  Serial.begin(9600);  // Start up serial
  Serial1.begin(115200);
  rfBegin(26);  // Initialize ATmega128RFA1 radio on channel 11 (can be 11-26)
  
  
}

unsigned long t_start, t_end;

String testString = "ZzzzzzzzzzZzzzzzzzzzZzzzzzzzzzZzzzzzzzzzZzzzzzzzzz";


void loop(){
  rfPrint(testString);
}
