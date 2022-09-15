// main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ex.h"
#include "cont.h"

using namespace std;

int main()
{
    IntegerArray_t ar(10);
    int step = 0; // do not need static, cause main called once 

    switch (step)
    {
        case 0:
        {
            try
            {
                // test array allocation
                IntegerArray_t* j = new IntegerArray_t(10000000000); // error
                delete j;
            }
            catch (exception& e)
            {
            // Code in high level. Read error, analize, and do something useful code
            // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 1:
        {
            try
            {
                // test array allocation
                IntegerArray_t* j = new IntegerArray_t(-1); // error
                delete j;
            }
            catch (exception& e)
            {
            // Code in high level. Read error, analize, and do something useful code
            // Add "try another" to UI

                cout << e.what() << ". Try another!";
                cout << endl;
                
            }
            step++;
        }
        case 2:
        {
            try
            {
                // test array allocation
                IntegerArray_t* j = new IntegerArray_t(10); // no error
                cout << "Array j created successful!" << endl;
                delete j;
                cout << "Array j destroyed successful!" << endl;
            }
            catch (exception& e)
            {
            // Code in high level. Read error, analize, and do something useful code
            // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 3:
        {
            try
            {   // test (-index) 
                // use ar array 
                cout << "Lenght of array is: " << ar.getLenght() << endl;
                ar.insert(-1, 3);               
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 4:
        {
            try
            {
                // test out of lenght
                // use ar array 
                ar.insert(10, 32);  
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 5:
        {
            try
            {
                // test bad int
                ar.insert(7,765765765765);
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 6:
        {
            try
            {
                // good array test Creation as var
                cout << endl;
                cout << "Show Array: " << endl;

                for (int i = 0; i < 10; i++)
                {
                    ar.insert(i, i * i); // fill array for test
                }
                ar.printArray();
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 7:
        {
            try
            {
                // test constructor of copy
                cout << endl;
                cout << "Show Array j: " << endl;

                IntegerArray_t* j = new IntegerArray_t(ar);
                j->printArray();
                delete j;
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 8:
        {
            try
            {
                // test copy
                cout << endl;
                cout << "Show Array j: " << endl;

                IntegerArray_t* j = new IntegerArray_t(1);
                j->printArray(); 
                j->copy(ar);
                j->printArray();
                delete j;
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 9:
        {
            try
            {
                // test resize error
                cout << endl;
                ar.resize(0);
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 10:
        {
            try
            {
                // test bigger resize success 
                cout << endl;
                ar.resize(13);
                ar.printArray();

            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 11:
        {
            try
            {
                // test smaller resize success
                cout << endl;
                ar.resize(2);
                ar.printArray();

            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 12:
        {
            try
            {
                // test smaller resize success
                cout << endl;
                ar.remove(0);
                ar.printArray();
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 13:
        {
            try
            {
                // test smaller resize success
                cout << endl;
                ar.remove(0);
                ar.printArray();
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }
        case 14:
        {
            try
            {
                // test smaller resize error
                cout << endl;
                ar.remove(0);
                ar.printArray();
            }
            catch (exception& e)
            {
                // Code in high level. Read error, analize, and do something useful code
                // Add try another to UI

                cout << e.what() << ". Try another!";
                cout << endl;
            }
            step++;
        }



        default:
            // Exit
            break;
    }
       


    return 0;
}

