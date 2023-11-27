#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
#include "../../My_Libraries/Date.h"

using namespace std;
using namespace Date;

struct stPeriod
{
    stDate Start;
    stDate End;
};

stPeriod ReadPeriodDate()
{
    stPeriod Period;
    cout << "Enter Start Date: \n";
    Period.Start = ReadFullDate();
    cout << "\nEnter End Date: \n";
    Period.End = ReadFullDate();

    return Period;
}

int GetPeriodLength(stPeriod Period, bool LastDay = false)
{
    return DiffInDays(Period.Start, Period.End, LastDay);
}

int main()
{
    Layout::setProgramHeader("Period Length");

    stPeriod Period01;

    cout << "Enter Period  : \n";
    Period01 = ReadPeriodDate();

    cout << "Period Length is : " << GetPeriodLength(Period01);
    cout << "\nPeriod Length (Include End Day) is : " << GetPeriodLength(Period01, true);

    return 0;
}