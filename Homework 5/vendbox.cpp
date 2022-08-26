#include <stdint.h>
#include "slot.h"
#include "product.h"
#include "vendbox.h"


Vendbox_t::Vendbox_t()
{
}

Vendbox_t::~Vendbox_t()
{
}
// return price or error
int32_t Vendbox_t::selectProduct(int32_t slotNumber)
{
	if (slotNumber && slotNumber < MAX_NUMBER_OF_SLOTS)
	{
		if (slots[slotNumber - 1].isEmpty())
		{
			return -2;	// slot is empty
		}
		else
		{
			return int32_t(slots[slotNumber - 1].getProduct().getPrice());
		}

	}
	else
	{
		return -1;	// incorrect slot
	}
}

int32_t Vendbox_t::buyProduct(int32_t slotNumber)
{
	if (slotNumber && slotNumber < MAX_NUMBER_OF_SLOTS)
	{
		if (slots[slotNumber - 1].isEmpty())
		{
			return -2; // slot is empty
		}
		else
		{
			slots[slotNumber - 1].removeItem();
			return 0;
		}

	}
	else
	{
		return -1; // incorrect slot
	}
}

int32_t Vendbox_t::servPutProducts(int32_t slotNumber, Product_t product, int32_t numberOfItems)
{
	if (slotNumber && (slotNumber < MAX_NUMBER_OF_SLOTS)) // slot is correct
	{
		// if name of product is equal or slot is empty
		if ((slots[slotNumber - 1].getProductName() == product.getName()) || slots[slotNumber - 1].isEmpty())
		{
			if (slots[slotNumber - 1].isFilled())
			{
				return -3; // slot is filled previously
			}
			else
			{
				if (slots[slotNumber - 1].isEmpty()) // if slot is empty - change product
				{
					slots[slotNumber - 1].setProduct(product);
				}

				int32_t temp = int32_t(slots[slotNumber - 1].getFree()); // temp to ret extra
				if (slots[slotNumber - 1].getFree() < numberOfItems)
				{
					slots[slotNumber - 1].fillSlot();
					return int32_t(numberOfItems - temp);
				}
				else
				{
					slots[slotNumber - 1].addItems(numberOfItems);
					return 0; // successful condition
				}	
			}
		}
		else
		{
			return -2; // incorrect product
		}
	}
	else
	{
		return -1; // incorrect slot
	}


	//return int32_t();
}

void Vendbox_t::printInfo(void)
{
	for (int i = 0; i < MAX_NUMBER_OF_SLOTS; i++)
	{
		if (slots[i].isEmpty())
		{
			cout << "Slot " << i + 1 << " is empty " << endl;
		}
		else
		{
			cout << "In slot " << i + 1 << " " << slots[i].getCount() << " " << slots[i].getProductName() << endl;
		}
	}
	cout << endl;
}
