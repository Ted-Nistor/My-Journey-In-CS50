#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // get string input from the user and print it.
    string paragraph = get_string("Text: ");
    printf("%s\n", paragraph);

}

int count_letters(string paragraph)
{
    int counter = 0;
    for (int i = 0 ; i < strlen(paragraph) ; i++)
    {
        if (paragraph[i])
    }
}