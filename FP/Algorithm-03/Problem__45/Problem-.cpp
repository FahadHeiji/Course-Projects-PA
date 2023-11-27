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

stClient addClient()
{
    stClient client;

    cout << "Please Enter Account Number: " << endl;
    getline(cin, client.accountNumber);
    cout << "Please Enter The Pin-Code: " << endl;
    getline(cin, client.pinCode);
    cout << "Please Enter Account Name: " << endl;
    getline(cin, client.fullName);
    cout << "Please Enter Phone Number: " << endl;
    getline(cin, client.phone);
    cout << "Please Enter Account Balnce: " << endl;
    cin >> client.accountBlance;
    cin.ignore();

    return client;
}

string ConvertRecordeToLine(stClient &client, string dlim = "#//#")
{
    string S1;
    S1 += client.accountNumber + dlim;
    S1 += client.pinCode + dlim;
    S1 += client.fullName + dlim;
    S1 += client.phone + dlim;
    S1 += to_string(client.accountBlance);

    return S1;
}
int main()
{
    Layout::setProgramHeader("Add Client Data!");
    stClient client;
    client = addClient();
    cout << ConvertRecordeToLine(client);
    return 0;
}