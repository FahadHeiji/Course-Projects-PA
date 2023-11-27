#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}
// void yearDetails(short year, bool LeapYear = 0)
// {
//     if (LeapYear)
//     {
//         cout << setw(15) << left << "\nNumbers Of Days"
//              << " In Year [" << year << "] Is " << 366 << endl;
//         cout << setw(15) << left << "Numbers Of Hours"
//              << " In Year [" << year << "] Is " << 8784 << endl;
//         cout << setw(15) << left << "Numbers Of Minutes"
//              << " In Year [" << year << "] Is " << 527040 << endl;
//         cout << setw(15) << left << "Numbers Of Seconds"
//              << " In Year [" << year << "] Is " << 31622400 << endl
//              << endl;
//     }
//     else
//     {
//         cout << setw(15) << left << "\nNumbers Of Days"
//              << " In Year [" << year << "] Is " << 365 << endl;
//         cout << setw(15) << left << "Numbers Of Hours"
//              << " In Year [" << year << "] Is " << 8760 << endl;
//         cout << setw(15) << left << "Numbers Of Minutes"
//              << " In Year [" << year << "] Is " << 525600 << endl;
//         cout << setw(15) << left << "Numbers Of Seconds"
//              << " In Year [" << year << "] Is " << 31536000 << endl
//              << endl;
//     }
// }

short NumbersOfDaysInYear(short year)
{
    return isLeapYear(year) ? 366 : 365;
}
short NumbersOfHoursInYear(short year)
{
    return NumbersOfDaysInYear(year) * 24;
}
int NumbersOfMinutesInYear(short year)
{
    return NumbersOfHoursInYear(year) * 60;
}
int NumbersOfSecondsInYear(short year)
{
    return NumbersOfMinutesInYear(year) * 60;
}

int main()
{
    Layout::setProgramHeader("Check Leap Year (One Line Code)");
    short year = Functions::ReadPositiveNumber("Please Enter A Year : ");

    cout << setw(15) << left << "\nNumbers Of Days"
         << " In Year [" << year << "] Is " << NumbersOfDaysInYear(year) << endl;
    cout << setw(15) << left << "Numbers Of Hours"
         << " In Year [" << year << "] Is " << NumbersOfHoursInYear(year) << endl;
    cout << setw(15) << left << "Numbers Of Minutes"
         << " In Year [" << year << "] Is " << NumbersOfMinutesInYear(year) << endl;
    cout << setw(15) << left << "Numbers Of Seconds"
         << " In Year [" << year << "] Is " << NumbersOfSecondsInYear(year) << endl
         << endl;
    // yearDetails(year, isLeapYear(year));
    return 0;
}