#pragma once
#include "Car.h"

class Circuit {
private:
	Car** cars;
	double circuitLength;
	Weather weather;
	int numCars=0;
	double time = 0;

public:
	Circuit();
	void timeConverter(double time);
	void SetLength(double length);
	void SetWeather(Weather w);
	void AddCar(Car* car);
	void Race();
	void ShowFinalRanks();
	void ShowWhoDidNotFinish();
};

