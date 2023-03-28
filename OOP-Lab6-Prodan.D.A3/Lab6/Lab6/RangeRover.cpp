#include "RangeRover.h"

RangeRover::RangeRover() {
	fuelCapacity = 18.0;
	fuelConsumption = 7.5;
	avgSpeedSunny = 95.0;
	avgSpeedRain = 75.0;
	avgSpeedSnow = 55.0;
}

double RangeRover::calculateTime(double circuitLength, Weather weather) {
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

	double time = circuitLength / speed * 60 * 60;
	double fuelConsumed = fuelConsumption * circuitLength / 100;
	if (fuelConsumed > fuelCapacity) {
		return -1.0;
	}
	fuelCapacity -= fuelConsumed;
	return time;
}

const char* RangeRover::getName()
{
	return "RangeRover";
}