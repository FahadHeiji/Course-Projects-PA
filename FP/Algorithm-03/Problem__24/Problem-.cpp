#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

void UpperingFirstLetter(string message)
{
    bool isFirstLetter = true;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] != ' ' && isFirstLetter)
        {
            message[i] = toupper(message[i]);
        }

        isFirstLetter = (message[i] == ' ' ? 1 : 0);
    }
    cout << message << endl;
}
int main()
{
    Layout::setProgramHeader("Uppering the Frist Letter In Each Word!");
    UpperingFirstLetter(Functions::ReadString("Please Enter Your String: "));
    return 0;
}