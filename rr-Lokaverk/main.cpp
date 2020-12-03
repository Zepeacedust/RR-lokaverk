#include <iostream>
#include "Complex.h"
#include "Image.h"
#include <random>
constexpr auto BOUNDS = 4;
int calculate(Complex C, int resolution) 
{
	Complex Z = Complex();
	for (size_t i = 0; i < resolution; i++)
	{
		Z = Z.sqrAdd(C);	
		if (Z.manhattan() > BOUNDS) 
		{
			return i;
		}
	}
	return resolution;
}
int main() 
{
	setlocale(LC_ALL, "icelandic");
	int iterations = 2048;
	int imageX = 2000;
	int imageY = 2000;
	long double worldX[2] {-1.5, 0.5};
	long double worldY[2] { -1, 1 };
	std::string fileName;
	std::cout << "Sláðu in fjölda itranna, hærra gerir nákvæmari mynd en það er hægara." << std::endl;
	std::cin >> iterations;
	std::cout << "Sláðu inn stærð myndarinnar í pixlum, x fyrst svo y, bil á milli" << std::endl;
	std::cin >> imageX;
	std::cin >> imageY;

	std::cout << "Sláðu inn byrjunn og enda myndarinnar á x ásinum" << std::endl;
	std::cin >> worldX[0];
	std::cin >> worldX[1];

	std::cout << "Sláðu inn byrjunn og enda myndarinnar á y ásinum" << std::endl;
	std::cin >> worldY[0];
	std::cin >> worldY[1];
	
	std::cout << "Sláðu inn filename, ef eitthvað er þar fyrirfram mun því vera eitt" << std::endl;
	std::cin >> fileName;
	
	long double widthX = worldX[1] - worldX[0];
	long double widthY = worldY[1] - worldY[0];
	long double pixelsPerUnitX = imageX / widthX;
	long double pixelsPerUnitY = imageY / widthY;

	Image image = Image(fileName, imageX, imageY);

	for (size_t y = 0; y < imageY; y++)
	{
		for (size_t x = 0; x < imageX; x++)
		{
			Complex c = Complex(x / pixelsPerUnitX + worldX[0], y / pixelsPerUnitY + worldY[0]);
			int zMax = (float)calculate(c, iterations) / iterations * 255;
			image.addPixel(zMax, zMax, zMax);
			
		}
		std::cout << (float)y / imageY * 100 << "%" << std::endl;
	}
}