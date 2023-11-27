#include <iostream>
#include "..\..\My_Libraries\Layout.h"
using namespace std;

int main()
{

    Layout::setProgramHeader("Range Loop");
    // initialize an int array
    int numArray[] = {1, 2, 3, 4, 5};

    // use of ranged for loop to print array elements
    for (int n : numArray)
    {
        cout << n << " ";
    }

    return 0;
}
