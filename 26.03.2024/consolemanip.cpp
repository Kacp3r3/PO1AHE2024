#include <iostream>
#include <Windows.h>


struct Point
{
	int x;
	int y;
};


class Pointc
{
	int x;
	int y;
};


int main()
{
	Point p;
	p.x = 10;

	Pointc pc;
	//pc.x = 10; Nie zadziała, wszystkie pola w klasie sa domyślnie priavte:


	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD cursorPos;
	cursorPos.X = 10;
	cursorPos.Y = 5;

	std::cout << "Tekst przed zmiana polozenia kursora";

	//Zmiena pozycji kursora konsoli
	SetConsoleCursorPosition(console, cursorPos);

	std::cout << "Tekst po zmianie polozenia kursora";

	std::cout << '\n';


	//Zmiana kolorów tekstu i tła konsoli
	for (int k = 1; k < 255; k++)
	{
		// pick the colorattribute k you want
		SetConsoleTextAttribute(console, k);
		std::cout << k << " I want to be nice today!" << std::endl;
	}
	return 0;
}