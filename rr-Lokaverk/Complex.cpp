#include "Complex.h"

Complex Complex::sqrAdd(Complex c) 
{
	return Complex(this->real* this->real - this->complex * this->complex, 2* this->real * this->complex) + c;
}

Complex::Complex(long double real, long double complex) 
{
	this->real = real;
	this->complex = complex;
}

Complex Complex::operator+(Complex& other) 
{
	return Complex(this->real + other.real, this->complex + other.complex);
}
Complex::Complex() 
{
	this->real = 0;
	this->complex = 0;
}

long double Complex::manhattan()
{
	return this->real + this->complex;
}