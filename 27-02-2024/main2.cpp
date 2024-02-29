#include <iostream>
#include "Foo.h"


class Ksztalt
{
public:
	Ksztalt() = delete;

	/// <summary>
	///
	/// </summary>
	/// <param name="r"></param>
	/// <param name="g"></param>
	/// <param name="b"></param>
	Ksztalt(int r, int g, int b)
	{
		std::cout << "Kontruktor Ksztalt\n";
		colorR = r;
		colorG = g;
		colorB = b;
	}

	~Ksztalt()
	{
		std::cout << "Destruktor Ksztalt\n";
	}

	void przedstaw_sie() { std::cout << "Czesc\n"; };

	int colorR = 255;

protected:
	int colorG = 0;

private:
	int colorB = 0;
};



class Kwadrat : public Ksztalt
{
public:
	Kwadrat()
		: // Lista inicjalizacyjna
		 Ksztalt(5,8,2) // Wywołanie konstruktora klasy bazowej
		,foo(-5) // Inicjalizacja zmiennej w liscie inicjalizacyjnej
	{
		std::cout << "Kontruktor Kwadrat\n";
		bar = "bar"; // Inicjalizacja zmiennej w ciele konstruktora
	}

	~Kwadrat()
	{
		std::cout << "Destruktor Kwadrat\n";
	}
	//Kwadrat(int bok);

	double do_something()
	{
		colorR = 50; // public ColorR mamy dostęp
		colorG = 128; // protectetd mamy dostep
		//colorB = 50  private nie mamy dostepu
	}

private:
	int foo;
	std::string bar;
};


using namespace std;

int main()
{

	Kwadrat kw;
	kw.colorR = 50; // Mam dostep do public zmiennej
	// kw.colorG = 50; Nie mam dostepu do zmiennej protected jako uzytkownik
	// kw.colorB = 50; Nie mam dostepu do zmiennej private jako uzytkownik

	return 0;
}