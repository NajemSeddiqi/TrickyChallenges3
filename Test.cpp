#include "Test.h"


#include <iostream>
#include <utility>

Test::Test(std::string name, const int id) : name(std::move(name)), id(id)
{
}

Test::Test(std::string name) : name(std::move(name))
{
}

Test::~Test()
{
	//std::cout << "Object destroyed" << std::endl;
}

void Test::print() const
{
	std::cout << id << ": " << name << std::endl;
}

//bool Test::operator<(const Test& other) const
//{
//	return name < other.name;
//}

bool comp(const Test& a, const Test& b);
