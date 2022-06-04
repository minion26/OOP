#include "IntegerData.h"
#include <iostream>
using namespace std;

void IntegerData::Add(string toAdd)
{
	this->value = this->value + stoi(toAdd);
}

bool IntegerData::Substract(int toSubstract)
{
	this->value = this->value - toSubstract;
	return 1;
}

void IntegerData::Print()
{
	cout << this->name << " = " << this->value << endl;
}