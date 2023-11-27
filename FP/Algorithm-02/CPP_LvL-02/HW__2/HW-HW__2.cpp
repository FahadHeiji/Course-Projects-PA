#include <iostream>
#include "..\..\My_Libraries\Layout.h"
using namespace std;

void IsPostive()
{
    short Number = 0;
    cout << "Please Enter A Number: " << endl;
    cin >> Number;

    (Number > 0) ? cout << "It\'s Postive Number.\n" : cout << "It\'s Nagative Number.\n";
}

int main()
{
    Layout::setProgramHeader("Check Positve Number / Ternary Operator");
    IsPostive();
    return 0;
}
