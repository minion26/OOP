#include "StringData.h"
#include <iostream>
using namespace std;

void StringData::Add(string toAdd)
{
	this->value = this->value + toAdd;
}

bool StringData::Substract(int toSubstract)
{
	if (this->value.length() < toSubstract)
		return 0; //nu se efectueaza
	else
	{
		this->value.substr(0, this->value.length() - toSubstract);
		return 1; //s a efectuat scaderea
	}
}

void StringData::Print()
{
	cout << this->name << " = " << this->value << endl;
}

