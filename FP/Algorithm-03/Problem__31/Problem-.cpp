
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

short countLetter(string message, char letter, bool caseMatch = true)
{
    short count = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (caseMatch)
        {
            if (message[i] == letter)
                count++;
        }

        else
        {
            if (message[i] == tolower(letter) || message[i] == toupper(letter))
                count++;
        }
    }
    return count;
}
short countAllCaseLetter(string message, char letter)
{
    short count = 0;
    for (int i = 0; i < message.length(); i++)
    {
    }
    return count;
}

int main()
{
    Layout::setProgramHeader("Inverting The Letter All Caes!");
    string S1 = Functions::ReadString("Please Enter A String: ");
    char C1 = Functions::ReadChar("\nPlease Enter A Character: ");
    cout << "\nLetter '" << C1 << "' Count = "
         << countLetter(S1, C1) << endl;
    cout << "\nLetter '" << C1 << "' or '" <<invertCharacter(C1) <<"' Count = "
         << countLetter(S1, C1, false) << endl;
    return 0;
}