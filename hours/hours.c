#include <cs50.h>
#include <ctype.h>
#include <stdio.h>


int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];
    int sum = 0;

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
        sum += hours[i];
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    if (output == 'T')
    {
        printf("T: %.1f hours\n", (float) sum);
    }
    else
    {
        printf("A: %.1f hours\n", (float) sum / weeks);
    }


}

