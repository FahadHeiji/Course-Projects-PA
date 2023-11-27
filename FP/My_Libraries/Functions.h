#pragma once
#include <iostream>
#include <limits>
#include <vector>
#include <string>
using namespace std;

namespace Functions
{
    int RandomNumber(int From, int To)
    {
        // Function to generate a random number
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }
    int ReadPositiveNumber(string Message)
    {
        int Number = 0;
        do
        {
            cout << Message << endl;
            cin >> Number;
        } while (Number <= 0);
        return Number;
    }
    int ReadNumber(string Message)
    {
        int Number = 0;
        
        cout << Message << endl;
        cin >> Number;

        return Number;
    }
    string ReadString(string Message)
    {
        string S1;
        cout << Message << endl;
        getline(cin >> ws, S1);
        return S1;
    }
    char ReadChar(string Message)
    {
        char S1;
        cout << Message << endl;
        cin >> S1;
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

    string ReplaceWordInString(string S1, string StringToReplace, string sRepalceTo)
    {
        short pos = S1.find(StringToReplace);

        while (pos != std::string::npos)
        {
            S1 = S1.replace(pos, StringToReplace.length(), sRepalceTo);
            pos = S1.find(StringToReplace); // find next
        }

        return S1;
    }
}