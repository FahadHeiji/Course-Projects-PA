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

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

void printSumArray(int arr1[100], int arr2[100], int arrSum[100], int length )
{
    for (int i = 0; i < length; i++)
    {
        arrSum[i] = arr1[i] + arr2[i];
    }
}

void printOutput()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], arr_02[100], arrSum[100], length;
    length = ReadPositiveNumber("\nPlease Enter The Number Of Elements you want: ");
    ReadArray(arr, length);
    ReadArray(arr_02, length);
    printSumArray(arr , arr_02 , arrSum , length);
    cout << "\nArray 1 Elements : \n";
    PrintArray(arr, length);
    cout << "\nArray 2 Elements : \n";
    PrintArray(arr_02, length);
    cout << "\nThe Sum Of Array 1 Elements & Array 2 Elements : \n";
    PrintArray(arrSum, length);
    
}

int main()
{
    setProgramHeader("<< Sum Array Of 2 Arrays >>");
    printOutput();
    return 0;
}
