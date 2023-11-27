#include <iostream>

using namespace std;

struct stDate
{
    short Year;
    short Month;
    short Day;
};

struct stPeriod
{
    stDate StartDate;
    stDate EndDate;
};

bool IsDate1BeforeDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year < Date2.Year) ? true
                                     : ((Date1.Year == Date2.Year) ? (Date1.Month < Date2.Month ? true
                                                                                                : (Date1.Month == Date2.Month ? Date1.Day < Date2.Day : false))
                                                                   : false);
}

bool IsDate1EqualDate2(stDate Date1, stDate Date2)
{
    return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
}

bool IsDate1AfterDate2(stDate Date1, stDate Date2)
{
    return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
}

enum enDateCompare
{
    Before = -1,
    Equal = 0,
    After = 1
};

enDateCompare CompareDates(stDate Date1, stDate Date2)
{
    if (IsDate1BeforeDate2(Date1, Date2))
        return enDateCompare::Before;
    if (IsDate1EqualDate2(Date1, Date2))
        return enDateCompare::Equal;
    // This is faster
    return enDateCompare::After;
}

bool isDateInPeriod(stDate Date, stPeriod Period)
{
    return !(CompareDates(Date, Period.StartDate) == enDateCompare::Before || CompareDates(Date, Period.EndDate) == enDateCompare::After);
}

short ReadDay()
{
    short Day;
    cout << "\nPlease enter a Day? ";
    cin >> Day;
    return Day;
}

short ReadMonth()
{
    short Month;
    cout << "Please enter a Month? ";
    cin >> Month;
    return Month;
}
short ReadYear()
{
    short Year;
    cout << "Please enter a Year? ";
    cin >> Year;
    return Year;
}

stDate ReadFullDate()
{
    stDate Date;
    Date.Day = ReadDay();
    Date.Month = ReadMonth();
    Date.Year = ReadYear();
    return Date;
}

stPeriod ReadPeriod()
{
    stPeriod Period;
    cout << "\nEnter Start Date:\n";
    Period.StartDate = ReadFullDate();
    cout << "\nEnter End Date:\n";
    Period.EndDate = ReadFullDate();
    return Period;
}

int main()
{
    cout << "\nEnter Period:\n";
    stPeriod Period = ReadPeriod();
    cout << "\nEnter Date to check:\n";
    stDate Date = ReadFullDate();
    if (isDateInPeriod(Date, Period))
        cout << "\nYes, Date is within the period.\n";
    else
        cout << "\nNo, Date is NOT within the period.\n";
    return 0;
}