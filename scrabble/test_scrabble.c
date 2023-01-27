#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int ascii_alphabet[] = {65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90};
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
    int index = -1;
    for (int i = 0 ; i < n ; i++)
    {
        letter = printf("%d", word[i]);
        for (int j = 0 ; j < 25 ; j ++)
        {
            if (ascii_alphabet[i] == letter)
            {
                printf("indexes: %i, ", i);
            }
        }
    }
    printf("\n");

}
