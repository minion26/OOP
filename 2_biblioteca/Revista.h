#pragma once
#include "Carte.h"
#include <string>
using namespace std;
class Revista:public Carte
{
private:
	string titlu;
	int nrArticole;
public:
	Revista(string titlu, int nrArticole);
	string GetInfo();
};

