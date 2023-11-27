#include <string>
#include <vector>
#include <iostream>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

struct stClient
{
    string fullName, accountNumber, pinCode, phone;
    double accountBlance;
};

vector<string> Split(string S1, string delim = " ")
{
    vector<string> vSplit;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != std::string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vSplit.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vSplit.push_back(S1);
    }
    return vSplit;
}

stClient ConvertlineToRecorde(string Line, string dlim = "#//#")
{
    vector<string> vRecorde = Split(Line, dlim);
    stClient client;
    client.accountNumber = vRecorde[0];
    client.pinCode = vRecorde[1];
    client.fullName = vRecorde[2];
    client.phone = vRecorde[3];
    client.accountBlance = stod(vRecorde[4]);

    return client;
}
void PrintClient(stClient &client)
{
    cout << "\nAccount Number: ";
    cout << client.accountNumber << endl;
    cout << "\nThe Pin-Code: ";
    cout << client.pinCode << endl;
    cout << "\nAccount Name: ";
    cout << client.fullName << endl;
    cout << "\nPhone Number: ";
    cout << client.phone << endl;
    cout << "\nAccount Balnce: ";
    cout << client.accountBlance << endl;
}
int main()
{
    Layout::setProgramHeader("Add Client Data!");
    string S1 = "A456#//#1177#//#Fahad Mohamed#//#996924787#//#500.5";
    cout << "\n"
         << S1 << endl;

    stClient client = ConvertlineToRecorde(S1, "#//#");
    cout << "\nAfter Converting: \n";
    PrintClient(client);

    return 0;
}