// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include "array.cpp"
using namespace std;

int main()
{
    
    Array<int> a(2);
    Array<int> b(20);
    Array<int> c(11);

    cout << "a: " << a.getLenght() << endl;

    a.remove(1);
    cout << "a: " << a.getLenght() << endl;

    cout << "b: " << b.getLenght() << endl;

    cout << "c: " << c.getLenght() << endl;

    c = b;
    cout << "b: " << b.getLenght() << endl;

    return 0;
}

