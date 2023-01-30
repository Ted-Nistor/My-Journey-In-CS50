#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool validate_string (string s);
string cipher_alphabet(string key, string plaintext);
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
    printf("%s",cipher_alphabet(argv[1], input));
    printf("\n");
    return 0;
}


bool validate_string (string s)
{
    int check = 0 ;
    int repeated = 0;
    if (strlen(s) == 26)
    {
        for (int i = 0 ; i < strlen(s) ; i++)
        {
            s[i] = toupper(s[i]);
            if (isalpha(s[i]))
            {
            check = 1;
            }
            else
            {
            check = 0;
            printf("Usage: ./substitution key\n");
            }
        }
    }
    else {
        printf("Key must contain 26 characters.\n");
        check = 0;
    }

    return check == 1 ? true : false;
}


string cipher_alphabet(string key, string plaintext)
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


