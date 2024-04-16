#include <iostream>
#include <fstream>

using namespace std;

/*

https://www.nco.ncep.noaa.gov/pmb/docs/on388/
https://www.nco.ncep.noaa.gov/pmb/docs/on388/
https://www.nco.ncep.noaa.gov/pmb/docs/on388/
https://www.nco.ncep.noaa.gov/pmb/docs/on388/


*/


int main()
{
	fstream grib;

	//Otworzenie pliku w trybie do odczytu oraz binarnym
	grib.open("all.grib", std::ios::binary | std::ios::in);
	
	if (!grib.is_open())
	{
		cout << "Nie udalo sie otworzyc pliku!\n";
	}

	// tellg(),  seekg(int)
	//grib.tellg(); // Na jakiej pozycji znajduje sie teraz kursor
	//grib.seekg(10); // Przesun kursor na miejsce X

	//unsigned char byte;

	//Typy zapewniajace nam pewny rozmiar zmiennej
	//int8_t chr;
	//int16_t chr2;
	//int32_t chr3;
	//int64_t chr4;

	//uint8_t byte;
	//uint16_t byte;
	//uint32_t byte;
	//uint64_t byte;

	char byte1;
	char byte2;
	char byte3;
	char byte4;

	uint32_t start_section0=0;

	//Szukamy "GRIB" w pliku binarnym
	while (!grib.eof())
	{
		//Za pomocą funkcji read, czytamy jeden bajt
		grib.read(&byte1, 1);
		if (byte1 == 'G')
		{
			grib.read(&byte2, 1);
			grib.read(&byte3, 1);
			grib.read(&byte4, 1);
			if (byte2 == 'R' && byte3 == 'I' && byte4 == 'B')
			{
				cout << "Znalazlem Grib na pozycji: " << static_cast<uint32_t>(grib.tellg()) - 4 << "\n";
				start_section0 = static_cast<uint32_t>(grib.tellg()) - 4;
				break;
			}
		}
	}

	//Szukamy 7777 na koncu pliku
	while (!grib.eof())
	{
		grib.read(&byte1,1);
		if (byte1 == '7')
		{
			grib.read(&byte2, 1);
			grib.read(&byte3, 1);
			grib.read(&byte4, 1);
			if (byte2 == '7' && byte3 == '7' && byte4 == '7')
			{
				cout << "Znalazlem 7777 na pozycji: " << static_cast<uint32_t>(grib.tellg()) - 4 << "\n";
				//start_section0 = static_cast<uint32_t>(grib.tellg()) - 4;
				break;
			}
		}
	}
	
	//Aktualnie kursor pliku jest ustawiony na koniec, wiec przesuniemy go
	//Do poczatku sekcji zerowej zaraz za napis GRIB
	grib.seekg(start_section0 + 4);


	//I wczytujemy kolejne 3 bajty - rozmiar całej wiadomosci
	grib.read(&byte1, 1);
	grib.read(&byte2, 1);
	grib.read(&byte3, 1);


	/*
	Przykład unii
	union length
	{
		int value;
		char data[4];
	};


	class example
	{
		int value;
		char data[4];
	};

	length section1;

	grib.seekg(start_section0 + 4);

	grib.read(section1.data, 3);

	cout << section1.value << endl;*/


	//Odpowiednia manipulacja bitami daje nam z 3 bajtów jedną liczbę
	int message_length = 0;
	message_length = ((int)byte1 << 16) | ((int)byte2 << 8) | (int)byte3 & 0xff;
	cout << "Dlugosc wiadomosci: " << message_length << "\n";

	grib >> byte4; // Ignorujemy jeden bajt miedzy sekcja 0 a 1


	int32_t start_section1 = grib.tellg();

	//Wczytujemy dlugosc sekcji 1
	grib.read(&byte1, 1);
	grib.read(&byte2, 1);
	grib.read(&byte3, 1);
	int32_t section1_length = (int)byte1 << 16 | (int)byte2 << 8 | (int)byte3 & 0xff;
	cout << "Dlugosc sekcji 1: " << section1_length << "\n";

	grib.seekg(start_section1 + section1_length);

	int32_t start_section2 = grib.tellg();

	//Wczytujemy dlugosc sekcji 2
	grib.read(&byte1, 1);
	grib.read(&byte2, 1);
	grib.read(&byte3, 1);
	int32_t section2_length = (int)byte1 << 16 | (int)byte2 << 8 | (int)byte3 & 0xff;
	cout << "Dlugosc sekcji 2: " << section2_length << "\n";

	grib.seekg(start_section2 + section2_length);

	int32_t start_section3 = grib.tellg();

	//Wczytujemy dlugosc sekcji 3
	grib.read(&byte1, 1);
	grib.read(&byte2, 1);
	grib.read(&byte3, 1);
	int32_t section3_length = (int)byte1 << 16 | (int)byte2 << 8 | (int)byte3 & 0xff;
	cout << "Dlugosc sekcji 3: " << section3_length << "\n";

	//grib.seekg(start_section3 + section3_length);

	//int32_t start_section4 = grib.tellg();

	//grib.read(&byte1, 1);
	//grib.read(&byte2, 1);
	//grib.read(&byte3, 1);
	//int32_t section4_length = (int)byte1 << 16 | (int)byte2 << 8 | (int)byte3 & 0xff;
	//cout << "Dlugosc sekcji 4: " << section4_length << "\n";


	//Odczytanie daty z ssekcji 1
	/*
	13 Year of century
	14 Month
	15 Day start of averaging or accumulation period 
	16 Hour
	17 Minute
	*/
	grib.seekg(start_section1 + 12);
	grib.read(&byte1, 1);
	cout << "Rok: " << (int)byte1 << "\n";

	grib.seekg(start_section1 + 13);
	grib.read(&byte1, 1);
	cout << "Miesiac: " << (int)byte1 << "\n";

	grib.seekg(start_section1 + 14);
	grib.read(&byte1, 1);
	cout << "Dzien: " << (int)byte1 << "\n";

	grib.seekg(start_section1 + 15);
	grib.read(&byte1, 1);
	cout << "Godzina: " << (int)byte1 << "\n";

	grib.seekg(start_section1 + 16);
	grib.read(&byte1, 1);
	cout << "Minuta: " << (int)byte1 << "\n";
	return 0;
}