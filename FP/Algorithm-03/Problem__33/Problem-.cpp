
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

char invertCharacter(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
}


short countVowelLetter(string message)
{
    short count = 0;
    for (int i = 0; i < message.length(); i++)
    {
        if (isVowel(message[i]))
            count++;
        
    }
    return count;
}

int main()
{
    Layout::setProgramHeader("Count Vowel Letters!");
    string S1 = Functions::ReadString("Please Enter A String: ");
    cout << "\nVowel Letters Count is: "
         << countVowelLetter(S1) << endl;
    return 0;
}