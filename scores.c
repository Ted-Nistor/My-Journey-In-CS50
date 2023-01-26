#include <stdio.h>
#include <cs50.h>

const int N = 3;
float average(int array[]);
int main(void)
{
    int scores[3];
    for (int i = 0 ; i < 3 ; i++)
    {
        scores[i] = get_int("Score:");
    }

    printf("Average: %f\n", average(scores));
}

float average(int array[])
{

}