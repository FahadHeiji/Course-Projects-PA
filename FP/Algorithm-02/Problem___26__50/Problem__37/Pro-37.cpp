
#include <iostream>
#include <string>
#include <cstdlib>
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

int RandomNumber(int From, int To)
{ // Function to generate a random number
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

void addArrayElement(int arr[100], int &arrLength, int number)
{
    arrLength++;
    arr[arrLength - 1] = number;
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

void copyAnArrayUsingAddArrayElemnts(int arrSource[100], int arrDestination[100], int length, int length_02)
{

    for (int i = 0; i < length; i++)
    {
        addArrayElement(arrDestination, length_02, arrSource[i] );
    }
}

void printOutput()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], arr_02[100], length, length_02;
    length = ReadPositiveNumber("\nPlease Enter The Number Of Elements you want: ");
    ReadArray(arr, length);
    copyAnArrayUsingAddArrayElemnts(arr, arr_02, length, length_02);
    cout << "\nArray 1 Elemnts Before Copy : \n";
    PrintArray(arr, length);
    cout << "\nArray 2 Elemnts After Copy : \n";
    PrintArray(arr_02, length);
}

int main()
{
    setProgramHeader("<< Creat a Copy of An Array Using AddArrayElement >>");
    printOutput();
    return 0;
}
