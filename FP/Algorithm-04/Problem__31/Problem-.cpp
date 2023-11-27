
#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
#include "../../My_Libraries/Date.h"

using namespace std;
using namespace Date;

bool isMonth(short month)
{
    return month >= 1 && month <= 12 ? 1 : 0;
}
bool isDay(stDate Date)
{
    return Date.day <= NumbersOfDaysInMonth(Date.month, isLeapYear(Date.year)) ? 1 : 0;
}

bool isValidate(stDate Date)
{
    return isMonth(Date.month) && isDay(Date) ;
}

int main()
{
    Layout::setProgramHeader("Validate Date");

    stDate Date;

    Date = ReadFullDate();

    if (isValidate(Date))
        cout << "\n\nYes, Date is A Validate Date.\n";
    else
        cout << "\n\nNo, Date is  NOT A Validate Date.\n";

    return 0;
}
