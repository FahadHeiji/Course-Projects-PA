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

char GetRandomCharacter(enCharType CharType)
{
    switch (CharType)
    {
    case enCharType::SamallLetter:
    {
        return char(RandomNumber(97, 122));
        break;
    }
    case enCharType::CapitalLetter:
    {
        return char(RandomNumber(65, 90));
        break;
    }
    case enCharType::SpecialCharacter:
    {
        return char(RandomNumber(33, 47));
        break;
    }
    case enCharType::Digit:
    {
        return char(RandomNumber(48, 57));
        break;
    }
    }
    return char(CharType);
}

string generateWord(enCharType CharType, short length)
{
    string word = "";
    for (int i = 0; i < length; i++)
    {
        word += GetRandomCharacter(CharType);
    }
    return word;
}

string generateKey()
{
    string key = "";
    key = generateWord(enCharType::CapitalLetter, 4) + "-";
    key += generateWord(enCharType::CapitalLetter, 4) + "-";
    key += generateWord(enCharType::CapitalLetter, 4) + "-";
    key += generateWord(enCharType::CapitalLetter, 4);

    return key;
}

void generateKeys(short numberOfKeys)
{
    for (int i = 1; i <= numberOfKeys; i++)
    {
        cout << "Key[" << i << "] : ";
        cout << generateKey() << endl;
    }
}

void ReadArray(string arr[100], int &arrLength)
{

    for (int i = 0; i < arrLength; i++)
    {
        arr[i] = generateKey();
    }
}

void PrintArray(string arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << "Array[" << i + 1 << "]: " << arr[i] << endl;
    cout << "\n\n";
}

void printOutput()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    string arr[100];
    int length;
    length = ReadPositiveNumber("\nPlease Enter The Number Of Keys you want: ");
    ReadArray(arr, length);
    cout << "\nArray Elemnts : \n\n";
    PrintArray(arr, length);
}

int main()
{
    // Seeds the random number generator in C++, called only once
    setProgramHeader("<< Fill Array With Keys >>");
    printOutput();
    return 0;
}