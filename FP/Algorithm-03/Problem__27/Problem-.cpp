#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;
char invertCharacter(char letter)
{
    return isupper(letter) ? tolower(letter) : toupper(letter);
    // return letter < 97 ? tolower(letter) : toupper(letter);
}
int main()
{
    Layout::setProgramHeader("Inverting The Letter!");
    char S1 = Functions::ReadChar("Please Enter A Character: ");
    cout << "Character after Inverting:\n"
         << invertCharacter(S1) << endl;

    return 0;
}