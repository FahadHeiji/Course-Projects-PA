#include <iostream>
#include <cmath>
#include "..\..\My_Libraries/Layout.h"
using namespace std;
// int Function1(int N, int M)
// {

//     int Total = N;
//     if (M > 1)
//     {
//         Total *=  Function1(N, M - 1);
//     }
//     return Total;
// }

int Function1(int Base, int Power)
{

    if (Power == 0)
        return 1;
    else
    {
        return (Base * Function1(Base, Power - 1));
    }
}

int main()
{
    Layout::setProgramHeader("Recursion HW");
    cout << Function1(2, 8) << endl;
    cout << pow(2, 8);
    return 0;
}