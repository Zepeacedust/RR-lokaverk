#include "Image.h"
#include <iostream>

void Image::writeInt(int data, int numBytes) 
{
	for (size_t i = 0; i < numBytes; i++)
	{
		this->file << (uint8_t)(data % 256);
		data >>= 8;
	}
}

Image::Image()
{

}
Image::Image(std::string name, int imageX, int imageY)
{
	this->file.open(name, std::ios::binary);
	init(imageX, imageY);
}
//skrifa header í file
void Image::init(int imageX, int imageY)
{

	this->file << "BM";
	int numbits = imageX * imageY * 3;
	//imagesize
	this->writeInt(numbits, 4);
	//intentionally left blank
	this->writeInt(0, 4);
	//dataoffset
	this->writeInt(54, 4);
	//size of infoHeader
	this->writeInt(40, 4);
	//width
	this->writeInt(imageX, 4);
	//height
	this->writeInt(imageY, 4);
	//planes
	this->writeInt(1, 2);
	//bits per pixel
	this->writeInt(24, 2);
	//compression
	this->writeInt(0, 4);
	//compressed size (0 ef ekkert compression)
	this->writeInt(0, 4);
	//x pixels per meter
	this->writeInt(100, 4);
	//y pixels per meter
	this->writeInt(100, 4);
	//num colours used
	this->writeInt(0, 4);
	//important colours
	this->writeInt(0, 4);

}
void Image::addPixel(uint8_t red, uint8_t green, uint8_t blue)
{
	this->file << blue << green << red;
}