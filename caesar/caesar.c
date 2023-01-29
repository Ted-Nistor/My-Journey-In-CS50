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
        int remainder
        if (isalpha(phrase[i]))
        {
            if (isupper(phrase[i]) && (phrase[i] + key) % 65 > 25)
            {
                phrase[i] = 64 +
            }
            // phrase[i] += key;
        }
    }
    printf("%s\n", phrase);
}
