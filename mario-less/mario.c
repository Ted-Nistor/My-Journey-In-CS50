#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 4;
    for (int i=0;i<height;i++)
    {
        for(int j=0;j<height - i;j++)
        {
        printf("#");
        }
    printf("\n");
    }

}