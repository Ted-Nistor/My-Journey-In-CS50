#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void cypher(string phrase, int key);
int main(int argc, string argv[])
{
    if (argc != 2 )
    {
        printf("Invalid input. Must contain one argument!\n");
        return 1;
    }
    else if (!atoi(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (atoi(argv[1]) < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string phrase = get_string("plaintext: ");
        cypher(phrase, argv[1]);
        return 0;
    }

}

void cypher(string phrase, int key)
{
    for (int i = 0 ; i < strlen(phrase) ; i++)
    {
        phrase[i] += key;
    }
    printf("%s\n", phrase);
}
