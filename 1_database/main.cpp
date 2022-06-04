#include <iostream>
#include <string>
#include "Database.h"
#include "Entry.h"
#include "IntegerData.h"
#include "StringData.h"

using namespace std;

int main()
{
	Database d;
	Entry* e1 = (Entry*)new StringData("Student", "Alexandru");
	Entry* e2 = (Entry*)new IntegerData("Notaengleza", "10");
	(d += e1) += (new StringData("Facultate", "fii"));
	(d += e2) += (new IntegerData("Notapoo", "9"));
	d.Print();

	/*d -= "NotaEngleza";	
	d.Print();*/

	/*for (Entry* e : d) {
		e->Substract(5);
	}
	d.Print();*/


	return 0;
}