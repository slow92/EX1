#include <exception>

class RangeValueException: public std::exception {
public:
	virtual const char* what() const throw()
	{
	return "Error! Incorrect value";
	}	
};
