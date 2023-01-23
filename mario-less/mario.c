#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 3;
    for (int i=0;i<height;i++)
    {

        for(int j=0;j<=height ;j++)
        {
            if (j == (height-i))
            {
                printf(".");
            }
        }
    printf("\n");
    }

}