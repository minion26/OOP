#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <fstream>

using namespace std;

class Element {
public:
	int countAppereances;
	string words;
};

class Compare {
public:
	bool operator()(Element e1, Element e2)
	{
		if (e1.countAppereances < e2.countAppereances)
			return true;
		else
			if (e1.countAppereances > e2.countAppereances)
				return false;
			else
				if (strcmp(e1.words.c_str(), e2.words.c_str()) < 0)
					return false;
				else
					return true;
	}
	
};


int main()
{

	string mystring; // = "I bought an apple. Then I eat an apple. Apple is my favorite.";
	vector <string> myvector;
	map<string, int> mymap;


	ifstream myFile("Text.txt");
	getline(myFile, mystring); //prima linie

	int poz, prev = 0;

	while ((poz = mystring.find_first_of(" ,!?.", prev)) != string::npos)
	{
		if (poz > prev) //am gasit
		{

			string aux;
			aux = mystring.substr(prev, poz - prev); //subcuvantul delimitat de semnele de punctuatie cerute

			// !!!    il transform in litere mici    !!!
			for (auto& c : aux)
			{
				c = tolower(c);
			}

			myvector.push_back(aux); //adaug la vectorul de cuvinte 
		}

		prev = poz + 1; //modif prev pt a putea gasi urmatorul cuvant delimitat 

	}

	if (prev < mystring.size())
		myvector.push_back(mystring.substr(prev, string::npos));

	//for (auto it = begin(myvector); it != end(myvector); ++it) vector<string>::iterator it 
		//cout <<*it << endl;


	for (int i = 0; i < myvector.size(); i++) {

		int count = 1;

		for (int j = i + 1; j < myvector.size(); j++) {

			if (myvector.at(i) == myvector.at(j))
				count++;
		}

		mymap.insert({ myvector.at(i), count });
	}

	for (auto iter = begin(mymap); iter != end(mymap); iter++) {
		cout << iter->first << "-" << iter->second;
		cout << endl;
	}

	cout << endl ;

	priority_queue<Element, std::vector<Element>, Compare> myqueue;

	for (auto it : mymap)
	{
		myqueue.push(Element{it.second, it.first});
		cout << "Pushed " << it.first << " - " << it.second << endl;
	}

	cout << endl;

	while (!myqueue.empty())
	{
		cout << myqueue.top().words << " - " << myqueue.top().countAppereances << endl;
		myqueue.pop();
	}


	return 0;
}