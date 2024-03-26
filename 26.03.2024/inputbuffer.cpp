
#include <iostream>

//getch i kbhit
#include <conio.h>

//sleep_for
#include <thread>

//końcówki s ms
#include <chrono>

using namespace std::chrono_literals;

int main()
{
	int character = 0;
	while (character != 27/* 27 - klawisz Escape*/)
	{
		//Jezeli zostal wcisniety klawisz
		if (_kbhit())
		{
			//Pobierz go z bufora wejsciowego
			character = _getch();
			//A nastepnie wyswietl na konsoli
			std::cout << "Uzytkownik wcisnal " << character << "\n";
		}
		//A jezeli nie
		else
		{
			//Wyswietl kropke i uspij watek na 100ms
			std::cout << ".";
			std::this_thread::sleep_for(0.1s);
		}
	}

}