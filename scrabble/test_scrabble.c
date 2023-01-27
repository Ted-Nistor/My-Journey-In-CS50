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
        
    }
    printf("the word is: %s\n", word);
    printf("the word has %i letters\n", n);
    for (int i = 0 ; i < strlen(word); i++)
    {
        printf("%d, \n", word[i]);
    }
}