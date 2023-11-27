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
string invertAllLetters(string message)
{
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = invertCharacter(message[i]);
    }
    return message;
}
int main()
{
    Layout::setProgramHeader("Inverting The Letter!");
    string S1 = Functions::ReadString("Please Enter A String: ");
    cout << "\nString after Inverting:\n"
         << invertAllLetters(S1) << endl;

    return 0;
}