#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
#include "../../My_Libraries/Date.h"

using namespace std;
using namespace Date;

string GetDayName(short order)
{
    string Day__Week[] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
    return Day__Week[order];
}

bool isEndOfTheWeek(short order)
{
    return order == 6 ? 1 : 0;
}

bool isWeekend(short order)
{
    return (order == 5 || order == 6) ? 1 : 0;
}
bool isBusinessDay(short order)
{
    return (order >= 1 && order <= 5) ? 1 : 0;
}

short DaysUntilEndOfTheWeek(short order)
{
    return 6 - order;
}
short DaysUntilEndOfTheMonth(stDate Date)
{
    return NumbersOfDaysInMonth(Date.month, isLeapYear(Date.year)) - Date.day;
}
short DaysUntilEndOfTheYear(stDate Date)
{
    return DayOfTheYear(Date.year, 12, 31) - DayOfTheYear(Date.year, Date.month, Date.day);
}

short GetVacationDays(stDate Date01, stDate Date02)
{
    short Weekend__Counter = 0;
    short Vacation__Days = DiffInDays(Date01, Date02);

    for (short i = 1; i <= Vacation__Days; i++)
    {
        if (isWeekend(GetDayOrder(Date01)))
        {
            Weekend__Counter++;
        }

        Date01 = AddOneDay(Date01);
    }
    return Vacation__Days - Weekend__Counter;
}

int main()
{
    Layout::setProgramHeader("Vacation Period");

    short Start__Index = 0, End__Index = 0;
    string Day__Start, Day__End;
    stDate Date__Start;
    stDate Date__End;

    cout << "Vacation Starts: \n";
    Date__Start = ReadFullDate();
    cout << "\nVacation Ends: \n";
    Date__End = ReadFullDate();

    Start__Index = GetDayOrder(Date__Start);
    End__Index = GetDayOrder(Date__End);

    Day__Start = GetDayName(Start__Index);
    Day__End = GetDayName(End__Index);

    cout << "\nVacation From: " << Day__Start << " , " << Date__Start.day << "/" << Date__Start.month << "/" << Date__Start.year << endl;
    cout << "Vacation To: " << Day__End << " , " << Date__End.day << "/" << Date__End.month << "/" << Date__End.year << endl;

    cout << "\n\nActucal Vacation Days : " << GetVacationDays(Date__Start, Date__End) << endl;

    return 0;
}
