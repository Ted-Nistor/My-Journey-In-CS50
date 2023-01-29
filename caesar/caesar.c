#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void cypher(string phrase, int key);
int main(int argc, string argv[])
{
    if (argc != 2 || !atoi(argv[1]) || atoi(argv[1]) < 0 )
    {
         printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        string phrase = get_string("plaintext: ");
        cypher(phrase, atoi(argv[1]));
        return 0;
    }

}

void cypher(string phrase, int key)
{
    for (int i = 0 ; i < strlen(phrase) ; i++)
    {
        if (isalpha(phrase[i]))
        {
            phrase[i] += key;
        }
    }
    printf("%s\n", phrase);
}
