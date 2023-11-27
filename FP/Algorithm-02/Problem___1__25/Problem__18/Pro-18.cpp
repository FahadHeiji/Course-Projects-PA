#include <iostream>
#include <string>
using namespace std;

string ReadPassword(string Message)
{
    string text;

    cout << Message << endl;
    getline(cin, text);

    return text;
}

string encryptText(string enText, int EncryptionKey)
{
    for (int i = 0; i < enText.length(); i++)
    {
        // int te = char(enText[i]) + 2;
        // enText[i] = char(te);
        enText[i] = char((int)enText[i] + EncryptionKey);
    }

    return enText;
}
string decryptText(string deText, int EncryptionKey)
{

    for (int i = 0; i < deText.length(); i++)
    {
        // int te = char(deText[i]) - 2;
        // deText[i] = char(te);
        deText[i] = char((int)deText[i] - EncryptionKey);
    }

    return deText;
}

void printOutput(string text)
{
    const short EncryptionKey = 2;
    string EncryptText = encryptText(text, EncryptionKey);
    string DecryptText = decryptText(EncryptText, EncryptionKey);
    cout << "\nText Before Encryption: " << text << endl;
    cout << "\nText After Encryption: " << EncryptText << endl;
    cout << "\nText After Decryption: " << DecryptText << endl;
}

int main()
{
    printOutput(ReadPassword("Please Enter A Text: "));
    return 0;
}