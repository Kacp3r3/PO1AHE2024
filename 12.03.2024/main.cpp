#include <iostream>
#include <utility>

#include "PBMReader.hpp"


//Przykład uzycia szablonu
//template<typename T>
//T razydwa(T a)
//{
//	return (T)2 * a;
//}


int main()
{
	PBMReader j("letterj.pbm");

	std::cout << "Zawartosc pliku:\n";
	j.printImageData();


	auto color = j.getMostFrequentColor();

	std::cout << "\nNajczestszy kolor na obrazie to " << color.first << 
		" i wystapil: " << color.second << " razy\n";


	//Przykład czym jest para
	/*std::pair<int,bool> para;

	para.first = 50;
	para.second = false;*/

	return 0;
}