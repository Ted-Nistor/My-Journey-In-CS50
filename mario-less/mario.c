#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");
    for (int i = 0 ; i < height ; i ++)
    {
        for (int j = 1 ; j <height ; j++)
        {
            char space = '';
            char brick = '#';
            printf("#");
        }
        printf("\n");
    }
}