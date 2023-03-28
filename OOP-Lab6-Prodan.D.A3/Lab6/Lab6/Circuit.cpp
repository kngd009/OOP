#include "Car.h"
#include "Circuit.h"
#include "Weather.h"
#include <iostream>

using namespace std;

Circuit::Circuit()
{
	weather = Weather::Sunny;
	circuitLength = 0;
	cars = new Car*[10];
}

void Circuit::SetLength(double length) {
	circuitLength = length;
}

void Circuit::SetWeather(Weather w) {
    weather = w;
    
    /*cout << "--------------------------------------------------------------" << endl;*/
    /*cout << "Weather status: " << weather << endl;*/
    /*cout << "--------------------------------------------------------------" << endl << endl;*/
}

void Circuit::AddCar(Car* car) {
	cars[numCars] = car;
	numCars++;
}

void Circuit::Race() {

    cout << "--------------------------------------------------------------" << endl;
    cout << "Circuit length: " << circuitLength << "km. " << endl;
    cout << "--------------------------------------------------------------" << endl << endl;
    for (int i = 0; i < numCars; i++) {
        Car* car = cars[i];
        time = car->calculateTime(circuitLength, weather);
        if (time == -1.0) {
            cout << car->getName() << " did not finish the race due to lack of fuel." << endl;
        }
        else {
            cout << car->getName() << " finished the race in " << time << " seconds." << " ( " << time/60 << " minutes ) " << "( " << time / 3600 << " hours )" << endl;
            car->setFinishTime(time);
        }
    }
}

void Circuit::ShowFinalRanks() {
    
    Car** tempCars = new Car * [numCars];
    for (int i = 0; i < numCars; i++) {
        tempCars[i] = cars[i];
    }

    
    for (int i = 0; i < numCars; i++) {
        for (int j = i + 1; j < numCars; j++) {
            if (tempCars[i]->getFinishTime() > tempCars[j]->getFinishTime()) {
                Car* temp = tempCars[i];
                tempCars[i] = tempCars[j];
                tempCars[j] = temp;
            }
        }
    }
    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "Final race ranking: " << endl;
    cout << "--------------------------------------------------------------" << endl << endl;
    for (int i = 0; i < numCars; i++) {
        cout << tempCars[i]->getName() << ": "; if (tempCars[i]->getFinishTime() > 0)
        {
             timeConverter(tempCars[i]->getFinishTime());
             cout << endl;
        }
        else {
            cout << "did not finish!" << endl;
        }
    }
    cout << endl;

    delete[] tempCars;
}

void Circuit::ShowWhoDidNotFinish() {
    bool everyoneFinished = true;
    for (int i = 0; i < numCars; i++) {
        if (cars[i]->getFinishTime() < 0) {
            everyoneFinished = false;
            break;
        }
    }
    if (everyoneFinished) {
        cout << "Everyone finished the race!" << endl;
    }
    else {
        cout << "--------------------------------------------------------------" << endl;
        cout << "The following cars did not finish the race:" << endl;
        cout << "--------------------------------------------------------------" << endl << endl;
        for (int i = 0; i < numCars; i++) {
            if (cars[i]->getFinishTime() < 0) {
                cout << cars[i]->getName() << endl;
            }
        }
    }
}
void Circuit::timeConverter(double time)
{
    int timp = time;
    int hours, minutes, seconds;

    hours = (int)(timp / 3600);
    minutes = (int)((timp / 60) % 60);
    seconds = (int)(timp % 60);

    cout << hours << " hours, " << minutes << " minutes, " << seconds << " seconds";
}