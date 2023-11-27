#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
using namespace std;

enum enPrimNotPrime

{

    Prime = 1,

    NotPrime = 2

};

enPrimNotPrime CheckPrime(int Number)
{
    int M = round(Number / 2);
    for (int Counter = 2; Counter <= M; Counter++)
    {
        if (Number % Counter == 0)
            return enPrimNotPrime::NotPrime;
    }
    return enPrimNotPrime::Prime;
}

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

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

void copyOnlyPrimeNumbersFromAnArray(int arrSource[100], int arrDestination[100], int arr1length, int &arr2length)
{
    int counter = 0;
    for (int i = 0; i < arr1length; i++)
    {
        if (CheckPrime(arrSource[i]) == enPrimNotPrime::Prime)
        {
            arrDestination[counter] = arrSource[i];
            counter++;
        }
    }
    arr2length = counter;
}

void printOutput()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], arr_02[100], length, arr2Length = 0;
    length = ReadPositiveNumber("\nPlease Enter The Number Of Elements you want: ");
    ReadArray(arr, length);
    copyOnlyPrimeNumbersFromAnArray(arr, arr_02, length, arr2Length);
    cout << "\nArray 1 Elemnts After Copy : \n";
    PrintArray(arr, length);
    cout << "\nPrime Number In Array 2 : \n";
    PrintArray(arr_02, arr2Length);
}

int main()
{
    setProgramHeader("<< Creat Prime Numbers Array from An Array >>");
    printOutput();
    return 0;
}
