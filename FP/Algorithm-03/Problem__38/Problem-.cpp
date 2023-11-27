#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

string Trimleft(string message)
{
    short pos = 0;
    for (short i = 0; i < message.length(); i++)
    {
        pos = message.find(' ');
        if (message[0] != ' ')
            return message;
        message.erase(pos, pos + 1);
    }

    return message;
}

string Trimrighit(string message)
{
    short pos = 0;
    for (short i = message.length(); i > 1; i--)
    {
        pos = message.find(' ', i - 1);
        if (message[(message.length() - 1)] != ' ')
            return message;
        message.erase(pos, pos - 1);
    }

    return message;
}

string Trim(string &message)
{
    return Trimleft(Trimrighit(message));
}

int main()
{
    Layout::setProgramHeader("Trim String!");
    string S1 = Functions::ReadString("Please Enter A string :");
    cout << "Trim-Right: " << Trimrighit(S1) << endl;
    cout << "Trim-Left: " << Trimleft(S1) << endl;
    cout << "Trim: " << Trim(S1) << endl;
    return 0;
}