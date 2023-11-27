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

float readInput(string Message)
{
    float number = 0;
    cout << Message << endl;
    cin >> number;
    return number;
}

float getFloatPart(float number)
{
    return number - (int)number;
}

int myceil(float number)
{
    int intPart = (int)number;
    if (intPart < 0)
        return intPart;
    else
        return ++intPart;
}

void printOutput()
{
    float Number = readInput("Please Enter Number : ");
    cout << "My ABS : " << myceil(Number) << endl;
    cout << "C++ ABS : " << ceil(Number) << endl;
}

int main()
{
    setProgramHeader("<< Create ceil Function >>");
    printOutput();
    return 0;
}
