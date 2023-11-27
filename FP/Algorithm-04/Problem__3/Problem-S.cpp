
#include <iostream>
using namespace std;

bool IsLeapYear(short Year)
{
    return (Year % 400 == 0) || (Year % 100 != 0 && Year % 4 == 0);
}

short ReadYear()
{
    short Year;
    cout << "\nPlease enter a year to check? ";
    cin >> Year;
    return Year;
}

int main()
{
    short Year = ReadYear();
    if (IsLeapYear(Year))
        cout << "\nYes, Year [" << Year << "] is a leap year.\n";
    else
        cout << "\nNo, Year [" << Year << "] is NOT a leap year.\n";
    return 0;
}
