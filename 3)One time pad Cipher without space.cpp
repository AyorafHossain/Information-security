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






string generateRandomKey(int length)
 {
    string key = "";
    for (int i = 0; i < length; i++)
    {
        key += char('A' + rand() % 26);
    }

    return key;
}



void encrypt(string plaintext)
{
    plaintext = cleanInput(plaintext);

    string key = generateRandomKey(plaintext.length());
    string ciphertext = "";


    for (int i = 0; i < plaintext.size(); i++)
    {
        int c = plaintext[i] - 'A';
        int k = key[i] - 'A';
        int p = (c + k);
        if (p < 0) p += 26;
        p = p % 26;
        ciphertext += char(p + 'A');
    }

     cout << "Keystream  : " << key << endl;
     cout << "Ciphertext : " << ciphertext << endl;

}




void decrypt(string ciphertext, string key)
{
    string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i++)
    {
        int c = ciphertext[i] - 'A';
        int k = key[i] - 'A';
        int p = (c - k);
        if (p < 0) p += 26;
        p = p % 26;
        plaintext += char(p + 'A');
    }

    cout << "Plaintext      : " << plaintext<< endl;

}




int main()
{
    srand(time(0)); // starting random number initialize by random seed
    int choice;
    string text, key, result;

    while (true)
    {
        cout << "\n=== One-Time Pad Cipher ===\n";
        cout << "1. Encrypt\n2. Decrypt\nChoice: ";
        cin >> choice;
        cin.ignore(); // clear newline


        if (choice == 1)
        {
            cout << "Enter plaintext: ";
            getline(cin, text);
            encrypt(text);

        }


        else if (choice == 2)

        {
            cout << "Enter ciphertext: ";
            getline(cin, text);
            text = cleanInput(text);
            cout << "Enter key: ";
            getline(cin, key);
            key = cleanInput(key);
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

