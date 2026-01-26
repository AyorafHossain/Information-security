#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

string cleanInput(string text)
{
    string result = "";
    for (char c : text)
    {
        if (isalpha(c))
        {
            result += toupper(c);
        }
    }
    return result;
}



void encrypt(string plaintext, string key)
{
    plaintext = cleanInput(plaintext);
    key = cleanInput(key);

    if (plaintext.length() != key.length())
    {
        cout << "Error: Key length must be same as plaintext length!\n";
        return;
    }

    string ciphertext = "";

    for (int i = 0; i < plaintext.length(); i++)
    {
        int p = plaintext[i] - 'A';
        int k = key[i] - 'A';
        int c = (p + k) % 26;
        ciphertext += char(c + 'A');
    }


    cout << "Ciphertext : " << ciphertext << endl;
}



void decrypt(string ciphertext, string key)
{
    ciphertext = cleanInput(ciphertext);
    key        = cleanInput(key);

    if (ciphertext.length() != key.length())
    {
        cout << "Error: Key length must be same as ciphertext length!\n";
        return;
    }

    string plaintext = "";

    for (int i = 0; i < ciphertext.length(); i++)
    {
        int c = ciphertext[i] - 'A';
        int k = key[i] - 'A';
        int p = (c - k + 26) % 26;
        plaintext += char(p + 'A');
    }

    cout << "Plaintext : " << plaintext << endl;
}



int main()
{
    int choice;
    string text, key;

    while (true)
    {
        cout << "\n=== One-Time Pad Cipher ===\n";
        cout << "1. Encrypt\n2. Decrypt\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter plaintext: ";
            getline(cin, text);

            cout << "Enter key (same length as plaintext): ";
            getline(cin, key);

            encrypt(text, key);
        }


        else if (choice == 2)
        {
            cout << "Enter ciphertext: ";
            getline(cin, text);

            cout << "Enter key: ";
            getline(cin, key);

            decrypt(text, key);
        }


        else
        {
            cout << "Invalid choice!\n";
            break;
        }
    }

    return 0;
}

