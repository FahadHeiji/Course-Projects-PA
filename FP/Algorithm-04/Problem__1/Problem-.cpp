#include <iostream>
#include <string>
#include "../../My_Libraries/Layout.h"
#include "../../My_Libraries/Functions.h"
using namespace std;

string replaceNumberToText(int Number)
{
    if (Number == 0)
    {
        return "";
    }
    if (Number >= 1 && Number <= 19)
    {
        string arr[]{
            "", "One ", " Two ", " Three ", " Four ", " Five ", " Six ", " Seven ", " Eight ", " Nine ", " Ten ", " Eleven ", " Twelve ", " Thirteen ", " Fourteen ", " Fifteen ", " Sixteen ", " Seventeen ", " Eighteen ", " Nineteen "};
        return arr[Number] + " ";
    }
    if (Number >= 20 && Number <= 99)
    {
        string arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        return arr[Number / 10] + " " + replaceNumberToText(Number % 10);
    }
    if (Number >= 100 && Number <= 199)
    {
        return "One Hundred " + replaceNumberToText(Number % 100);
    }
    if (Number >= 200 && Number <= 999)
    {
        return replaceNumberToText(Number / 100) + "Hundreds " + replaceNumberToText(Number % 100);
    }
    if (Number >= 1000 && Number <= 1999)
    {
        return "One Thousand " + replaceNumberToText(Number % 1000);
    }
    if (Number >= 2000 && Number <= 999999)
    {
        return replaceNumberToText(Number / 1000) + "Thousands " + replaceNumberToText(Number % 1000);
    }
    if (Number >= 1000000 && Number <= 1999999)
    {
        return "One Million " + replaceNumberToText(Number % 1000000);
    }
    if (Number >= 2000000 && Number <= 999999999)
    {
        return replaceNumberToText(Number / 1000000) + "Millions " + replaceNumberToText(Number % 1000000);
    }
    if (Number >= 1000000000 && Number <= 1999999999)
    {
        return "One Billion " + replaceNumberToText(Number % 1000000000);
    }
    else
    {
        return replaceNumberToText(Number / 1000000000) + "Bilions " + replaceNumberToText(Number % 1000000000);
    }
}
int main()
{
    Layout::setProgramHeader("Number To Text");
    int Number = Functions::ReadPositiveNumber("Please Enter a Number: ");
    cout << replaceNumberToText(Number) << endl;

    return 0;
}