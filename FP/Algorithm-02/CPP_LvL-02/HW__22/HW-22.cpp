#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
using namespace std;

short fillArr(short arr[10][10])
{
    for (short row = 1; row <= 10; row++)
    {
        for (short col = 1; col <= 10; col++)
        {
            arr[row - 1][col - 1] = row * col;
        }
    }

    return arr[10][10];
}
void prshortMultiplayTable()
{
    short mulArr[10][10];

    fillArr(mulArr);

    for (short row = 0; row < 10; row++)
    {
        for (short col = 0; col < 10; col++)
        {
            // if (mulArr[row][col] < 10)
            // {
            //     printf("%0*d ", 2, mulArr[row][col]);
            // }
            // else
            //     printf("%d ", mulArr[row][col]);
            printf("%0*d ", 2, mulArr[row][col]); // Correct Answer
        }
        cout << "\n";
    }
}

int main()
{
    Layout::setProgramHeader("Prshort Multiplay Table Using 2D Array");
    prshortMultiplayTable();
}
