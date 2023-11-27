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

short CountOddNumbersInArray(int arrSource[100], int arrLength)
{
    short counter = 0;
    for (int i = 0; i < arrLength; i++)
    {
        if (arrSource[i] % 2 != 0)
            counter++;
    }

    return counter;
}

void printOutput()
{

    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], arrLength;

    FillArrayWithRandomNumbers(arr, arrLength);

    cout << "\nArray Elements:\n";

    PrintArray(arr, arrLength);

    cout << "\nThe Odd Numbers Inside The Array is : " << CountOddNumbersInArray(arr, arrLength) << endl;
}

int main()
{
    setProgramHeader("<< Count Odd Numbers Inside Array >>");
    printOutput();
    return 0;
}
