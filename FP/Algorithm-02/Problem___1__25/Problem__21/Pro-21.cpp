#include <iostream>
#include <cstdlib>
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

string RandomKey()
{ // Function to generate a random Key
    string randKey = "";
    for (int i = 0; i < 20; i++)
    {
        if (i % 5 == 0 && i != 0)
        {
            randKey += '-';
        }
        else
        {
            char randLetter = rand() % (90 - 65 + 1) + 65;
            randKey += randLetter;
        }
    }

    return randKey;
}

void printOutput(int number)
{
    for (int i = 1; i <= number; i++)
    {
        cout << "Key[" << i << "]: " << RandomKey() << endl;
    }
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    printOutput(ReadPositiveNumber("Please Enter How Many Keys You want: "));
    return 0;
}