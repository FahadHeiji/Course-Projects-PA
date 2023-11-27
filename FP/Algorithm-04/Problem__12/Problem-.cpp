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

stDate AddDaysToDate(short Days, stDate Date)
{

    short Remaing__Days = Days + DayOfTheYear(Date.year, Date.month, Date.day);
    short month__Days = 0;
    Date.month = 1;

    while (true)
    {
        month__Days = NumbersOfDaysInMonth(Date.month, isLeapYear(Date.year));
        if (Remaing__Days > month__Days)
        {
            Remaing__Days -= month__Days;
            if (Date.month == 13)
            {
                Date.year++;
                Date.month = 0;
            }

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
    Layout::setProgramHeader("Day Of The Year After Adding x Days");

    stDate Date;
    short Days__ToAdd = 0;

    Date = ReadFullDate();
    Days__ToAdd = Functions::ReadPositiveNumber("How Many Days To Add : ");

    Date = AddDaysToDate(Days__ToAdd, Date);
    printf("\n\nDate After Adding [%d] Days is : %d/%d/%d\n", Days__ToAdd, Date.day, Date.month, Date.year);
    return 0;
}