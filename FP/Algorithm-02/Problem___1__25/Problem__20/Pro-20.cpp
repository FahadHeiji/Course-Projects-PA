#include <iostream>
#include <cstdlib>
using namespace std;

enum enASCII_Code
{
    SpcialCharcaterStartPT1 = 33,
    SpcialCharcaterEndPT1 = 47,
    DigitZero = 48,
    DigitNine = 57,
    SpcialCharcaterStartPT2 = 58,
    SpcialCharcaterEndPT2 = 64,
    A = 65,
    Z = 90,
    SpcialCharcaterStartPT3 = 91,
    SpcialCharcaterEndPT3 = 96,
    a = 97,
    z = 122,
    SpcialCharcaterStartPT4 = 123,
    SpcialCharcaterEndPT4 = 126
};

int randomNumber(int from, int to)
{
    int random = rand() % (to - from + 1) + from;

    return random;
}

char randomItem(enASCII_Code from, enASCII_Code to)
{
    int randomItem = rand() % (to - from + 1) + from;

    return char(randomItem);
}

void randomSC()
{
    int random = randomNumber(1, 4);
    if (random = 1)
    {
        cout << randomItem(enASCII_Code::SpcialCharcaterStartPT1, enASCII_Code::SpcialCharcaterEndPT1) << endl;
    }
    else if (random = 2)
    {
        cout << randomItem(enASCII_Code::SpcialCharcaterStartPT2, enASCII_Code::SpcialCharcaterEndPT2) << endl;
    }
    else if (random = 3)
    {
        cout << randomItem(enASCII_Code::SpcialCharcaterStartPT3, enASCII_Code::SpcialCharcaterEndPT3) << endl;
    }
    else
    {
        cout << randomItem(enASCII_Code::SpcialCharcaterStartPT4, enASCII_Code::SpcialCharcaterEndPT4) << endl;
    }
}

void printOutput()
{
    cout << randomItem(enASCII_Code::a, enASCII_Code::z) << endl;
    cout << randomItem(enASCII_Code::A, enASCII_Code::Z) << endl;
    randomSC();
    cout << randomItem(enASCII_Code::DigitZero, enASCII_Code::DigitNine) << endl;
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    printOutput();

    return 0;
}