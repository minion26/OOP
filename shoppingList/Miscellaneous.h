#pragma once
#include "Item.h"
#include <string>
using namespace std;

class Miscellaneous:public Item
{
private:
	int count;

public:
	string GetInfo();
	void SetCount(int count);

};

