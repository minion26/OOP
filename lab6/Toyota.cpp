#include "Toyota.h"
void Toyota::SetFuelCapacity() {
	this->fuel_capacity = 25;
}

void Toyota::SetFuelConsumption() {
	this->fuel_consumption = 5;
}

void Toyota::SetWeatherCar(Weather value) {
	this->vreme = value;
}

void Toyota::SetAveregeSpeed() {

	if (this->vreme == Weather::Rain)
		this->averege_speed = 50;
	else
		if (this->vreme == Weather::Sunny)
			this->averege_speed = 160;
		else
			if (this->vreme == Weather::Snow)
				this->averege_speed = 40;
}

int Toyota::GetFuelCapacity()
{
	return this->fuel_capacity;
}

int Toyota::GetFuelConsumption()
{
	return this->fuel_consumption;
}

int Toyota::GetAveregeSpeed()
{
	return this->averege_speed;
}