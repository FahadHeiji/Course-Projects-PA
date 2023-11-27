#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

// void findInString(string message)
// {
//     int pos = 0;
//     cout << "First Letter : " << message[(pos == 0) ? pos : pos + 1] << endl;
//     while ((pos = message.find(' ', pos)) != string::npos)
//     {
//         cout << "First Letter : " << message[pos + 1] << endl;
//         pos++;
//     }
// }
void findInString(string message)
{
    bool isFirstLetter = true;
    for (int i = 0; i < message.length(); i++)
    {
        if (message[i] != ' ' && isFirstLetter)
        {
            cout << message[i] << endl;
        }

        isFirstLetter = (message[i] == ' ' ? 1 : 0);
    }
}
int main()
{
    Layout::setProgramHeader("Print Frist Letter In Each Word!");
    findInString(Functions::ReadString("Please Enter Your String: "));
    return 0;
}