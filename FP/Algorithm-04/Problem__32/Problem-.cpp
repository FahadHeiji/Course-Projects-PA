
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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
    return isMonth(Date.month) && isDay(Date);
}

stDate vectorToDate(string S1, vector<string> &vString)
{
    stDate Date;

    while (vString.size() != 3)
    {
        S1 = Functions::ReadString("InValide input.\nPlease Enter Valide Input [dd/mm/yyyy]: ");
        vString.clear();
        vString = Functions::Split(S1, "/");
    }

    Date.day = stoi(vString[0]);
    Date.month = stoi(vString[1]);
    Date.year = stoi(vString[2]);

    return Date;
}
stDate stringToDate(string S1)
{
    stDate Date;
    vector<string> vString = Functions::Split(S1, "/");
    Date = vectorToDate(S1, vString);

    while (!isValidate(Date))
    {
        vString.clear();
        Date = vectorToDate(S1, vString);
    }

    return Date;
}

void StringToDate(stDate Date)
{
    cout << "\n\nDay : " << Date.day << "\n";
    cout << "Month : " << Date.month << "\n";
    cout << "Year : " << Date.year << "\n";
}

string DateToString(stDate Date)
{
    return to_string(Date.day) + "/" + to_string(Date.month) + "/" + to_string(Date.year);
}

int main()
{
    Layout::setProgramHeader("Read Date as String");

    stDate Date;
    string S__Date;

    S__Date = Functions::ReadString("Please Enter a Date dd/mm/yyyy: ");

    Date = stringToDate(S__Date);

    StringToDate(Date);

    cout << "\nYou Entered Date is : "
         << DateToString(Date) << "\n";

    return 0;
}
