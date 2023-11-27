#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
#include "../../My_Libraries/Date.h"

using namespace std;
using namespace Date;

bool isDateAfter(stDate Date01, stDate Date02)
{
    return (!isDateBefore(Date01, Date02) && !isDateEqual(Date01, Date02));
}

int main()
{
    Layout::setProgramHeader("Is Date01 Afeter Date02?");

    stDate Date01;
    stDate Date02;
    cout << "Enter Date[1]: \n";
    Date01 = ReadFullDate();

    cout << "\n\nEnter Date[2]: \n";
    Date02 = ReadFullDate();

    if (isDateAfter(Date01, Date02))

        cout << "\n\nYes, Date[1] is After Date[2].\n";
    else
        cout << "\n\nNo, Date[1] is NOT After Date[2].\n";

    return 0;
}
