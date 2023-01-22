#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 8;
    for (int i=0;i<height;i++)
    {
        for(int j=height - 1;j<=height ;j++)
        {
        printf("#");
        }
    printf("\n");
    }

}