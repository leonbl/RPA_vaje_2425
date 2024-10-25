#include <Arduino.h>

#define tipka1 15
#define tipka2 4
int staro_stanje = 0;


void setup()
{
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(tipka1, INPUT);
  pinMode(tipka2, INPUT);
}

void loop()
{
  int t1 = digitalRead(tipka1);
  if(staro_stanje == 1 && t1 == 0){
    digitalWrite(19, !digitalRead(tipka1));
    delay(100);
  }
  staro_stanje = t1;
}
