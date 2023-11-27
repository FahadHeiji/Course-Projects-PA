#include <iostream>
#include <string>
using namespace std;

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

void ReadArray(int arr[100], int &size)
{
    cout << "\nPlease Enter Array Elements: " << endl;

    for (int i = 0; i < size; i++)
    {
        cout << " Elements[" << i + 1 << "]: ";
        cin >> arr[i];
    }
}

void PrintArray(int arr[100], int size)
{
    cout << "\nOrignal Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int CountElementFrequency(short NumberToCheck, int size, int arr[100])
{
    int FreqCount = 0, counter = 0, i = 0;
    while (i < size)
    {
        counter = arr[i];
        if (NumberToCheck == counter)
        {
            FreqCount++;
        }
        i++;
    }
    return FreqCount;
}

void printOutput(int size)
{
    int arr[100];
    ReadArray(arr, size);
    int NumberToCheck = ReadPositiveNumber("\nPlease Enter The Number You want to check : ");

    PrintArray(arr, size);
    cout << NumberToCheck << " is Repeated " << CountElementFrequency(NumberToCheck, size, arr) << " Time(s).\n";
}

int main()
{
    int arraySize = ReadPositiveNumber("\nPlease Enter The Number Of Element Do want: ");

    printOutput(arraySize);
    return 0;
}