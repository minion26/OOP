#pragma once
#include "Printer.h"
class Decimal:public Printer
{
private:

public:
	Decimal();

	string GetFormatName();

	string FormatNumber(int number);
};

