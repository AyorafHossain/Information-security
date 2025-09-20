#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char text[1000], key[1000], result[1000] = "";
    int choice;

    printf("Vigenere Cipher\n");
    printf("1. Encrypt\n2. Decrypt\nChoose option : ");
    scanf("%d", &choice);
    getchar();

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    int keyIndex = 0;
    int textLen = strlen(text);
    int keyLen = strlen(key);

    for (int i = 0; i < textLen; i++)
    {
        char ch = text[i];
        if (isalpha(ch))
        {
            char k = toupper(key[keyIndex % keyLen]);
            keyIndex++;

            char c;

            // encryption
            if (choice == 1)
            {
                c = toupper(ch) + (k - 'A');
                if (c > 'Z') c -= 26;
            }



            // decryption
            else
            {
                c = toupper(ch) - (k - 'A');
                if (c < 'A') c += 26;
            }
            result[i] = c;
        }
        else
        {
            result[i] = ch;
        }
    }
    result[textLen] = '\0';
    if (choice == 1)
        printf("Ciphertext: %s\n", result);
    else
        printf("Decrypted text: %s\n", result);

    return 0;
}

