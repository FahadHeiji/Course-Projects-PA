#pragma once
#include <iostream>;

using namespace std;

class clsPlayer
{
private:
    string _Name;
    string _Club;
    // inner class
    class clsAddress
    {
    private:
        string _Address01;
        string _Address02;
        string _City;
        string _Country;

    public:
        clsAddress(string Address01, string Address02, string City, string Country)
        {
            _Address01 = Address01;
            _Address02 = Address02;
            _City = City;
            _Country = Country;
        }
        void setAddress01(string Address01)
        {
            _Address01 = Address01;
        }
        void setAddress02(string Address02)
        {
            _Address02 = Address02;
        }
        void setCity(string City)
        {
            _City = City;
        }
        void setCountry(string Country)
        {
            _Country = Country;
        }
        string getAddress01(string Address01)
        {
            return _Address01 = Address01;
        }
        string getAddress02(string Address02)
        {
            return _Address02 = Address02;
        }
        string getCity(string City)
        {
            return _City = City;
        }
        string getCountry(string Country)
        {
            return _Country = Country;
        }
        void PPrint()
        {
            cout << "\nAddress: \n";
            cout << _Address01 << endl;
            cout << _Address02 << endl;
            cout << _City << endl;
            cout << _Country << endl;
        }
    };

public:
    clsAddress Address = clsAddress("", "", "", "");
    clsPlayer(string FullName, string Club, string Adress01, string Adress02, string City, string Country)
    {
        _Name = FullName;
        _Club = Club;
        Address = clsAddress(Adress01, Adress02, City, Country);
    }
};
