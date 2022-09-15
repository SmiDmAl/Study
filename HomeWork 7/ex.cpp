#include <iostream>
#include <exception>
#include "ex.h"

const const char* ExBadLenght::what() const noexcept
{
	return "Error: Bad lenght of array!";
}

const const char* ExBadCreation::what() const noexcept
{
	return "Error: Can not create array!";
}

const const char* ExBadInteger::what() const noexcept
{
	return "Error: Bad integer!";
}

const const char* ExBadIndex::what() const noexcept
{
	return "Error: Bad index!";
}

