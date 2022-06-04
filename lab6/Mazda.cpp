#include "Mazda.h"
void Mazda::SetFuelCapacity() {
	this->fuel_capacity = 20;
}

void Mazda::SetFuelConsumption() {
	this->fuel_consumption = 9;
}

void Mazda::SetWeatherCar(Weather value) {
	this->vreme = value;
}

void Mazda::SetAveregeSpeed() {

	if (this->vreme == Weather::Rain)
		this->averege_speed = 50;
	else
		if (this->vreme == Weather::Sunny)
			this->averege_speed = 130;
		else
			if (this->vreme == Weather::Snow)
				this->averege_speed = 40;
}

int Mazda::GetFuelCapacity()
{
	return this->fuel_capacity;
}

int Mazda::GetFuelConsumption()
{
	return this->fuel_consumption;
}

int Mazda::GetAveregeSpeed()
{
	return this->averege_speed;
}