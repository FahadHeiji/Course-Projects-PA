#include <iostream>
#include <string>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

bool isLeapYear(short year)
{
    string Centery__digit = to_string(year);
    Centery__digit = Centery__digit.substr(Centery__digit.length() - 2, Centery__digit.length() - 1);
    if (Centery__digit != "00" && year % 4 == 0)
    {
        return 1;
    }
    else if (Centery__digit == "00" && (year % 400 == 0))
    {
        return 1;
    }

    return 0;
}

int main()
{
    Layout::setProgramHeader("Check Leap Year");
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
