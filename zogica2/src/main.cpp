#include <Arduino.h>

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
// The pins for I2C are defined by the Wire-library.
// On an arduino UNO:       A4(SDA), A5(SCL)
// On an arduino MEGA 2560: 20(SDA), 21(SCL)
// On an arduino LEONARDO:   2(SDA),  3(SCL), ...
#define OLED_RESET -1       // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int16_t w, h;

int16_t getPotPos();

void setup()
{
  Serial.begin(9600);

  // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
  if (!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS))
  {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;)
      ; // Don't proceed, loop forever
  }
  h = display.height();
  w = display.width();

}

int16_t xZoga=6, yZoga=6, rZoga=5;
int16_t xspeed=5, yspeed=1;
int16_t xRect=50, yRect=59, wRect=25, hRect=5;

void loop()
{
  display.clearDisplay();
  xZoga += xspeed;
  yZoga += yspeed;
  if(xZoga>(w-rZoga) || xZoga<rZoga){
    xspeed = -xspeed;
  }
  if(yZoga>(h-rZoga) || yZoga<rZoga){
    yspeed = -yspeed;
  }
  display.drawCircle(xZoga, yZoga, rZoga, SSD1306_WHITE);
  getPotPos();
  display.drawRect(xRect, yRect, wRect, hRect, 1);  
  display.display();
}

int16_t getPotPos(){
  int16_t val = analogRead(14);
  Serial.println(val);
  return val;
}