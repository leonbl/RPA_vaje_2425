#include <Arduino.h>

hw_timer_t *TIMER0 = NULL;
bool stanje = false;

void tipka()
{
  stanje = !stanje;
}

void prekinetev_timer0()
{
  if (stanje)
    digitalWrite(16, !digitalRead(16));
}

void setup()
{
  pinMode(15, INPUT);
  pinMode(16, OUTPUT);
  attachInterrupt(15, tipka, RISING);
  TIMER0 = timerBegin(0, 80, true);
  timerAttachInterrupt(TIMER0, prekinetev_timer0, true);
  timerAlarmWrite(TIMER0, 100000, true);
  timerAlarmEnable(TIMER0);
}

void loop()
{
}
