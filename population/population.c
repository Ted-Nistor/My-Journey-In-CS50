#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
       start= get_int("Type starting population: ");
    }
    while(start<9);
    // TODO: Prompt for end size
    int end;
    do
    {
        end= get_int("Type ending population: ");
    }
    while(end<start);
    // TODO: Calculate number of years until we reach threshold
    int years;
    
    // TODO: Print number of years
}
