#include "Number.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

Number::Number(const char* value, int base)
{
	this->baza = base; 
    this->val =  new char[strlen(value)+1];
	strcpy_s(this->val, strlen(value)+1, value);

	//this->val[strlen(value) + 1] = NULL;
	//this->val = (char*)(malloc(strlen(value) * sizeof(char)));
	//memcpy(this->val, value, sizeof(value));
	//std::cout << this->val;

}

Number::~Number()
{
	delete this->val;
	this->baza = -1;
}

Number::Number(const Number& other)
{
	strcpy_s(this->val, strlen(this->val), other.val);
	this->val = other.val;
}

Number::Number(Number&& other)
{
	this->baza = other.baza;
	this->val = other.val;
	other.val = nullptr;
}

Number& Number::operator= (Number&& x)
{
	this->baza = x.baza;
	strcpy_s(this->val, strlen(this->val), x.val);
	return *this;
}

int Number::BaseToDecimal()
{
	int len = strlen(this->val);
	int p = 1;
	int num = 0;

	for (int i = len - 1; i >= 0; i--)
	{
		if (this->val[i] >= '0' && this->val[i] <= '9')
			num = num + (this->val[i] - '0') * p;
		else
			num = num + (this->val[i] - 'A' + 10) * p;

		p = p * this->baza;
	}

	return num;
}


void Number::SwitchBase(int newBase)
{
	if (newBase == this->baza)
		printf("Conversie in aceeasi baza");
	else
	{
		int nr_nou = BaseToDecimal(); //stiu ca baza este 10
		int i = 0;
		char res[]="";

		while (nr_nou != 0)
		{
			if (nr_nou % newBase >= 0 && nr_nou % newBase < newBase)
			{
				res[i] = (nr_nou % newBase) + '0';
				i++;
				nr_nou /= newBase;
			}
			else
			{
				res[i] = (nr_nou % newBase) - 10 + 'A';
				i++;
				nr_nou /= newBase;
			}
		}

		res[i] = '\0';
		strrev(res);
		strcpy_s(this->val, strlen(res), res);
		this->baza = newBase;

	}
}

int  Number::GetBase()
{
	return this->baza;
}

int  Number::GetDigitsCount()
{
	return strlen(this->val);
}

void Number::Print()
{
		printf("%s", this->val);
}

char Number::operator[](int index)
{
	return this->val[index];
}

Number operator+( Number& left,  Number& right)
{
	int max; //baza cea mai mare
	if (left.baza > right.baza)
		max = left.baza;
	else
		max = right.baza;

	int l =  left.BaseToDecimal(); //schimb in zecimal
	int r = right.BaseToDecimal(); //schimb in zecimal

	int rezultat = l + r; //suma va fi tot in zecimal
	char a = rezultat + '0'; //transform suma din int in char

	Number rez( &a, 10); //obiect cu rezultatul adunarii in baza 10

	rez.SwitchBase(max); //transform obiectul in baza cea mai mare

	return rez;
}

Number operator-(Number& left, Number& right)
{
	int max; //baza cea mai mare
	if (left.baza > right.baza)
		max = left.baza;
	else
		max = right.baza;

	int l = left.BaseToDecimal(); //schimb in zecimal
	int r = right.BaseToDecimal(); //schimb in zecimal

	int rezultat = l - r;
	char a = rezultat + '0'; 

	Number rez(&a, 10); //obiect cu rezultatul adunarii in baza 10

	rez.SwitchBase(max);

	return rez;
}

bool Number::operator<(const Number& other)
{
	int max; //baza cea mai mare
	if (this->baza > other.baza)
		max = this->baza;
	else
		max = other.baza;

	//trebuie sa transform obiectele in aceeasi baza sa ca pot compara

	//Number copy1 = other; //copie a obiectului
	int old1 = this->baza;
	int old2 = other.baza;
	int a = this->BaseToDecimal();
	int b = other.BaseToDecimal();
	
	if (a > b)
		return false;
	else
		return true;

	//return (a <= b);
}

