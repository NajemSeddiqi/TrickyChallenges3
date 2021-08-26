#pragma once
#include <ostream>

class Complex
{
private:
	double real;
	double imaginary;

public:
	Complex();
	Complex(double real, double imaginary);
	Complex(const Complex& other);
	const Complex& operator=(const Complex& other);
	//std::ostream& operator<<(std::ostream& out, Complex& c);
	Complex operator+(const Complex& c2) const;
	Complex operator+(double d) const;

	double GetReal() const;
	double GetImaginary() const;
};

//When operator< is defined inside class, left operand of operator is current instance
//If declared inside class, you can only do one param which is the right operand (unless you're marking it as friend)
//If declared outside class, you can use two params, left and right operand
inline std::ostream& operator<<(std::ostream& out, Complex& c)
{
	out << "(" << c.GetReal() << "," << c.GetImaginary() << ")";
	return out;
}
