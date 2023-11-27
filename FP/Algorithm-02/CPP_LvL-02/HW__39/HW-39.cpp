#include <iostream>
using namespace std;

int main()
{
    int arr[5] = {1, 2, 3, 4, 8};
    int *ptr = arr;
    cout << ptr << endl;
    for (int i = 1; i < 5; i++)
    {
        cout << ptr + i << endl;
    }
    cout << *(ptr) << endl;
    for (int i = 1; i < 5; i++)
    {
        cout << *(ptr + i) << endl;
    }
    return 0;
}
