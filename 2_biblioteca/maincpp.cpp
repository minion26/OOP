#include <iostream>
#include "Biblioteca.h"
#include "Carte.h"
#include "Revista.h"
#include "Roman.h"
using namespace std;

int main()
{
	Biblioteca b;
	(b += new Roman("DON QUIJOTE", "MIGUEL DE CERVANTES")) += new Revista("Journal of Artificial Intelligence", 100);
	b += new Roman("MACBETH", "WILLIAM SHAKESPEARE");

	for (auto x : b)
	{
		std::cout << x->GetInfo() << std::endl;
	}
	std::cout << "Lista doar cu romane:" << std::endl;

	b.PrintFilter([](Carte* c) {
		if (c->GetInfo().find("Roman") == 0)
			return true;
		else
			return false; 
		});

	std::cout << "Numar de intrari in biblioteca: " << (int)b << std::endl;

	return 0;
}