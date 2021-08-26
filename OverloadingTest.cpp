#include "OverloadingTest.h"

#include <iostream>

OverloadingTest::OverloadingTest() : id(0)
{
}

OverloadingTest::OverloadingTest(const int id, std::string name) : id(id), name(std::move(name))
{
}

void OverloadingTest::print() const
{
	std::cout << id << ": " << name << std::endl;
}

const OverloadingTest& OverloadingTest::operator=(const OverloadingTest& other)
{
	std::cout << "Assignment running" << std::endl;
	id = other.id;
	name = other.name;
	return *this;
}

//Copy constructor
OverloadingTest::OverloadingTest(const OverloadingTest& other)
{
	std::cout << "Copy constructor running" << std::endl;
	*this = other;
}

std::ostream& operator<<(std::ostream& out, const OverloadingTest& test)
{
	out << test.id << ": " << test.name;
	return out;
}
