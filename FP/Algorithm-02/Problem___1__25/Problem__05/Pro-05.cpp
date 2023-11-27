#include <iostream>
#include <string>
using namespace std;

// string ReadPositiveNumber(string Message)
// {
//     int Number = 0;
//     do
//     {
//         cout << Message << endl;
//         cin >> Number;
//     } while (Number <= 0);
//     return to_string(Number);
// }
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

void printDigits(int num) // print Number Reversed Order
{
    // for (int i = num.length() - 1; i >= 0; i--)
    // {
    //     cout << num[i] << endl;
    // }
    int reminder = 0;
    while (num > 0)
    {
        reminder = num % 10;
        num = num / 10;
        cout << reminder << endl;
    }
}

int main()
{
    printDigits(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}