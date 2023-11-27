#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>

using namespace std;

struct stQuizzResult
{
    short NumberOfQuestions = 0, QuestionLeve = 0, OpreationType = 0, NumberOfRightAnswers = 0, NumberOfWrongAnswers = 0;
};

void setProgramHeader(string title)
{
    cout << "\n\t\t\t\t \n\n\t\t\t";
    for (int i = 0; i < title.length() + 18; i++)
    {
        cout << "-";
    }
    cout << "\n\n\t\t\t\t" << title << "\n\n\t\t\t";
    for (int i = 0; i < title.length() + 18; i++)
    {
        cout << "-";
    }
    cout << "\n\n";
}

void setHeader(string title, short Number, stQuizzResult QuizzResult)
{
    cout << "\n\n";
    for (int i = 0; i < title.length() + 18; i++)
    {
        cout << "*";
    }
    cout << "\n\n"
         << title << " [" << Number << "/" << QuizzResult.NumberOfQuestions << "] :"
         << "\n\n";
    for (int i = 0; i < title.length() + 18; i++)
    {
        cout << "*";
    }
    cout << "\n\n";
}

char readInput(string Message)
{
    char Answer;
    cout << Message << endl;
    cin >> Answer;

    return (char)Answer;
}

short readPostiveNumberInput(string Message)
{
    short number = 0;
    do
    {
        cout << Message << endl;
        cin >> number;
    } while (number < 0);

    return number;
}

void resetScreen()
{
    system("cls");
    system("color 0F");
}

int RandomNumber(int From, int To)
{
    // Function to generate a random number
    int randNum = rand() % (To - From + 1) + From;
    return randNum;
}

void OpreationType(stQuizzResult &QuizzResult, short num_01, short num_02, short ans)
{
    switch (QuizzResult.OpreationType)
    {
    case 1:

        cout << num_01 << endl;
        cout << num_02 << "\t+\n";
        cout << "____________________\n";
        cin >> ans;
        if (ans == num_01 + num_02)
        {
            system("color 20");
            cout << "The Answer is Right :-)\n\n";
            QuizzResult.NumberOfRightAnswers++;
        }
        else
        {
            system("color 40");
            cout << "\a";
            cout << "The Answer is Wrong :-(\n"
                 << "The Right Answer is " << num_01 + num_02 << endl;
            QuizzResult.NumberOfWrongAnswers++;
        }
        break;
    case 2:

        cout << num_01 << endl;
        cout << num_02 << "\t-\n";
        cout << "____________________\n";
        cin >> ans;
        if (ans == num_01 - num_02)
        {
            system("color 20");
            cout << "The Answer is Right :-)\n\n";
            QuizzResult.NumberOfRightAnswers++;
        }
        else
        {
            system("color 40");
            cout << "\a";
            cout << "The Answer is Wrong :-(\n"
                 << "The Right Answer is " << num_01 - num_02 << endl;
            QuizzResult.NumberOfWrongAnswers++;
        }
        break;
    case 3:

        cout << num_01 << endl;
        cout << num_02 << "\t*\n";
        cout << "____________________\n";
        cin >> ans;
        if (ans == num_01 * num_02)
        {
            system("color 20");
            cout << "The Answer is Right :-)\n\n";
            QuizzResult.NumberOfRightAnswers++;
        }
        else
        {
            system("color 40");
            cout << "\a";
            cout << "The Answer is Wrong :-(\n"
                 << "The Right Answer is " << num_01 * num_02 << endl;
            QuizzResult.NumberOfWrongAnswers++;
        }
        break;
    case 4:

        cout << num_01 << endl;
        cout << num_02 << "\t/\n";
        cout << "____________________\n";
        cin >> ans;
        if (ans == num_01 / num_02)
        {
            system("color 20");
            cout << "The Answer is Right :-)\n\n";
            QuizzResult.NumberOfRightAnswers++;
        }
        else
        {
            system("color 40");
            cout << "\a";
            cout << "The Answer is Wrong :-(\n"
                 << "The Right Answer is " << num_01 / num_02 << endl;
            QuizzResult.NumberOfWrongAnswers++;
        }
        break;
    case 5:
        QuizzResult.OpreationType = RandomNumber(1, 4);
        OpreationType(QuizzResult, num_01, num_02, ans);
    default:
        break;
    }
}

