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

enCompare compareDates(stDate Date01, stDate Date02)
{
    return (isDateBefore(Date01, Date02)) ? enCompare::Before : (isDateEqual(Date01, Date02) ? enCompare::Equal : enCompare::After);
}

int main()
{
    Layout::setProgramHeader("Compare Date01 & Date02");

    stDate Date01;
    stDate Date02;
    cout << "Enter Date[1]: \n";
    Date01 = ReadFullDate();

    cout << "\n\nEnter Date[2]: \n";
    Date02 = ReadFullDate();

    cout << "\n\nCompare Result = " << compareDates(Date01, Date02) << endl;

    return 0;
}
