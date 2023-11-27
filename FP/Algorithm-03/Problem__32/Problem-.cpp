
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

int main()
{
    Layout::setProgramHeader("Is Vowel?!");
    char C1 = Functions::ReadChar("\nPlease Enter A Character: ");

    if (isVowel(C1))
        cout << "\nYes: Letter '" << C1 << "' is a Vowel."
             << endl;
    else
        cout << "\nNo: Letter '" << C1 << "' is NOT a Vowel."
             << endl;

    return 0;
}