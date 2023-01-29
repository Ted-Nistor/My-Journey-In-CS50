#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool validate_string (string s);
// string cipher_text (string plaintext , string cipher);
void cipher_alphabet(string key);
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    // else if (atoi(argv[1]) != 26)
    // {
    //     printf("Key must contain 26 characters.\n");
    //     return 1;
    // }
    else if (!validate_string(argv[1]))
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        string input = get_string("plaintext: ");
        cipher_alphabet(argv[1]);
        printf("\n");
        return 0;
    }
}

bool validate_string (string s)
{
    int check = 0 ;
    int repeated = 0;
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        if (isalpha(s[i]))
        {
            check = 1;
        }
        else
        {
            check = 0;
        }
    }
    return check == 1 ? true : false;
}


void cipher_alphabet(string key)
{
    int index = 0 ;
    int cipher[26];
    printf("cipher alphabet: ");
    for (int i = 0 ; i < strlen(key) ; i++)
    {
        if ()
        cipher[i] = key[i];
        printf("%i, ",key[i]);

        for (int j = 0 ; )
    }
}
