#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 8;
    for (int i=height;i>=0;i--)
    {
        for(int j=height - i;j<=height ;j++)
        {
        printf("#");
        }
    printf("\n");
    }

}