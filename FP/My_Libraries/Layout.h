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

    void Header(string title, char Delim = '=')
    {

        for (int i = 0; i < title.length() + 30; i++)
        {
            cout << Delim;
        }
        cout << "\n\n\t\t" << title << "\n\n";
        for (int i = 0; i < title.length() + 30; i++)
        {
            cout << Delim;
        }
        cout << "\n\n";
    }

    void Section(string title)
    {

        cout << "\t" << title << "\t\n";
    }

    void Border(char di)
    {
        cout << "\n";
        for (int i = 0; i < 39; i++)
        {
            cout << di;
        }
        cout << "\n";
    }
}