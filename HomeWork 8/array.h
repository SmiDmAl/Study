#pragma once
#include <iostream>

#pragma once

// ќбъ€вление шаблонного класса Array
template <typename T> class Array
{
public:
	Array(unsigned int lenght);
	~Array();
	Array(Array& arrayToCopy);
	
	void erase();
	T getValue(int index);
	unsigned int getLenght();

	int insert(unsigned int index, T value);
	void remove(unsigned int index);
	Array& operator=(Array& arrayToCopy);

private:
	unsigned int _lenght;
	T* _data;

};

