#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 4;
    for (int i=0;i<height;i++)
    {
        for(int j=height-i;j<=height ;j++)
        {
        printf("#");
        }
    printf("\n");
    }

}