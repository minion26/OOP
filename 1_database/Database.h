#pragma once
#include "Entry.h"
#include <string>
using namespace std;

class Database
{
private:
	Entry* entries[100];
	int curr_idx = 0;

public:
	class DataIterator
	{
	private:
		int index;
		Database* ptr;
	public:
		DataIterator(int idx, Database* pointer) : index(idx), ptr(pointer) {};

		DataIterator& operator++()
		{
			this->index++;
			return *this;
		}

		bool operator!=( DataIterator & pointer)
		{
			return (this->index != pointer.index);
		}

		bool operator==(DataIterator& pointer)
		{
			return (this->index == pointer.index);
		}

		Entry& operator*()
		{
			return *this->ptr->entries[index];
		}
	};

	Database& operator+=(Entry* entr);

	Database& operator-=(string entr);

	DataIterator begin()
	{
		return { 0, this };
	}

	DataIterator end()
	{
		return { this->curr_idx, this };
	}

	void Print();
};

