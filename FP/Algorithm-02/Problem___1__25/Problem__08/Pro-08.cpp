#include <iostream>
#include <string>
using namespace std;

struct strFreq
{
    int Number;
    int Digit;
    int DigitFreq;
};

strFreq ReadPositiveNumber(string Message)
{
    strFreq Number;
    do
    {
        cout << Message << endl;
        cin >> Number.Number;
        cin >> Number.Digit;
    } while (Number.Number <= 0);
    return Number;
}

strFreq digitFrequency(strFreq Number)
{
    int Remainder = 0, Freq = 0;
    while (Number.Number > 0)
    {
        Remainder = Number.Number % 10;
        Number.Number = Number.Number / 10;

        if (Remainder == Number.Digit)
        {
            Freq++;
        }
    }
    Number.DigitFreq = Freq;
    return Number;
}

void printOutput(strFreq Number)
{
    if (Number.DigitFreq == 1)

        cout << "Digit " << Number.Digit << " Frequency is " << Number.DigitFreq << " Time." << endl;
    else
        cout << "Digit " << Number.Digit << " Frequency is " << Number.DigitFreq << " Time(s)." << endl;
}

int main()
{
    printOutput(digitFrequency(ReadPositiveNumber("Please Enter A Postive Number Then Enter A Digit to check: ")));
    return 0;
}
