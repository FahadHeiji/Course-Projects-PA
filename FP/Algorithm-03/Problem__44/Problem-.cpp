#include <string>
#include <vector>
#include <iostream>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

bool isPunctuation(char character)
{
    if ((int)character > 32 && (int)character < 48)
    {

        for (short i = 33; i < 48; i++)
        {
            if (character == char(i))
            {
                return 1;
            }
        }
    }

    else if ((int)character > 57 && (int)character < 65)
    {
        for (short i = 58; i < 65; i++)
        {
            if (character == char(i))
            {
                return 1;
            }
        }
    }

    else if ((int)character > 90 && (int)character < 97)
    {
        for (short i = 91; i < 97; i++)
        {
            if (character == char(i))
            {
                return 1;
            }
        }
    }
    return 0;
}

string removePunctuations(string S1)
{
    for (short i = 0; i < S1.length(); i++)
    {

        if (isPunctuation(S1[i]))
        {
            S1.erase(S1.find(S1[i]), 1);
        }
    }
    return S1;
} 

int main()
{
    Layout::setProgramHeader("Replace Word In String!");
    string S1 = "Hi! My: Name[ ] Is F'ahad; Nice: to meet You.";

    // string ReplaceFrom = Functions::ReadString("Please Enter The Word to Replce it:");
    cout << removePunctuations(S1);

    return 0;
}