#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // static array
    int numbers [] = {20, 500, 10, 5, 100, 1, 50};
    // or
    // int numbers[7];
    // numbers[0] = 20;
    // numbers[1] = 500;
    // ... and so on --- same thing

    int n = get_int("Number: ");
    //linear search
    for (int i = 0 ; i < 7 ; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
}