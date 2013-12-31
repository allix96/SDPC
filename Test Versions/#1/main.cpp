#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include "Bor.h"

using namespace std;
using namespace bor;
using bor::Bor;

int main()
{
	//---INPUT DATA-------------------------------------------//

	string inputA = "inputA.txt";
	string inputB = "inputB.txt";

	ifstream finA, finB;
	finA.open(inputA);
//	finB.open(inputB);

	if (!finA.is_open())
	{ 
		cout << "File " << inputA << "not found!" << endl;
		return -1;
	}
	//if (!finB.is_open())
	//{
	//	cout << "File " << inputB << "not found!" << endl;
	//	return -1;
	//}

	string	TempText;
	Bor TextBor;
	xfast_tree_t* rootA = TextBor.CreateNode();
//	xfast_tree_t* rootB = TextBor.CreateNode();

	while (!finA.eof())
	{
		finA >> TempText;
		const char * Test = TempText.c_str();
		TextBor.AddString(Test, rootA);
//		cout << TempText << endl;
		//		TextA += ' ' + TempText;
	}
//	while (!finB.eof())
//	{
//		finB >> TempText;
//		TextBor.AddString(TempText, rootB);
//
////		TextB += ' ' + TempText;
//	}

	//!!!INPUT DATA!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//

	finA.close();

	_getch();
	return 0;
}
