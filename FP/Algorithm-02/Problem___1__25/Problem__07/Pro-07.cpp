#include <iostream>
#include <string>
using namespace std;

int ReadPositiveNumber(string Message)
{
    int Number = 0;
    do
    {
        cout << Message << endl;
        cin >> Number;
    } while (Number <= 0);
    return Number;
}

int ReverseNumber(int Number)
{
    int Remainder = 0, Number_02 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        // cout << Remainder;
        Number_02 = Number_02 * 10 + Remainder;
    }
    return Number_02;
}

int main()
{
    int num = ReverseNumber(ReadPositiveNumber("Please enter a positive number?"));
    cout << "\nReverse is:\n"
         << num << "\n";
    return 0;
}
