#pragma once
class Complex
{
public:
	long double real;
	long double complex;
	long double manhattan();
	Complex();
	Complex(long double real, long double complex);
	Complex operator+(Complex& other);
	Complex sqrAdd(Complex c);
};

