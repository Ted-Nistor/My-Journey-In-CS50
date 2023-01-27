#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


int main(void)
{
    string word = get_string("Word: ");
    int n = strlen(word);
    for (int i = 0 ; i < n ; i ++)
    {
        word[i] = toupper(word[i]);
    }
    printf("the word is: %s\n", word);
    printf("the word has %i letters\n", n);
    int letter = 0;
    for (int i = 0 ; i < n ; i++)
    {
        letter = printf("%d", word[i]);
        return letter;
    }
}