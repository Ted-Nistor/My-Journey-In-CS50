#include <stdio.h>
#include <cs50.h>
#include <string.h>

typedef struct
{
    string name;
    string number;
}
person;

int main (void)
{
    person people[2];
    people[0].name = "Carter";
    people[0].number = "+1-617-495-100";
    people[1].name = "David";
    people[1].number = "+1-949-250-2750";
    // first example
    // string names[] = {"Carter", "David"};
    // string numbers[]= {"+1-617-495-1000", "+1-949-468-2750"};


    string name = get_string("Name: ");
    for (int i = 0 ; i < 2 ; i++)
    {
        // first example
        // if (strcmp(names[i], name) == 0)
        if(strcmp(people[i].name, name) == 0)
        {
            printf("Found %s\n", people[i].number);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}