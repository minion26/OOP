#include "Number.h"
#include <iostream>
Number::operator int()
{
	return this->number;
}

Number& Number::operator+(Number nr)
{
	Number a = Number((int)*this);
	a.number = this->number + nr.number;

	return a;
}

Number& Number::operator-(Number nr)
{
	Number a = Number((int)*this);
	a.number = this->number - nr.number;

	return a;
}

Number& Number::operator*(Number nr)
{
	Number a = Number((int)*this);
	a.number = this->number * nr.number;

	return a;
}

Number& Number::operator/(Number nr)
{
	Number a = Number((int)*this);
	a.number = this->number / nr.number;

	return a;
}

Number& Number::operator+=(Printer* prnt)
{
	this->printers[this->count] = prnt;
	this->count++;

	return *this;
}

void Number::Print()
{
	for (int i = 0; i < this->count; i++)
	{
		cout << "Format: " << this->printers[i]->GetFormatName() << "  Value: " << this->printers[i]->FormatNumber(this->number);
		cout << endl;
	}
}