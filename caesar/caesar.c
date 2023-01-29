#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int alphabet[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
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
        return 0;
    }

}

void cypher(string phrase, int key)
{
    for (int i = 0 ; i < strlen(phrase) ; i++)
    {

    }
}
