#include <iostream>
#include "../../My_Libraries/Layout.h"
using namespace std;
void Function1(int N, int M)
{
    if (M >= N)
    {
        cout << M << endl;
        Function1(N, M - 1);
    }
}

int main()
{
    Layout::setProgramHeader("Recursion HW");
    Function1(1, 10);
    return 0;
}