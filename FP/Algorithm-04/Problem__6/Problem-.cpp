#include <iostream>
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
    return (month == enMonths::April || month == enMonths::June || month == month == enMonths::September || month == enMonths::November) ? 30 : (month == enMonths::January || month == enMonths::March || month == enMonths::May || month == enMonths::July || month == enMonths::August || month == enMonths::October || month == enMonths::December) ? 31
                                                                                                                                            : (month == enMonths::February && isLeapYear)                                                                                                                                                               ? 29
                                                                                                                                                                                                                                                                                                                                                        : 28;
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

int main()
{
    Layout::setProgramHeader("Check Month (One Line Code)");
    short year = Functions::ReadPositiveNumber("Please Enter A Year : ");
    short month = Functions::ReadPositiveNumber("Please Enter A Month : ");

    cout << setw(15) << left << "\nNumbers Of Days"
         << " In Month [" << month << "] Is " << NumbersOfDaysInMonth(month, isLeapYear(year)) << endl;
    cout << setw(15) << left << "Numbers Of Hours"
         << " In Month [" << month << "] Is " << NumbersOfHoursInMonth(month, year) << endl;
    cout << setw(15) << left << "Numbers Of Minutes"
         << " In Month [" << month << "] Is " << NumbersOfMinutesInMonth(month, year) << endl;
    cout << setw(15) << left << "Numbers Of Seconds"
         << " In Monthr [" << month << "] Is " << NumbersOfSecondsInMonth(month, year) << endl
         << endl;
    return 0;
}