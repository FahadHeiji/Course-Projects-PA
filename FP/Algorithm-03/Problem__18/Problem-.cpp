#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
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
bool checkNumberInVector(vector<int> &result, int Number)
{
    if (result.empty())
        return 1;
    for (int i : result)
    {

        if (i == Number)
            return 0;
    }

    return 1;
}
void check2Matrix(int arr[3][3], int arr_02[3][3], vector<int> &result)
{

    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            if (checkNumberInMatrix(arr_02, arr[row][col]) && checkNumberInVector(result, arr[row][col]))
            {
                result.push_back(arr[row][col]);
            }
        }
    }
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("Check Intersected In 2 Matrix");
    int Matrix[3][3], Matrix_2[3][3];
    vector<int> inter;
    FillMatrixWithNumbers(Matrix, 3, 3);
    FillMatrixWithNumbers(Matrix_2, 3, 3);
    cout << "\nHere is Matrix [1] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(Matrix);
    cout << "\nHere is Matrix [2] 3 x 3 With Random Numbers :" << endl;
    PrintMatrix(Matrix_2);
    check2Matrix(Matrix, Matrix_2, inter);
    cout << "\nHere is The Intersected Numbers in 2 Matrix :" << endl;
    for (int i : inter)
    {
        cout << i << "\t";
    }

    return 0;
}