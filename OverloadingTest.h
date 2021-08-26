#pragma once
#include <string>

class OverloadingTest
{
private:
	int id{};
	std::string name;

public:
	OverloadingTest();

	OverloadingTest(int id, std::string name);

	void print() const;

	const OverloadingTest& operator=(const OverloadingTest& other);

	OverloadingTest(const OverloadingTest& other);

	friend std::ostream& operator<<(std::ostream& out, const OverloadingTest& test);
};
