#include <iostream>
#include "..\..\My_Libraries\Layout.h"
using namespace std;

void IsPostive()
{
    short Number = 0;
    cout << "Please Enter A Number: " << endl;
    cin >> Number;

    (Number > 0) ? cout << "It\'s Postive Number.\n" : (Number == 0) ? cout << "It\'s Zero.\n"
                                                                    : cout << "It\'s Negative Number.\n";
}

int main()
{
    Layout::setProgramHeader("Check Positve Number / Ternary Operator");
    IsPostive();
    return 0;
}
