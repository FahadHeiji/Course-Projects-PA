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

int SumOfDigits(int num) // print The Total Sum of Digits
{

    int reminder = 0;
    int sum = 0;
    while (num > 0)
    {
        reminder = num % 10;
        num = num / 10;
        sum += reminder;
    }
    // cout << "Sum of Digits = " << sum << endl;
    return sum;
}

int main()
{
    cout << "\nSum Of Digits = " << SumOfDigits(ReadPositiveNumber("Please enter a positive number?")) << "\n";
    // printDigitsSum(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}