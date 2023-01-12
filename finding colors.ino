#include <Wire.h>
#include "Adafruit_TCS34725.h"

//#define Red_MAX_OFFSET 350;  // the maximum diff you found between readings
//#define Green_MAX_OFFSET 80;
//#define Yellow_MAX_OFFSET 2000;
#define MAX_OFFSET 80
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_600MS, TCS34725_GAIN_1X);

typedef struct {  // struct to hold raw color data 
   uint16_t red;
   uint16_t green;
   uint16_t blue;
   uint16_t clear;
} Color;

//farverne er målt i 2 forskellige distancer, da tallene variere meget.

//Red //maybe works
Color my_redcloseup = {832,128,231,1096};
Color my_reddistance = {515,159,138,760};

//yellow
Color my_yellowcloseup = {2770, 800, 527, 3740};
Color my_yellowdistance = {839,485,201,1540};

//Green
Color my_greencloseup = {154, 142, 102, 342}; //close up values
Color my_greendistance = {77, 88, 47, 207}; //distance values

void setup() {
  //starter op og ser er om den rigtige sensor er tilsluttet
  Serial.begin(9600);
  Serial.println("Color View Test!");

  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1); // halt!
  }
}

void loop() {
  uint16_t clear, red, green, blue;

  tcs.setInterrupt(false);      // turn on LED

  delay(100);  // takes 50ms to read 

  tcs.getRawData(&red, &green, &blue, &clear);

  tcs.setInterrupt(true);  // turn off LED
  //tjekker om farven er rød, denne kan drille, da RGBsensorer har det med at tage rød som en brun/orange farve.
  if (compare_colour(&my_redcloseup, red, green, blue, clear)){
    Serial.println("I see red");
  }
  if (compare_colour(&my_reddistance, red, green, blue, clear)){
    Serial.println("I see red");
  }
  //tjekker om det er gult
  if (compare_colour(&my_yellowcloseup, red, green, blue, clear)){
    Serial.println("I see yellow");
  }
  if (compare_colour(&my_yellowdistance, red, green, blue, clear)){
    Serial.println("I see yellow");
  }
  //tjekker om det er grøn
  if (compare_colour(&my_greencloseup, red, green, blue, clear)){
      Serial.println("I see green.");
  }
  else if (compare_colour(&my_greendistance, red, green, blue, clear)){
      Serial.println("I see green.");
  }
}

//denne bliver brugt til at sammenligne farver, og hvis de passer sammen, så printer den linjen for den tilhørende farve. 
boolean compare_colour(Color * std, uint16_t r, uint16_t g, uint16_t b, uint16_t c){
if ((r - std -> red <= MAX_OFFSET) && (r - std -> red >= 0) &&
      (g - std  -> green <= MAX_OFFSET) && (g - std -> green >= 0) &&
      (b - std -> blue <= MAX_OFFSET) && (b - std -> blue >= 0) &&
      (c - std -> clear <= MAX_OFFSET) && (c - std ->clear >= 0))
  {
      return true;
  }
  return false;
}
