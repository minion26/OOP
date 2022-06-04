#include "Mercedes.h"
void Mercedes::SetFuelCapacity() {
	this->fuel_capacity = 30;
}

void Mercedes::SetFuelConsumption() {
	this->fuel_consumption = 10;
}

void Mercedes::SetWeatherCar(Weather value) {
	this->vreme = value;
}

void Mercedes::SetAveregeSpeed() {

	if (this->vreme == Weather::Rain)
		this->averege_speed = 60;
	else
		if (this->vreme == Weather::Sunny)
			this->averege_speed = 200;
		else
			if (this->vreme == Weather::Snow)
				this->averege_speed = 50;
}

int Mercedes::GetFuelCapacity()
{
	return this->fuel_capacity;
}

int Mercedes::GetFuelConsumption()
{
	return this->fuel_consumption;
}

int Mercedes::GetAveregeSpeed()
{
	return this->averege_speed;
}