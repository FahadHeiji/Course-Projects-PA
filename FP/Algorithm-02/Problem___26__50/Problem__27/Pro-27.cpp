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
    cout << "\nArray Elemnts: ";
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

int sumNumberInArray(int arr[100], int arrLength)
{
    int sum = 0;

    for (int i = 0; i < arrLength; i++)
    {
        sum += arr[i];
    }

    return sum;
}

float AverageInArray(int arr[100], int length)
{
    return (float)sumNumberInArray(arr, length) / length;
}

void printOutput()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));

    int arr[100], length;
    length = ReadPositiveNumber("\nPlease Enter The Number Of Elements you want: ");
    ReadArray(arr, length);
    PrintArray(arr, length);
    cout << "Average of All Numbers is: << " << AverageInArray(arr, length) << " >>\n\n";
}

int main()
{
    setProgramHeader("<< Average of All Numbers Inside An Array >>");
    printOutput();
    return 0;
}
