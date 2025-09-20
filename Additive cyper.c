#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt using Additive Cipher
void encrypt(char plaintext[], int key)
{
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        char ch = plaintext[i];
        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            plaintext[i] = (ch - base + key) % 26 + base;
        }
    }
}

// Function to decrypt using Additive Cipher
void decrypt(char ciphertext[], int key)
{
    for (int i = 0; ciphertext[i] != '\0'; i++)
    {
        char ch = ciphertext[i];
        if (isalpha(ch))
        {
            char base = isupper(ch) ? 'A' : 'a';
            plaintext[i] = (ch - base - key + 26) % 26 + base;
        }
    }
}

int main()
{
    char text[100];
    int key, choice;

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin);

    // remove newline if present
    text[strcspn(text, "\n")] = 0;

    printf("Enter key (number): ");
    scanf("%d", &key);

    printf("Choose option:\n1. Encrypt\n2. Decrypt\nEnter choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        encrypt(text, key);
        printf("Encrypted Text: %s\n", text);
    }
    else if (choice == 2)
    {
        decrypt(text, key);
        printf("Decrypted Text: %s\n", text);
    }
    else
    {
        printf("Invalid choice!\n");
    }

    return 0;
}

