#include <iostream>
#include <vector>
#include "../../My_Libraries/Layout.h"
using namespace std;

int main()
{
    vector<double> vNum = {1, 100, 100000, 10000000000, 100000000, 10000003324};
    cout << "Numbers of Vector = ";
    for (double& Num : vNum) // by using & it will be much Faster
    {
        cout << Num << " ";
    }
    cout << endl;

    return 0;
}
