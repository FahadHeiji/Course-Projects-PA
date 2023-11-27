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
            printf("%0*d\t", 2, arr[row][col]);
        }
        cout << endl;
    }
}

int sumMatrixElements(int arr[3][3])
{
    short sum = 0;
    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            sum = sum + arr[row][col];
        }
    }
    return sum;
}

bool isEqual(int arr[3][3], int arr2[3][3])
{
    return (sumMatrixElements(arr) == sumMatrixElements(arr2));
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("Check The Sum Of Two Matries");

    int Matrix1[3][3], Matrix2[3][3];
    FillMatrixWithNumbers(Matrix1, 3, 3);
    FillMatrixWithNumbers(Matrix2, 3, 3);
    cout << "\nHere is Matrix [1] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(Matrix1);
    cout << "\nHere is The Sum Of Matrix [1] Elements  : " << sumMatrixElements(Matrix1) << endl;
    cout << "\nHere is Matrix [2] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(Matrix2);
    cout << "\nHere is The Sum Of Matrix [2] Elements  : " << sumMatrixElements(Matrix2) << endl;
    if (isEqual(Matrix1, Matrix2))
        cout << "Yes: Matrieces Are Equal.\n";
    else
        cout << "No: Matrieces Are NOT Equal.\n";
    return 0;
}