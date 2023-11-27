#include <string>
#include <windows.h>
#include <vector>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <limits>
#include "../My_Libraries/Layout.h"
#include "../My_Libraries/Functions.h"
using namespace std;

const string File__Path = "Clients-Data.txt";
void bank();
void Transactions();
enum MainOptions
{
    eShowClientList = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClientInfo = 4,
    eFindCleint = 5,
    eTransactions = 6,
    eExit = 7
};
enum TransactionsMainOptions
{
    eDeposit = 1,
    eWithdraw = 2,
    eTotalBalance = 3,
    eMainMenu = 4
};

struct stClient
{
    string Account__Number, Account__Name, PIN__Code, Phone;
    double Account__Balance;
    bool Mark__To__Delete = false;
};

vector<string> SplitString(string S1, string Delim = "#//#")
{
    vector<string> vString;
    string sWord;
    short pos = 0;
    while ((pos = S1.find(Delim)) != string::npos)
    {
        sWord = S1.substr(0, pos);
        if (sWord != "")
        {
            vString.push_back(sWord);
        }
        S1.erase(0, pos + Delim.length());
    }
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}
stClient ConvertLineToRecord(string Client__Data__line, string Sepretor = "#//#")
{
    stClient Client;
    vector<string> vClient = SplitString(Client__Data__line, Sepretor);

    Client.Account__Number = vClient[0];
    Client.PIN__Code = vClient[1];
    Client.Account__Name = vClient[2];
    Client.Phone = vClient[3];
    Client.Account__Balance = stod(vClient[4]);

    return Client;
}

vector<stClient> loadClientDataFromFile(string File__Path)
{
    fstream file;
    vector<stClient> vClient;
    file.open(File__Path, ios::in);
    if (file.is_open())
    {
        string Client__Data__line;
        stClient Client;
        while (getline(file, Client__Data__line))
        {
            Client = ConvertLineToRecord(Client__Data__line);
            vClient.push_back(Client);
        }
        file.close();
    }

    return vClient;
}

void ShowClientList()
{
    system("cls");
    system("color 17");
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    string Header = "Client List (" + to_string(vClient.size()) + ") Client(s).";
    cout << setfill(' ') << setw(51) << left << "\n\n\t\t\t\t" + Header;
    cout << "\n\n"
         << setfill('_') << setw(96) << "_";
    cout << "\n"
         << setfill(' ') << setw(18) << left << "\n| Account Number" << setw(12) << "| PIN-Code" << setw(40) << "| Account Name" << setw(14) << "| Phone" << setw(14) << "| Balance";
    cout << "\n"
         << setfill('_') << setw(98) << " \n";
    cout << "\n\n";

    for (stClient &Client : vClient)
    {
        cout << setfill(' ') << setw(17) << left << "| " + Client.Account__Number << setw(12) << left << "| " + Client.PIN__Code << setw(40) << left << "| " + Client.Account__Name << setw(14) << left << "| " + Client.Phone << setw(14) << left << "| " + to_string(Client.Account__Balance);
        cout << "\n";
    }
    cout << "\n";
    cout << setfill('_') << setw(97) << "_";
    cout << "\n\n";
}

bool checkAccountNumber(string Account__Number, vector<stClient> vClient, stClient &Client)
{
    for (stClient &C : vClient)
    {
        if (C.Account__Number == Account__Number)
        {
            Client = C;
            return 1;
        }
    }
    return 0;
}
string AddNewAccountNumber(vector<stClient> vClient)
{
    bool Added = 1;
    cout << "Add New Client:\n";
    string Account__Number;
    stClient Client;
    Account__Number = Functions::ReadString("Please Enter Account Number: ");

    do
    {
        if (checkAccountNumber(Account__Number, vClient, Client))
        {
            system("color 47");
            cout << "Client With [" << Account__Number << "] Already Exists, Enter another Account Number: " << endl;
            cin >> Account__Number;
        }
        else
        {
            system("color 57");
            Added = 0;
        }
    } while (Added);
    return Account__Number;
}
void addClient(string Account__Number, vector<stClient> &vClinet)
{
    stClient Client;

    Client.Account__Number = Account__Number;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This line ignores the leftover newline character in the buffer
    cout << "\nPlease Enter PIN-Code : " << endl;
    getline(cin, Client.PIN__Code);
    cout << "Please Enter Name : " << endl;
    getline(cin, Client.Account__Name);
    cout << "Please Enter Phone : " << endl;
    getline(cin, Client.Phone);
    cout << "Please Enter Account Balance : " << endl;
    cin >> Client.Account__Balance;

    vClinet.push_back(Client);
}

