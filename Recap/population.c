#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_population;
    do
    {
        start_population = get_int("start_population : ");
    }
    while (start_population < 9);

    // TODO: Prompt for end size
    int end_population;
    do
    {
        end_population = get_int("end_population : ");
    }
    while (end_population < start_population);
    // TODO: Calculate number of years until we reach threshold
    int years;
    for (int i = 1; start_population < end_population; i++)
    {
        start_population += (start_population / 3 - start_population / 4 );
        years = i;
    }
    // TODO: Print number of years
    printf("Years: %i\n", years);
}
