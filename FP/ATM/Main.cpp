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
void ATM();
void logIn();
enum MainOptions
{
    eQWithdraw = 1,
    eNormalWithdraw = 2,
    eDepositQuick = 3,
    eCheckBlalnce = 4,
    eLogOut = 5,
    eExit = 6,
};

struct stClient
{
    string Account__Number, Account__Name, PIN__Code, Phone;
    double Account__Balance;
    bool Mark__To__Delete = false;
};

stClient Client;

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

bool checkLogIn()
{
    vector<stClient> vClients = loadClientDataFromFile(File__Path);

    Client.Account__Number = Functions::ReadString("Enter Account Number: ");

    Client.PIN__Code = Functions::ReadString("Enter Pin-Code: ");

    for (stClient &C : vClients)
    {
        if (C.Account__Number == Client.Account__Number && C.PIN__Code == Client.PIN__Code)
        {
            Client = C;
            return 1;
        }
    }
    return 0;
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

void UpdateClientDataToFile(string File__Path, vector<stClient> vClient)
{
    fstream file;
    file.open(File__Path, ios::out);
    if (file.is_open())
    {
        string Client__Data__line;
        for (stClient &C : vClient)
        {
            if (Client.Account__Number == C.Account__Number)
            {
                C = Client;
            }

            Client__Data__line = ConvertRecordToLine(C);
            file << Client__Data__line << endl;
        }
    }
}

void QWidthdraw();
void GetQWidthdraw(double GetWidthdraw)
{
    // double GetWidthdraw = Functions::ReadPositiveNumber("Please Enter Widthdraw Amount: ");
    char AddWidthdraw = 'n';

    if (Client.Account__Balance < GetWidthdraw)
    {
        cout << "Amount Exceed The Balance. Please Enter Anotherg Choice\n";
        system("pause");
        QWidthdraw();
    }

    cout << "Are You Sure Want Preform This Trasaction? [y/n]";
    cin >> AddWidthdraw;

    if (toupper(AddWidthdraw) == 'Y')
    {
        Client.Account__Balance -= GetWidthdraw;
        cout << "\nWidthdraw Done Successfully, Your Balance = " << Client.Account__Balance << endl
             << endl;
    }
}
void GetWidthdraw(double GetWidthdraw)
{

    char AddWidthdraw = 'n';

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
        Client.Account__Balance -= GetWidthdraw;
        cout << "\nWidthdraw Done Successfully, Your Balance = " << Client.Account__Balance << endl
             << endl;
    }
}

void printQWithdrawMainMenu()
{
    Layout::Header("Widthdraw", '-');
    Layout::Section("[1] 20");
    Layout::Section("[2] 50");
    Layout::Section("[3] 100");
    Layout::Section("[4] 200");
    Layout::Section("[5] 400");
    Layout::Section("[6] 600");
    Layout::Section("[7] 800");
    Layout::Section("[8] 1000");
    Layout::Section("[9] Exit");
    Layout::Border('-');
}

void QWidthdraw()
{
    system("cls");
    system("color 04");
    printQWithdrawMainMenu();
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    cout << "Your Balance is : " << Client.Account__Balance << endl;
    short Client__Option = Functions::ReadPositiveNumber("Choose What Do You Want To Do [1 To 9] ? ");

    switch (Client__Option)
    {
    case 1:
        GetQWidthdraw(20);
        break;
    case 2:
        GetQWidthdraw(50);
        break;
    case 3:
        GetQWidthdraw(100);
        break;
    case 4:
        GetQWidthdraw(200);
        break;
    case 5:
        GetQWidthdraw(400);
        break;
    case 6:
        GetQWidthdraw(600);
        break;
    case 7:
        GetQWidthdraw(800);
        break;
    case 8:
        GetQWidthdraw(1000);
        break;
    case 9:
        ATM();
        break;

    default:
        cout << "Invalid Input...";
        QWidthdraw();
        break;
    }
    UpdateClientDataToFile(File__Path, vClient);
}
void Widthdraw()
{
    system("cls");
    Layout::Header("Widthdraw", '-');
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    short Client__Option = Functions::ReadPositiveNumber("Enter An Amount Multiply of 5's : ");
    while (Client__Option % 5 != 0)
    {
        cout << "Invalid Amount, Please Enter An Amount Multiply of 5's : \n";
        cin >> Client__Option;
    }

    GetWidthdraw(Client__Option);
    UpdateClientDataToFile(File__Path, vClient);
}

void AddDeposit(double GetDeposit)
{

    char AddDeposit = 'n';

    cout << "Are You Sure Want Preform This Trasaction? [y/n]";
    cin >> AddDeposit;
    if (toupper(AddDeposit) == 'Y')
    {
        Client.Account__Balance += GetDeposit;
        cout << "\nDeposit Done Successfully, Your Balance = " << Client.Account__Balance << endl
             << endl;
    }
}

void Deposit()
{
    system("cls");
    system("color 57");
    Layout::Header("Deposit", '-');
    vector<stClient> vClient = loadClientDataFromFile(File__Path);
    short Client__Option = Functions::ReadPositiveNumber("Please Enter Deposit Amount: ");

    AddDeposit(Client__Option);
    UpdateClientDataToFile(File__Path, vClient);
}

void CheckBlalnce()
{
    system("cls");
    system("color 60");
    Layout::Header("Check Blalnce", '-');
    cout << "Your Balance is : " << Client.Account__Balance << endl;
    Layout::Border('=');
}

void LogOut()
{
    logIn();
}

void Exit()
{
    system("cls");
    Layout::Header("Program Ends :) Sayonara... ");
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
    Layout::Section("[1] Quick Withdraw.");
    Layout::Section("[2] Normal Withdraw.");
    Layout::Section("[3] Deposit.");
    Layout::Section("[4] Check Blalnce LogOut.");
    Layout::Section("[5] LogOut.");
    Layout::Section("[6] LogOut & Exit.");
    Layout::Border('=');
}

void BackToMainMenu()
{
    cout << "Press any Key To Back To Main Menu...";
    system("pause");
}
void ATM()
{
    system("cls");
    system("color 07");
    string Client__Option;
    printMainMenu();
    cout << "Welecom " << Client.Account__Name << endl;
    Client__Option = Functions::ReadChar("Choose What Do You Want To Do [1 To 6] ? ");

    switch (stoi(Client__Option))
    {
    case MainOptions::eQWithdraw:
        QWidthdraw();
        BackToMainMenu();
        ATM();
        break;
    case MainOptions::eNormalWithdraw:
        Widthdraw();
        BackToMainMenu();
        ATM();
        break;
    case MainOptions::eDepositQuick:
        Deposit();
        BackToMainMenu();
        ATM();
        break;
    case MainOptions::eCheckBlalnce:
        CheckBlalnce();
        BackToMainMenu();
        ATM();
        break;
    case MainOptions::eLogOut:
        LogOut();
        break;
    case MainOptions::eExit:
        Exit();
        break;

    default:
        cout << "Invalid Input.\n";
        break;
    }
}
void logIn()
{
    system("cls");
    system("color 70");
    Layout::Header("LogIn");

    while (!checkLogIn())
    {
        system("cls");
        Layout::Header("Login");
        cout << "\a";
        cout << "Invalid Input, Account Number/Pin-Code\n\n";
    }

    ATM();
}
int main()
{
    logIn();

    return 0;
}