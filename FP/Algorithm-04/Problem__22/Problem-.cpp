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

int main()
{
    Layout::setProgramHeader("Days Until...");

    short order = 0;
    string Day__Name;
    stDate Date;
    Date = GetSystemDate();
    order = GetDayOrder(Date);
    Day__Name = GetDayName(order);

    cout << "Today is " << Day__Name << " , " << Date.day << "/" << Date.month << "/" << Date.year << endl;

    cout << "\n\nIs it End Of Week?\n";
    if (isEndOfTheWeek(order))
        cout << "Yes, End Of The Week\n";
    else
        cout << "No, NOT End Of The Week\n";

    cout << "\n\nIs it Weekend?\n";
    if (isWeekend(order))
        cout << "Yes, It's a Weekend\n";
    else
        cout << "No, It's NOT a Weekend\n";

    cout << "\n\nIs it Business Day?\n";
    if (isBusinessDay(order))
        cout << "Yes, It's a Business Day\n";
    else
        cout << "No, It's NOT a Business Day\n";

    printf("\n\nDays Until End Of Week : %d Days(s).\n", DaysUntilEndOfTheWeek(order));
    printf("Days Until End Of Month : %d Days(s).\n", DaysUntilEndOfTheMonth(Date));
    printf("Days Until End Of Year : %d Days(s).\n\n", DaysUntilEndOfTheYear(Date));

    return 0;
}
