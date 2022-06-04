#pragma once
#include "Weather.h"
//enum Weather {
//	Rain,
//	Sunny,
//	Snow
//};

class Car
{
	
protected:
	int fuel_capacity;
	int fuel_consumption;
	int averege_speed;
	Weather vreme;


public:
	//SETTER functions
	virtual void SetFuelCapacity() = 0;
	virtual void SetFuelConsumption() = 0;
	virtual void SetWeatherCar(Weather value) = 0;
	virtual void SetAveregeSpeed() = 0;

	//GETTER functions
	virtual int GetFuelCapacity() = 0;
	virtual int GetFuelConsumption() = 0;
	virtual int GetAveregeSpeed() = 0;
};

