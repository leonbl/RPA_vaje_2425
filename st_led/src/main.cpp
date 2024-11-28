#include <Arduino.h>
#define SDI 8
#define SCL 7
#define LCL 4

void t_scl();
void t_lcl();

uint8_t stevila[]={0x03,0x9f,0x25,0x0d,0x99,0x49,0x41,0x1f,0x01,0x09};

void setup() {
  pinMode(LCL, OUTPUT);
  pinMode(SCL, OUTPUT);
  pinMode(SDI, OUTPUT);
}

void loop() {
  uint8_t a = stevila[9], b = 0;
  for(int n=0; n<8; n++){
    b = a & 0x01;
    digitalWrite(SDI, b);
    a = a >> 1;
    t_scl();
  }
  a = 0xff;
  for(int n=0; n<8; n++){
    b = a & 0x01;
    digitalWrite(SDI, b);
    a = a >> 1;
    t_scl();
  }

  t_lcl();
  delay(1000);
}

void t_scl(){
  digitalWrite(SCL, 1);
  digitalWrite(SCL, 0);
}

void t_lcl(){
  digitalWrite(LCL, 1);
  digitalWrite(LCL, 0);
}