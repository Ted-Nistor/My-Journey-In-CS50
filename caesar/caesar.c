#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

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
    
}
