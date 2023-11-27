
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

void EachWordInLine(string message)
{
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
            message[i] = '\n';
    }
    cout << message << endl;
}

int main()
{
    Layout::setProgramHeader("Make String Words in Lines!");
    string S1 = Functions::ReadString("Please Enter A String: ");
    cout << "\nYour String Words are: " << endl;
    EachWordInLine(S1);
    return 0;
}