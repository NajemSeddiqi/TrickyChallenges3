#include "Complex.h"

#include <iostream>

Complex::Complex() : real(0), imaginary(0)
{
}

Complex::Complex(const double real, const double imaginary) : real(real), imaginary(imaginary)
{
}

Complex::Complex(const Complex& other)
{
	std::cout << "Copy" << std::endl;
	real = other.real;
	imaginary = other.imaginary;
}

const Complex& Complex::operator=(const Complex& other)
{
	real = other.real;
	imaginary = other.imaginary;
	return *this;
}

Complex Complex::operator+(const Complex& c2) const
{
	const Complex temp(*this);
	return Complex(temp.GetReal() + c2.GetReal(), temp.GetImaginary() + c2.GetImaginary());
}

Complex Complex::operator+(const double d) const
{
	const Complex temp(*this);
	return Complex(temp.GetReal() + d, temp.GetImaginary());
}


double Complex::GetReal() const
{
	return real;
}

double Complex::GetImaginary() const
{
	return imaginary;
}
