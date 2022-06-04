#include "Revista.h"
#include <iostream>
using namespace std;
Revista::Revista(string titlu, int nrArticole)
{
	this->titlu = titlu;
	this->nrArticole = nrArticole;
}

string Revista::GetInfo() 
{
	return (string)"Revista "+this->titlu+" cu "+ std::to_string(this->nrArticole)+ " articole";
}
