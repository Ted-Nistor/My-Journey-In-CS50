#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

// float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }
    float total_hours = calc_hours(hours[weeks], weeks);
    printf("Total Hours: %.1f\n", total_hours);

    // char output;
    // do
    // {
    //     output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    // }
    // while (output != 'T' && output != 'A');

    // printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// // TODO: complete the calc_hours function
float calc_hours(int hours[], int weeks, char output)
{
    int sum = 0;
    for (int i = 0 ; i < weeks ; i++)
    {
        sum += hours[i];
    }
    return sum;
}