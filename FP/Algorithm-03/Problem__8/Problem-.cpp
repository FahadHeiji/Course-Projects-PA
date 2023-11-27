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
void MUlTwoMatrix(int arr_01[3][3], int arr_02[3][3], int result[3][3], int rows, int cols)
{
    for (short row = 0; row < rows; row++)
    {
        for (short col = 0; col < cols; col++)
        {
            result[row][col] = arr_01[row][col] * arr_02[row][col];
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
            printf("%0*d\t",  2, arr[row][col]);
        }
        cout << endl;
    }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("The Mul of Two Matries");

    int arr_01[3][3], arr_02[3][3], result[3][3];
    FillMatrixWithNumbers(arr_01, 3, 3);
    FillMatrixWithNumbers(arr_02, 3, 3);
    MUlTwoMatrix(arr_01, arr_02, result, 3, 3);
    cout << "\nHere is Matrix [1] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(arr_01);
    cout << "\nHere is Matrix [2] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(arr_02);
    cout << "\nHere is Result Matrix 3 x 3 :" << endl;
    PrintMatrix(result);
    return 0;
}