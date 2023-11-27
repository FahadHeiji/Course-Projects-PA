
#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

void FillMatrixWithNumbers(int arr[3][3], int rows, int cols)
{
    int counter = 1;
    for (short row = 0; row < rows; row++)
    {
        for (short col = 0; col < cols; col++)
        {
            arr[row][col] = counter;
            counter++;
        }
    }
}

void FillTRMatrix(int arr[3][3], int TRArr[3][3], int rows, int cols)
{

    for (short row = 0; row < rows; row++)
    {
        for (short col = 0; col < cols; col++)
        {
            TRArr[row][col] = arr[col][row];
        }
        cout << endl;
    }
}

void PrintMatrix(int arr[3][3])
{
    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            cout << arr[row][col] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("Fill Matrix With Ordered NUmbers & Transposed Matrix");

    int arr[3][3], TRArr[3][3];
    FillMatrixWithNumbers(arr, 3, 3);
    FillTRMatrix(arr, TRArr, 3, 3);
    cout << "\nHere is A Matrix 3 x 3 With Orderd Numbers :" << endl;
    PrintMatrix(arr);
    cout << "\nHere is A Transposed Matrix 3 x 3 :" << endl;
    PrintMatrix(TRArr);
    return 0;
}