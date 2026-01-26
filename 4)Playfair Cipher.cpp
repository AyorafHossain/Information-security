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
            char ch = toupper(c);
            if (ch == 'J')
                ch = 'I';
            result += ch;
        }
    }
    return result;
}




string removeDuplicates(string key)
{
    string result = "";
    for (int i = 0; i < key.length(); i++)
    {
        bool found = false;
        for (int j = 0; j < result.length(); j++)
        {
            if (key[i] == result[j])
            {
                found = true;
                break;
            }
        }
        if (!found)
            result += key[i];
    }
    return result;
}





/* ---------- Build 5x5 key matrix ---------- */
void buildMatrix(string keyword, char matrix[5][5])
{
    keyword = cleanInput(keyword);
    keyword = removeDuplicates(keyword);

    string keystring = keyword;

    for (char c = 'A'; c <= 'Z'; c++)
    {
        if (c == 'J')
            continue;

        bool exists = false;

        for (char k : keystring)
        {
            if (k == c)
            {
                exists = true;
                break;
            }
        }
        if (!exists)
            keystring += c;
    }

    int k = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrix[i][j] = keystring[k++];
        }
    }
}




/* ---------- Find position in matrix ---------- */
void findPosition(char matrix[5][5], char ch, int &row, int &col)
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (matrix[i][j] == ch)
            {
                row = i;
                col = j;
                return;
            }
        }
    }
}

/* ---------- Your plaintext preparation method ---------- */
string preparePlaintext(string text)
{
    text = cleanInput(text);
    string prepared = "";

    int i = 0;
    while (i < (int)text.size())
    {
        char a = text[i];
        char b = (i + 1 < (int)text.size()) ? text[i + 1] : '\0';

        // last single letter
        if (b == '\0')
        {
            prepared += a;

            if (a == 'Z') prepared += 'X';
            else if (a == 'X') prepared += 'Z';
            else prepared += 'Z';

            break;
        }

        // same letter pair
        if (a == b)
        {
            prepared += a;

            if (a == 'X') prepared += 'Z';
            else prepared += 'X';

            i += 1;
        }
        else
        {
            prepared += a;
            prepared += b;
            i += 2;
        }
    }

    return prepared;
}





/* ---------- Encryption ---------- */
string encryptPlayfair(string plaintext, char matrix[5][5])
{
    string text = preparePlaintext(plaintext);
    string cipher = "";

    for (int i = 0; i < text.length(); i += 2)
    {
        int r1, c1, r2, c2;
        findPosition(matrix, text[i], r1, c1);
        findPosition(matrix, text[i + 1], r2, c2);

        if (r1 == r2) // same row
        {
            cipher += matrix[r1][(c1 + 1) % 5];
            cipher += matrix[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2) // same column
        {
            cipher += matrix[(r1 + 1) % 5][c1];
            cipher += matrix[(r2 + 1) % 5][c2];
        }
        else // rectangle
        {
            cipher += matrix[r1][c2];
            cipher += matrix[r2][c1];
        }
    }

    return cipher;
}

/* ---------- Decryption ---------- */
string decryptPlayfair(string ciphertext, char matrix[5][5])
{
    ciphertext = cleanInput(ciphertext);
    string plain = "";

    for (int i = 0; i < ciphertext.length(); i += 2)
    {
        int r1, c1, r2, c2;
        findPosition(matrix, ciphertext[i], r1, c1);
        findPosition(matrix, ciphertext[i + 1], r2, c2);

        if (r1 == r2) // same row
        {
            plain += matrix[r1][(c1 + 4) % 5];
            plain += matrix[r2][(c2 + 4) % 5];
        }
        else if (c1 == c2) // same column
        {
            plain += matrix[(r1 + 4) % 5][c1];
            plain += matrix[(r2 + 4) % 5][c2];
        }
        else // rectangle
        {
            plain += matrix[r1][c2];
            plain += matrix[r2][c1];
        }
    }

    return plain;
}








int main()
{
    char matrix[5][5];
    string text, keyword;
    int choice;

    while (true)
    {
        cout << "\n=== Playfair Cipher ===\n";
        cout << "1. Encrypt\n2. Decrypt\n3. Exit\nChoice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 3)
            break;

        cout << "Enter keyword: ";
        getline(cin, keyword);
        buildMatrix(keyword, matrix);

        cout << "Enter text: ";
        getline(cin, text);

        if (choice == 1)
        {
            cout << "Ciphertext: " << encryptPlayfair(text, matrix) << endl;
        }
        else if (choice == 2)
        {
            cout << "Plaintext: " << decryptPlayfair(text, matrix) << endl;
        }
        else
        {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

