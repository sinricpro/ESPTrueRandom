/*
 * Uuid
 *
 * UUIDs are unique numbers that are used for identifying individual units,
 * functions, programmes, or whatever you want to tag.
 *
 * In this demo, press the Arduino Reset button to generate a new number.
 *
 * UUIDs can be assigned sequentially from allocated blocks of numbers, but
 * they are most powerful when randomly assigned. UUIDs are such big numbers
 * that, for all effective purposes, no two numbers will ever match.
 *
 * UUIDs are particularly useful in web-aware devices, or radio networks.
 *
 * For a discussion of the use of UUIDs, see
 *   http://en.wikipedia.org/wiki/Universally_Unique_Identifier
 *
 * For implementation details of UUIDs, see
 *   http://tools.ietf.org/html/rfc4122
 */

#include "ESPTrueRandom.h"

byte uuidNumber[16]; // UUIDs in binary form are 16 bytes long

void setup() {
  Serial.begin(9600);

  // Generate a new UUID
  ESPTrueRandom.uuid(uuidNumber);
  String uuidStr = ESPTrueRandom.uuidToString(uuidNumber);
  Serial.println("The UUID number is " + uuidStr);
  
}

void loop() {
}
