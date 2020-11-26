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
	int imageX, imageY;
	long double worldX, worldY;

	Image image = Image("Test.bmp", 32, 32);

	for (size_t i = 0; i < 1024; i++)
	{
		image.addPixel(0, 0, i%256);
	}



	/*for (size_t y = 0; y < 40; y++)
	{
		for (size_t x = 0; x < 40; x++)
		{
			Complex c = Complex(x / (long double)10 - 2, y / (long double)10 - 2);
			if (calculate(c,500) == 500) 
			{
				std::cout << "#";
			}
			else
			{
				std::cout << " ";
			}
		}
		std::cout << std::endl;
	}*/
}