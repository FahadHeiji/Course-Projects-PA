#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

struct stDate
{
    short year, month, day;
};

bool isLeapYear(short year)
{
    return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

short NumbersOfDaysInMonth(short month, bool isLeapYear = 1)
{
    if (month < 1 || month > 12)
        return 0;
    short Days__Of__Month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (month == 2) ? (isLeapYear ? 29 : 28) : Days__Of__Month[month - 1];
    return 31;
}

short DayOfTheYear(short year, short month, short day)
{
    short Total__Days = 0;
    for (short i = 1; i < month; i++)
    {
        Total__Days += NumbersOfDaysInMonth(i, isLeapYear(year));
    }

    Total__Days += day;
    return Total__Days;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.day = Functions::ReadPositiveNumber("Please Enter A Day : ");
    Date.month = Functions::ReadPositiveNumber("Please Enter A Month : ");
    Date.year = Functions::ReadPositiveNumber("Please Enter A Year : ");

    return Date;
}

bool isLastMonth(short month)
{
    return ((month == 12)) ? 1 : 0;
}
bool isLastDay(stDate Date1)
{
    return (Date1.day == NumbersOfDaysInMonth(Date1.month, isLeapYear(Date1.year))) ? 1 : 0;
}

int main()
{
    Layout::setProgramHeader("Month || Day are Last");

    stDate Date01;

    Date01 = ReadFullDate();

    if (isLastDay(Date01))
    {
        cout << "\nYes, Day is Last Day in The Month.\n";
    }
    else
        cout << "\nNo, Day is NOT Last Day in The Month.\n";
    if (isLastMonth(Date01.month))
    {
        cout << "Yes, Month is Last Day in The Year.\n";
    }
    else
        cout << "No, Month is NOT Last Day in The Year.\n";

    return 0;
}