#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
#include "../../My_Libraries/Date.h"
using namespace std;

void PrintAllDates(Date::stDate Date01)

{
    Date01 = Date::AddXYearF(Date01, 10);
    printf("\nDate After Adding %d Year is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);


    Date01 = Date::AddOneDay(Date01);
    printf("\nDate After Adding One Day is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddXDays(Date01, 10);
    printf("\nDate After Adding %d Day is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddOneweek(Date01);
    printf("\nDate After Adding One week is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddXweek(Date01, 10);
    printf("\nDate After Adding %d week is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddOneMonth(Date01);
    printf("\nDate After Adding One Month is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddXMonth(Date01, 5);
    printf("\nDate After Adding %d Month is: %d/%d/%d", 5, Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddOneYear(Date01);
    printf("\nDate After Adding One Year is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddXYear(Date01, 10);
    printf("\nDate After Adding %d Year is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddXYearF(Date01, 10);
    printf("\nDate After Adding %d Year is (Faster): %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddOneDecade(Date01);
    printf("\nDate After Adding One Decade is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddXDecade(Date01, 10);
    printf("\nDate After Adding %d Decade is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddXDecadeF(Date01, 10);
    printf("\nDate After Adding %d Decade is (Faster): %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = Date::AddOneCentury(Date01);
    printf("\nDate After Adding One Century is: %d/%d/%d", Date01.day, Date01.month, Date01.year);
    
    Date01 = Date::AddOneMillennium(Date01);
    printf("\nDate After Adding One Millennium is: %d/%d/%d", Date01.day, Date01.month, Date01.year);
}

int main()
{
    Layout::setProgramHeader("Adding One Day");

    Date::stDate Date01;
    short Days = 0;

    Date01 = Date::ReadFullDate();
    // Days = Functions::ReadPositiveNumber("Please Enter Number Of Month To Add: ");
    PrintAllDates(Date01);

    return 0;
}