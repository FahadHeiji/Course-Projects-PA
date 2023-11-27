#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

string LoweringLetters(string message)
{
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = tolower(message[i]);
    }
    return message;
}
string UpperingLetters(string message)
{
    for (int i = 0; i < message.length(); i++)
    {
        message[i] = toupper(message[i]);
    }
    return message;
}
int main()
{
    Layout::setProgramHeader("Lowering The Letters In Each Word!");
    string S1 = Functions::ReadString("Please Enter Your String: ");
    cout << "Lower:\n"
         << LoweringLetters(S1) << endl;
    cout << "Upper:\n"
         << UpperingLetters(S1) << endl;
    return 0;
}