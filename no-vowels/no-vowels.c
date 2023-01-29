// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string word);
int main(int argc, string argv[])
{
    if (argc == 2)
    {
        printf("%s\n", replace(argv[1]));
        return 0;
    }
    else
    {
        printf("Missing or exceeding command line\n");
        return 1;
    }
}

string replace(string word)
{
    for (int i = 0 ; i < strlen(word) ; i++)
    {
        if (word[i] == 'A' || word[i] == 'a' )
        {
            word[i] = '6';
        }
        else if (word[i] == 'E' || word[i] == 'e')
        {
            word[i] = '3';
        }
        else if (word[i] == 'I' || word[i] == 'i')
        {
            word[i] = '1';
        }
        else if (word[i] == 'O' || word[i] == 'o')
        {
            word[i] = '0';
        }
    }

    return word;

}
