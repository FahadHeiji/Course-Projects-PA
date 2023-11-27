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

short SumRowMatrix(int arr[3][3], int rowNumber, int cols)
{
    short sum = 0;
    for (short col = 0; col < cols; col++)
    {
        sum = sum + arr[rowNumber][col];
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

void PrintSumRowMatrix(int arr[3][3], int rows, int cols)
{
    cout << "\nHere is The Sum of Rows Matrix:" << endl;
    for (short row = 0; row < rows; row++)
    {
        cout << setw(2) << "Row " << row + 1 << " Sum = " << SumRowMatrix(arr, row, cols) << endl;
    }
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("The Sum of Rows Matrix");

    int arr[3][3], SumRowArr[3];
    FillMatrixWithNumbers(arr, 3, 3);
    PrintMatrix(arr);
    PrintSumRowMatrix(arr, 3, 3);
    return 0;
}