string ConvertRecordToLine(stClient Client, string Sepretor = "#//#")
{
    string S1 = "";

    S1 += Client.Account__Number + Sepretor;
    S1 += Client.PIN__Code + Sepretor;
    S1 += Client.Account__Name + Sepretor;
    S1 += Client.Phone + Sepretor;
    S1 += to_string(Client.Account__Balance);
    return S1;
}
void saveClientDataToFile(string File__Path, vector<stClient> vClient)
{
    fstream file;
    file.open(File__Path, ios::app);
    if (file.is_open())
    {
        string Client__Data__line;
        stClient Client = vClient[vClient.size() - 1];
        Client__Data__line = ConvertRecordToLine(Client);
        file << Client__Data__line << endl;
        file.close();
    }
}
void AddNewClient()
{
    system("cls");
    system("color 57");
    Layout::Header("Add New Client", '-');
    char Answer = 'n';
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    string Account__Number = AddNewAccountNumber(vClient);
    addClient(Account__Number, vClient);
    saveClientDataToFile(File__Path, vClient);
    system("color 20");
    cout << "\nClient Added Successfully, Do You Want Add More Clients? [y/n]";
    cin >> Answer;
    if (toupper(Answer) == 'Y')
        return AddNewClient();
}

bool MarkClinet(string Account__Number, vector<stClient> &vClient)
{
    for (stClient &C : vClient)
    {
        if (C.Account__Number == Account__Number)
        {
            C.Mark__To__Delete = true;
            return 1;
        }
    }
    return 0;
}

void DeleteClientDataFromFile(string File__Path, vector<stClient> vClient)
{
    fstream file;
    file.open(File__Path, ios::out);
    if (file.is_open())
    {
        string Client__Data__line;
        for (stClient &C : vClient)
        {
            if (C.Mark__To__Delete == false)
            {
                Client__Data__line = ConvertRecordToLine(C);
                file << Client__Data__line << endl;
            }
        }
        file.close();
    }
}

void PrintClientCard(stClient Client)
{
    cout << "The Following Are Clinet Details:\n";
    Layout::Border('-');
    cout << setfill(' ') << setw(17) << left << "Account Number"
         << ": " << Client.Account__Number << endl;
    cout << setfill(' ') << setw(17) << "PIN-Code "
         << ": " << Client.PIN__Code << endl;
    cout << setfill(' ') << setw(17) << "Account Name"
         << ": " << Client.Account__Name << endl;
    cout << setfill(' ') << setw(17) << "Phone "
         << ": " << Client.Phone << endl;
    cout << setfill(' ') << setw(17) << "Account Balance"
         << ": " << to_string(Client.Account__Balance) << endl;
    Layout::Border('-');
}
void DeleteClient()
{
    Layout::Header("Delete Client", '-');
    string Account__Number = Functions::ReadString("Please Enter Account Number: ");
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    stClient Client;
    char Answer = 'n';
    if (checkAccountNumber(Account__Number, vClient, Client))
    {
        system("color 70");
        PrintClientCard(Client);
        cout << "Are You Sure You Want To Delete This Client? [y/n]" << endl;
        cin >> Answer;
        cin.ignore();
        if (toupper(Answer) == 'Y')
        {
            system("color 80");
            MarkClinet(Account__Number, vClient);
            DeleteClientDataFromFile(File__Path, vClient);
            vClient = loadClientDataFromFile(File__Path);
            cout << "\n\nClient Deleted Successfully.";
        }
    }
    else
    {
        system("color 47");
        cout << "Client With [" << Account__Number << "] NOT Found!" << endl;
    }
}
stClient UpdateData(string Account__Number)
{
    stClient Client;

    Client.Account__Number = Account__Number;
    // cin.ignore(numeric_limits<streamsize>::max(), '\n'); // This line ignores the leftover newline character in the buffer
    cout << "\nPlease Enter PIN-Code : " << endl;
    getline(cin, Client.PIN__Code);
    cout << "Please Enter Name : " << endl;
    getline(cin, Client.Account__Name);
    cout << "Please Enter Phone : " << endl;
    getline(cin, Client.Phone);
    cout << "Please Enter Account Balance : " << endl;
    cin >> Client.Account__Balance;

    return Client;
}
void UpdateClient(string Account__Number, vector<stClient> &vClient)
{
    for (stClient &C : vClient)
    {
        if (C.Account__Number == Account__Number)
        {
            C = UpdateData(Account__Number);
        }
    }
}
void UpdateClientDataToFile(string File__Path, vector<stClient> vClient)
{
    fstream file;
    file.open(File__Path, ios::out);
    if (file.is_open())
    {
        string Client__Data__line;
        for (stClient &C : vClient)
        {
            Client__Data__line = ConvertRecordToLine(C);
            file << Client__Data__line << endl;
        }
    }
}
void UpdateClientInfo()
{
    system("color 60");
    Layout::Header("Update Client Info", '-');
    string Account__Number = Functions::ReadString("Please Enter Account Number: ");
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    stClient Client;
    char Answer = 'n';
    if (checkAccountNumber(Account__Number, vClient, Client))
    {
        PrintClientCard(Client);
        cout << "Are You Sure You Want To Update This Client? [y/n]" << endl;
        cin >> Answer;
        cin.ignore();
        if (toupper(Answer) == 'Y')
        {
            system("color 27");
            system("color 27");
            UpdateClient(Account__Number, vClient);
            UpdateClientDataToFile(File__Path, vClient);
            vClient = loadClientDataFromFile(File__Path);
            cout << "\n\nClient Deleted Successfully.";
        }
    }
    else
    {
        system("color 47");
        cout << "Client With [" << Account__Number << "] NOT Found!" << endl;
    }
}

