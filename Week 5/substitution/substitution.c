#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>



int check_key(string s);
string rotate(string key, string text);
int main(int argc, string argv[])
{
    if (argc!= 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (check_key(argv[1]) == 0)
    {
        return 2;
    }
    string key = argv[1];
    string text = get_string("plaintext: ");
    string cipher = rotate(argv[1], text);
    printf("ciphertext: %s\n", cipher);




}

int check_key(string s)
{
    int check;
    for (int i = 0; i < strlen(s); i++)
    {
        s[i] = toupper(s[i]);
        if (isalpha(s[i]))
        {
            check = 1;
        }
        else
        {
            check = 0;
            printf("The key must contain only alphabetical chars\n");
        }
        for (int j = i + 1 ; j < strlen(s); j++)
        {
            if (s[i] == s[j])
            {
                check = 0;
                printf("Key must not contain repeating characters\n");
            }
        }
    }
    if (strlen(s) != 26)
    {
        check = 0;
        printf("Key must contain 26 characters.\n");
    }
    return check;
}

string rotate(string key, string text)
{
    int cipher[26];
    int index;

    for (int i = 0; i < strlen(key); i++)
    {
        cipher[i] = key[i];
    }
    for (int j = 0; j < strlen(text); j++)
    {

            index = toupper(text[j]) % 65;
            text[j] = cipher[index];


    }
    return text;

}

