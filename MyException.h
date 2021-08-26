#pragma once
#include <exception>

class MyException final : public std::exception
{
public:
	const char* what() const throw() override;
};
