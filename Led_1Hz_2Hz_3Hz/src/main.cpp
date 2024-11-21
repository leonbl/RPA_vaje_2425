#include <Arduino.h>
#define led1 16
#define led2 17
#define led3 18
#define led4 19

void task_led1(void *parameter){
  pinMode(led1, OUTPUT);
  while(1){
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);
  }
}
void task_led2(void *parameter){
  pinMode(led2, OUTPUT);
  while(1){
    digitalWrite(led2, HIGH);
    delay(166);
    digitalWrite(led2, LOW);
    delay(166);
  }
}
void task_led3(void *parameter){
  pinMode(led3, OUTPUT);
  while(1){
    digitalWrite(led3, HIGH);
    delay(71);
    digitalWrite(led3, LOW);
    delay(71);
  }
}

void setup() {
  xTaskCreate(task_led1, "t1", 2000, NULL, 1, NULL);
  xTaskCreate(task_led2, "t2", 2000, NULL, 1, NULL);
  xTaskCreate(task_led3, "t2", 2000, NULL, 1, NULL);
}

void loop() {
}
