#include "Circuit.h"
#include "Fiat.h"
#include "Seat.h"
#include "BMW.h"
#include "Volvo.h"
#include "RangeRover.h"

int main() {
	Circuit c;
	c.SetLength(300);
	c.SetWeather(Weather::Snow);
	c.AddCar(new Volvo());
	c.AddCar(new BMW());
	c.AddCar(new Seat());
	c.AddCar(new Fiat());
	c.AddCar(new RangeRover());
	c.Race();
	c.ShowFinalRanks();
	c.ShowWhoDidNotFinish();

	return 0;
}