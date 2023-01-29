#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, int arvg[])
{

}

bool validate_key(string s)
{
    if (strlen(s) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0 ; i < strlen(s) ; i++)
    {
        if(!isalpha(s))
        {
            prinf("Usage: ./substitution key\n");
        }
    }
}