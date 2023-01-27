#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int sum = 0;
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

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
    while (output != 'T' || output != 'A' || output != 't' || output != 'a');

    if (output == 'T')
    {
        printf("%c = %i\n", output, sum);
    }
    else
    {
        printf("%c = %i\n", output ,sum / weeks);
    }



    // printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
// float calc_hours(int hours[], int weeks, char output)
// {

// }