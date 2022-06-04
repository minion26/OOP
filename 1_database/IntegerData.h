#pragma once
#include "Entry.h"
#include <string>
using namespace std;
class IntegerData:public Entry
{
private:
	int value;

public:
	IntegerData(string name, string value) : Entry(name), value(stoi(value)) {};

	void Add(string toAdd);

	bool Substract(int toSubstract);

	void Print();
};

