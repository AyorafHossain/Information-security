#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// Function to clean input (remove spaces,punctuation and make uppercase)

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



// Function to generate encryption key stream
string generateKeyStream(string plaintext, string keyword)
{
    string key = keyword;
    int pLen = plaintext.size();
    for (int i = 0; key.size() < pLen; i++)
    {
        key += plaintext[i];
    }
    return key;
}



// Encryption
string encrypt(string plaintext, string keyword)
{
    plaintext = cleanInput(plaintext);
    keyword = cleanInput(keyword);

    string key = generateKeyStream(plaintext, keyword);
    string ciphertext = "";

    for (int i = 0; i < plaintext.size(); i++)
    {
        int p = plaintext[i] - 'A';
        int k = key[i] - 'A';
        int c = (p + k) % 26;
        ciphertext += char(c + 'A');
    }
    return ciphertext;
}



// Decryption
string decrypt(string ciphertext, string keyword)
{
    ciphertext = cleanInput(ciphertext);
    keyword = cleanInput(keyword);

    string plaintext = "";
    string key = keyword;

    for (int i = 0; i < ciphertext.size(); i++)
    {
        int c = ciphertext[i] - 'A';
        int k = key[i] - 'A';
        int p = (c - k);
        if (p < 0) p += 26;
        p = p % 26;
        char plainChar = char(p + 'A');
        plaintext += plainChar;
        key += plainChar; // dynamically extend the key with plaintext
    }
    return plaintext;
}




int main()
{
    int choice;
    string text, keyword;

    cout << "=== Autokey Cipher ===" << endl;
    cout << "1. Encryption" << endl;
    cout << "2. Decryption" << endl;
    cout << "Enter your choice (1/2): ";
    cin >> choice;
    cin.ignore(); // to clear newline from buffer

    switch (choice)
    {
    case 1:
    {
        cout << "\nEnter plaintext: ";
        getline(cin, text);
        cout << "Enter keyword: ";
        getline(cin, keyword);

        string ciphertext = encrypt(text, keyword);
        cout << "Ciphertext: " << ciphertext << endl;
        break;
    }
    case 2:
    {
        cout << "\nEnter ciphertext: ";
        getline(cin, text);
        cout << "Enter keyword: ";
        getline(cin, keyword);

        string recoveredText = decrypt(text, keyword);
        cout << "Plaintext: " << recoveredText << endl;
        break;
    }
    default:
        cout << "Invalid choice." << endl;
    }

    return 0;
}
