#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <ctime>
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

bool isLess(stDate Date1, stDate Date2)
{
    return (Date1.year < Date2.year) ? 1 : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? 1 : (Date1.month == Date2.month ? Date1.day < Date2.day : 0)) : 0);
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
int DiffInDays(stDate Date01, stDate Date02, bool lastDay = false)
{
    int Diff__Days = 0;
    while (isLess(Date01, Date02))
    {
        Diff__Days++;
        Date01 = AddOneDay(Date01);
    }

    return lastDay ? ++Diff__Days : Diff__Days;
}

stDate GetSystemDate()
{
    stDate Date;
    time_t current__time = time(0);
    tm *current__Date = localtime(&current__time);
    Date.day = current__Date->tm_mday;
    Date.month = current__Date->tm_mon + 1;
    Date.year = current__Date->tm_year + 1900;

    return Date;
}

int main()
{
    Layout::setProgramHeader("Age To Days");

    stDate Date01, Date02;
    short Diff__Days = 0;

    cout << "Please Enter Your Date Of Birth: \n\n";
    Date01 = ReadFullDate();
    Date02 = GetSystemDate();

    printf("\nYour Age is : %d Day(s).", DiffInDays(Date01, Date02));

    return 0;
}