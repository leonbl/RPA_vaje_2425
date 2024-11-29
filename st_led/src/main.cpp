#include <Arduino.h>

#define SDI 8
#define SCL 7
#define LCL 4

uint32_t nmb = 0; 
uint32_t stari = 0;

void t_scl();
void t_lcl();
void display(uint8_t num, uint8_t pos);
void display4(uint32_t st);

uint8_t stevila[]={0x03, 0x9f, 0x25, 0x0d, 0x99, 0x49, 0x41, 0x1f, 0x01, 0x09};

void setup() {
 pinMode(SDI, OUTPUT);
 pinMode(SCL, OUTPUT);
 pinMode(LCL, OUTPUT);
}

void loop() {
  
  if(millis()-stari > 10){
    nmb++;
    stari = millis();
  }
  display4(nmb);

}

void display(uint8_t num, uint8_t pos){
  u_int8_t a = stevila[num], b = 0;
  for(int n=0; n<8; n++){
    b = a & 0x01;
    digitalWrite(SDI, b);
    a = a >> 1;
    t_scl();
  }
    a = 0x10;
    a = a << pos;
    for(int n=0; n<8; n++){
    b = a & 0x01;
    digitalWrite(SDI, b);
    a = a >> 1;
    t_scl();

  }
  t_lcl();

}

void display4(uint32_t st){

   display(st / 1000, 3);
   display((st % 1000)/100  ,2);
   display((st % 100)/10, 1);
   display(st %10, 0);
 
}

void t_scl(){
  digitalWrite(SCL, 1);
  digitalWrite(SCL, 0);
}

void t_lcl(){
  digitalWrite(LCL, 1);
  digitalWrite(LCL, 0);
}