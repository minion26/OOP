#include "Hexazecimal.h"
#include <string>
using namespace std;

string Hexazecimal::GetFormatName()
{
	return (string)"Hexazecimal";
}

string Hexazecimal::FormatNumber(int number)
{
	//transform numarul in baza 16
	int rest = 0;
	string raspuns = "";

	while ( number != 0)
	{
		rest = number % 16;
		if (rest >= 0 && rest <= 9)
			raspuns.push_back((char)('0'+rest));
		else
			raspuns.push_back((char)('A'+rest-10));

		number = number / 10;
	}

	//trebuie sa inversez stringul

	string raspuns_final = "";
	for (int i = raspuns.length(); i != -1; i--)
	{
		raspuns_final.push_back(raspuns[i]);
	}

	return raspuns_final;
}
