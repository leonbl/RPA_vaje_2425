#include <Arduino.h>
#define led 16
#define tipka 15

TaskHandle_t led_h;
bool stanje = true;
int staro_stanje_tipke = 1;

void task_led(void *parameter){
  pinMode(led, OUTPUT);
  while(1){
      digitalWrite(led, HIGH);
      vTaskDelay(200/portTICK_PERIOD_MS);
      digitalWrite(led, LOW);
      vTaskDelay(200/portTICK_PERIOD_MS);
  }
  vTaskDelay(1);
}

void task_tipka(void *parameter){
  pinMode(tipka, INPUT);
  while(1){
    int stanje_tipke = digitalRead(tipka);
    if(staro_stanje_tipke == 0 && stanje_tipke == 1){
      stanje = !stanje;
      if(stanje){ 
        vTaskResume(led_h);
      }
      else
      {
        vTaskSuspend(led_h);
      }
    }
    staro_stanje_tipke = stanje_tipke;
    vTaskDelay(1);
  }
}


void setup() {
  Serial.begin(9600);
  xTaskCreate(task_led, "t1", 3000, NULL, 1, &led_h);
  xTaskCreate(task_tipka, "t2", 3000, NULL, 1, NULL);
}

void loop() {

}