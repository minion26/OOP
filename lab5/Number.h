#pragma once
class Number
{
	// add data members
	char* val; // pointer to  memory for number  
	int baza;

public:

	Number(const char* value, int base); // where base is between 2 and 16

	~Number();

	// add operators and copy/move constructor

	Number(const Number& x); //Copy constructor

	Number(Number&& x); //Move constructor

	Number& operator= (Number&& x); //move asignment operator

	int BaseToDecimal(); 

	void SwitchBase(int newBase);

	void Print();

	int  GetDigitsCount(); // returns the number of digits for the current number

	int  GetBase(); // returns the current base

	char operator[](int index);

	friend Number operator+( Number& left, Number& right);

	friend Number operator-(Number& left, Number& right);

	bool operator<(const Number& left);

	bool operator<=(const Number& left);

	bool operator>(const Number& left);

	bool operator>=(const Number& left);

	bool operator==(const Number& left);

	bool operator!=(const Number& left);
};

