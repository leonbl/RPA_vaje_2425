#include <Arduino.h>
#define led 16
#define tipka 15
int staro_stanje_tipke = 1;
bool tipka_pritisnjena = false;

void task_led(void *parameter){
  pinMode(led, OUTPUT);
  while(1){
    if(tipka_pritisnjena){
      digitalWrite(led, HIGH);
      vTaskDelay(200/portTICK_PERIOD_MS);
      digitalWrite(led, LOW);
      vTaskDelay(200/portTICK_PERIOD_MS);
    }
   vTaskDelay(1);
  }
}
void task_tipka(void *parameter){
  pinMode(tipka, INPUT);
  while(1){
    int stanje_tipke = digitalRead(tipka);
    if(staro_stanje_tipke == 0 && stanje_tipke == 1){
      tipka_pritisnjena = !tipka_pritisnjena;
      Serial.println(tipka_pritisnjena);
    }
    staro_stanje_tipke = stanje_tipke;
    vTaskDelay(1);
  }
}


void setup() {
  Serial.begin(9600);
  xTaskCreate(task_led, "t1", 3000, NULL, 1, NULL);
  xTaskCreate(task_tipka, "t2", 3000, NULL, 1, NULL);
}

void loop() {

}