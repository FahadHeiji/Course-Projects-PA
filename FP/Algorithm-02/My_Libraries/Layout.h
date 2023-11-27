#pragma once
#include <iostream>
using namespace std;

namespace Layout
{
    void setProgramHeader(string title)
    {
        cout << "\n\t\t\t\t \n\n\t\t\t";
        for (int i = 0; i < title.length() + 18; i++)
        {
            cout << "-";
        }
        cout << "\n\n\t\t\t\t" << title << "\n\n\t\t\t";
        for (int i = 0; i < title.length() + 18; i++)
        {
            cout << "-";
        }
        cout << "\n\n";
    }
}