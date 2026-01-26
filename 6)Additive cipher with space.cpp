#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Encryption
string encrypt(string text, int key)
{
    string cipher = "";
    key = key % 26;

    for (char c : text)
    {
        if (isalpha(c))
        {
            c = toupper(c);
            cipher += char((c - 'A' + key) % 26 + 'A');
        }
        else
        {
            cipher += c;
        }
    }
    return cipher;
}

// Decryption
string decrypt(string text, int key)
{
    string plain = "";
    key = key % 26;

    for (char c : text)
    {
        if (isalpha(c))
        {
            c = toupper(c);
            plain += char((c - 'A' - key + 26) % 26 + 'A');
        }
        else
        {
            plain += c;
        }
    }
    return plain;
}

int main()
{
    int choice;
    string text;
    int key;

    while (true)
    {
        cout << "\n=== Additive (Caesar) Cipher ===\n";
        cout << "1. Encrypt\n2. Decrypt\nChoice: ";
        cin >> choice;
        cin.ignore();

        cout << "Enter text: ";
        getline(cin, text);

        cout << "Enter key (number): ";
        cin >> key;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Encrypted Text: " << encrypt(text, key) << endl;
        }
        else if (choice == 2)
        {
            cout << "Decrypted Text: " << decrypt(text, key) << endl;
        }
        else
        {
            cout << "Invalid choice!\n";
            break;
        }
    }

    return 0;
}

