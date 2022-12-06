#include <Wire.h>
#include "Adafruit_TCS34725.h"
int led = 5;

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_1X);

void setup(void) {
  Serial.begin(9600);
  pinMode (led, OUTPUT); 
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }
}

void loop(void) {
  uint16_t r, g, b, c;
  r = map(r, 0, 65535, 0, 255);
  g = map(g, 0, 65535, 0, 255);
  b = map(b, 0, 65535, 0, 255);
  tcs.getRawData(&r, &g, &b, &c);
  // if ((b > r ) && (b > g )) Serial.println("Blå farve detekteret");  
  // if ((r > g ) && (r > b )) Serial.println("Rød farve detekteret"); 
  // if ((g > r ) && (g > b )) Serial.println("Grøn farve detekteret"); 
  // delay(3000);  
  
  Serial.print("Red: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("Green: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("Blue: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("Color: "); Serial.print(c, DEC); Serial.print(" ");
  delay(5000);
  Serial.println(" ");
  analogWrite (led, c); 
  delay(1000);
}
