#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void rotate(string phrase, int key);
bool only_digits(string s);
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
        // First check if the character is alphabetical

        if (isalpha(phrase[i]))
        {
            //Then check if the character is upper case or lower case
            printf("ciphertext: ");
            if (isupper(phrase[i]))
            {
                // Uppercase letters range from 65 (A) to 90 (Z)
                // Use the formula ciphered text = (letter + key)% 26
                // (since there are 26 letters in the alphabet)
                // If we consider the letter A to start at 0
                // and the letter Z to end at 25, then there are
                // 26 characters in the alphabet.
                // We always start from the letter A , so first
                // we consider the letter as being A (65), then
                // add the result of the formula
                // keep in mind to use % 65 on the letter
                // (since we are using ascii formatted letters)
                // and we want to get a value from 0 to 25.
                phrase[i]= 65 + ((phrase[i] % 65 + key) % 26);
            }
            else if(islower(phrase[i]))
            {
                // We do the same formula for the lower case letters
                // but we take the range from 97 (a) to 122 (z);
                phrase[i] = 97 + ((phrase[i] % 97 + key) % 26);
            }
        }
    }
    printf("%s", phrase);
}

bool only_digits(string s)
{
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        if (isdigit(s[i]))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}