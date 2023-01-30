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

// Function to validate the string
bool validate_string(string s)
{
    //If everything is ok, the check should remain equal to 1
    int check = 1 ;
    // First check if the string has 26 characters
    if (strlen(s) != 26)
    {
        check = 0;
        printf("Usage: ./substitution key must containt 26 characters\n");
    }
    // Then loop through each character
    for (int i = 0; i < strlen(s) ; i++)
    {
        // check if the character is alphabetical
        if (!isalpha(s[i]))
        {
            printf("Usage: ./substitution key must contain only alphabetical characters\n");
            check = 0;
            break;
        }
        // Create a second loop starting from i+1 and check if the characters are repeating
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

//Function to conver the string to cipher text
string cipher_text(string key, string plaintext)
{
    // Initialize a 26 elements array for the cipher
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


