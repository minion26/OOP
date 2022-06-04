#include <iostream>
#include <array>
#include <string>

using namespace std;

//class MyException : public std::exception
//{
//public:
//	char const * what() const noexcept
//	{
//		return "ERORR, index out of range";
//	}
//}; 
//int print (int a ) 
//{
//	return a;
//	throw 5;
//
//}
//
//int main()
//{
//	MyException ex;
//	//array<int,5> a = { 1,2,3,4,5 };
//	int i = 6;
//	try {
//		//if (i > 5 || i < 0)
//			//throw ex;
//
//		if (print(5) != 0)
//			throw 0;
//
//
//
//	}
//	catch (MyException& exception) {
//		cout << "The error is: " << exception.what();
//	}
//	catch (int exception) {
//		cout << "error";
//	}
//	return 0;
//}

class MyException : public exception
{
private:
	string mes;
public:
	MyException(int wrongindex)
	{
		this->mes = "Index" + to_string(wrongindex) + " out of bounds";
	}
	char const* what() const noexcept
	{
		return this->mes.c_str();
	}
};


class compare
{
public:
	virtual int compareelements(void* e1, void* e2) = 0;
};

template<class t>
class arrayiterator
{
private:
	int current; // mai adaugati si alte date si functii necesare pentru iterator
public:
	arrayiterator();

	arrayiterator& operator ++ ();

	arrayiterator& operator -- ();

	bool operator= (arrayiterator<t>&);

	bool operator!=(arrayiterator<t>&);

	t* getelement();
};

template<class t>
class array
{
private:
	t** list; // lista cu pointeri la obiecte de tipul t*

	int capacity; // dimensiunea listei de pointeri

	int size; // cate elemente sunt in lista

public:
	array()// lista nu e alocata, capacity si size = 0
	{
		this->list = nullptr;
		this->capacity = 0;
		this->size = 0;
	}

	~array(); // destructor

	array(int capacity) // lista e alocata cu 'capacity' elemente
	{
		this->list = nullptr;
		this->capacity = capacity;
		this->size = size;
	}

	array(const array<t>& otherarray); // constructor de copiere

	//t& => referinta la element
	t& operator[] (int index) throw(std::exception) // arunca exceptie daca index este out of range
	{
		if (index >= this->capacity || index < 0)
			throw MyException(index);

		return *list[index];
	}



	const array<t>& operator+=(const t& newelem) // adauga un element de tipul t la sfarsitul listei si returneaza this
	{
		if (this->capacity == 0)
		{
			//setez lista cu o capacitate default
			this->list = new t * [8];
			this->capacity = 8;

			for (i = 0; i < 8; i++)
				this->list[i] = nullptr; //fac lista=array nullptr ca sa pointeze la nimic
		}
		else
			if (this->size == this->capacity)
			{
				//daca am atins capacitatea maxima -> dublez
				this->capacity = this->capacity * 2;
				T ** newlist = new T * [this->capacity];

				//copiez elementele in noul array, restul le setez la nullptr
				for (i = 0; i < this->capacity; i++)
					if (i < this->size)
						newlist[i] = this->list[i];
					else
						newlist[i] = nullptr;

				//sterg vechiul array
				delete [] this->list;

				//this setez la noua lista
				this->list = newlist;
			}

		//adaug la sfarsit noul element
		this->list[this->size] = new T(newelem);
		/*echivalent la linia 143
		  this->list[this->size]=new T;
		  *this->list[this->size]=newelem;
		*/
		this->size++;
		return *this;

	}
	const array<t>& insert(int index, const t& newelem) // adauga un element pe pozitia index, retureaza this. daca index e invalid arunca o exceptie
	{
		if (index >= this->capacity || index < 0)
			throw std::exception("index out of bounds!");

		*list[index] = newelem;
		return this;
	}

	const array<t>& insert(int index, const array<t> otherarray); // adauga o lista pe pozitia index, retureaza this. daca index e invalid arunca o exceptie

	array<t>& delete(int index) // sterge un element de pe pozitia index, returneaza this. daca index e invalid arunca o exceptie
	{
		if (index >= this->capacity || index < 0)
			throw std::exception("index out of bounds!");

		if (list[index] == nullptr)
			throw std::exception("trying to delete an empty slot!");

		delete list[index];
		list[index] = nullptr;
		size--;

		return this;
	}

