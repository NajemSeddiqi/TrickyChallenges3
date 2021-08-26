#pragma once
#include <string>


class Person
{
	std::string Name;
	int Age;

public:
	Person();

	Person(const Person& other);

	Person(std::string name, const int age);

	void Print() const;

	bool operator<(const Person& other) const;
};
