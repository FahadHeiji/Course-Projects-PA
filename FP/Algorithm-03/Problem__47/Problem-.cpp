#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

struct stClient
{
    string fullName, accountNumber, pinCode, phone;
    double accountBlance;
};

stClient MakeClient()
{
    stClient client;

    cout << "Please Enter Account Number: " << endl;
    getline(cin >> ws, client.accountNumber);
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

void addClientToFile(string cleint)
{
    fstream file;
    file.open("Clients-Data.txt", ios::app | ios::out);
    if (!file)
    {
        cout << "Error 404.";
    }
    file << cleint << endl;
    file.close();
}

void addClient()
{
    stClient client = MakeClient();
    addClientToFile(ConvertRecordeToLine(client));
}
void addClients()
{
    char addMore = 'A';
    do
    {
        system("cls");
        addClient();
        cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
        cin >> addMore;
    } while (toupper(addMore) == 'Y');
}
int main()
{
    Layout::setProgramHeader("Add Client Data To File!");
    addClients();
    return 0;
}