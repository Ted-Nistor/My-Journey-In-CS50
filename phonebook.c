#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main (void)
{
    string names[] = {"Carter", "David"};
    string numbers[]= {"+1-617-495-1000", "+1-949-468-2750"};

    string name = get_string("Name: ");
    for (int i = 0 ; i < 2 ; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[1]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}