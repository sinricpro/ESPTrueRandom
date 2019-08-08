/*
 * SetRandomSeed.
 *
 * You can use ESPTrueRandom to set the seed for the normal Arduino
 * random number generator.
 *
 * That way you can quickly generate random numbers that are
 * different every time using the random number generator.
 */

#include "ESPTrueRandom.h"

int i;

void setup() {
  Serial.begin(9600);
  Serial.println("Here are some pseudo random digits.");
  for (i=1;i<=20;i++) Serial.print(random(10));
  Serial.println();

  randomSeed(ESPTrueRandom.random());
  
  Serial.println("Here are some random seeded pseudo random digits.");
  for (i=1;i<=20;i++) Serial.print(random(10));
  Serial.println();
}
void loop() {
}
