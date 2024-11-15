#include <Arduino.h>
char prejeto[100]={0};
uint32_t indx = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  if (Serial.available() > 0) {
    char znak = Serial.read();
    if(znak == 10){
      Serial.println(prejeto);
      indx = 0;
    }else{
      prejeto[indx] = znak;
      indx++;
    }
  }
}