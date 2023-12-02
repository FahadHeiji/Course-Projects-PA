#pragma once
#include <iostream>;
#include <iomanip>;
using namespace std;

class clsPerson
{
private:
    int _ID;
    string _first__Name;
    string _last__Name;

    string _email;
    string _phone;

public:
    clsPerson(){};
    clsPerson(int ID, string first__Name, string last__Name, string email, string phone)
    {
        _ID = ID;
        _first__Name = first__Name;
        _last__Name = last__Name;
        _email = email;
        _phone = phone;
    }

    // Set Property
    void setFirstName(string first__Name)
    {
        _first__Name = first__Name;
    }
    void setLastName(string last__Name)
    {
        _last__Name = last__Name;
    }
    void setEmail(string email)
    {
        _email = email;
    }
    void setPhone(string phone)
    {
        _phone = phone;
    }

    // Get Property
    int getID()
    {
        return _ID;
    }
    string getFirstName()
    {
        return _first__Name;
    }
    string getLastName()
    {
        return _last__Name;
    }
    string getFullName()
    {
        return _first__Name + " " + _last__Name;
    }
    string getEmail()
    {
        return _email;
    }
    string getPhone()
    {
        return _phone;
    }

    // Methods:
    // Virtual Function;
    virtual void print()
    {
        cout << "\nInfo:\n";
        cout << setfill('_') << setw(30) << "" << endl;
        cout << "\nID : " << getID() << endl;
        cout << "\nFirst Name : " << _first__Name << endl;
        cout << "\nLast Name : " << _last__Name << endl;
        cout << "\nFull Name : " << getFullName() << endl;
        cout << "\nEmail: " << _email << endl;
        cout << "\nPhone : " << _phone << endl;
        cout << setfill('_') << setw(30) << "" << endl;
    }

    void sendEmail(string subject, string body)
    {
        cout << setfill('-') << setw(30) << "" << endl;
        cout << "\nThe Following Message Sent Successfuly To Email: " << _email << endl;
        cout << "Subject: " << subject << endl;
        cout << "Body: " << body << endl;
        cout << setfill('-') << setw(30) << "" << endl;
    }
    void sendSMS(string text)
    {
        cout << setfill('*') << setw(30) << "" << endl;
        cout << "\nThe Following SMS Sent Successfuly To Phone: " << _phone << endl;
        cout << "Text: \n";
        cout << "\t" << text << "\n\n";
        cout << setfill('*') << setw(30) << "" << endl;
    }

    // Friend Class
    friend class clsEmployee;
};
