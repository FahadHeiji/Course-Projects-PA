
#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
#include "../../My_Libraries/Date.h"

using namespace std;
using namespace Date;

enum enCompare
{
    Before = -1,
    Equal = 0,
    After = 1,

};

struct stPeriod
{
    stDate Start;
    stDate End;
};

enCompare compareDates(stDate Date01, stDate Date02)
{
    return (isDateBefore(Date01, Date02)) ? enCompare::Before : (isDateEqual(Date01, Date02) ? enCompare::Equal : enCompare::After);
}

stPeriod ReadPeriodDate()
{
    stPeriod Period;
    cout << "Enter Start Date: \n";
    Period.Start = ReadFullDate();
    cout << "\nEnter End Date: \n";
    Period.End = ReadFullDate();

    return Period;
}

bool isOverlap(stPeriod Period01, stPeriod Period02)
{
    return ((compareDates(Period02.End, Period01.Start) == enCompare::Before) || (compareDates(Period02.Start, Period01.End) == enCompare::After)) ? 0 : 1;
}
bool isDateInPeriod(stPeriod Period01, stDate Date)
{
    return ((compareDates(Date, Period01.Start) == enCompare::Before) || (compareDates(Date, Period01.End) == enCompare::After)) ? 0 : 1;
}

int main()
{
    Layout::setProgramHeader("is Overlap?  Period - Date");

    stPeriod Period01;
    stDate Date;

    cout << "Enter Period  : \n";
    Period01 = ReadPeriodDate();

    cout << "\n\nEnter Date To Check : \n";
    Date = ReadFullDate();

    if (isDateInPeriod(Period01, Date))
        cout << "\n\nYes, Date is within Period." << endl;
    else
        cout << "\n\nNo, Date is without Period." << endl;

    return 0;
}