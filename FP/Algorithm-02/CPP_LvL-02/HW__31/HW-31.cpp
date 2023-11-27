#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vNum;
    int a = 10;
    int * x = &a;
    vNum.push_back(10);
    vNum.push_back(20);
    vNum.push_back(30);
    vNum.push_back(40);
    cout << "a = " << a << endl;
    cout << "x = " << x << endl;
    cout << "First Stack = " << vNum.front() << endl;
    cout << "Last Stack = " << vNum.back() << endl;
    cout << "Size Stack = " << vNum.size() << endl;
    cout << "Capacity Stack = " << vNum.capacity() << endl;
    cout << "Empty Stack = " << vNum.empty() << endl;
    cout << "VNumber : " << endl;
    for (int &number : vNum)
    {
        cout << number << endl;
    }
    vNum.clear();
    cout << "Size Stack = " << vNum.size() << endl;
    return 0;
}
