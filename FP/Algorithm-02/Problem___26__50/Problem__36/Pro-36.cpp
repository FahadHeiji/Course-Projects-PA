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
    } while (Number < 0);
    return Number;
}

void addArrayElement(int arr[100], int &arrLength, int number)
{
    arrLength++;
    arr[arrLength - 1] = number;
}

void ReadArray(int arr[100], int &arrLength)
{
    short addMore ;
    do
    {
        addArrayElement(arr, arrLength, ReadPositiveNumber("Please Enter A number: "));
        addMore = ReadPositiveNumber("Do you want a More Numbers? [Yes = 1 / No = 0]: ");
    } while (addMore == true);
}

void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n\n";
}

void printOutput()
{
    int arr[100], length = 0;
    ReadArray(arr, length);
    cout << "\nArray Length: " << length << endl;
    cout << "Array Elements : \n";
    PrintArray(arr, length);
}

int main()
{
    // Seeds the random number generator in C++, called only once
    setProgramHeader("<< Add Array Elements Simi-Dynamic >>");
    printOutput();
    return 0;
}