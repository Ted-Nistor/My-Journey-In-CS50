// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

void replace(string argv[1]);
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n", replace(&argv[1]));
        return 0;
    }
    else
    {
        printf("Missing or exceeding command line\n");
        return 1;
    }
}

void replace(string argv[1])
{
    string new_word;
    for (int i = 0 ; i < strlen(argv[1]) ; i++)
    {
        if (argv[1][i] == 'A' || argv[1][i] == 'a' )
        {
            argv[1][i] = '6';
        }
        else if (argv[1][i] == 'E' || argv[1][i] == 'e')
        {
            argv[1][i] = '3';
        }
        else if (argv[1][i] == 'I' || argv[1][i] == 'i')
        {
            argv[1][i] = '1';
        }
        else if (argv[1][i] == 'O' || argv[1][i] == 'o')
        {
            argv[1][i] = '0';
        }
    }
    new_word = argv[1];
    return new_word;

}
