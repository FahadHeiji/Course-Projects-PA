#include <iostream>
#include <string>
using namespace std;

string ReadPassword(string Message)
{
    string password = "";

    cout << Message << endl;
    cin >> password;

    return password;
}

bool GuessPassword(string password)
{
    cout << "\n";
    string word = "";
    int counter = 1;
    for (int i = 1; i <= 26; i++)
    {

        for (int j = 1; j <= 26; j++)
        {

            for (int m = 1; m <= 26; m++)
            {
                word = word + char(64 + i);
                word = word + char(64 + j);
                word = word + char(64 + m);

                cout << "Trial[" << counter << "] : " << word << endl;

                if (word == password)
                {
                    cout << "\nPassword is " << word << endl;
                    cout << "Found After " << counter << " Trial(s)." << endl;
                    return true;
                }
                word = "";
                counter++;
            }
        }
    }
    return false;
}
int main()
{
    GuessPassword(ReadPassword("Please enter Your Passowrd to Guess it? (CAPTIAL LETTERS)"));
    return 0;
}
