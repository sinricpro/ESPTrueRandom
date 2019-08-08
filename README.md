# ESPTrueRandom
TrueRandom Arduino library for the ESP

**This is a fork from [ESP8266TrueRandom](https://github.com/marvinroger/ESP8266TrueRandom).**
**It has been modified to be compatible to ESP32**


**The code is only slightly modified from [tinkerit TrueRandom](https://code.google.com/archive/p/tinkerit/wikis/TrueRandom.wiki) to work on the ESP, and this is probably not as random as the original. However, it still performs better than the original random function, based on my tests. What I wanted was a library to generate an UUID for an home automation system using ESP, and unless you have millions of devices, I think this is random enough to avoid conflicts.**

## Introduction

ESPTrueRandom generates true random numbers on ESP. They are different every time you start your program, and are truly unpredictable unlike the default Arduino random() function.

## Compatibility

ESPTrueRandom currently functions on the ESP. ESPTrueRandom reads the ESP internal hardware random number generator register by default or alternatively can use the A0/TOUT pin when useRNG is set to false. If using A0/TOUT do not connect anything to this pin and leave it floating.

## Download

[Download ESPTrueRandom library](https://github.com/sivar2311/ESPTrueRandom/archive/master.zip). Extract the zip file, and copy the directory to your Arduino libraries folder.

## What happens when you use the Arduino random() function?

The Arduino default random() function generates what appear to be random numbers. They are actually calculated from a formula. On reset, the formula is reset at a start point, then progresses through a long sequence of random looking numbers. However, ESP starts at the same point in the sequence every reset. You can move to a different part of the sequence using srandom(), but how do you get a random start point from in the first place?
What happens when you use ESPTrueRandom.random() function?

You get a random number. Really random. Different every time you restart.

## Example

```c++
#include <ESPTrueRandom.h>

void setup() {
  Serial.begin(115200);

  Serial.print("I threw a random die and got ");
  Serial.print(random(1,7));

  Serial.print(". Then I threw a TrueRandom die and got ");
  Serial.println(ESPTrueRandom.random(1,7));

}

void loop() {
  ; // Do nothing
}
```

Upload that code to an ESP and watch it on the Serial Monitor at 115200 baud. The random() function returns the same value every time, but the ESPTrueRandom version is always different.

## ESPTrueRandom basic functions

The existing random functions of Arduino are replicated in ESPTrueRandom.

### ESPTrueRandom.random()

Like the Arduino library and ANSI C, this generates a random number between 0 and the highest signed long integer 2,147,483,647.

### ESPTrueRandom.random(n)

This generates a random number between 0 and (n-1). So random(6) will generate numbers between 0 and 5.

### ESPTrueRandom.random(a,b)

This generates a random number between a and (b-1). So random(1,7) will generate numbers between 1 and 6.

## ESPTrueRandom advanced functions

### ESPTrueRandom.randomBit()

Generating true random numbers takes time, so it can be useful to only generate as many random bits as you need. randomBit() generates a 0 or a 1 with 50% probability. This is the core function from which the other ESPTrueRandom libraries are built.

### ESPTrueRandom.randomByte()

Generates a random byte between 0 and 255. Equivalent to random(256).

### ESPTrueRandom.rand()

Like the ANSI C rand() command, this generates a random number between 0 and the highest signed integer 32767.

### ESPTrueRandom.memfill(address, length)

Fills a block of bytes with random numbers. (length) bytes are filled in total, starting at the given (address).

## ESPTrueRandom specialist functions

### ESPTrueRandom.mac(address)

When operating devices on an Ethernet network, each device must have a unique MAC address. Officially, MAC addresses should be assigned formally via the [IEEE Registration Authority](http://standards.ieee.org/regauth/index.html). However, for practical purposes, MAC addresses can be randomly assigned without problems. This function writes a 6 byte MAC address to a given address. Randomly generated MAC addresses are great for projects or workshops involving large numbers of Arduino Ethernet shields, as each shield has a different MAC address, even though they are running identical code. See the MacAddress example which shows this in use.

### ESPTrueRandom.uuid(address)

UUIDs are unique identifiers. They are 16 bytes (128 bits) long, which means that generating them randomly This generates a random UUID, and writes it to an array. UUIDs are globally unique numbers that are often used in web services and production electronics. ESPTrueRandom can produce any one of 5,316,911,983,139,663,491,615,228,241,121,378,304 different numbers. You're more likely to win top prize in the national lottery 3 times in a row than get two matching UUIDs.

### ESPTrueRandom.uuidToString(address)

Returns a String containing the string representation of the given UUID

## How TrueRandom works

ESPTrueRandom achieves random numbers by reading the ESP internal hardware random number generator register or by by measuring the A0/TOUT pin. However, that isn't noisy enough so a [von Neumann whitening algorithm](http://en.wikipedia.org/wiki/Hardware_random_number_generator) gathers enough entropy from multiple readings to ensure a fair distribution of 1s and 0s.

The other functions within ESPTrueRandom construct the requested values by gathering just enough random bits to produce the required numbers. Generating a random bit takes time, so a significant part of the code works to ensure the random bits are used as efficiently as possible.
