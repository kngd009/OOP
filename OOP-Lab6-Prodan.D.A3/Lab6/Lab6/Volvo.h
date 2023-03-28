#pragma once
#include "Car.h"

class Volvo : public Car {
private:
    double fuelCapacity = 0.0;
    double fuelConsumption = 0.0;
    double avgSpeedSunny = 0.0;
    double avgSpeedRain = 0.0;
    double avgSpeedSnow = 0.0;
public:
	Volvo();
	virtual const char* getName() override;
	virtual double calculateTime(double circuitLength, Weather weather) override;
};