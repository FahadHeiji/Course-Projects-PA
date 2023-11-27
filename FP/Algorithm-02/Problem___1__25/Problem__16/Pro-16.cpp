#include <iostream>
#include <string>
using namespace std;

void PrintWordsFromAAAtoZZZ()
{

    for (int i = 1; i <= 26; i++)
    {

        for (int j = 1; j <= 26; j++)
        {

            for (int m = 1; m <= 26; m++)
            {
                cout << char(64 + i) << char(64 + j) << char(64 + m) << endl;
            }
        }
    }
}
int main()
{
    PrintWordsFromAAAtoZZZ();
    return 0;
}
