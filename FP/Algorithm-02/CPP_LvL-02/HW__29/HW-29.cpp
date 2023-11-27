#include <iostream>
#include <vector>
#include "../../My_Libraries/Layout.h"
using namespace std;

vector <int> readNumber(vector <int> &vNumbers)
{
    char addNumber;
    int number = 0;
    do
    {
        cout << "Please Enter a Number : \n";
        cin >> number;
        vNumbers.push_back(number);
        cout << "Do You Wanna Enter Anthor Number?[Y/N]: \n";
        cin >> addNumber;
    } while (addNumber == 'Y' || addNumber == 'y');
    return vNumbers;
}

void printVector(vector <int> vNumber)
{
    cout << "You Entered : ";
    for ( int number: vNumber)
    {
        cout << number << " ";
    }
    
    cout << endl;
}

int main()
{
    vector <int> vNumber;
    Layout::setProgramHeader("Creat A Vector By the User");
    printVector(readNumber(vNumber));
}
