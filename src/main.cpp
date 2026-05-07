#include <Arduino.h>

void setup() { 
}

void loop() {
  analogWrite(9, 64);
  delay(1000);
  analogWrite(9, 128);
  delay(1000);
  analogWrite(9, 192);
  delay(1000);
  analogWrite(9, 255);
  delay(1000);
}