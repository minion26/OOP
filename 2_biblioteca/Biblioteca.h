#pragma once
#include "Carte.h"
#include "Revista.h"
#include "Roman.h"
#include <string>
using namespace std;
class Biblioteca
{
private:
	int count;
	Carte** carti = new Carte * [100];

public:
	class BookIterator {
	private:
		int index = 0;
		Biblioteca* b;

	public:
		BookIterator(int idx, Biblioteca* ptr)
		{
			this->index = idx;
			this->b = ptr;
		}

		bool operator!=(BookIterator const& ptr)
		{
			return (this->index != ptr.index);
		}

		BookIterator& operator++()
		{
			this->index++;
			return *this;
		}

		Carte* operator*()
		{
			return this->b->carti[this->index];
		}
	
	};

	Biblioteca();
	~Biblioteca();
	Biblioteca& operator+=(Carte* c);

	operator int();

	BookIterator begin()
	{
		return { 0, this};
	}
	BookIterator end()
	{
		return { this->count, this };
	}

	void PrintFilter(bool (*)(Carte* c));

};

