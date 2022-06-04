#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Number.h" 
//void fct(int nr_nou, int newBase)
//{
//	int i = 0;
//	char res[10000] = "";
//	int rest;
//
//	while (nr_nou != 0)
//	{
//		rest = nr_nou % newBase;
//		if (rest >= 0 && rest < newBase)
//		{
//			res[i] = (char)(rest + '0');
//			i++;
//			nr_nou = nr_nou / newBase;
//		}
//		else
//		{ 
//			switch (rest)
//			{
//			case 10:
//				res[i] = 'A';
//				break;
//			case 11:
//				res[i] = 'B';
//				break;
//			case 12:
//				res[i] = 'C';
//				break;
//			case 13:
//				res[i] = 'D';
//				break;
//			case 14:
//				res[i] = 'E';
//				break;
//			case 15:
//				res[i] = 'F';
//				break;
//			}
//			
//			//res[i] = (char)(rest - 10 + 'A');
//			i++;
//			nr_nou = nr_nou / newBase;
//		}
//	}
//
//	//res[i] = '\0';
//	_strrev(res);
//	for (int i = 0; i < strlen(res); i++)
//		printf("%c", res[i]);
//
//}

using namespace std;

int main()
{ 
	//fct (15, 16);

	Number n1("123", 10);
	Number n2("1", 10);
	cout << n1 < n2;
}