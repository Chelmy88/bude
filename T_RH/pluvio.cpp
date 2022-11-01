//
//    FILE: dht.cpp
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.18
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: http://arduino.cc/playground/Main/DHTLib
#include "pluvio.h"

double pluvio::rain = 0.;

pluvio::pluvio(uint8_t pin_in): pin(pin_in) {
  attachInterrupt(digitalPinToInterrupt(pin), addRain, FALLING);
}

double pluvio::getRain() const {
  return rain;
}
static void pluvio::resetRain() {
  rain = 0.;
}

static void pluvio::addRain() {
  Serial.println("RAIN...");
  rain += CLICK;
}
