#include <iostream>
#include <string>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

bool isLeapYear(short year)
{
    // return (year % 400 == 0) ? 1 : (year % 100 != 0 && year % 4 == 0) ? 1
    //                                                                   : 0;

    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

int main()
{
    Layout::setProgramHeader("Check Leap Year (One Line Code)");
    short year = Functions::ReadPositiveNumber("Please Enter A Year : ");
    if (isLeapYear(year))
    {
        cout << "\nYes, Year [" << year << "] It\'s A Leap Year.\n";
    }
    else
    {
        cout << "\nNo, Year [" << year << "] It\'s NOT A Leap Year.\n";
    }

    return 0;
}
