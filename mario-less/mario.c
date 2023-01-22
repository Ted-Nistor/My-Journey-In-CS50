#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 8;
    for (int i = 0 ; i < height ; i ++)
    {
        if (i <height-1)
        {
            printf(".");
        }
        else
        {

        printf("#");
        }
    }
    printf("\n");
}