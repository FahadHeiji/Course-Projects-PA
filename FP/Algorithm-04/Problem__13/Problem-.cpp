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

bool isLess(stDate Date1, stDate Date2)
{
    return (Date1.year < Date2.year) ? 1 : ((Date1.year == Date2.year) ? (Date1.month < Date2.month ? 1 : (Date1.month == Date2.month ? Date1.day < Date2.day : 0)) : 0);
}

int main()
{
    Layout::setProgramHeader("Date01 Less Than Date02");

    stDate Date01, Date02;

    Date01 = ReadFullDate();
    Date02 = ReadFullDate();

    if (isLess(Date01, Date02))
    {
        cout << "\nYes, Date01 is Less Than Date02.\n";
    }
    else
        cout << "\nNo, Date01 is NOT Less Than Date02.\n";

    return 0;
}