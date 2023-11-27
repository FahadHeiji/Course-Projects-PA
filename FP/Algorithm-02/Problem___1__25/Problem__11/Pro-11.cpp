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
    int Remainder = 0, Number2 = 0;
    while (Number > 0)
    {
        Remainder = Number % 10;
        Number = Number / 10;
        Number2 = Number2 * 10 + Remainder;
    }
    return Number2;
}
void checkPalindromeNumber(int Number)
{
    int revNumber = ReverseNumber(Number);
    if (Number == revNumber)
        cout << "\nYes, It\'s a Palindrome Number" << endl;
    else
        cout << "\nNo, It\'s NOT a Palindrome Number" << endl;
    
}
int main()
{
    checkPalindromeNumber(ReadPositiveNumber("Please enter a positive number?"));
    return 0;
}