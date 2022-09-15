#pragma once
#include <iostream>
#include "ex.h"

class IntegerArray_t
{
public:
	IntegerArray_t() = default;
	IntegerArray_t(const IntegerArray_t& other);
	IntegerArray_t(int lenght);
	~IntegerArray_t();

	void erase();
	void printArray();

	const int getLenght();
	const int getValue(int index);

	void insert(int index, long long int value);
	void remove(int index);
	void resize(int newSize);
	void copy(IntegerArray_t& arrayToCopy);

	int& operator[](int index);


private:
	int f_lenght;
	int* f_data;
};

