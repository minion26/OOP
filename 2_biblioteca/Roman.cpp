#include "Roman.h"
#include <iostream>
using namespace std;
Roman::Roman(string nume, string autor)
{
	this->nume = nume;
	this->autor = autor;
}

string Roman::GetInfo()
{
	return (string)"Romanul " + this->nume + " scris de " + this->autor;
}