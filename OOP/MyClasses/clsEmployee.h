#pragma once
#include <iostream>;
#include "clsPerson.h";
using namespace std;

class clsEmployee : public clsPerson
{
private:
    string _title;
    float _salary;
    string _department;
    // Struct
    struct stAddress
    {
        string __Address01;
        string __Address02;
        string __City;
        string __Country;
    };

public:
    clsEmployee(int ID, string first__Name, string last__Name, string title, string email, string phone, float salary, string department) : clsPerson(ID, first__Name, last__Name, email, phone)
    {
        _title = title;
        _salary = salary;
        _department = department;
    }

    // Set Property
    void setTitle(string title)
    {
        _title = title;
    }
    void setSalary(float salary)
    {
        _salary = salary;
    }
    void setDepartment(string department)
    {
        _department = department;
    }
    // Get Property
    string getTitle()
    {
        return _title;
    }
    float getSalary()
    {
        return _salary;
    }
    string getDepartment()
    {
        return _department;
    }

    void print()
    {
        cout << "\nInfo:\n";
        cout << setfill('_') << setw(30) << "" << endl;
        cout << "\nID         :" << getID() << endl;
        cout << "\nFirst Name : " << getFirstName() << endl;
        cout << "\nLast Name  : " << getLastName() << endl;
        cout << "\nFull Name  : " << getFullName() << endl;
        cout << "\nEmail      : " << getEmail() << endl;
        cout << "\nPhone      : " << getPhone() << endl;
        cout << "\nTitle      : " << _title << endl;
        cout << "\nSalary     : " << _salary << endl;
        cout << "\nDepartment : " << _department << endl;
        cout << setfill('_') << setw(30) << "" << endl;
    }

    // friend method
    void friendd(clsPerson P)
    {
        cout << P._ID << endl;
    }

    // friend Function
    friend string fullNAme(clsEmployee E);

    // struct method
    void stFun()
    {
        stAddress Addresss;
        Addresss.__Address01 = "GG";
        Addresss.__Address02 = "AA";
        Addresss.__City = "GG";
        Addresss.__Country = "AA";

        cout << "\nAddress: " << endl;
        cout << Addresss.__Address01 << endl;
        cout << Addresss.__Address02 << endl;
        cout << Addresss.__City << endl;
        cout << Addresss.__Country << endl;
    }
};
