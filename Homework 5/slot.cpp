
#include <stdint.h>
#include <iostream>
#include <string>
#include "product.h"
#include "slot.h"

using namespace std;

Slot_t::Slot_t()
{
}

Slot_t::Slot_t(int32_t slotAddress, Product_t slotProduct, int32_t numberOfItems)
{
	address = slotAddress;
	product = slotProduct;

	if (numberOfItems > FILLED_STATE_DEF)
	{
		count = FILLED_STATE_DEF;
	}
	else
	{
		count = numberOfItems;
	}
}

Slot_t::~Slot_t()
{
}

int32_t Slot_t::getAddress()
{
	return int32_t(address);
}

Product_t Slot_t::getProduct()
{
	return Product_t(product);
}

const string Slot_t::getProductName()
{
	return string(product.getName());
}

int32_t Slot_t::getCount()
{
	return int32_t(count);
}

int32_t Slot_t::getFree()
{
	return int32_t(capacity - count);
}

int32_t Slot_t::getCapacity()
{
	return int32_t(capacity);
}

void Slot_t::setAddress(uint8_t slotAddress)
{
	address = slotAddress;
}

void Slot_t::setProduct(Product_t slotProduct)
{
	product = slotProduct;
}

void Slot_t::setCount(uint8_t numberOfItems)
{
	count = numberOfItems;

	if (numberOfItems > FILLED_STATE_DEF)
	{
		count = FILLED_STATE_DEF;
	}
	else
	{
		count = numberOfItems;
	}
}

void Slot_t::removeItem()
{
	if (count)
	{
		count--;
	}	
}

void Slot_t::addItem()
{
	if (count < capacity)
	{
		count++;
	}
}

void Slot_t::removeItems(uint8_t numberOfItems)
{
	if (numberOfItems < count)
	{
		count -= numberOfItems;
	}
	else
	{
		count = 0;
	}
}

void Slot_t::addItems(uint8_t numberOfItems)
{
	if (numberOfItems < (capacity - count))
	{
		count += numberOfItems;
	}
	else
	{
		count = capacity;
	}
}

void Slot_t::fillSlot()
{
	count = capacity;
}

void Slot_t::clearSlot()
{
	count = 0;
}

bool Slot_t::isFilled()
{
	if (count == capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Slot_t::isEmpty()
{
	if (!count)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Slot_t::printSlotInfo(void)
{
	cout << "Slot number: " << getAddress() << endl;
	cout << "Product: " << getProductName() << endl;
	cout << "Occuped: " << getCount() << endl;
	cout << "Vacant: " << getFree() << endl;
	cout << endl;
}

Slot_t& Slot_t::operator++()
{
	if (count < capacity)
	{
		++count;
	}
	return *this;
}

Slot_t& Slot_t::operator--()
{
	if (count > 0)
	{
		--count;
	}
	return *this;
}

Slot_t Slot_t::operator++(int)
{
	Slot_t temp(*this);
	++(*this);
	return Slot_t(temp);
}

Slot_t Slot_t::operator--(int)
{
	Slot_t temp(*this);
	--(*this);
	return Slot_t(temp);
}

Slot_t Slot_t::operator+=(int numberOfItems)
{
	if (numberOfItems < (capacity - count))
	{
		count += numberOfItems;
	}
	else
	{
		count = capacity;
	}
	return Slot_t(*this);
}

Slot_t Slot_t::operator-=(int numberOfItems)
{
	if (numberOfItems < count)
	{
		count -= numberOfItems;
	}
	else
	{
		count = 0;
	}
	return Slot_t(*this);
}
