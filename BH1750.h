#ifndef ZYL_BH1750_H
#define ZYL_BH1750_H

#include "Particle.h"


/* This library for Digital Light sensor BH1750FVI
   use I2C Communication protocal , SDA,SCL Are required 
 
   to interface with this sensor
  
   pin configuration :
  
   VCC >>> 3.3V
   SDA >>> A4 
   SCL >>> A5
   ADDR >> A3 "Optional"
   GND >>> gnd
  
   written By : Mohannad Rawashdeh
   www.genotronex.com
*/


#define DEVICE_ADDRESS_LOW 0x23 // Device address when address pin LOW
#define DEVICE_ADDRESS_HIGH 0x5C // Device address when address pin HIGH
//all command here taken from Data sheet OPECODE Table page 5
#define POWER_DOWN 0x00

#define POWER_ON 0x01

#define RESET 0x07

#define CONTINUOUS_HIGH_RESOLUTION_MODE  0x10
#define CONTINUOUS_HIGH_RESOLUTION_MODE2  0x11
#define CONTINUOUS_LOW_RESOLUTION_MODE  0x13

#define ONETIME_HIGH_RESOLUTION_MODE  0x20
#define ONETIME_HIGH_RESOLUTION_MODE2  0x21
#define ONETIME_LOW_RESOLUTION_MODE  0x23//As well as address value


class BH1750 {  
    void _i2cWriteTo(uint8_t dataToSend);  
    byte _deviceAddress;
    boolean _state;

public:
    BH1750();
    void begin(uint8_t address);
    void sleep(); 
    void setMode(uint8_t mode);
    void reset();
    void setAddress(uint8_t add);
    uint16_t getLightIntensity();
};


#endif