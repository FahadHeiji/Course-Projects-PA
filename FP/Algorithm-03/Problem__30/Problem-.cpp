#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

short countLetter(string message, char letter)
{
    short count = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == letter)
            count++;
    }
    return count;
}

int main()
{
    Layout::setProgramHeader("Count Letter in String!");
    string S1 = Functions::ReadString("Please Enter A String: ");
    char C1 = Functions::ReadChar("\nPlease Enter A Character: ");
    cout << "\nLetter '"<< C1 << "' Count = "
         << countLetter(S1, C1) << endl;
    return 0;
}