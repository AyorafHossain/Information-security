#include <iostream>
#include <string>
#include <cctype>
using namespace std;


string toUpperCase(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = toupper(text[i]);
    }
    return text;
}




string cleanKeyword(string key)
{
    string result = "";
    for (int i = 0; i < key.length(); i++)
    {
        if (isalpha(key[i]))
        {
            result += toupper(key[i]);
        }
    }
    return result;
}





string encrypt(string plaintext, string keyword)
{
    plaintext = toUpperCase(plaintext);
    keyword = cleanKeyword(keyword);

    string ciphertext = "";
    string key = keyword; // Start key with the keyword

    int keyIndex = 0;

    for (int i = 0; i < plaintext.length(); i++)
    {
        char p = plaintext[i];

        if (isalpha(p))
        {
            int pVal = p - 'A';
            int kVal = key[keyIndex] - 'A';

            char c = char((pVal + kVal) % 26 + 'A');
            ciphertext += c;

            // AutoKey: append plaintext letter to key
            key += p;

            keyIndex++;
        }
        else
        {
            ciphertext += p;
        }
    }

    return ciphertext;
}




// Decryption
string decrypt(string ciphertext, string keyword)
{
    ciphertext = toUpperCase(ciphertext);
    keyword = cleanKeyword(keyword);

    string plaintext = "";
    string key = keyword; // Start key with the keyword

    int keyIndex = 0;

    for (int i = 0; i < ciphertext.length(); i++)
    {
        char c = ciphertext[i];

        if (isalpha(c))
        {
            int cVal = c - 'A';
            int kVal = key[keyIndex] - 'A';

            char p = char((cVal - kVal + 26) % 26 + 'A');
            plaintext += p;

            // AutoKey: append decrypted plaintext letter to key
            key += p;

            keyIndex++;
        }
        else
        {
            plaintext += c; // keep non-letter characters
        }
    }

    return plaintext;
}






int main()
{
    int choice;
    string text, keyword;

    while (true)
    {
        cout << "\n=== AutoKey Cipher ===\n";
        cout << "1. Encryption\n2. Decryption\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1)
        {
            cout << "Enter plaintext: ";
            getline(cin, text);
            cout << "Enter keyword: ";
            getline(cin, keyword);

            cout << "Ciphertext: " << encrypt(text, keyword) << endl;
        }
        else if (choice == 2)
        {
            cout << "Enter ciphertext: ";
            getline(cin, text);
            cout << "Enter keyword: ";
            getline(cin, keyword);

            cout << "Plaintext: " << decrypt(text, keyword) << endl;
        }
        else
        {
            cout << "Invalid choice!\n";
            return 0;
        }
    }

    return 0;
}

