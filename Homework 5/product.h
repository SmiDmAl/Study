#pragma once
#include <stdint.h>
#include <iostream>
#include <string>
using namespace std;

class Product_t
{
public:
	Product_t();
	Product_t(const string prodName, uint32_t prodPrice);
	Product_t(const string prodName, uint32_t prodPrice, uint32_t prodMass, uint32_t prodValue);
	Product_t(const Product_t& other);
	~Product_t();

	const string getName();
	const uint32_t getPrice();
	const uint32_t getMass();
	const uint32_t getEnergyValue();
	const uint32_t getCalories();

	void setName(const string prodName);
	void setPrice(uint32_t prodPrice);
	void setMass(uint32_t prodMass);
	void setEnergyValue(uint32_t value);
	
	void printProductInfo(void);

	Product_t& operator++();
	Product_t& operator--();

	Product_t operator++(int);
	Product_t operator--(int);

	Product_t operator+=(int);
	Product_t operator-=(int);




private:
	string name;			//name of product
	uint32_t price;			// price must be greater than MINIMAL_PRICE_DEF
	uint32_t mass;			// for calories counting
	uint32_t energyValue;	// for calories counting
};

