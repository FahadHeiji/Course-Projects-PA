#include <iostream>
#include <vector>
#include "../../My_Libraries/Layout.h"
using namespace std;

struct stPlayerInfo
{
    string firstName, lastName, clubName;
    float salary;
};

vector<stPlayerInfo> creatVector()
{
    char addMore = 'Y';
    vector<stPlayerInfo> playerInfo;
    while (addMore == 'Y' || addMore == 'y')
    {
        stPlayerInfo temPlayerInfo;
        cout << "Please Enter Player Frist Name: " << endl;
        cin >> temPlayerInfo.firstName;
        cout << "Please Enter Player Last Name: " << endl;
        cin >> temPlayerInfo.lastName;
        cout << "Please Enter Player Club Name: " << endl;
        cin >> temPlayerInfo.clubName;
        cout << "Please Enter Player Net Salary: " << endl;
        cin >> temPlayerInfo.salary;
        playerInfo.push_back(temPlayerInfo);
        cout << "Do Want To Add More Players? [Y/N]: " << endl;
        cin >> addMore;
        cout << "\n";
    };

    return playerInfo;
}

void printVector()
{
    vector<stPlayerInfo> PlayerInfo = creatVector();
    short PlayerCounter = 1;
    for (stPlayerInfo &Player : PlayerInfo)
    {
        cout << "\nPlayer [" << PlayerCounter << "]: \n";
        cout << "First Name: " << Player.firstName << endl;
        cout << "Last Name: " << Player.lastName << endl;
        cout << "Club Name: " << Player.clubName << endl;
        cout << "Net Salary: " << Player.salary << endl;
        PlayerCounter++;
    }
}

int main()
{
    Layout::setProgramHeader("Read & Print Players Info from the User Using Vector Structure");
    printVector();
    return 0;
}