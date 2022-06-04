#pragma once
#include "Printer.h"
#include "Number.h"

class Number
{
private:
	int number;
	int count = 0;
	Printer* printers[100];

public:
	Number(int value) : number(value) {};
	operator int();

	Number& operator+(Number nr);
	Number& operator-(Number nr);
	Number& operator*(Number nr);
	Number& operator/(Number nr);
	
	Number& operator+=(Printer* prnt);

	void Print();
};