void FindCleint()
{
    system("color 97");
    Layout::Header("Find Cleint", '-');
    string Account__Number = Functions::ReadString("Please Enter Account Number: ");
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    stClient Client;
    char Answer = 'n';
    if (checkAccountNumber(Account__Number, vClient, Client))
    {
        PrintClientCard(Client);
    }
    else
    {
        system("color 47");
        cout << "Client With [" << Account__Number << "] NOT Found!" << endl;
    }
}
void AddDeposit(stClient Client, vector<stClient> &vClient)
{
    double GetDeposit = Functions::ReadPositiveNumber("Please Enter Deposit Amount: ");
    char AddDeposit = 'n';
    for (stClient &C : vClient)
    {
        if (Client.Account__Number == C.Account__Number)
        {
            cout << "Are You Sure Want Preform This Trasaction? [y/n]";
            cin >> AddDeposit;
            if (toupper(AddDeposit) == 'Y')
            {
                C.Account__Balance += GetDeposit;
                cout << "Deposit Done Successfully, Your Balance = " << C.Account__Balance << endl;
                break;
            }
        }
    }
}
void Deposit()
{
    system("cls");
    system("color 57");
    Layout::Header("Deposit", '-');
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    string Account__Number = Functions::ReadString("Please Enter Account Number: ");
    stClient Client;
    bool isExist = 1;
    do
    {
        if (checkAccountNumber(Account__Number, vClient, Client))
        {
            system("color 50");
            PrintClientCard(Client);
            isExist = 0;
        }
        else
        {
            system("color 47");
            cout << "Client With [" << Account__Number << "] Does NOT Exists!" << endl;
            string Account__Number = Functions::ReadString("Please Enter Account Number: ");
        }

    } while (isExist);
    AddDeposit(Client, vClient);
    UpdateClientDataToFile(File__Path, vClient);
}
void TotalBalance()
{
    system("cls");
    system("color 17");
    double Total__Balance = 0;
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    string Header = "Client List (" + to_string(vClient.size()) + ") Client(s).";
    cout << setfill(' ') << setw(51) << left << "\n\n\t\t\t\t" + Header;
    cout << "\n\n"
         << setfill('_') << setw(96) << "_";
    cout << "\n"
         << setfill(' ') << setw(18) << left << "\n| Account Number" << setw(40) << "| Account Name" << setw(14) << "| Balance";
    cout << "\n"
         << setfill('_') << setw(98) << " \n";
    cout << "\n\n";

    for (stClient &Client : vClient)
    {
        cout << setfill(' ') << setw(17) << left << "| " + Client.Account__Number << setw(40) << left << "| " + Client.Account__Name << setw(14) << left << "| " + to_string(Client.Account__Balance);
        cout << "\n";
        Total__Balance += Client.Account__Balance;
    }
    cout << "\n";
    cout << setfill('_') << setw(97) << "_";
    cout << "\n\n";
    cout << "\t\t\t\t\tTotal Balance = " << Total__Balance << endl;
}

