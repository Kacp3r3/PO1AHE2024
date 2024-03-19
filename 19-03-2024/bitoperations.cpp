#include <iostream>
#include <set>
#include <map>
#include <sstream>
#include <vector>
using namespace std;


int main()
{
	set<int> unique_ints;

	unique_ints.insert(5);
	unique_ints.insert(3);
	unique_ints.insert(2);

	cout << "Size of set: " << unique_ints.size() << "\n";
	
	unique_ints.insert(5);
	unique_ints.insert(5);
	unique_ints.insert(5);

	cout << "Size of set: " << unique_ints.size() << "\n";


	std::map<int, std::string> mapOfNumbers;
	mapOfNumbers[0] = "zero";
	mapOfNumbers[1] = "jeden";
	mapOfNumbers[2] = "dwa";
	mapOfNumbers[3] = "trzy";
	mapOfNumbers[4] = "cztery";

	std::map<std::string, int> mapOfNumbersTwo;

	mapOfNumbersTwo["one"] = 1;


	int number=2;
	//cin >> number;

	//cout << numbers[number];

	if (mapOfNumbers.find(number) != mapOfNumbers.end())
	{
		cout << mapOfNumbers[number] << "\n";
	}
	else
	{
		cout << "Nie obslugiwana liczba\n";
	}


	int a;// -> 4 bajty
	char c; // -> 1 bajt

	//PPM kolor: 50 150 255


	


	//0x - zapis szesnastkowy
	char hex = 0xFF; //255
	

	// << - przesunięcie w lewo
	// 00001111 // 15
	// 00001111 << 4
	// 11110000 //240
	// >> - przesunięcie w prawo
	// 11110000 // 240
	// 11110000 >> 4
	// 00001111 // 15

	//0b - zapis binarny
	int R = 0b11110000; //240
	int G = 0b00111100; //60
	int B = 0b00001111; //15
	int example = 0;// 00000000 00000000 00000000 00000000

	example = (R << 16) | (G << 8) | B;

	cout << example << '\n';


	std::stringstream ss;

	std::string line = "0 0 0 0 1 0";

	ss << line;

	for (int i = 0; i < 6; ++i)
	{
		int tmp;
		ss >> tmp;
		std::cout << tmp << "\n";
	}
	



	return 0;
}