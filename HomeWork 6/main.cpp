// HomeWork 6 : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdint.h>
#include <iostream>
#include <string>
#include "device.h"
#include "portable.h"
#include "products.h"

using namespace std;

device_t shop[3];

TV_t tv("LG 430", "LG", 1601034, 10, 99.5, 43.1);
notebook_t nb("Modern 14", "MSI", 100102, 10, 60, 1300, 5000, 16.3, true);
device_t cattle("Magic Cat", "Xiaomi", 3254, 3, 1023.5);

int main()
{
    shop[0] = tv;
    shop[1] = nb;
    shop[2] = cattle;

    for (int i = 0; i < 3; i++)
    {
        shop[i].writeInfo();
    }

    nb.writeInfo();

    return 0;
}


