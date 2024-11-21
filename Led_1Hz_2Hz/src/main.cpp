#include <Arduino.h>
#define led1 16
#define led2 17

bool led1_state = false;
bool led2_state = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  digitalWrite(led1, HIGH);
  delay(50);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led2, LOW);
  delay(200);
  digitalWrite(led1, LOW);
  delay(50);
  digitalWrite(led2, HIGH);
  delay(250);
  digitalWrite(led2, LOW);
  delay(200);
}
