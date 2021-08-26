#include <iostream>

#include "Person.h"

Person::Person() : Age(0)
{
}

Person::Person(const Person& other)
{
	std::cout << "Copy constructor running!" << std::endl;
	Name = other.Name;
	Age = other.Age;
}

Person::Person(std::string name, const int age) : Name(std::move(name)), Age(age)
{
}

void Person::Print() const
{
	std::cout << Name << ": " << Age << std::flush;
}

bool Person::operator<(const Person& other) const
{
	if (Name == other.Name)
		return Age < other.Age;

	return Name < other.Name;
}
