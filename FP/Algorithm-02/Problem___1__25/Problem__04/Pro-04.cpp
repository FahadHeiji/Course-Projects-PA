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

bool isPerfectNumber(int Number)
{
    int Sum = 0;
    for (int i = 1; i < Number; i++)
    {
        if (Number % i == 0)
            Sum += i;
    }
    return Number == Sum;
}

void PrintResults(int Number) // Print Perfect Numbers From 1 To N
{

    for (int i = 1; i <= Number; i++)
    {
        if (isPerfectNumber(i))
            cout << i << " Is Perfect Number.\n";
    }
}

int main()
{
    PrintResults(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}
