//
//    FILE: dht.h
//  AUTHOR: Rob Tillaart
// VERSION: 0.1.18
// PURPOSE: DHT Temperature & Humidity Sensor library for Arduino
//     URL: http://arduino.cc/playground/Main/DHTLib
//
// HISTORY:
// see dht.cpp file
//

#ifndef pluvio_h
#define pluvio_h

#if ARDUINO < 100
#include <WProgram.h>
#include <pins_arduino.h>  // fix for broken pre 1.0 version - TODO TEST
#else
#include <Arduino.h>
#endif

#define CLICK 0.01

// max timeout is 100 usec.
// For a 16 Mhz proc 100 usec is 1600 clock cycles
// loops using DHTLIB_TIMEOUT use at least 4 clock cycli
// so 100 us takes max 400 loops
// so by dividing F_CPU by 40000 we "fail" as fast as possible
#define DHTLIB_TIMEOUT 400 // (F_CPU/40000)

class pluvio
{
public:

  pluvio(uint8_t pin);
  double getRain() const;
  static void resetRain();

private:
  
  static void addRain();
  uint8_t pin;  // buffer to receive data
  static double rain;
};
#endif
//
// END OF FILE
//
