#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // get string input from the user and print it.
    long paragraph = get_string("Text: ");
    printf("%\n", paragraph);

}