#ifndef _PBMREADER_HPP_
#define _PBMREADER_HPP_

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "ImageReader.hpp"

class PBMReader : public ImageReader
{
public:
	PBMReader(std::string imagePath);

	void printImageInfo() override;
	void printMostFrequentColor() override;
	int calcualteNumberOfUniqueColors() override;
	
	
	std::pair<int, int> getMostFrequentColor();
	void printImageData();

private:
	std::fstream imageFile;
	std::vector<int> imageData;

	int width;
	int height;
};

#endif // _PBMREADER_HPP_

// #pragma once