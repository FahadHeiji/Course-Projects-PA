#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include "../My_Libraries/Layout.h"
#include "../My_Libraries/Functions.h"

using namespace std;
const string ClientsFileName = "Clients-Data.txt";

enum enMainMenuOptions
{
    eListClients = 1,
    eAddNewClient = 2,
    eDeleteClient = 3,
    eUpdateClient = 4,
    eFindClient = 5,
    eExit = 6
};
struct stClient
{
    string AccountNumber;
    string PinCode;
    string Name;
    string Phone;
    double AccountBalance;
    bool MarkForDelete = false;
};

vector<stClient> LoadClietsDataFromFile(string ClientsFileName)
{
    vector<stClient> vClients;
    fstream File;
    File.open(ClientsFileName, ios::in);
    if (File.is_open())
    {
        string Line;
        stClient Client;

        while (getline(File,Line))
        {
            Client = ConvertLinetoRecord(Line)
        }
        
    }
    
}
short ReadMainMenuOption()
{

    cout << "Choose what do you want to do? [1 to 6]? ";
    short Choice = 0;
    cin >> Choice;

    return Choice;
}

void ShowAllClientsScreen()
{
    vector<stClient> vClients = LoadClietsDataFromFile();
}

void PrefromMainMenuOption(enMainMenuOptions MainMenuOption)
{
    switch (MainMenuOption)
    {
    case enMainMenuOptions::eListClients:
    {
        system("cls");
        ShowAllClientsScreen();
        GoBackToMainMenue();
        break;
    }
    case enMainMenuOptions::eAddNewClient:
        system("cls");
        ShowAddNewClientsScreen();
        GoBackToMainMenue();
        break;

    case enMainMenuOptions::eDeleteClient:
        system("cls");
        ShowDeleteClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenuOptions::eUpdateClient:
        system("cls");
        ShowUpdateClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenuOptions::eFindClient:
        system("cls");
        ShowFindClientScreen();
        GoBackToMainMenue();
        break;

    case enMainMenuOptions::eExit:
        system("cls");
        ShowEndScreen();
        break;
    }
}
void Bank__Main__Menu()
{
    system("cls");
    Layout::Header("Main Menu");
    Layout::Section("[1] Show Client List.");
    Layout::Section("[2] Add New Client..");
    Layout::Section("[3] Delete Client.");
    Layout::Section("[4] Update Client Info.");
    Layout::Section("[5] Find Client.");
    Layout::Section("[6] Exit.");
    Layout::Border('=');
    PrefromMainMenuOption((enMainMenuOptions)ReadMainMenuOption())
}
int main()
{
    Bank__Main__Menu();
    system("pause");
    return 0;
}