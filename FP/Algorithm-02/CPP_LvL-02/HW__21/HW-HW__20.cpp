#include <iostream>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
using namespace std;

void setTableHeader3x3(string arr[9])
{
    short total_length = arr[0].length() *2+2+
                         arr[1].length() *2+2+
                         arr[2].length()*2+1;

    for (int i = 0; i <= total_length; i++)
    {
        cout << "_";
    }
    cout << "\n";
    for (size_t i = 0; i < 3; i++)
    {

        cout << "| " << setw(arr[i].length()) << arr[i] << "\t";
    }

    cout << " |\n";
    for (int i = 0; i <= total_length; i++)
    {
        cout << "_";
    }
}

int main()
{
    string arr[9] = {"Code", "Course", "Mark"};
    Layout::setProgramHeader("setw Format");
    setTableHeader3x3(arr);
    return 0;
}