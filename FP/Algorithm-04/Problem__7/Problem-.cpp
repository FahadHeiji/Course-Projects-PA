#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;
enum enMonths
{
    January = 1,
    February = 2,
    March = 3,
    April = 4,
    May = 5,
    June = 6,
    July = 7,
    August = 8,
    September = 9,
    October = 10,
    November = 11,
    December = 12

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
short NumbersOfHoursInMonth(short month, short year)
{
    return NumbersOfDaysInMonth(month, isLeapYear(year)) * 24;
}
int NumbersOfMinutesInMonth(short month, short year)
{
    return NumbersOfHoursInMonth(month, year) * 60;
}
int NumbersOfSecondsInMonth(short month, short year)
{
    return NumbersOfMinutesInMonth(month, year) * 60;
}
short GetDayOrder(short day, short month, short year)
{
    short a = 0, y = 0, m = 0, d = 0;
    a = (14 - month) / 12;
    y = year - a;
    m = month + (12 * a) - 2;
    // Gorgian Calinder : 0: Sunday, 1: Tuseday etc..
    d = (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

    return d;
}

string GetDayName(short order)
{
    string Day__Week[]{
        "Sun",
        "Mon",
        "Tue",
        "Wed",
        "Thu",
        "Fri",
        "Sat"};
    return Day__Week[order];
}
int main()
{
    Layout::setProgramHeader("Check Day In Week");

    short year = 0, month = 0, day = 0, Day__Order = 0;
    string Day__Name = "";

    year = Functions::ReadPositiveNumber("Please Enter A Year : ");
    month = Functions::ReadPositiveNumber("Please Enter A Month : ");
    day = Functions::ReadPositiveNumber("Please Enter A Day : ");

    Day__Order = GetDayOrder(day, month, year);
    Day__Name = GetDayName(Day__Order);

    cout << setw(15) << left << "\nDate"
         << ": " << day << "/"
         << month << "/" << year
         << endl;
    cout << setw(15) << left << "Day Order"
         << ": " << Day__Order << endl;
    cout << setw(15) << left << "Day Name"
         << ": " << Day__Name << endl;
    return 0;
}