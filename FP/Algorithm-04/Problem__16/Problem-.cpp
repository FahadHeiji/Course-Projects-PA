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

stDate AddOneDay(stDate Date)
{

    if (isLastDay(Date) && isLastMonth(Date.month))
    {
        Date.day = 1;
        Date.month = 1;
        Date.year++;
    }
    else if (isLastDay(Date) && !(isLastMonth(Date.month)))
    {
        Date.day = 1;
        Date.month++;
    }
    else 
    {
        Date.day++;
    }

    return Date;
}

int main()
{
    Layout::setProgramHeader("Adding One Day");

    stDate Date01;

    Date01 = ReadFullDate();
    Date01 = AddOneDay(Date01);

    printf("Day After Adding One Day is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    return 0;
}