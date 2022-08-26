#pragma once

#include <stdint.h>
#include "slot.h"
#include "product.h"


#define MAX_NUMBER_OF_SLOTS 10

class Vendbox_t
{
public:
	Vendbox_t();
	~Vendbox_t();
		
	//choose the product with check, return price (to cash box) or error
	// return: -1 if incorrect slot
	// return: -2 if slot is empty
	int32_t selectProduct(int32_t slotNumber);

	
	//check the product and decrement number of products in slot
	// return: -1 if incorrect slot
	// return: -2 if slot is empty
	int32_t buyProduct(int32_t slotNumber);

	
	//Function for service engineers to put products in slot
	// return +int: if success, and return number of extra products (and slot is filled)
	// return 0: success and have no extra products
	// return: -1 if incorrect slot
	// return: -2 if incorrect product (slot have another product)
	// return: -3 if slot is filled before and have no free space
	int32_t servPutProducts(int32_t slotNumber, Product_t product, int32_t numberOfItems);

	//show info
	void printInfo(void);

private:
	Slot_t slots[MAX_NUMBER_OF_SLOTS];
};
