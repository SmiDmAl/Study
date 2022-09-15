#include <iostream>
#include "ex.h"
#include "cont.h"

using namespace std;

#define MAX_NUMBER_OF_ELEMENTS 1000000UL

IntegerArray_t::IntegerArray_t(const IntegerArray_t& other)
{
	// other array is errorless and safety do not need to check
	this->f_data = new int[other.f_lenght];
	this->f_lenght = other.f_lenght;
	for (int i = 0; i < f_lenght; i++)
	{
		this->f_data[i] = other.f_data[i];
	}
}

IntegerArray_t::IntegerArray_t(int lenght)
{
	if (lenght > 0 && lenght <= MAX_NUMBER_OF_ELEMENTS)//  limit max value
	{
		try // if int too much cause #define changed
		{
			f_data = new int[lenght];

			for (int i = 0; i < lenght; i++)
			{
				f_data[i] = 0; // set to zero all datas in creation
			}
		}
		catch (exception& e)
		{
			throw ExBadLenght(); // translate to upper level of program
		}

		f_lenght = lenght;
	}
	else
	{
		throw ExBadLenght( );
	}
}

IntegerArray_t::~IntegerArray_t()
{
	if (f_data != nullptr) // check array is present
	{
		delete[] f_data;
	}
}

void IntegerArray_t::erase()
{
	if (f_data != nullptr) // check array is present
	{
		delete[] f_data;
	}

	f_data = nullptr;
	f_lenght = 0;
}

void IntegerArray_t::printArray()
{
	cout << endl;

	for (int i = 0; i < f_lenght; i++)
	{
		cout << f_data[i] << "; ";
	}
	cout << endl;
}

const int IntegerArray_t::getLenght()
{
	return f_lenght;
}

const int IntegerArray_t::getValue(int index)
{
	if (index >= 0 && index < f_lenght)
	{
		return f_data[index];
	}
	else
	{
		throw ExBadIndex();
	}	
}

void IntegerArray_t::insert(int index, long long int value)
{
	if (index >= 0 && index < f_lenght)
	{
		if (INT32_MIN < value && value < INT32_MAX)
		{
			f_data[index] = value;
		}
		else
		{
			throw ExBadInteger();
		}
	}
	else
	{
		throw ExBadIndex();
	}
	
}
void IntegerArray_t::remove(int index)
{
	if (index >= 0 && index < f_lenght)
	{
		if (f_lenght == 1) // if last element
		{
			erase(); 
			return;
		}
		int* data = new int[f_lenght - 1];

		for(int i = 0; i < index; i++)
		{
			data[i] = f_data[i];
		}
		for (int i = index + 1; i < f_lenght; i++)
		{
			data[i-1] = f_data[i];
		}
		delete[] f_data;
		f_data = data;
		f_lenght--;
	}
	else
	{
		throw ExBadIndex();
	}
}
void IntegerArray_t::resize(int newSize)
{
	if (newSize == f_lenght)
	{
		return;
	}

	if (newSize > 0 && newSize <= MAX_NUMBER_OF_ELEMENTS)
	{
		int* data = new int[newSize];
		
		int copy_count;
		if (newSize > f_lenght)
		{
			copy_count = f_lenght;
			for (int i = f_lenght; i < newSize; i++) // new_elemens set to zero
			{
				data[i] = 0;
			}
		}
		else
		{
			copy_count = newSize;
		}

		for (int i = 0; i < copy_count; i++)
		{
			data[i] = f_data[i];
		}
		delete[] f_data;

		f_data = data;
		f_lenght = newSize;
	}
	else
	{
		//erase();
		throw ExBadIndex();
	}
}

void IntegerArray_t::copy(IntegerArray_t& arrayToCopy)
{
	erase();
	f_lenght = arrayToCopy.f_lenght;

	if (f_lenght > 0)
	{	
		f_data = new int[f_lenght];
		for (int i = 0; i < f_lenght; i++)
		{
			f_data[i] = arrayToCopy[i];
		}
	} 
	
}
// analog of getValue
int& IntegerArray_t::operator[](int index)
{
	if (index >= 0 && index < f_lenght)
	{
		return f_data[index];
	}
	else
	{
		throw ExBadIndex();
	}
}
