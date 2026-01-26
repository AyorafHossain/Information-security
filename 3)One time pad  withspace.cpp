#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

// Remove non-letters and convert to uppercase
string cleanInput(string text)
{
    string result = "";
    for (char c : text)
    {
        if (isalpha(c))
            result += toupper(c);
    }
    return result;
}

// Convert full string to uppercase
string toUpperCase(string text)
{
    for (int i = 0; i < text.length(); i++)
        text[i] = toupper(text[i]);
    return text;
}

// Generate random key (letters only, same count as letters in text)
string generateRandomKey(string text)
{
    string key = "";
    for (char c : text)
    {
        if (isalpha(c))
            key += char('A' + rand() % 26);
    }
    return key;
}

// Encryption
string encryptOTP(string plaintext, string key)
{
    string cipher = "";
    int keyIndex = 0;

    for (char c : plaintext)
    {
        if (isalpha(c))
        {
            int p = c - 'A';
            int k = key[keyIndex++] - 'A';
            cipher += char((p + k) % 26 + 'A');
        }
        else
        {
            cipher += c; // keep space/symbol
        }
    }
    return cipher;
}

// Decryption
string decryptOTP(string ciphertext, string key)
{
    string plain = "";
    int keyIndex = 0;

    for (char c : ciphertext)
    {
        if (isalpha(c))
        {
            int cVal = c - 'A';
            int k = key[keyIndex++] - 'A';
            plain += char((cVal - k + 26) % 26 + 'A');
        }
        else
        {
            plain += c; // keep space/symbol
        }
    }
    return plain;
}

int main()
{
    srand(time(0));
    int choice;
    string text, key, result;

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

            text = toUpperCase(text);

            // key only for letters
            string cleanText = cleanInput(text);
            key = generateRandomKey(cleanText);

            result = encryptOTP(text, key);

            cout << "Random Key  : " << key << endl;
            cout << "Ciphertext : " << result << endl;
        }


        else if (choice == 2)
        {
            cout << "Enter ciphertext: ";
            getline(cin, text);
            text = toUpperCase(text);

            cout << "Enter key (letters only): ";
            getline(cin, key);
            key = toUpperCase(key);

            result = decryptOTP(text, key);
            cout << "Plaintext  : " << result << endl;
        }


        else
        {
            cout << "Invalid choice!\n";
            break;
        }
    }


    return 0;
}
