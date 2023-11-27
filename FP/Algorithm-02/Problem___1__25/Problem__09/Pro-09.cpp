#include <iostream>
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

int CountDigitFrequency(short DigitToCheck, int Number)
{
    int FreqCount = 0, Remainder = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        if (DigitToCheck == Remainder)
        {
            FreqCount++;
        }
    }
    return FreqCount;
}
void CountDigitFrequencyAll(int Number)
{
    cout << endl;
    for (int i = 0; i < 10; i++)
    {
        short digitFreq = 0;
        digitFreq = CountDigitFrequency(i, Number);
        if (digitFreq == 0)
            continue;
        else
            cout << "Digit " << i << " Frequency is " << digitFreq << " Time(s).\n";
    }
}

int main()
{
    int Number = ReadPositiveNumber("Please enter the main number?");
    CountDigitFrequencyAll(Number);
    return 0;
}
