#include <iostream>
#include <fstream>
using namespace std;
struct stEmplyee
{
    string Name;
    float Salary;
};
int main()
{

    fstream Myfile;
    Myfile.open("File.txt", ios::out);
    if(Myfile.is_open())
    {
        Myfile << "Hi There,\n";
        Myfile << "\tIt\'s me.";
        Myfile.close();
    }
    return 0;
}