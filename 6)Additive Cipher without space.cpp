#include <iostream>
#include <string>
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



string encrypt(string text, int key)
{
    text = cleanInput(text);
    string cipher = "";

    for (int i = 0; i < text.length(); i++)
    {
         cipher += char((text[i] - 'A' + key) % 26 + 'A');
    }

    return cipher;
}




string decrypt(string text, int key)
{
    text = cleanInput(text);
    string plain = "";


    for (int i = 0; i < text.length(); i++)
    {
        plain += char((text[i] - 'A' - key + 26) % 26 + 'A');
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
