#include <iostream>
#include <iomanip>

using namespace std;

class clsEmployee
{
private:
    int _ID;
    string _first__Name;
    string _last__Name;
    string _title;
    string _email;
    string _phone;
    float _salary;
    string _department;

public:
    clsEmployee(int ID, string first__Name, string last__Name, string title, string email, string phone, float salary, string department)
    {
        _ID = ID;
        _first__Name = first__Name;
        _last__Name = last__Name;
        _title = title;
        _email = email;
        _phone = phone;
        _salary = salary;
        _department = department;
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
    void setTitle(string title)
    {
        _title = title;
    }
    void setEmail(string email)
    {
        _email = email;
    }
    void setPhone(string phone)
    {
        _phone = phone;
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
    string setTitle()
    {
        return _title;
    }
    string getEmail()
    {
        return _email;
    }
    string getPhone()
    {
        return _phone;
    }
    float getSalary()
    {
        return _salary;
    }
    string getDepartment()
    {
        return _department;
    }

    // Methods:
    void print()
    {
        cout << "\nInfo:\n";
        cout << setfill('_') << setw(30) << "" << endl;
        cout << "\nID : " << getID() << endl;
        cout << "\nFirst Name : " << _first__Name << endl;
        cout << "\nLast Name : " << _last__Name << endl;
        cout << "\nFull Name : " << getFullName() << endl;
        cout << "\nTitle: " << _title << endl;
        cout << "\nEmail: " << _email << endl;
        cout << "\nPhone : " << _phone << endl;
        cout << "\nSalary : " << _salary << endl;
        cout << "\nDepartment : " << _department << endl;
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
};

int main()
{
    clsEmployee Employee01(7, "Fahad", "Heiji", "Software Engineer", "HeijiDev@gmail.com", "0996924787", 125000, "Back-End");
    Employee01.print();
    Employee01.sendEmail("Movie 26", "Is Already There");
    Employee01.sendSMS("OOKiNi");
    return 0;
}