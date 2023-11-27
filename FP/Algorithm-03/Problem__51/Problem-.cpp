#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;
const string Path = "Clients-Data.txt";
struct stClient
{
    string accountNumber, accountName, pinCode, phone;
    double accountBalance;
    bool markForupdate = false;
};
vector<string> splitString(string S1, string delim)
{
    vector<string> vString;
    short pos = 0;
    string sWord;
    while ((pos = S1.find(delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }
    return vString;
}
stClient convertLineToRecord(string line, string seperator = "#//#")
{
    stClient client;
    vector<string> vClientData;
    vClientData = splitString(line, seperator);
    client.accountNumber = vClientData[0];
    client.pinCode = vClientData[1];
    client.accountName = vClientData[2];
    client.phone = vClientData[3];
    client.accountBalance = stod(vClientData[4]);
    return client;
}
vector<stClient> loadClientsDataFromFile(string fileName)
{
    vector<stClient> vClient;
    fstream file;
    file.open(fileName, ios::in);
    if (file.is_open())
    {
        string line;
        stClient client;
        while (getline(file, line))
        {
            client = convertLineToRecord(line);
            vClient.push_back(client);
        }
        file.close();
    }
    return vClient;
}
bool findClientByAccountNumber(string accountNumber, vector<stClient> vClient, stClient &cleint)
{
    for (stClient C : vClient)
    {
        if (C, accountNumber == accountNumber)
        {
            cleint = C;
            return 1;
        }
    }
    return 0;
}
void printClientCard(stClient cleint)
{
    cout << "\nThis Following Are The Client Detalis:\n";
    cout << "\nAccount PIN Code : " << cleint.accountNumber;
    cout << "\nAccount Number : " << cleint.pinCode;
    cout << "\nAccount Name : " << cleint.accountName;
    cout << "\nAccount Phone : " << cleint.phone;
    cout << "\nAccount Balance : " << cleint.accountBalance;
}

string convertRecordToLine(stClient client, string Seperator = "#//#")
{
    string stClientRecord = "";
    stClientRecord += client.accountNumber + Seperator;
    stClientRecord += client.pinCode + Seperator;
    stClientRecord += client.accountName + Seperator;
    stClientRecord += client.phone + Seperator;
    stClientRecord += to_string(client.accountBalance) + Seperator;
    return stClientRecord;
}

bool markCleintforupdateByAccountNumber(string accountNumber, vector<stClient> &vClient)
{
    for (stClient &C : vClient)
    {
        if (C.accountNumber == accountNumber)
        {
            C.markForupdate = true;
            return 1;
        }
    }
    return 0;
}
vector<stClient> saveCleintDataToFile(string path, vector<stClient> vClient, stClient client)
{
    fstream file;
    file.open(path, ios::out);
    string dataLine;

    if (file.is_open())
    {
        for (stClient C : vClient)
        {
            if (C.markForupdate == false)
            {
                dataLine = convertRecordToLine(C);
                file << dataLine << endl;
            }
            else
            {
                dataLine = convertRecordToLine(client);
                file << dataLine << endl;
            }
        }
        file.close();
    }
    return vClient;
}
stClient addClient()
{
    stClient client;
    cout << "Please Enter The Pin-Code: " << endl;
    getline(cin >> ws, client.pinCode);
    cout << "Please Enter Account Name: " << endl;
    getline(cin, client.accountName);
    cout << "Please Enter Phone Number: " << endl;
    getline(cin, client.phone);
    cout << "Please Enter Account Balnce: " << endl;
    cin >> client.accountBalance;
    cin.ignore();

    return client;
}
stClient updateClient(stClient &cleint, string accountNumber)
{
    cleint = addClient();
    cleint.accountNumber = accountNumber;
    return cleint;
}
bool updateClientByAccountNumber(string accountNumber, vector<stClient> &vClient)
{
    stClient cleint;
    char answer = 'n';
    if (findClientByAccountNumber(accountNumber, vClient, cleint))
    {
        printClientCard(cleint);
        cout << "\n\nAre You Sure You Want To Update This Cleint? [y/n]\n";
        cin >> answer;
        if (toupper(answer) == 'Y')
        {
            markCleintforupdateByAccountNumber(accountNumber, vClient);
            updateClient(cleint, accountNumber);
            saveCleintDataToFile(Path, vClient, cleint);
            vClient = loadClientsDataFromFile(Path);
            cout << "\n\nClient Updated Successfully.";
            return 1;
        }
    }
    else
    {
        cout << "\nClient with Account Number(" << accountNumber << ") is NOT Found!";
        return 0;
    }
    return 0;
}

int main()
{
    Layout::setProgramHeader("Update Cleint By Account Number");
    vector<stClient> vClient = loadClientsDataFromFile(Path);
    string accountNumbeer = Functions::ReadString("Please Enter Account Number : ");
    updateClientByAccountNumber(accountNumbeer, vClient);
    return 0;
}
