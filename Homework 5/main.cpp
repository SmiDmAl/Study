/*
HomeWork 5

Author: Smirnov Dmitriy
10.08.2022

Class traning with wendbox
*/

#include <stdint.h>
#include <iostream>
#include <string>


#include "vendbox.h"
#include "slot.h"
#include "product.h"

using namespace std;
#define NUMBER_OF_PRODUCTS 5

Product_t ProductList[NUMBER_OF_PRODUCTS];  
Vendbox_t mashine;


int main()
{
    ProductList[0] = Product_t("Mars", 60, 81, 455);
    ProductList[1] = Product_t("Snickers", 42, 51, 488);
    ProductList[2] = Product_t("Bounty", 52, 83, 484);
    ProductList[3] = Product_t("Twix", 38, 55, 497);
    ProductList[4] = Product_t("MilkyWay", 15, 26, 450);

    for (int i = 0; i < NUMBER_OF_PRODUCTS; i++) // show assortiment
    {
        ProductList[i].printProductInfo();
    }

    Product_t* cola = new Product_t("Cola", 10, 40, 300);
    cola->printProductInfo();
 
    mashine.servPutProducts(1, ProductList[0], 10);
    mashine.servPutProducts(2, ProductList[1], 12);
    mashine.servPutProducts(3, ProductList[2], 1);
    mashine.servPutProducts(4, ProductList[3], 20);
    mashine.servPutProducts(5, ProductList[4], 5);

    mashine.printInfo();

    if (mashine.selectProduct(2) > 0)
    {
        mashine.buyProduct(2);
    }
    cout << "Buy product from slot 2" << endl; 
    cout << endl;

    mashine.printInfo();
    
    delete cola;
    return 0;
}
