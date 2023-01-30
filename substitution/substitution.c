#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool validate_string(string s);
string cipher_text(string key, string plaintext);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (!validate_string(argv[1]))
    {
        return 1;
    }
    string input = get_string("plaintext: ");
    printf("ciphertext: ");
    printf("%s", cipher_text(argv[1], input));
    printf("\n");
    return 0;
}


bool validate_string(string s)
{
    int check = 1 ;
    int repeated = 0;
    int index = 0;
    if (strlen(s) != 26)
    {
        check = 0;
        printf("Usage: ./substitution key must containt 26 characters\n");
    }
    for (int i = 0; i < strlen(s) ; i++)
    {
        if (!isalpha(s[i]))
        {
            printf("Usage: ./substitution key must contain only alphabetical characters\n");
            check = 0;
            break;
        }
        for (int j = i + 1 ; j < strlen(s) ; j++)
        {
           if (s[i] == s[j])
           {
            printf("Usage: ./substitution key must not contain repeating characters\n");
            check = 0;
            break;
           }
        }
    }
    return check == 1 ? true : false;
}


string cipher_text(string key, string plaintext)
{
    int index = 0 ;
    int cipher[26];
    for (int i = 0 ; i < strlen(key) ; i++)
    {

        cipher[i] = key[i];
    }

    for (int j = 0 ; j < strlen(plaintext) ; j++)
    {
        if (isalpha(plaintext[j]))
        {
            if (isupper(plaintext[j]))
            {
                index = plaintext[j] % 65;
                plaintext[j] = toupper(cipher[index]);
            }
            else if (islower(plaintext[j]))
            {
                index = plaintext[j] % 97;
                plaintext[j] = tolower(cipher[index]);
            }

        }

    }
    return plaintext;
}


