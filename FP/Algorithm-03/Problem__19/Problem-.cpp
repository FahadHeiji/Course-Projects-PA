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

int minNumInMatrix(int arr[3][3])
{
    short min = 0;
    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            if (arr[row][col] <= min || min == 0)
                min = arr[row][col];
        }
    }

    return min;
}
int MaxNumInMatrix(int arr[3][3])
{
    short max = 0;
    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            if (arr[row][col] >= max)
                max = arr[row][col];
        }
    }

    return max;
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("Check Min & Max Number In Matrix");
    int Matrix[3][3];
    FillMatrixWithNumbers(Matrix, 3, 3);
    cout << "\nHere is Matrix [1] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(Matrix);

    cout << "\nHere is The Min Numbers in  Matrix : " << minNumInMatrix(Matrix) << endl;
    cout << "\nHere is The Max Numbers in  Matrix : " << MaxNumInMatrix(Matrix) << endl;

    return 0;
}