#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void setProgramHeader(string title)
{
    cout << "\n\t\t\t\t" << title << "\n\n\t\t\t";
    for (int i = 0; i < title.length() + 18; i++)
    {
        cout << "-";
    }
    cout << "\n\n";
}

int readInput(string Message)
{
    int number  = 0;
    cout << Message << endl;
    cin >> number;
    return number;
}

int myABS(int number)
{
    if (number < 0)
        return number *= -1;
    else
        return number;
}

void printOutput()
{
    int Number =readInput("Please Enter Number To Make it ABS: ");
    cout << "My ABS : " << myABS(Number) << endl;
    cout << "C++ ABS : " << abs(Number) << endl;
}

int main()
{
    setProgramHeader("<< Create ABS Function >>");
    printOutput();
    return 0;
}
