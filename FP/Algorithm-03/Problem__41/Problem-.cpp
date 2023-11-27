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

string reverseSrting(vector<string> &vString)
{
    string S2 = "";
    for (short i = vString.size() - 1; i >= 0; i--)
    {
        S2 += vString[i] + " ";
    }
    return S2 = S2.substr(0, S2.length() - 1);
}

int main()
{
    Layout::setProgramHeader("Reverse String!");
    vector<string> vString = Split(ReadString());
    cout << reverseSrting(vString);
    return 0;
}