#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

void setProgramHeader(string title)
{
    cout << "\n\t\t\t\t" << title << "\n\n\t\t\t";
    for (int i = 0; i < title.length() + 18; i++)
    {
        cout << "-";
    }
    cout << "\n\n";
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

enum enCharType
{
    SamallLetter = 1,
    CapitalLetter = 2,
    SpecialCharacter = 3,
    Digit = 4
};

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void ReadArray(int arr[100], int &arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = RandomNumber(1, 100);
    }
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

short numberIndexInArray(int arr[100], int arrLength, int number)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == number)
            return i;
    }
    return -1;
}

void printOutput()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], length, number;
    length = ReadPositiveNumber("\nPlease Enter The Number Of Elements you want: ");
    ReadArray(arr, length);
    cout << "\nArray Elemnts : \n\n";
    PrintArray(arr, length);
    number = ReadPositiveNumber("Please Enter Number To Search For : ");
    short numberIndex = numberIndexInArray(arr, length, number);

    cout << "Number You are Looking For : " << number << endl;
    if (numberIndex == -1)
        cout << "Sorry The Number Not Found :-(\n";
    else
    {
        cout << "The Number Found at Position: " << numberIndex << endl;
        cout << "The Number Found it\'s Order: " << numberIndex + 1 << endl;
    }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    setProgramHeader("<< Return Number Index In Array >>");
    printOutput();
    return 0;
}