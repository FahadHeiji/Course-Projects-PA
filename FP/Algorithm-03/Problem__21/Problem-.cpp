#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

void FillVectorWithFibonacciNumbers(vector<int> &vFibon, short ofNumber)
{
    vFibon = {1, 1};
    short sum = 0;
    for (short i = 0; i < ofNumber - 2; i++)
    {
        sum = vFibon[i] + vFibon[i + 1];
        vFibon.push_back(sum);
    }
}

void PrintVector(vector<int> &vFibon)
{

    for (int &number : vFibon)
    {

        cout << setw(4);
        printf("%d\t", number);
    }
}

int main()
{
    Layout::setProgramHeader("Fibonacci Series Using Vector");
    vector<int> vFibon;
    FillVectorWithFibonacciNumbers(vFibon, 10);
    PrintVector(vFibon);
    return 0;
}