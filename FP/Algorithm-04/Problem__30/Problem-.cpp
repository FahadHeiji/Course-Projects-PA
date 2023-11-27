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
int GetPeriodLength(stPeriod Period, bool LastDay = false)
{
    return DiffInDays(Period.Start, Period.End, LastDay);
}

bool isDateInPeriod(stPeriod Period01, stDate Date)
{
    return ((compareDates(Date, Period01.Start) == enCompare::Before) || (compareDates(Date, Period01.End) == enCompare::After)) ? 0 : 1;
}

short CountOverlapDays(stPeriod Period01, stPeriod Period02)
{
    short Days__Counter = 0;
    short Period01__Length = GetPeriodLength(Period01, 1);
    short Period02__Length = GetPeriodLength(Period02, 1);
    if (!isOverlap(Period01, Period02))
    {
        return 0;
    }

    if (Period01__Length < Period02__Length)
    {
        while (isDateBefore(Period01.Start, Period01.End))
        {
            if (isDateInPeriod(Period02, Period01.Start))
            {
                Days__Counter++;
            }

            Period01.Start = AddOneDay(Period01.Start);
        }
    }
    else
    {
        while (isDateBefore(Period02.Start, Period02.End))
        {
            if (isDateInPeriod(Period01, Period02.Start))
            {
                Days__Counter++;
            }

            Period02.Start = AddOneDay(Period02.Start);
        }
    }

    return Days__Counter;
}

int main()
{
    Layout::setProgramHeader("is Overlap? Two Period");

    stPeriod Period01, Period02;

    cout << "Enter Period 1 : \n";
    Period01 = ReadPeriodDate();

    cout << "\n\nEnter Period 2 : \n";
    Period02 = ReadPeriodDate();

    cout << "\n\nOverlap Days Count = " << CountOverlapDays(Period01, Period02) << endl;

    return 0;
}