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
  int delay = 1000;
  t_start = micros();
  for(int i = 0; i<1000; i++){
    rfPrint(testString);
    delayMicroseconds(delay);   
  }
  t_end = micros();
  Serial.println(t_end);
  Serial.println(t_start);
  double result = (double)(testString.length()) * 1000000000.0/(double)(t_end - t_start);
  Serial.print(result);
  Serial.println("Bps");
  
  delayMicroseconds(10000000);

  while(true);
}
