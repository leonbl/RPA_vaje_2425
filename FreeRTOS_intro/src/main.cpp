#include <Arduino.h>
#define led1 16
#define led2 17
#define led3 18
#define led4 19
#define tipka 15

void task_led(void *parameter){
  while(1){
  }
}
void task_led2(void *parameter){
  while(1){
   
  }
}


void setup() {
  Serial.begin(115200);
  xTaskCreate(task_led1, "t1", 2000, NULL, 1, NULL);
  xTaskCreate(task_led2, "t2", 2000, NULL, 1, NULL);
}

void loop() {

}