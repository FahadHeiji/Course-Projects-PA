
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

void counterhWordInString(string message)
{
    short counter = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] == ' ')
            counter++;
    }
    counter > 0 || !message.empty() ? counter++ : counter;
    cout << counter << endl;
}

int main()
{
    Layout::setProgramHeader("Counter hWord In String!");
    string S1 = Functions::ReadString("Please Enter A String: ");
    cout << "\nYour String Words are: " << endl;
    counterhWordInString(S1);
    return 0;
}