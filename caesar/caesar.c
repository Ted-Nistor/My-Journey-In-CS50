#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void rotate(string phrase, int key);
int main(int argc, string argv[])
{
    // If the you enter more than one arguments, or if you
    // don't enter an integer or if the integer argument is negative
    // exit the program with message "Usage: ./caesar key\n" and
    // return 1 as an error for the $? echo
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
    //loop through the letters of the phrase
    for (int i = 0 ; i < strlen(phrase) ; i++)
    {
        // make a temp variable to store the ascii formatted
        // letter + the assigned key (used for the rotation
        // and assigned from  the arv[1] argument up above.
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
                    code_phrase %= 90;
                    if (code_phrase > 25)
                    {
                        code_phrase %= 26;
                    }
                    phrase[i] = 65 + code_phrase;
                    printf("%c", phrase[i]);
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
                        phrase[i] = 96 + (code_phrase % 97 - 25 );
                    }
            }

        }
    }
    printf("ciphertext: %s", phrase);
}
