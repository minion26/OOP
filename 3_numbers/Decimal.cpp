#include "Decimal.h"
#include <string>
string Decimal::GetFormatName()
{
	return (string)"Decimal";
}

string Decimal::FormatNumber(int number)
{
	return (std::to_string)(number);
}