void quizz(stQuizzResult &QuizzResult)
{
    short num_01, num_02, ans = 0;

    switch (QuizzResult.QuestionLeve)
    {
    case 1:
        num_01 = RandomNumber(0, 10);
        num_02 = RandomNumber(0, 10);
        OpreationType(QuizzResult, num_01, num_02, ans);
        break;
    case 2:
        num_01 = RandomNumber(10, 100);
        num_02 = RandomNumber(10, 100);
        OpreationType(QuizzResult, num_01, num_02, ans);
        break;
    case 3:
        num_01 = RandomNumber(100, 1000);
        num_02 = RandomNumber(100, 1000);
        OpreationType(QuizzResult, num_01, num_02, ans);
        break;
    case 4:
        num_01 = RandomNumber(0, 1000);
        num_02 = RandomNumber(0, 1000);
        OpreationType(QuizzResult, num_01, num_02, ans);
        break;
    default:
        break;
    }
}

stQuizzResult quizzRound(stQuizzResult &QuizzResult)
{
    for (int i = 1; i <= QuizzResult.NumberOfQuestions; i++)
    {
        setHeader("Qusetion", i, QuizzResult);
        quizz(QuizzResult);
    }

    return QuizzResult;
}

stQuizzResult startQuizz()
{
    stQuizzResult QuizzResult;
    QuizzResult.NumberOfQuestions = readPostiveNumberInput("How Many Qusetions Do Want?");
    QuizzResult.QuestionLeve = readPostiveNumberInput("Enter Qusetion Level? [1] Easy, [2] Mid, [3] Hard, [4] Mix : ");
    QuizzResult.OpreationType = readPostiveNumberInput("Enter Opreation Type? [1] Add, [2] Sub, [3] Mul, [4] Div, [5] Mix : ");
    quizzRound(QuizzResult);
    return QuizzResult;
}

string quizzLevel(stQuizzResult QuizzResult)
{
    string Levels[4] = {"Easy", "Mid", "Hard", "Mix"};
    return Levels[QuizzResult.QuestionLeve - 1];
}

string IsPassed(stQuizzResult QuizzResult)
{
    if (QuizzResult.NumberOfRightAnswers > QuizzResult.NumberOfWrongAnswers)
    {
        system("color 20");
        return "You Passed!! :)";
    }
    else
    {
        system("color 40");
        cout << "\a";
        return "You Failed!! :(";
    }
}

string quizzOpreationType(stQuizzResult QuizzResult)
{
    string OpreationType[5] = {"Add", "Sub", "Mul", "Div", "Mix"};
    return OpreationType[QuizzResult.OpreationType - 1];
}

void showResult(stQuizzResult QuizzResult)
{
    setProgramHeader("Fianl Results");
    cout << "\t\t\t\t" << IsPassed(QuizzResult) << endl;
    cout << "\n\t\t\tNumber Of Questions: " << QuizzResult.NumberOfQuestions << endl;
    cout << "\t\t\tQuestions Level: " << quizzLevel(QuizzResult) << endl;
    cout << "\t\t\tOpreation Type: " << quizzOpreationType(QuizzResult) << endl;
    cout << "\t\t\tNumber Of Right Answers: " << QuizzResult.NumberOfRightAnswers << endl;
    cout << "\t\t\tNumber Of Wrong Answers: " << QuizzResult.NumberOfWrongAnswers << endl;
    cout << "\t\t\t_________________________________" << endl;
}

void mathGame()
{
    char playAgain = 'Y';
    do
    {
        resetScreen();
        stQuizzResult QuizzResult = startQuizz();
        showResult(QuizzResult);
        playAgain = readInput("\t\t\tDo You Wanna Play Again? [Y\\N]");
    } while (playAgain == 'Y' || playAgain == 'y');
    resetScreen();
}

int main()
{
    // Seeds the random number generator in C++, called only once
    srand((unsigned)time(NULL));
    setProgramHeader("Math Game");
    mathGame();
    return 0;
}