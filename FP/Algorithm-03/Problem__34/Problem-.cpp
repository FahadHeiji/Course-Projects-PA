
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

bool isVowel(char letter)
{
    char vowelArr[5] = {'a', 'e', 'o', 'i', 'u'};
    for (char lett : vowelArr)
    {
        if (lett == tolower(letter))
            return 1;
    }
    return 0;
}

vector<char> countVowelInString(string message)
{
    vector<char> countVowel;
    for (int i = 0; i < message.length(); i++)
    {
        if (isVowel(message[i]))
            countVowel.push_back(message[i]);
    }
    return countVowel;
}

int main()
{
    Layout::setProgramHeader("Count Vowel Letters!");
    string S1 = Functions::ReadString("Please Enter A String: ");
    vector<char> vCountVowel = countVowelInString(S1);
    cout << "\nVowel Letters Count is: " << endl;
    for (char &vowel : vCountVowel)
    {
        cout << vowel << "\t";
    }
    cout << endl;
    return 0;
}