#pragma once
#include "Car.h"
class Mercedes :
    public Car
{
    void SetFuelCapacity();
    void SetFuelConsumption();
    void SetWeatherCar(Weather value);
    void SetAveregeSpeed();

    int GetFuelCapacity();
    int GetFuelConsumption();
    int GetAveregeSpeed();
};

