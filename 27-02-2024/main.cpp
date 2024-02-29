#include <iostream>
#include <string>
#include "Foo.h"

//Dzięki & przekazujemy oryginał do fukncji a nie kopie
void example_func(int& a)
{
	std::cout << "Wewnatrz fukncji " << a << "\n";
	a = 20;
	std::cout << "Wewnatrz fukncji po zmianie " << a << "\n";
}





int main3()
{
	int wartosc = 10;
	example_func(wartosc);
	std::cout << "Po funkcji " << wartosc << "\n";


	//Utworzenie obiektu klasy Foo ( ciasto )
	Foo foo1("Jan");
	{
		Foo foo2 = foo1;
		foo2.sayHi();
	}
	foo1.sayHi();

	//Przykład pętli alokującej i dealokującej obiekty Foo
	/*while (true)
	{
		Foo* f = new Foo();
		delete f;
	}*/

	return 0;
}