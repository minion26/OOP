#pragma once
#include "Printer.h"

class Hexazecimal:public Printer
{
private:

public:
	Hexazecimal();

	string GetFormatName();

	string FormatNumber(int number);
};

