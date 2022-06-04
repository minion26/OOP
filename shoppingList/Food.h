#pragma once
#include "Item.h"
#include <string>
using namespace std;

class Food:public Item
{
private:
	float quantity;

public:
	void SetQuantity(float quant);
	string GetInfo();
};

