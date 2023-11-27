#include <string>
#include <vector>
#include <iostream>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;
string ReadString()
{
    string S1;
    cout << "Please Enter Your String?\n";
    getline(cin, S1);
    return S1;
}
vector<string> Split(string S1, string delim = " ")
{
    vector<string> vSplit;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vSplit.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vSplit.push_back(S1);
    }
    return vSplit;
}

string JoinSrting(vector<string> &vString, string delim)
{
    string S1;
    for (string &word : vString)
    {
        S1 = S1 + word + delim;
    }
    return S1 = S1.substr(0, S1.length() - delim.length());
}
string JoinSrting(string arr[], short arrLength, string delim)
{
    string S1;
    for (short i = 0; i <= arrLength; i++)
    {
        S1 = S1 + arr[i] + delim;
    }
    return S1 = S1.substr(0, S1.length() - delim.length());
}



int main()
{
    Layout::setProgramHeader("Join String!");
    vector<string> vSplit = Split(ReadString());
    string arrString[] = {"Hi", "My", "Name", "Is", "Fahad"};
    cout << JoinSrting(vSplit, " ") << endl;
    cout << JoinSrting(arrString, 4, " ");
    return 0;
}