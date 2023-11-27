#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

void PrintFibonacciUsingRE(int number, int per01, int per02)
{
    int fibNumber = 0;
    if (number > 0)
    {
        fibNumber = per02 + per01;
        cout << fibNumber << " ";
        per02 = per01;
        per01 = fibNumber;
        PrintFibonacciUsingRE(number - 1, per01, per02);
    }
}
int main()
{
    Layout::setProgramHeader("Fibonacci Series Using recurtion");
    PrintFibonacciUsingRE(10, 0, 1);
    return 0;
}