#include <iostream>
#include "array.h"


template<typename T>
inline Array<T>::Array(unsigned int lenght)
{
	if (lenght > 0)
	{
		_lenght = lenght;
		_data = new T[lenght];
	}

}

template<typename T>
inline Array<T>::~Array()
{

}

template<typename T>
Array<T>::Array(Array& arrayToCopy)
{
	_lenght = arrayToCopy._size;				// Копируем значение поля размера массива
	_data = new T[_lenght];				// Выделяем память для нового массива
	for (int i = 0; i < _lenght; i++)
		_data[i] = arrayToCopy._data[i];
}

template<typename T>
void Array<T>::erase()
{
	if (_data != nullptr) 
	{
		delete[] _data;
	}

	_data = nullptr;
	_lenght = 0;
}

template<typename T>
T Array<T>::getValue(int index)
{
	if (index >= 0 && index < _lenght)
	{
		return (T)_data[index];
	}
		
	else return 0;
}

template<typename T>
unsigned int Array<T>::getLenght()
{
	return _lenght;
}

template<typename T>
int Array<T>::insert(unsigned int index, T value)
{
	if (index >= 0 && index < _lenght)
	{
		_data[index] = value;
		return 0;
	}
	else
	{
		return 2;
	}	
}

template<typename T>
void Array<T>::remove(unsigned int index)
{
	if (index >= 0 && index < _lenght)
	{
		if (_lenght == 1) // if last element
		{
			erase();
			return;
		}
		T* data = new int[_lenght - 1];

		for (int i = 0; i < index; i++)
		{
			data[i] = _data[i];
		}
		for (int i = index + 1; i < _lenght; i++)
		{
			data[i - 1] = _data[i];
		}
		delete[] _data;
		_data = data;
		_lenght--;
	}
}

template<typename T> Array<T>& Array<T>::operator=(Array& arrayToCopy)
{
	if (this != &arrayToCopy)
	{			
		_lenght = arrayToCopy._lenght;
		delete[] _data;		
		_data = new T[_lenght];	        
		for (int i = 0; i < _lenght; i++)
		{
			_data[i] = arrayToCopy._data[i];
		}
			
	}
	return *this;  
}
