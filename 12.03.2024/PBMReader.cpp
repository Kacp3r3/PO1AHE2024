#include "PBMReader.hpp"

PBMReader::PBMReader(std::string imagePath)
{
	imageFile.open(imagePath, std::ios::in);

	if (imageFile.good())
	{
		std::string fileType;
		std::string comment;
		int pixelValue;
		try
		{
			//Wczytanie typu pliku
			std::getline(imageFile, fileType);
			//Wczytanie lini z komentarzem
			std::getline(imageFile, comment);

			//Wczytanie szerokosci i wysokosci
			imageFile >> width >> height;

			for (int i = 0; i < width * height; ++i)
			{
				imageFile >> pixelValue;
				imageData.push_back(pixelValue);
			}
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << "\n";
		}
	}
	else
	{
		std::cout << "Nie udalo sie otworzyc pliku " << imagePath << "\n";
	}
}

std::pair<int, int> PBMReader::getMostFrequentColor()
{
	std::pair<int, int> rv;

	int zeroCounter =0;
	int oneConter = 0;

	//For po kontenerze
	for (int element : imageData)
	{
		if (element == 0) zeroCounter++;
		else oneConter++;
	}

	if (zeroCounter > oneConter)
	{
		rv.first = 0;
		rv.second = zeroCounter;
	}
	else
	{
		rv.first = 1;
		rv.second = oneConter;
	}

	return rv;
}

void PBMReader::printImageData()
{
	for (int i = 0; i < imageData.size(); ++i)
	{
		std::cout << imageData[i] << " ";
		if ((i+1) % width == 0) std::cout << "\n";
	}
}
