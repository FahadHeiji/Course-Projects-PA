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
int main()
{
    Layout::setProgramHeader("Split String!");
    vector<string> vSplit = Split(ReadString());
    cout << "\nToken = " << vSplit.size() << endl;
    for (string &word : vSplit)
    {
        cout << word << endl;
    }
    return 0;
}