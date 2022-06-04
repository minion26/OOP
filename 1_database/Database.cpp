#include "Database.h"
#include <iostream>
using namespace std;

Database& Database::operator+=(Entry* entr)
{
	this->entries[this->curr_idx] = entr;
	this->curr_idx++;
	return *this;
}

void Database::Print()
{
	for (int i = 0; i < this->curr_idx; i++)
	{
		this->entries[i]->Print();
	}
}


//Database& Database::operator-=(string entr)
//{
//	int i = 0;
//	while (i < this->curr_idx)
//	{
//		if (this->entries[i].value == entr)
//			for (int j = i + 1; j < this->curr_idx; j++)
//				this->entries[j - 1] = this->entries[j];
//
//		this->curr_idx--;
//	}
//
//	return *this;
//
//}