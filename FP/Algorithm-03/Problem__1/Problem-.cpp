#include <iostream>
#include <string>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

void FillMatrixWithNumbers(int arr[3][3])
{
    for (short row = 0; row < 3; row++)
    {
        for (short col = 0; col < 3; col++)
        {
            arr[row][col] = Functions::RandomNumber(1, 100);
        }
    }
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
};

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    Layout::setProgramHeader("A Matrix 3 x 3 With Random Numbers");

    int arr[3][3];
    FillMatrixWithNumbers(arr);
    PrintMatrix(arr);
    return 0;
}
