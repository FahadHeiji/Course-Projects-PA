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
char invertCharacter(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
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
vector<string> replaceWordInSrting(vector<string> &vString, string preWord, string postWord)
{
    string preWordMatchCase = preWord;
    preWordMatchCase[0] = invertCharacter(preWordMatchCase[0]);
    for (short i = vString.size() - 1; i >= 0; i--)
    {
        if (vString[i] == preWord || vString[i] == preWordMatchCase)
            vString[i] = postWord;
    }
    return vString;
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

int main()
{
    Layout::setProgramHeader("Replace Word In String!");
    vector<string> vString = Split(ReadString());
    string ReplaceFrom = Functions::ReadString("Please Enter The Word to Replce it:");
    string ReplaceTo = Functions::ReadString("Please Enter The New Word to Replce it:");
    replaceWordInSrting(vString, ReplaceFrom, ReplaceTo);
    cout << JoinSrting(vString, " ");
    return 0;
}