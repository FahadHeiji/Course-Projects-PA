#include <iostream>
#include <string>
#include <cmath>
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

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

short FindNumberPositionInArray(int Number, int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
    {
        if (arr[i] == Number)
            return i; // return the index
    }
    // if you reached here, this means the number is not found
    return -1;
}

bool IsNumberInArray(int Number, int arr[100], int arrLength)
{
    return FindNumberPositionInArray(Number, arr, arrLength) != -1;
}

void FillArrayWithRandomNumbers(int arr[100], int &arrLength)
{
    cout << "\nEnter number of elements:\n";
    cin >> arrLength;
    for (int i = 0; i < arrLength; i++)
        arr[i] = RandomNumber(1, 100);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

void AddArrayElement(int Number, int arr[100], int &arrLength)
{
    // its a new element so we need to add the length by 1
    arrLength++;
    arr[arrLength - 1] = Number;
}

void CopyDistinctNumbers(int arrSource[100], int arrDestination[100], int arrLength, int &arrDestinationLength)
{
    for (int i = 0; i < arrLength; i++)
    {

        if (!IsNumberInArray(arrSource[i], arrDestination, arrDestinationLength))
            AddArrayElement(arrSource[i], arrDestination, arrDestinationLength);
    }
}

void printOutput()
{

    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100] = {10, 10, 10, 50, 50, 50, 60, 60, 70, 100, 100}, arrLength = 11, arr2Length = 0;
    int arr2[100];

    CopyDistinctNumbers(arr, arr2, arrLength, arr2Length);

    cout << "\nArray 1 elements:\n";

    PrintArray(arr, arrLength);

    cout << "\nArray 2 elements after copy the Distinct Elements:\n";

    PrintArray(arr2, arr2Length);
}

int main()
{
    setProgramHeader("<< Creat a Distinct Array from An Array Using AddArrayElement >>");
    printOutput();
    return 0;
}
