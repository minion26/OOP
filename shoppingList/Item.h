#pragma once
#include <string>
using namespace std;

class Item
{
private: 
	string name;

public:
	string GetName();
	virtual string GetInfo() = 0;
	void SetName(string name);
};

