#include <stdio.h>
#include <cs50.h>
#include <string.h>


void get_ascii(string word);
int main(void)
{
    get_ascii("Tomato");
}

void get_ascii(string word)
{
    char c;
    // word = tolower(word);
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        c = word[i];
        printf("%d", c);
    }
}