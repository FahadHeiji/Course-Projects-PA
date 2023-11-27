#include <iostream>
#include <limits>
#include "..\..\My_Libraries\Layout.h"
using namespace std;



int main()
{
    Layout::setProgramHeader("Validate Number");
    short Number = 0;
    cout << "Please Enter A Number: " << endl;
    cin >> Number;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please Enter A Number: " << endl;
        cin >> Number;
    }

    cout << "You Entered " << Number << endl;
    
    return 0;
}