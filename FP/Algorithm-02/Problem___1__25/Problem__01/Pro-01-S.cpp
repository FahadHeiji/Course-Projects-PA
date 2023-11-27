#include <iostream>
using namespace std;

void printTableHeader()
{
    cout << "\n\n\t\t Multipliaction Table From 1 To 10\n\n";
    cout << "\t";
    for (int i = 1; i <= 10; i++)
    {
        cout << i << "\t";
    }
    cout << "\n___________________________________________________________________________________\n";
}

string columSperator(int i)
{
    if (i < 10)
        return "   |";
    else
        return "  |";
}

void printMultiplicationTable()
{
    printTableHeader();
    for (int i = 1; i <= 10; i++)
    {
        cout << " " << i << columSperator(i) << "\t";
        for (int j = 1; j <= 10; j++)
        {
            cout << i * j << "\t";
        }
        cout << endl;
    }
}

int main()
{
    printMultiplicationTable();
    return 0;
}