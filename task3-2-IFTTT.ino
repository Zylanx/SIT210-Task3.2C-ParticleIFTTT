#include "Wire.h"

#include "BH1750.h"


#define LIGHT_THRESHOLD 30
#define LIGHT_OFFSET 10

#define CHECK_TIME 3000


bool sunny = false;
BH1750 lightSensor;


void setup() {
    lightSensor.begin(DEVICE_ADDRESS_LOW);
    lightSensor.setMode(CONTINUOUS_HIGH_RESOLUTION_MODE);
}

void loop() {
    detectSunny();
    delay(CHECK_TIME);
}

void detectSunny()
{
    if (sunny && lightSensor.getLightIntensity() < LIGHT_THRESHOLD)
    {
        sunny = false;
        Particle.publish("Terrarium_Sunny", "false");
        Serial.println("The terrarium is now in the shade");
    }
    else if (!sunny && lightSensor.getLightIntensity() > LIGHT_THRESHOLD + LIGHT_OFFSET)
    {
        sunny = true;
        Particle.publish("Terrarium_Sunny", "true");
        Serial.println("The terrarium is now in the sun");
    }
}