#pragma once
#include "Weather.h"
#include "Car.h"

class Circuit
{
private:
	int length;
	Weather vreme;
	int MaxCars;
	int CurrentCar;
	Car** VectorCars; //vector pentru masinile adaugate
	float** VectorRace;

public:
	Circuit();
	~Circuit();
	void SetLength(int value);
	void SetWeather(Weather value);
	bool AddCar(Car* mycar);
	void Race();
	void ShowFinalRanks(); // it will print the time each car needed to finish the circuit sorted from the fastest car to the   slowest.
	void ShowWhoDidNotFinish(); // it is possible that some cars don't have enough fuel to finish the circuit

};

