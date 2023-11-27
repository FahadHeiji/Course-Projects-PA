#include <iostream>
#include <fstream>
using namespace std;
struct stEmplyee
{
    string Name;
    float Salary;
};

void readFiles(string FilePath)
{
    fstream Myfile;
    Myfile.open(FilePath, ios::in);
    if (Myfile.is_open())
    {
        string line;
        while (getline(Myfile, line))
        {
            cout << line << endl;
        }

        Myfile.close();
    }
}
int main()
{
    readFiles("File.txt");
    return 0;
}

// #include <ctime>
// #include <iostream>
// using namespace std;
// int main()
// {
//     time_t t = time(0);   // get time now
//     char *dt = ctime(&t); // convert in string form
//     cout << "Local date and time is: " << dt << "\n";
//     tm *gmtm = gmtime(&t); // converting now to tm struct for UTC date/time
//     dt = asctime(gmtm);
//     cout << "UTC date and time is: " << dt;
// }