#include <Arduino.h>
#define led 11

int32_t pos = 0, predznak = 10;
void setServo(uint32_t pos);
void timerInt();

void setup() {
  pinMode(9, OUTPUT);
  pinMode(led, OUTPUT);
  HardwareTimer *Timer1 = new HardwareTimer(TIM1);
  Timer1->setOverflow(20000, MICROSEC_FORMAT);
  Timer1->attachInterrupt(timerInt);
  Timer1->resume();
  Serial.begin(9600);
}

void loop() {
  pos = pos + predznak;
  if(pos>1000){
    predznak = -10;
  }
  if(pos<0){
    predznak = 10;
  }
  delay(10);
}

void setServo(uint32_t pos){
  digitalWrite(9, 1);
  delayMicroseconds(1000 + pos);
  digitalWrite(9, 0);
}

void timerInt(){
  setServo(pos);
}