	bool operator==(const array<t>& otherarray)
	{
		//daca adresele din memorie coincid
		if (this == &otherarray)
			return true;

		//daca  marimile nu sunt egale =? nici cele 2 array-uri nu pot fi egale
		if (this->size != otherarray.size)
			return false;

		for (i = 0; i < this->size; i++)
			if (*this->list[i] != *otherarray.list[i]) // * -> ca sa iau valoarea din memorie, nu ma intereseaza sa compar adresele din memorie
				return false;

		return true;
	}

	array<t>& operator=(const array<t>& otherarray)
	{
		if (this == &otherarray) //daca au aceeasi adresa de memorie
			return *this;
		
		for (int i = 0; i < this->size; i++)
			delete this->list[i];

		delete[] this->list;

		this->list = new T * [otherarray.capacity];
		for(int i = 0; i < otherarray.capacity; i++)
			if (i < this->size)
			{
				this->list[i] = new T(*otherarray.list[i]); 
			}
			else
			{
				this->list[i] = nullptr;
			}

		this->size = otherarray.size;
		this->capacity = otherarray.capacity;

		return *this;
	}



	void sort(); // sorteaza folosind comparatia intre elementele din t

	void sort(int(*compare)(const t&, const t&)); // sorteaza folosind o functie de comparatie

	void sort(compare* comparator) // sorteaza folosind un obiect de comparatie
	{
		for (int i = 0; i < this->size; i++)
			for (int j = 0; j < this->size; j++)
				if (comparator(*this->list[i], *this->list[j]) > 0)
				{
					T* aux = this->list[i];
					this->list[i] = this->list[j];
					this->list[j] = aux;
				}
	}



	// functii de cautare - returneaza pozitia elementului sau -1 daca nu exista

	int binarysearch(const t& elem); // cauta un element folosind binary search in array

	int binarysearch(const t& elem, int(*compare)(const t&, const t&));//  cauta un element folosind binary search si o functie de comparatie

	int binarysearch(const t& elem, compare* comparator);//  cauta un element folosind binary search si un comparator


	//cauta cu *this->list[i]==elem
	int find(const t& elem) // cauta un element in array
	{
		for (i = 0; i < this->size; i++)
			if (*this->list[i] == elem)
				return i;

		//throw ca nu s a gasit si mi fac o clasa pt asta
	}

	//cauta cu compare(*this->list[i],elem) ==0
	int find(const t& elem, int(*compare)(const t&, const t&))//  cauta un element folosind o functie de comparatie
	{
		for (i = 0; i < this->size; i++)
			if (compare(*this->list[i], elem) == 0)
				return i;

		//throw ca nu s a gasit
	}

	//cauta cu comparator->CompareElements(this->list[i], &elem) ==0
	int find(const t& elem, compare* comparator)//  cauta un element folosind un comparator
	{
		for (int i = 0; i < this->size; i++)
			if (comparator->compareelements(this->list[i], &elem) == 0)
				return i;

		//throw ca nu s a gasit
	}


	int getsize()
	{
		return this->size;
	}

	int getcapacity()
	{
		return this->capacity;
	}



	arrayiterator<t> getbeginiterator();

	arrayiterator<t> getenditerator();
};

int main()
{
	array<int>vector;
	vector += 3;
	vector += 5;



	//int(*ptrFct)(int,int)=&impartire; pointer la functia impartire
	//alternativ
	//using ImpartireType = int(*)(int,int)
	//ImpartireType ptrFct=&impartire
	//int x = ptrFct(2,3)

	//lambda => 
	auto compareFunction = [](int const& a, int const& b) {
		if (a > b)
			return 1;
		else
			if (b > a)
				return -1;
			else
				return 0;
	};

	//cum apelez: vector.sort(compareFunction);

	//clasa comparatoare
	class IntComparator : public compare
	{
		int CompareElements(void* e1, void* e2) {
			//cast la int
			int* pE1 = (int*)e1;
			int* pE2 = (int*)e2;

			if (*pE1 > *pE2)
				return 1;
			else
				if (*pE1 < *pE2)
					return -1;
				else
					return 0;
		}
	};
	
	//cum apelez folosind un obiect de comparatie:
	// IntComparator comp;
	// vector.sort(&comp)
	return 0;
}