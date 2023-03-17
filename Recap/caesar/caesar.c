#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


void caesar (int key, string text);
bool only_digits(string key);
int main(int argc, string argv[])
{
    if (argc != 2 )
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    caesar(atoi(argv[1]), text);
}

bool only_digits(string s)
{
    int check = 0;
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        // loop through each character and check if it's a digit
        if (isdigit(s[i]))
        {
            check = 1;
        }
        else
        {
            check = 0;
        }
    }
    return check == 1 ? true : false ;
}

void caesar (int key, string text)
{
    int temp;
    printf("ciphertext: ");
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            temp = toupper(text[i]);
            if (temp + key > 90)
            {
                temp = 65 + (temp % 65 + key) % 26;
            }
            else
            {
                temp = temp + key;

            }
            if (text[i] == toupper(text[i]))
            {
                printf("%c",temp);

            }
            else if (text[i] == tolower(text[i]))
            {
                printf("%c",tolower(temp));
            }

        }
        else
        {
            printf("%c", text[i]);
        }
    }
    printf("\n");
}


