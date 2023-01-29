#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void rotate(string phrase, int key);
int main(int argc, string argv[])
{
    if (argc != 2 || !atoi(argv[1]) || atoi(argv[1]) < 0 )
    {
         printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string phrase = get_string("plaintext:  ");
        rotate(phrase, atoi(argv[1]));
        printf("\n");
        return 0;
    }

}

void rotate(string phrase, int key)
{
    for (int i = 0 ; i < strlen(phrase) ; i++)
    {
        int code_phrase = phrase[i] + key;
        if (isalpha(phrase[i]))
        {
           if (isupper(phrase[i]))
            {
                if (code_phrase <= 90)
                {
                    phrase[i] += key;
                }
                else
                {
                    phrase[i] = 64 + (code_phrase % 90);
                }
            }
            else if (islower(phrase[i]))
            {
                    if (code_phrase <= 122 )
                    {
                        phrase[i] += key;
                    }
                    else
                    {
                        phrase[i] = 96 + (code_phrase % 122);
                    }
            }

        }
    }
    printf("ciphertext: %s", phrase);
}
