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

bool CheckPerfect(int Number)
{
    int sum = 0;
    for (int Counter = 1; Counter < Number; Counter++)
    {
        if (Number % Counter == 0)
        {
            sum += Counter;
        }
    }

    return sum == Number;
}

void printOutput(int Number)
{
    if (CheckPerfect(Number))
    {
        cout << Number << " is Perfect Number." << endl;
    }
    else
    {
        cout << Number << " is NOT Perfect Number." << endl;
    }
}
int main()
{
    printOutput(ReadPositiveNumber("Please Enter a Postive Number: "));
    return 0;
}