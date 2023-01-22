#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");
    float z = x/y;
    printf("%f\n",z);
}