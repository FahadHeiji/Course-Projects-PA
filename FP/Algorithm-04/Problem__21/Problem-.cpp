#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
#include "../../My_Libraries/Date.h"
using namespace std;
using namespace Date;



void PrintAllDates(stDate Date01)

{
    
    Date01 = SubtractOneDay(Date01);
    printf("\nDate After Subtracting One Day is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = SubtractXDays(Date01, 10);
    printf("\nDate After Subtracting %d Day is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = SubtractOneweek(Date01);
    printf("\nDate After Subtracting One week is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = SubtractXweek(Date01, 10);
    printf("\nDate After Subtracting %d week is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = SubtractOneMonth(Date01);
    printf("\nDate After Subtracting One Month is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = SubtractXMonth(Date01, 5);
    printf("\nDate After Subtracting %d Month is: %d/%d/%d", 5, Date01.day, Date01.month, Date01.year);

    Date01 = SubtractOneYear(Date01);
    printf("\nDate After Subtracting One Year is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = SubtractXYear(Date01, 10);
    printf("\nDate After Subtracting %d Year is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = SubtractXYearF(Date01, 10);
    printf("\nDate After Subtracting %d Year is (Faster): %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = SubtractOneDecade(Date01);
    printf("\nDate After Subtracting One Decade is: %d/%d/%d", Date01.day, Date01.month, Date01.year);

    Date01 = SubtractXDecade(Date01, 10);
    printf("\nDate After Subtracting %d Decade is: %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = SubtractXDecadeF(Date01, 10);
    printf("\nDate After Subtracting %d Decade is (Faster): %d/%d/%d", 10, Date01.day, Date01.month, Date01.year);

    Date01 = SubtractOneCentury(Date01);
    printf("\nDate After Subtracting One Century is: %d/%d/%d", Date01.day, Date01.month, Date01.year);
    
    Date01 = SubtractOneMillennium(Date01);
    printf("\nDate After Subtracting One Millennium is: %d/%d/%d", Date01.day, Date01.month, Date01.year);
}

int main()
{
    Layout::setProgramHeader("Subtracting One Day");

    stDate Date01;
    short Days = 0;

    Date01 = ReadFullDate();
    // Days = Functions::ReadPositiveNumber("Please Enter Number Of Month To Add: ");
    PrintAllDates(Date01);

    return 0;
}