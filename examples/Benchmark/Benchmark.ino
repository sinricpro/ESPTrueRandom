#include "ESPTrueRandom.h"

unsigned long startTime;
int i;

void setup() {
  Serial.begin(9600);
  
  Serial.println("ESPTrueRandom benchmark");
  Serial.println("--------------------");
  Serial.println();

  Serial.print("Arduino clock speed: ");
  Serial.print(F_CPU/1000000);
  Serial.println("MHz");

  Serial.print("randomBit(): ");
  startTime = millis();
  ESPTrueRandom.randomBit();
  Serial.print(millis() - startTime);
  Serial.println("ms");
  
  Serial.print("randomByte(): ");
  startTime = millis();
  ESPTrueRandom.randomByte();
  Serial.print(millis() - startTime);
  Serial.println("ms");
  
  Serial.print("random(100): ");
  startTime = millis();
  ESPTrueRandom.random(100);
  Serial.print(millis() - startTime);
  Serial.println("ms");
  
  Serial.print("random(65536): ");
  startTime = millis();
  ESPTrueRandom.random(65536);
  Serial.print(millis() - startTime);
  Serial.println("ms");
  
  Serial.print("random(65537): ");
  startTime = millis();
  ESPTrueRandom.random(65537);
  Serial.print(millis() - startTime);
  Serial.println("ms");
}
void loop() {
}
