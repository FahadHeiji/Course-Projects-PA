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

int main()
{
    Layout::setProgramHeader("is Overlap? Two Period");

    stPeriod Period01, Period02;

    cout << "Enter Period 1 : \n";
    Period01 = ReadPeriodDate();

    cout << "\n\nEnter Period 2 : \n";
    Period02 = ReadPeriodDate();

    if (isOverlap(Period01, Period02))
        cout << "\n\nYes, Periods Overlap." << endl;
    else
        cout << "\n\nNo, Periods Dos\'nt Overlap." << endl;

    return 0;
}