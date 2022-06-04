//#include "Car.h"
#include "Weather.h"
#include "Circuit.h"
#include "Dacia.h"
#include "Ford.h"
#include "Mazda.h"
#include "Mercedes.h"
#include "Toyota.h"
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
	Circuit c;
	c.AddCar(new Dacia());
	c.AddCar(new Toyota());
	c.AddCar(new Mercedes());
	c.AddCar(new Ford());
	c.AddCar(new Mazda());

	c.SetWeather(Sunny);
	c.Race();
	return 0;
}