#include <iostream>
#include <string>
#include <cstdlib>


//Etykiety
enum class AppStatus
{
	RUNNING,
	STOPPED,
	RESUMED,
	KILLED
};


//Definicje symboli za pomocą preprocesora
//#define first_element 0
//#define second_element 1






int main2()
{
	//Typy całkowite ( dodatnie i ujemne )
	short s = 5;
	int a = 5;
	long long ll = 5;

	//Typy całkowite bez znaku (dodatnie)  u - unsigned
	unsigned short us = 5u;
	unsigned int ui = 10u;
	unsigned long long ull = 15u;

	//Typy zmiennoprzecinkowe 
	float f = 3.0f;  // 0.00000005;      //0.000000048   //0.000000052  
	double d = 3.;
	char c = '5';
	std::string string = "5";
	bool b = false;


	int A = 10;
	int B = 10;
	int C = 25;

	//Zmiana strony kodowej na obsługującą polskie znaki
	system("chcp 1250");

	//Operatory logiczne > < >= <= == != !
	if ( A > B )
	{
		std::cout << "A jest większe od B\n";
	}
	else if ( A < B )
	{
		std::cout << "B jest większe od A\n";
	}
	else
	{
		std::cout << "Liczby są równe\n";
	}




	//&& oba true, || chociaż jeden true
	if (A > B && A > C)
	{
		std::cout << "A jest największa\n";
	}
	else if (B > A && B > C)
	{
		std::cout << "B jest największa\n";
	}
	else if (C > A && C > B)
	{
		std::cout << "C jest największa\n";
	}

	
	//Deklaracja zmiennej w bloku if C++17
	if (bool serverResponse = true; serverResponse == true)
	{
		std::cout << "Nawiązano połączenie\n";
	}
	else
	{
		std::cout << "Server nie osiągalny\n";
	}

	

	for (int i = 0 ; i<10   ;   i++   )
	{
		std::cout << i << "\n";
	}

	//while (true) 
	//{

	//};

	//do 
	//{


	//} while (true);




	AppStatus status = AppStatus::RUNNING;
	std::string response = "";

	switch (status)
	{
		case AppStatus::RUNNING:
			response = "Response 1";

		case AppStatus::STOPPED:
			response = "Response 2";
			break;

		default:
			response = "Response default";
	}

	std::cout << response << "\n";





	int numbers[5] = {4 , 7 ,12, 56 , 11};

	std::cout << numbers[0] << "\n";


	//Dane spoza zakresu tablicy, very bad
	//std::cout << numbers[5] << "\n";
	//numbers[25] = 55555;


	char word[] = "Alpaka&Company";

	std::cout << word << "\n";
	
	//Ucięcie wyrazu w zmiennej word na 7 literze
	word[6] = '\0';

	std::cout << word << "\n";


	char word2[5] = { 'k', 'o', 't', 'e', 'k' };

	std::cout << word2 << "\n";



	std::string sentence = "Ala ma kota i psa";
	
	std::cout << sentence << '\n';

	sentence += " i chomika";

	//Find zwraca index pod ktorym zaczyna się szukany łańcuch lub npos jak nie znajdzie
	if (size_t index = sentence.find("mysz"); index != std::string::npos)
	{
		std::cout << "Znaleziono kota na pozyycji " << index << "\n";
	}
	else
	{
		std::cout << "Nie znaleziono mysz w zdaniu" << "\n";
	}


	int liczba = 5;
	//& daje nam adres
	int* wskaznik = &liczba;

											//* wydostaje nam to co znajduje sie pod adresem
	std::cout << "Wartość zmiennej liczba: " << *wskaznik << "\n";
	std::cout << "Adres zmiennej liczba: " << wskaznik << "\n";
	std::cout << "Adres wskaznika: " << &wskaznik << "\n";
	

	int user_size;

	std::cout << " Podaj rozmiar tablicy: ";
	std::cin >> user_size;

	const int static_size = 15;
	int tablica_statyczna[static_size];

	//Alokacja i usuwanie tablicy dynamicznej
	int* tablica_dynamiczna = new int[user_size];
	delete[] tablica_dynamiczna;

	//Alokacja i usuwanie pojedynczego obiektu
	int* single = new int;
	delete single;


	return 0;
}