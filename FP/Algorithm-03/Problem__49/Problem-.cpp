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

vector<stClient> getClientFromFile()
{
    vector<stClient> vClient;

    fstream file;
    file.open("Clients-Data.txt", ios::in);
    if (file)
    {
        string line;
        stClient Client;
        while (getline(file, line))
        {
            Client = ConvertlineToRecorde(line);
            vClient.push_back(Client);
        }
    }

    return vClient;
}

void PrintClient(stClient &client)
{
    cout << "\nThe Follwing Are Client Details: \n\n";
    cout << "Account Number: ";
    cout << client.accountNumber << endl;
    cout << "The Pin-Code: ";
    cout << client.pinCode << endl;
    cout << "Account Name: ";
    cout << client.fullName << endl;
    cout << "Phone Number: ";
    cout << client.phone << endl;
    cout << "Account Balnce: ";
    cout << client.accountBlance << endl;
}

bool iExists(stClient Client, string accNumber)
{
    if (Client.accountNumber == accNumber)
        return 1;
    else
    {
        cout << "Client With Account Number (" << accNumber << ") NOT Found!.\n";
        return 0;
    }
}

void PrintClients()
{
    vector<stClient> vClient = getClientFromFile();
    string AccountNumber = Functions::ReadString("Please Enter The Account Number?");
    for (stClient &Client : vClient)
    {
        if (Client.accountNumber == AccountNumber)
            return PrintClient(Client);
        else
            cout << "Client With Account Number (" << AccountNumber << ") NOT Found!.\n";
    }
}
int main()
{
    Layout::setProgramHeader("Search Client Data By Account Number!");
    PrintClients();
    return 0;
}