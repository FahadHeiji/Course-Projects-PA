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
            arr[row][col] = Functions::RandomNumber(1, 100);
        }
    }
}

short SumColMatrix(int arr[3][3], int colNumber, int rows)
{
    short sum = 0;
    for (short row = 0; row < rows; row++)
    {
        sum = sum + arr[row][colNumber];
    }
    return sum;
}

void PrintMatrix(int arr[3][3])
{
    cout << "\nHere is A Matrix 3 x 3 With Random Numbers :" << endl;
    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            cout << arr[row][col] << "\t";
        }
        cout << endl;
    }
}

void PrintSumColMatrix(int arr[3][3], int rows, int cols, int SumColArr[3])
{
    cout << "\nHere is The Sum of Cols Matrix:" << endl;
    for (short col = 0; col < cols; col++)
    {
        cout << setw(2) << "Col " << col + 1 << " Sum = " << SumColMatrix(arr, col, rows) << endl;
    }
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("The Sum of Cols Matrix");

    int arr[3][3], SumColArr[3];
    FillMatrixWithNumbers(arr, 3, 3);
    PrintMatrix(arr);
    PrintSumColMatrix(arr, 3, 3, SumColArr);
    return 0;
}
