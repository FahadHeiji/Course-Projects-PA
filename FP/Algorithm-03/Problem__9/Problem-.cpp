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

void PrintMidRowMatrix(int arr[3][3], int rows, int cols)
{
    short midRow = rows / 2;
    for (short col = 0; col < cols; col++)
    {
        cout << setw(4);
        printf("%0*d\t", 2, arr[midRow][col]);
    }
    cout << endl;
}
void PrintMidColMatrix(int arr[3][3], int rows, int cols)
{
    short midCol = cols / 2;
    for (short row = 0; row < rows; row++)
    {
        cout << setw(4);
        printf("%0*d\t", 2, arr[row][midCol]);
    }
    cout << endl;
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


int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("The Midll Row/Col Of the A Matrix");

    int Matrix[3][3];
    FillMatrixWithNumbers(Matrix, 3, 3);
    cout << "\nHere is Matrix [1] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(Matrix);
    cout << "\nHere is Matrix Mid Row :" << endl;
    PrintMidRowMatrix(Matrix, 3, 3);
    cout << "\nHere is Matrix Mid Col :" << endl;
    PrintMidColMatrix(Matrix, 3, 3);
    return 0;
}