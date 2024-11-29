#include <Arduino.h>
#define led 11

HardwareTimer *Timer2 = new HardwareTimer(TIM2);
int32_t pos = 0, predznak = 10;
void timerInt();
void timer2Int();

void setup() {
  pinMode(9, OUTPUT);
  pinMode(led, OUTPUT);
  HardwareTimer *Timer1 = new HardwareTimer(TIM1);
  Timer1->setOverflow(20000, MICROSEC_FORMAT);
  Timer1->attachInterrupt(timerInt);
  Timer1->resume();
  Timer2->attachInterrupt(timer2Int);
  Serial.begin(9600);
}

void loop() {
  
}

void timerInt(){
  digitalWrite(9, 1);
  Timer2->setOverflow(pos + 1000, MICROSEC_FORMAT);
  Timer2->refresh();
  Timer2->resume();
}

void timer2Int(){
  digitalWrite(9, 0);
  Timer2->pause();
}