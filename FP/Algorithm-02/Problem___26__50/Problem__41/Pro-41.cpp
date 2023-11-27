#include <iostream>
using namespace std;

void FillArray(int arr[100], int &arrLength)
{
    arrLength = 11;
    arr[0] = 10;
    arr[1] = 10;
    arr[2] = 10;
    arr[3] = 20;
    arr[4] = 20;
    arr[5] = 30;
    arr[6] = 20;
    arr[7] = 20;
    arr[8] = 10;
    arr[9] = 10;
    arr[10] = 10;
}
void PrintArray(int arr[100], int arrLength)
{
    for (int i = 0; i < arrLength; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

bool checkPalindromeArray(int arrSource[100], int SourceLength)
{
    for (int i = 0; i < SourceLength; i++)
    {
        if (arrSource[i] != arrSource[SourceLength - 1 - i])
            return 0;
    };
    return 1;
}

int main()
{
    int arr[100], arrLength;
    FillArray(arr, arrLength);
    cout << "\nArray 1 elements:\n";
    PrintArray(arr, arrLength);
    if (checkPalindromeArray(arr, arrLength))
        cout << "\nYes, The Array is Palindrome.\n";
    else
        cout << "\nNo, The Array is\'nt Palindrome\n";
    return 0;
}
