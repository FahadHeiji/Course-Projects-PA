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

stDate PrintDayOfTheYear(short year, short Doy)
{
    stDate Date;
    short Remaing__Days = Doy, month__Days = 0;
    Date.year = year;
    Date.month = 1;

    while (true)
    {
        month__Days = NumbersOfDaysInMonth(Date.month, isLeapYear(Date.year));
        if (Remaing__Days > month__Days)
        {
            Remaing__Days -= month__Days;
            Date.month++;
        }
        else
        {
            Date.day = Remaing__Days;
            break;
        }
    }

    return Date;
}

int main()
{
    Layout::setProgramHeader("Day Of The Year");

    stDate Date;
    short year = 0, month = 0, day = 0, Doy = 0;

    day = Functions::ReadPositiveNumber("Please Enter A Day : ");
    month = Functions::ReadPositiveNumber("Please Enter A Month : ");
    year = Functions::ReadPositiveNumber("Please Enter A Year : ");
    Doy = DayOfTheYear(year, month, day);

    cout
        << "Number Of Days From The Begining Of The Year Is " << Doy;

    Date = PrintDayOfTheYear(year, Doy);
    printf("\n\nDate For [%d] : %d/%d/%d\n", Doy, Date.day, Date.month, Date.year);
    return 0;
}