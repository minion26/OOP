#include "Circuit.h"
#include "Car.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

Circuit::Circuit() {
	this->MaxCars = 100;
	this->CurrentCar = 0;
	this->VectorCars = new Car* [this->MaxCars]; //(Car**)(malloc(this->MaxCars * sizeof(Car*)));
	this->VectorRace = new float* [this->MaxCars];
}

Circuit::~Circuit() {
	delete[] VectorCars;
	delete[] VectorRace;
}

void Circuit::SetLength(int value) {
	this->length = value;
}

void Circuit::SetWeather(Weather value) {
	this->vreme = value;
}

bool Circuit::AddCar(Car* mycar) {
	if (this->CurrentCar < this->MaxCars)
	{
		this->VectorCars[this->CurrentCar++] = mycar;
		return true;
	}
	return false;
}

void Circuit::Race()
{
	for (int i = 0; i < this->CurrentCar; i++)
	{
		float x;
		if (this->vreme == Weather::Sunny)
		{
			this->VectorCars[i]->SetWeatherCar(Sunny);
			int speed = this->VectorCars[i]->GetAveregeSpeed();
			x = this->length / speed;
			this->VectorRace[i] = &x;
		}
		else
			if (this->vreme == Weather::Rain)
			{
				this->VectorCars[i]->SetWeatherCar(Rain);
				int speed = this->VectorCars[i]->GetAveregeSpeed();
				x = this->length / speed;
				this->VectorRace[i] = &x;
			}
			else
				if (this->vreme == Weather::Snow)
				{
					this->VectorCars[i]->SetWeatherCar(Snow);
					int speed = this->VectorCars[i]->GetAveregeSpeed();
					x = this->length / speed;
					this->VectorRace[i] = &x;
				}
	}

	for (int i = 0; i < this->CurrentCar; i++)
	{
		std::cout << "Masina " << this->VectorCars[i] << "a terminat cursa in " << this->VectorRace[i] << "h";
		std::cout << std::endl;
	}
}

void Circuit::ShowFinalRanks()
{
	int  i, j;
	float* aux;
	Car* aux1;

	for (i = 0; i < this->CurrentCar - 1; i++)
		for (j = 0; j < this->CurrentCar - i - 1; j++)
			if ( this->VectorRace[j] > this->VectorRace[j + 1])
			{
				aux = VectorRace[j];
				VectorRace[j] = VectorRace[j + 1];
				VectorRace[j + 1] = aux;
				aux1 = VectorCars[j];
				VectorCars[j] = VectorCars[j + 1];
				VectorCars[j + 1] = aux1;

			}
	for (int i = 0; i < this->CurrentCar; i++)
	{
		std::cout << "Masina " << this->VectorCars[i];
		std::cout << std::endl;
	}
}
