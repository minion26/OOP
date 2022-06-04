#include "Ford.h"
void Ford::SetFuelCapacity() {
	this->fuel_capacity = 25;
}

void Ford::SetFuelConsumption() {
	this->fuel_consumption = 9;
}

void Ford::SetWeatherCar(Weather value) {
	this->vreme = value;
}

void Ford::SetAveregeSpeed() {

	if (this->vreme == Weather::Rain)
		this->averege_speed = 40;
	else
		if (this->vreme == Weather::Sunny)
			this->averege_speed = 120;
		else
			if (this->vreme == Weather::Snow)
				this->averege_speed = 30;
}

int Ford::GetFuelCapacity()
{
	return this->fuel_capacity;
}

int Ford::GetFuelConsumption()
{
	return this->fuel_consumption;
}

int Ford::GetAveregeSpeed()
{
	return this->averege_speed;
}