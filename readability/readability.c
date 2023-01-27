#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_letters(string paragraph);

int main(void)
{
    // get string input from the user and print it.
    string paragraph = get_string("Text: ");
    printf("%s\n", paragraph);
    printf("%i letters\n", count_letters(paragraph));
}

// make a letter counter by incrementing the counter if
//the character is alphabetical
int count_letters(string paragraph)
{
    int counter = 0;
    for (int i = 0 ; i < strlen(paragraph) ; i++)
    {
        if (isalpha(paragraph[i]))
        {
            counter++;
        }
    }
    return counter;
}

//initialize a word counter
int count_words(string paragraph)
{
    int words = 0;
    
    for (int i = 0 ; i < strlen(paragraph) ; i++)
    {

    }

}