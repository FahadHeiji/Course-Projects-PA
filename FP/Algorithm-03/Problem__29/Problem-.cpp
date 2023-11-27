#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;
char invertCharacter(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
}
short countUpperLetters(string message)
{
    short countUpper = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (isupper(message[i]))
            countUpper++;
    }
    return countUpper;
}
short countLowerLetters(string message)
{
    short countLower = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (islower(message[i]))
            countLower++;
    }
    return countLower;
}
int main()
{
    Layout::setProgramHeader("Inverting The Letter!");
    string S1 = Functions::ReadString("Please Enter A String: ");
    cout << "\nString Length : "
         << S1.length() << endl;
    cout << "\nString Upper Letters Count: "
         << countUpperLetters(S1) << endl;
    cout << "\nString Lower Letters Count: "
         << countLowerLetters(S1) << endl;

    return 0;
}