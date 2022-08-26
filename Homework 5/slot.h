#pragma once

#include <stdint.h>
#include <iostream>
#include <string>
#include "product.h"
using namespace std;

#define FILLED_STATE_DEF 20

class Slot_t
{
public:
	Slot_t();
	Slot_t(int32_t slotAddress, Product_t slotProduct, int32_t numberOfItems);
	~Slot_t();

	int32_t getAddress();
	Product_t getProduct();
	const string getProductName();
	int32_t getCount();
	int32_t getFree();
	int32_t getCapacity();

	void setAddress(uint8_t slotAddress);
	void setProduct(Product_t slotProduct);
	void setCount(uint8_t numberOfItems);
	
	void removeItem();
	void addItem();

	void removeItems(uint8_t numberOfItems);
	void addItems(uint8_t numberOfItems);

	void fillSlot();
	void clearSlot();

	bool isFilled();
	bool isEmpty();

	void printSlotInfo(void);

	Slot_t& operator++();
	Slot_t& operator--();

	Slot_t operator++(int);
	Slot_t operator--(int);

	Slot_t operator+=(int);
	Slot_t operator-=(int);


private:
	int32_t address;   // number of slot in vendbox
	Product_t product; // 1 slot have only 1 type of product
	int32_t count;	   // count of items of product

	const int32_t capacity = FILLED_STATE_DEF;

};