void GetWidthdraw(stClient Client, vector<stClient> &vClient)
{
    double GetWidthdraw = Functions::ReadPositiveNumber("Please Enter Widthdraw Amount: ");
    char AddWidthdraw = 'n';
    for (stClient &C : vClient)
    {
        if (Client.Account__Number == C.Account__Number)
        {
            while (Client.Account__Balance < GetWidthdraw)
            {
                cout << "Amount Exceed The Balance. You Can Widthdraw uo to : " << Client.Account__Balance;
                cout << "\nPlease Enter Another Widthdraw: \n";
                cin >> GetWidthdraw;
            }

            cout << "Are You Sure Want Preform This Trasaction? [y/n]";
            cin >> AddWidthdraw;

            if (toupper(AddWidthdraw) == 'Y')
            {
                C.Account__Balance -= GetWidthdraw;
                cout << "Widthdraw Done Successfully, Your Balance = " << C.Account__Balance << endl;
                break;
            }
        }
    }
}
void Widthdraw()
{
    system("cls");
    system("color 04");
    Layout::Header("Widthdraw", '-');
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    string Account__Number = Functions::ReadString("Please Enter Account Number: ");
    stClient Client;
    bool isExist = 1;
    do
    {
        if (checkAccountNumber(Account__Number, vClient, Client))
        {
            system("color 02");
            PrintClientCard(Client);
            isExist = 0;
        }
        else
        {
            system("color 47");
            cout << "Client With [" << Account__Number << "] Does NOT Exists!" << endl;
            string Account__Number = Functions::ReadString("Please Enter Account Number: ");
        }

    } while (isExist);
    GetWidthdraw(Client, vClient);
    UpdateClientDataToFile(File__Path, vClient);
}
void printTransactionsMainMenu()
{
    Layout::Header("Main Menu");
    Layout::Section("[1] Deposit.");
    Layout::Section("[2] Withdraw.");
    Layout::Section("[3] Total Balance.");
    Layout::Section("[4] Main Menu.");
    Layout::Border('=');
}

void BackToTransactionsMainMenu()
{
    cout << "Press any Key To Back To Main Menu...";
    system("pause");
    Transactions();
}
void Transactions()
{
    system("cls");
    system("color 70");
    printTransactionsMainMenu();
    short User__Option;
    User__Option = Functions::ReadPositiveNumber("Choose What Do You Want To Do [1 To 4] ? ");
    User__Option = (TransactionsMainOptions)User__Option;
    switch (User__Option)
    {
    case TransactionsMainOptions::eDeposit:
        Deposit();
        BackToTransactionsMainMenu();
        break;
    case TransactionsMainOptions::eWithdraw:
        Widthdraw();
        BackToTransactionsMainMenu();
        break;
    case TransactionsMainOptions::eTotalBalance:
        TotalBalance();
        BackToTransactionsMainMenu();
        break;
    case TransactionsMainOptions::eMainMenu:
        bank();
        break;

    default:
        break;
    }
}

void Exit()
{
    Layout::Header("Program Ends :) Sayonara");
    system("color 17");
    Sleep(1000);
    system("color 57");
    Sleep(1000);
    system("color 70");
    Sleep(1000);
    system("color 07");
}
void printMainMenu()
{
    Layout::Header("Main Menu");
    Layout::Section("[1] Show Client List.");
    Layout::Section("[2] Add New Client.");
    Layout::Section("[3] Delete Client.");
    Layout::Section("[4] Update Client Info.");
    Layout::Section("[5] Find Cleint.");
    Layout::Section("[6] Transactions.");
    Layout::Section("[7] Exit.");
    Layout::Border('=');
}

void BackToMainMenu()
{
    cout << "Press any Key To Back To Main Menu...";
    system("pause");
    bank();
}
void bank()
{
    system("cls");
    system("color 07");
    string User__Option;
    printMainMenu();
    User__Option = Functions::ReadChar("Choose What Do You Want To Do [1 To 6] ? ");

    switch (stoi(User__Option))
    {
    case MainOptions::eShowClientList:
        ShowClientList();
        BackToMainMenu();
        break;
    case MainOptions::eAddNewClient:
        AddNewClient();
        BackToMainMenu();
        break;
    case MainOptions::eDeleteClient:
        system("cls");
        DeleteClient();
        BackToMainMenu();
        break;
    case MainOptions::eUpdateClientInfo:
        system("cls");
        UpdateClientInfo();
        BackToMainMenu();
        break;
    case MainOptions::eFindCleint:
        system("cls");
        FindCleint();
        BackToMainMenu();
        break;
    case MainOptions::eTransactions:
        system("cls");
        Transactions();
        break;
    case MainOptions::eExit:
        system("cls");
        Exit();
        break;

    default:
        cout << "Invalid Input.\n";
        break;
    }
}
int main()
{
    bank();

    return 0;
}