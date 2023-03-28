#include "Fiat.h"

Fiat::Fiat() {
     fuelCapacity = 25.0;
     fuelConsumption = 10.0;
     avgSpeedSunny = 100.0;
     avgSpeedRain = 80.0;
     avgSpeedSnow = 60.0;
}

double Fiat::calculateTime(double circuitLength, Weather weather) {
    double speed;
    if (weather == Weather::Rain) {
        speed = avgSpeedRain;
    }
    else if (weather == Weather::Sunny) {
        speed = avgSpeedSunny;
    }
    else {
        speed = avgSpeedSnow;
    }

    double time = (circuitLength / speed) * 60 * 60;
    double fuelConsumed = fuelConsumption * circuitLength / 100;
    if (fuelConsumed > fuelCapacity) {
        return -1.0;
    }

    fuelCapacity -= fuelConsumed;
    return time;
}

const char* Fiat::getName() 
{
    return "Fiat";
}