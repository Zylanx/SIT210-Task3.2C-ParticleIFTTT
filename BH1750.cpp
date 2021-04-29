#include "BH1750.h"
#include "Particle.h"

#include "Wire.h"


// I have edited all of this horribly written code to not be absolutely horrible.


BH1750::BH1750()
{
    ;
}

void BH1750::begin(uint8_t address)
{
    Wire.begin(); 
    _i2cWriteTo(POWER_ON);
    setAddress(address);
}

void BH1750::sleep()
{
    //Turn it off , Reset operator won't work in this mode
    _i2cWriteTo(POWER_DOWN); 
}

void BH1750::reset()
{
    //Turn it on again
    _i2cWriteTo(POWER_ON);
    _i2cWriteTo(RESET);
}


void BH1750::setAddress(uint8_t add)
{
    switch(add)
    {
        case DEVICE_ADDRESS_LOW:
            _deviceAddress = DEVICE_ADDRESS_LOW;
            _state = false;
            break;
        case DEVICE_ADDRESS_HIGH:
            _deviceAddress = DEVICE_ADDRESS_HIGH;
            _state = true;
            break;
    }
}


void BH1750::setMode(uint8_t mode)
{
    switch(mode)
    {
        case CONTINUOUS_HIGH_RESOLUTION_MODE:
            break;
        case CONTINUOUS_HIGH_RESOLUTION_MODE2:
            break;
        case CONTINUOUS_LOW_RESOLUTION_MODE:       
            break;
        case ONETIME_HIGH_RESOLUTION_MODE:
            break;
        case ONETIME_HIGH_RESOLUTION_MODE2:
            break;
        case ONETIME_LOW_RESOLUTION_MODE:  
            break;
    }
    delay(10);
    _i2cWriteTo(mode);
}

uint16_t BH1750::getLightIntensity()
{
    uint16_t intensityValue;
    
    Wire.beginTransmission(_deviceAddress);
    Wire.requestFrom(_deviceAddress, 2);
    
    intensityValue = Wire.read();
    intensityValue <<= 8;
    intensityValue |= Wire.read();
    
    Wire.endTransmission();
    
    intensityValue = intensityValue / 1.2;
    
    return intensityValue;
}

void BH1750::_i2cWriteTo(uint8_t dataToSend)
{
    Wire.beginTransmission(_deviceAddress);
    Wire.write(dataToSend);
    Wire.endTransmission();
}