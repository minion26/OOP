#pragma once
#include <string>
using namespace std;
class Entry
{
protected:
	string name;

public:
	Entry(string name) : name(name) {};
	 
	 //virtual string GetName() = 0;

	 virtual void Add(string toAdd) = 0;

	 virtual bool Substract(int toSubstract) = 0;

	 virtual void Print() = 0;

};

