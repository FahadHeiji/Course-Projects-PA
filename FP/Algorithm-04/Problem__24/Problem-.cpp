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

bool isWeekend(short order)
{
    return (order == 5 || order == 6) ? 1 : 0;
}
bool isBusinessDay(short order)
{
    return !isWeekend(order);
}

stDate CalcVacationDays(stDate Date01, short Vacation__Days)
{
    while (Vacation__Days > 0)
    {
        if (isBusinessDay(GetDayOrder(Date01)))
        {

            Vacation__Days--;
        }
        Date01 = AddOneDay(Date01);
    }
    return Date01;
}

int main()
{
    Layout::setProgramHeader("Calc Vacation Period");

    short Vacation__Days = 0;
    stDate Date__Start;
    stDate Date__End;

    cout << "Vacation Starts: \n";
    Date__Start = ReadFullDate();

    Vacation__Days = Functions::ReadPositiveNumber("Please Enter Vacations Days?");

    Date__End = CalcVacationDays(Date__Start, Vacation__Days);

    cout << "\n\nReturn Date : " << GetDayName(GetDayOrder(Date__End)) << ", " << Date__End.day << "/" << Date__End.month << "/" << Date__End.year << endl;

    return 0;
}
