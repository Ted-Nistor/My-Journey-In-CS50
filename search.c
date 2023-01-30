#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // static array
    // int numbers [] = {20, 500, 10, 5, 100, 1, 50};
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    // or
    // int numbers[7];
    // numbers[0] = 20;
    // numbers[1] = 500;
    // ... and so on --- same thing

    // int n = get_int("Number: ");
    string s = get_string("String: ")l
    //linear search
    // for (int i = 0 ; i < 7 ; i++)
    // {
    //     if (numbers[i] == n)
    //     {
    //         printf("Found\n");
    //         return 0;
    //     }
    // }
    // printf("Not found\n");
    // return 1;
    // for the strings example
    for (int i = 0 ; i < 7 ; i ++)
    {
        if (strings[i] == s)
        {
            printf("Found\n");
            return 0;
        }
        printf("Not found\n");
        return 1;
    }
}