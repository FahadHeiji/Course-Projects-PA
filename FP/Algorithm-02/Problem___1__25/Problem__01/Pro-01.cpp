#include <iostream>
using namespace std;

void makeMultiplayTable()
{
    int size = 10;
    int arrCol[size];
    for (int i = 1; i <= size; i++)
    {
        arrCol[i - 1] = i;
        cout << arrCol[i - 1] << "\t|";
        int rowSize = 10;
        int arrRow[rowSize];
        for (int j = 1; j <= rowSize; j++)
        {
            arrRow[j - 1] = j;
            cout << "\t" << arrRow[j - 1] * arrCol[i - 1];
        }
        cout << endl;
    }
}

void printTable()
{

    cout << "\n\t\t\t\tMultiplication Table From 1 To 10\n";
    cout << "\n\t\t1\t2\t3\t4\t5\t6\t7\t8\t9\t10\n";
    cout << "___________________________________________________________________________________________\n";
    makeMultiplayTable();
}

int main()
{
    printTable();
    return 0;
}