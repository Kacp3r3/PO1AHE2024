#include <iostream>
#include "Foo.h"

using namespace std;

int main()
{
	//Statyczna tablica 2d
	double tablica[10][10];
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			tablica[i][j] = 0.;
		}
	}


	//Dynamiczna tablica 1d
	int* dynamic_tablica = new int[20];
	delete[] dynamic_tablica;


	//Dynamiczna tablica 2D 
	int** dynamic2d_tablica = new int*[20];
	for (int i = 0; i < 20; ++i)
	{
		dynamic2d_tablica[i] = new int[20];
	}

	
	//Usuwanie dynamicznej tablicy 2D
	for (int i = 0; i < 20; ++i)
	{
		delete[] dynamic2d_tablica[i];
	}
	delete[] dynamic2d_tablica;



	Foo f("First");
	Foo f2("Second");


	cout << "Operator dodawania \n";
	Foo f3 = f + f2;
	cout << "f: "; f.sayHi();
	cout << "f2: "; f2.sayHi();
	cout << "f3: "; f3.sayHi();



	cout << "Operator += \n";
	f += f2;

	cout << "f: "; f.sayHi();
	cout << "f2: "; f2.sayHi();

	return 0;
}