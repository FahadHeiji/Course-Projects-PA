#include <string>
#include <iostream>
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
void PrintEachWordInString(string S1)
{
    string delim = " "; // delimiter
    cout << "\nYour string words are: \n\n";
    short pos = 0, counter = 0;
    string sWord; // define a string variable
                  // use find() function to get the position of the delimiters
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos); // store the word
        if (sWord != "")
        {
            counter++;
        }
        S1.erase(0, pos + delim.length()); /* erase() until positon and move to next word. */
    }
    if (S1 != "")
    {
        counter++; // it print last word of the string.
        cout << "Word Counter = "<< counter;
    }
}
int main()
{
    PrintEachWordInString("Hi My Name Is Fahad");
    return 0;
}