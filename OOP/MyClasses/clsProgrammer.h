#pragma once
#include <iostream>;
#include "clsEmployee.h";
using namespace std;
class clsProgrammer : public clsEmployee
{
private:
    string _main_PL;

public:
    clsProgrammer(int ID, string first__Name, string last__Name, string title, string email, string phone, float salary, string department, string main_PL) : clsEmployee(ID, first__Name, last__Name, title, email, phone, salary, department)
    {
        _main_PL = main_PL;
    }

    // Set Property
    void setMainPL(string main_PL)
    {
        _main_PL = main_PL;
    }
    // Get Property
    string getMainPL()
    {
        return _main_PL;
    }

    // Methods
    void print()
    {
        cout << "\nInfo:\n";
        cout << setfill('_') << setw(30) << "" << endl;
        cout << "\nID                        : " << getID() << endl;
        cout << "\nFirst Name                : " << getFirstName() << endl;
        cout << "\nLast Name                 : " << getLastName() << endl;
        cout << "\nFull Name                 : " << getFullName() << endl;
        cout << "\nEmail                     : " << getEmail() << endl;
        cout << "\nPhone                     : " << getPhone() << endl;
        cout << "\nTitle                     : " << getTitle() << endl;
        cout << "\nSalary                    : " << getSalary() << endl;
        cout << "\nDepartment                : " << getDepartment() << endl;
        cout << "\nMain Programming Language : " << _main_PL << endl;
        cout << setfill('_') << setw(30) << "" << endl;
    }
};
