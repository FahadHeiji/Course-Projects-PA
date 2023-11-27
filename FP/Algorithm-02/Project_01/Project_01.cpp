#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

void setProgramHeader(string title)
{
    cout << "\n\t\t\t\t" << title << "\n\n\t\t\t";
    for (int i = 0; i < title.length() + 18; i++)
    {
        cout << "-";
    }
    cout << "\n\n";
}

enum gameRules
{
    Rock = 1,
    Papar = 2,
    Sicssor = 3
};

string PlayerChoice(int number)
{
    switch (number)
    {
    case gameRules::Rock:
        return "Rock";

    case gameRules::Papar:
        return "Papar";

    case gameRules::Sicssor:
        return "Sicssor";
    default:
        return "Invalid choice";
    }
}

void setRounds(int number)
{
    cout << "\n\t\t\t\tRound " << number << " :\n\n\t\t\t";
    for (int i = 0; i < 9 + 18; i++)
    {
        cout << "-";
    }
    cout << "\n\n";
}

int readInput(string Message)
{
    int number = 0;
    cout << Message << endl;
    cin >> number;
    return number;
}
int readRPS(string Message)
{
    int number = 0;
    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number < 1 || number > 3);

    return number;
}

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void rounds(int number, int &winCounter, int &drawCounter, int &LossCounter)
{

    for (int i = 1; i <= number; i++)
    {
        setRounds(i);
        int player = readRPS("Choose : [Rock = 1, Papar = 2, Scissor = 3]?");
        int CPU = RandomNumber(1, 3);
        if ((player == 1 && CPU == 1) || (player == 2 && CPU == 2) || (player == 3 && CPU == 3))
        {
            system("color 60");
            cout << "Player : " << PlayerChoice(player) << endl;
            cout << "CPU : " << PlayerChoice(CPU) << endl;
            cout << "It\'s A Draw!\n";
            drawCounter++;
        }
        else if ((player == 1 && CPU == 2) || (player == 2 && CPU == 3) || (player == 3 && CPU == 1))
        {
            system("color 47");
            cout << "\a" << endl;
            cout << "Player : " << PlayerChoice(player) << endl;
            cout << "CPU : " << PlayerChoice(CPU) << endl;
            cout << "CPU Wins!\n";
            LossCounter++;
        }
        else
        {
            system("color 27");
            cout << "Player : " << PlayerChoice(player) << endl;
            cout << "CPU : " << PlayerChoice(CPU) << endl;
            cout << "Player Wins!\n";
            winCounter++;
        }
    }
}

void results(int numberOfRounds, int winCounter, int drawCounter, int LossCounter)
{
    setProgramHeader("Game Over");
    cout << "Game Rounds : " << numberOfRounds << endl;
    cout << "Player Won Times : " << winCounter << endl;
    cout << "CPU Won Times : " << LossCounter << endl;
    cout << "Draws Times: " << drawCounter << endl;
    if (winCounter > LossCounter)
        cout << "The Winner : Player " << endl;
    else if (LossCounter > winCounter)
        cout << "The Winner : CPU " << endl;
    else
        cout << "The Winner : NO Winner " << endl;
}

void RPS_Game()
{
    int drawCounter = 0, winCounter = 0, LossCounter = 0;
    int numberOfRounds = readInput("How many Round Do You Want: ");
    rounds(numberOfRounds, winCounter, drawCounter, LossCounter);
    results(numberOfRounds, winCounter, drawCounter, LossCounter);
}

void playAgain()
{
    short Num = 0;
    cout << "Do You Want Play Again?[Yes = 1 / No = 0]\n";
    cin >> Num;
    if (Num == 1)
    {
        system("cls");
        system("color 07");
        RPS_Game();
        playAgain();
    }
    else
        system("color 07");
}
int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    setProgramHeader("RPS Game");
    RPS_Game();
    playAgain();
    return 0;
}