#include "Dacia.h"
void Dacia::SetFuelCapacity() {
	this->fuel_capacity = 20;
}

void Dacia::SetFuelConsumption() {
	this->fuel_consumption = 20;
}

void Dacia::SetWeatherCar(Weather value) {
	this->vreme = value;
}

void Dacia::SetAveregeSpeed() {
	
	if (this->vreme == Weather::Rain)
		this->averege_speed = 60;
	else
		if (this->vreme == Weather::Sunny)
			this->averege_speed = 100;
		else
			if(this->vreme == Weather::Snow)
			this->averege_speed = 50;
}

int Dacia::GetFuelCapacity()
{
	return this->fuel_capacity;
}

int Dacia::GetFuelConsumption()
{
	return this->fuel_consumption;
}

int Dacia::GetAveregeSpeed()
{
	return this->averege_speed;
}
