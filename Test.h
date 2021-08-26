#pragma once
#include <string>

class Test
{
private:
	int id{};
	std::string name;

public:

	explicit Test(std::string name, int id);

	explicit Test(std::string name);

	~Test();

	void print() const;

	//bool operator<(const Test& other) const;

	friend bool comp(const Test& a, const Test& b);
};
