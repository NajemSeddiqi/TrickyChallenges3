#include "MyException.h"


const char* MyException::what() const throw()
{
	return "Something bad happened!";
}
