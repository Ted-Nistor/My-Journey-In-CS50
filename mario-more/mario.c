#include <cs50.h>
#include <stdio.h>

int get_size (void);
int main(void)
{
//Prompt the height of the blocks
    int height = get_size();
    printf("%i\n",height);
//Print the number of rows equal to height ;
    for (int rows = 0 ; rows < height ; rows++)
    {
//Print spaces before #
        for (int space = (height-rows-1); space > 0 ; )
    }

}


int get_size ()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    return n;
}