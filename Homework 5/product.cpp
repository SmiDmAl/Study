#include <stdint.h>
#include <iostream>
#include <string>
#include "product.h"

using namespace std;

#define MINIMAL_PRICE_DEF 10

Product_t::Product_t()
{
	name = "";
	price = 0;
	mass = 0;
	energyValue = 0;
}

Product_t::Product_t(const string prodName, uint32_t prodPrice)
{
	name = prodName;
	price = prodPrice;
	mass = 0;
	energyValue = 0;
}

Product_t::Product_t(const string prodName, uint32_t prodPrice, uint32_t prodMass, uint32_t prodValue)
{
	name = prodName;
	price = prodPrice;
	mass = prodMass;
	energyValue = prodValue;
}

Product_t::Product_t(const Product_t& other)
{
	this->name = other.name;
	this->price = other.price;
	this->mass = other.mass;
	this->energyValue = other.energyValue;
}

Product_t::~Product_t()
{
}

const string Product_t::getName()
{
	return string(name);
}

const uint32_t Product_t::getPrice()
{
	return uint32_t(price);
}

const uint32_t Product_t::getMass()
{
	return uint32_t(mass);
}

const uint32_t Product_t::getEnergyValue()
{
	return uint32_t(energyValue);
}

const uint32_t Product_t::getCalories()
{
	return uint32_t(energyValue * mass /100);
}

void Product_t::setName(const string prodName)
{
	name = prodName;
}

void Product_t::setPrice(uint32_t prodPrice)
{
	if (MINIMAL_PRICE_DEF > prodPrice)
	{
		price = MINIMAL_PRICE_DEF;
	}
	else
	{
		price = prodPrice;
	}
}

void Product_t::setMass(uint32_t prodMass)
{
	mass = prodMass;
}

void Product_t::setEnergyValue(uint32_t value)
{
	energyValue = value;
}

void Product_t::printProductInfo(void)
{
	cout << "Name:" << getName() << endl;
	cout << "Price: " << getPrice() << endl;
	cout << "Mass: " << getMass() << endl;
	cout << "Energy Value: " << getEnergyValue() << endl;
	cout << "Calories: " << getCalories() << endl;
	cout << endl;
}

Product_t& Product_t::operator++()
{
	++price;
	return *this;
}

Product_t& Product_t::operator--()
{
	--price;

	if (price < MINIMAL_PRICE_DEF)
	{
		price = MINIMAL_PRICE_DEF;
	}
	return *this;
}

Product_t Product_t::operator++(int)
{
	Product_t temp(*this);
	++(*this);
	return Product_t(temp);
}

Product_t Product_t::operator--(int)
{
	Product_t temp(*this);
	--(*this);
	return Product_t(temp);
}

Product_t Product_t::operator+=(int val)
{
	price += val;
	return Product_t(*this);
}

Product_t Product_t::operator-=(int val)
{
	price -= val;
	if (price < MINIMAL_PRICE_DEF)
	{
		price = MINIMAL_PRICE_DEF;
	}
	return Product_t(*this);
}







