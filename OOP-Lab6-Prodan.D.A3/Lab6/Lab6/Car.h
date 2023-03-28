#pragma once
#include <iostream>
#include "Weather.h"

using namespace std;

class Car {
protected:
	double fuelCapacity;
	double fuelConsumption;
	double avgSpeedSunny;
	double avgSpeedRain;
	double avgSpeedSnow;
	double finishTime;
	int time;

public:
	virtual double calculateTime(double circuitLength, Weather weather) = 0;
	virtual const char* getName() = 0;
	void setFinishTime(double timp) { time = timp; };
	double getFinishTime() { return time; };
};
