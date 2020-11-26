#pragma once
#include <fstream>
class Image
{
	std::ofstream file;
public:
	Image();
	Image(std::string name,int imageX, int imageY);
	void writeInt(int data, int numBits);
	void init(int imageX, int imageY);
	void addPixel(uint8_t red, uint8_t green, uint8_t blue);

};

