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
void PrintHeader(short month)
{
    string Months[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    cout << setw(12) << setfill('_') << "_";
    cout << setw(3) << Months[month - 1];
    cout << setw(12) << setfill('_') << "_"
         << "\n\n";
    for (short i = 0; i < 7; i++)
    {
        cout << setfill(' ') << setw(3) << left << GetDayName(i) << " ";
    }
    cout << "\n";
}
void PrintMonthCalinder(short month, short year)
{

    short Day__Order, First__day, Day__Counter, Month__Days, Last__Week;

    Day__Order = GetDayOrder(1, month, year);
    Month__Days = NumbersOfDaysInMonth(month, isLeapYear(year));

    Day__Counter = 1;
    First__day = Day__Order;
    Last__Week = (Day__Order == 6 || (Day__Order > 4 && Month__Days == 31)) ? 6 : 5;

    PrintHeader(month);

        for (short week = 1; week <= Last__Week; week++)
    {
        for (short day = 1; day <= 7; day++)
        {
            if (First__day > 0)
            {
                cout << setw(4) << "  ";
                First__day--;
            }
            else
            {

                if (Day__Counter <= Month__Days)
                {
                    cout << setw(3) << right << Day__Counter << " ";
                    Day__Counter++;
                }
            }
        }

        cout << "\n";
    }
    cout << setw(27) << setfill('_') << "_";
}
int main()
{
    Layout::setProgramHeader("Print Calendar - Month");

    short year = 0, month = 0, day = 0, Day__Order = 0;
    string Day__Name = "";

    year = Functions::ReadPositiveNumber("Please Enter A Year : ");
    month = Functions::ReadPositiveNumber("Please Enter A Month : ");

    PrintMonthCalinder(month, year);
    return 0;
}