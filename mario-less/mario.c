#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = get_int("Height: ");
    char space = ' ';
    char bricks='#';
    for (int i = 0 ; i < height ; i ++)
    {
        for (int j = 0 ; j <height ; j++)
        {
            printf("%c",bricks);
        }
        printf("\n");
    }
}