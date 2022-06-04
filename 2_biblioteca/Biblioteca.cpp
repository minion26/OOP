#include "Biblioteca.h"
#include "Carte.h"
#include <iostream>
using namespace std;
Biblioteca::Biblioteca()
{
	this->count = 0;
	for (int i = 0; i < 100; i++)
		this->carti[i] = nullptr;
}

Biblioteca::~Biblioteca()
{
	for (int i = 0; i < 100; i++)
		delete this->carti[i];
	
	delete[] this->carti;
}

//b+=new Roman("a","b") => += reflexiva => ca eu returnez obiectul curent, adica biblioteca mea, la care adaug o carte
Biblioteca& Biblioteca::operator+=(Carte* c)
{
	this->carti[this->count] = c;
	this->count++;
	return *this;
}

Biblioteca::operator int()
{
	return this->count;
}

void Biblioteca::PrintFilter(bool (*foo)(Carte* c))
{
	for(int i = 0; i < this->count; i++)
		if (foo(this->carti[i]) != 0)
		{
			//este roman => afisam
			cout << this->carti[i]->GetInfo();
			cout<< endl;
		}
}

