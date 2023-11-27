#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
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

    cout << "| " << left << setw(15) << client.accountNumber;

    cout << "| " << left << setw(10) << client.pinCode;

    cout << "| " << left << setw(40) << client.fullName;

    cout << "| " << left << setw(12) << client.phone;
    cout << "| " << left << setw(12) << client.accountBlance << endl;
}

vector<stClient> getClientFromFile()
{
    vector<stClient> vClient;

    fstream file;
    file.open("Clients-Data.txt", ios::in);
    if (file)
    {
        string line;
        while (getline(file, line))
        {
            stClient Client;
            Client = ConvertlineToRecorde(line);
            vClient.push_back(Client);
        }
    }

    return vClient;
}
void tableHeader(short numberOfClients)
{
    cout << "\n\t\t\t\t\tClient List (" << numberOfClients << ") Client(s).";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
    cout << "| " << left << setw(15) << "Accout Number";
    cout << "| " << left << setw(10) << "Pin Code";
    cout << "| " << left << setw(40) << "Client Name";
    cout << "| " << left << setw(12) << "Phone";
    cout << "| " << left << setw(12) << "Balance";
    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}
void PrintClients()
{
    vector<stClient> vClient = getClientFromFile();
    tableHeader(vClient.size());
    for (short i = 0; i < vClient.size(); i++)
    {
        PrintClient(vClient[i]);
    }

    cout << "\n_______________________________________________________";
    cout << "_________________________________________\n"
         << endl;
}
int main()
{
    Layout::setProgramHeader("Add Client Data!");
    PrintClients();
    return 0;
}