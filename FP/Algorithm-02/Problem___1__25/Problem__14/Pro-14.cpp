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
void PrintInvertedLetterPattern(int Number)
{
    cout << "\n";
    for (int i = Number; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << char(64 + i);
        }
        cout << "\n";
    }
}
int main()
{
    PrintInvertedLetterPattern(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}
