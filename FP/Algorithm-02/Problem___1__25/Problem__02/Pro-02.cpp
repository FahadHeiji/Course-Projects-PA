#include <iostream>

#include <string>

#include <cmath>

using namespace std;

enum enPrimeOrNotPrinme

{

    prime = 1,

    notPrime = 2

};

float readInput(string message)

{

    float num = 0;

    do

    {

        cout << message << endl;

        cin >> num;

    } while (num <= 0);

    return num;
}

enPrimeOrNotPrinme checkPrimeNum(int num)

{

    int m = round(num / 2);

    for (int i = 2; i <= m; i++)

    {

        if (num % i == 0)

        {

            return enPrimeOrNotPrinme::notPrime;
        }
    }

    return enPrimeOrNotPrinme::prime;
}

void printOutput(int num) // Print Prime Numbers from 1 to num

{
    cout << "\nThe Prime Numbers From 1 To " << num;
    cout <<" are:\n";
    for (int i = 1; i <= num; i++)
    {
        switch (checkPrimeNum(i))

        {

        case enPrimeOrNotPrinme::prime:

            cout << i << endl;
            break;
        }
    }
}

int main()

{

    printOutput(readInput("Please Enter A Postive Number: "));

    return 0;
}