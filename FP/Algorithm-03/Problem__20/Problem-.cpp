#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

void FillMatrixWithNumbers(int arr[3][3], int rows, int cols)
{
    for (short row = 0; row < rows; row++)
    {
        for (short col = 0; col < cols; col++)
        {
            arr[row][col] = Functions::RandomNumber(1, 10);
        }
    }
}

void PrintMatrix(int arr[3][3])
{

    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            cout << setw(4);
            printf("%d\t", arr[row][col]);
        }
        cout << endl;
    }
}

bool checkNumberInMatrix(int arr[3][3], int Number)
{

    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            if (arr[row][col] == Number)
                return 1;
        }
    }

    return 0;
}

bool checkIsPalindrome(int arr[3][3])
{
    short FirstCol = 0, LastCol = 2;
    for (short row = 0; row < 3; row++)
    {
        if (arr[row][FirstCol] != arr[row][LastCol])
            return 0;
    }

    return 1;
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("Check if The Matrix is Palindrome");
    int Matrix[3][3] = {{1, 0, 1}, {1, 0, 1}, {3, 5, 3}};
    // FillMatrixWithNumbers(Matrix, 3, 3);
    cout << "\nHere is Matrix [1] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(Matrix);
    if (checkIsPalindrome(Matrix))
        cout << "\nYes: It\'s a Palindrome Matrix. " << endl;

    else
        cout << "\nNo: It\'s NOT a Palindrome Matrix. " << endl;

    return 0;
}