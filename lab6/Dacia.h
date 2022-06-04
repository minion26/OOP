#pragma once
#include "Car.h"
class Dacia :
    public Car
{
public:
    void SetFuelCapacity();
    void SetFuelConsumption();
    void SetWeatherCar(Weather value);
    void SetAveregeSpeed();

    int GetFuelCapacity();
    int GetFuelConsumption();
    int GetAveregeSpeed();
};

