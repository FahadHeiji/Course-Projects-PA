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

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("The Sum of Two Matries");

    int Matrix[3][3];
    FillMatrixWithNumbers(Matrix, 3, 3);
    cout << "\nHere is Matrix [1] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(Matrix);
    cout << "\nHere is The Sum Of Matrix Elements  : " << sumMatrixElements(Matrix) << endl;

    return 0;
}