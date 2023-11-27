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

        arr[i] = i + 1;
    }
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

void swapNumber(int &a, int &b)
{
    int temp = 0;
    temp = a;
    a = b;
    b = temp;
}

void MakeShuffleArray(int shuffleArray[100], int length)
{
    int checker = 0;
    for (int i = 0; i < length; i++)
    {
        swapNumber(shuffleArray[RandomNumber(1, length) - 1], shuffleArray[RandomNumber(1, length) - 1]);
    }
}

void printOutput()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], length;
    length = ReadPositiveNumber("\nPlease Enter The Number Of Elements you want: ");
    ReadArray(arr, length);

    cout << "\nArray  Elements Before Shuffle : \n";
    PrintArray(arr, length);
    MakeShuffleArray(arr, length);
    cout << "\nArray  Elements After Shuffle : \n";
    PrintArray(arr, length);
}

int main()
{
    setProgramHeader("<< Shuffle Ordered Array >>");
    printOutput();
    return 0;
}
