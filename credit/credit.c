#include <cs50.h>
#include <stdio.h>

long prompt_card(void);
int length(long x);
void print_digits(long x);
int main(void)
{
    long card = prompt_card();
    printf("Card Number: %li\n", card);
    int card_length = length(card);
    printf("Card Length: %i\n", card_length);
    print_digits(card);
}


long prompt_card(void)
{
    long card;
    do
    {
        card = get_long("Enter your credit card number: ");
    }
    while (card < 1);
    return card;
}

int length(long x)
{
    int counter = 0;
    while (x > 0)
    {
        x= x / 10;
        counter++;
    }
    return counter;
}

void print_digits(long x)
{
    int digits;
    while(x > 0)
    {
        digits = x % 10;
        printf("%i ",digits);
        x/=10;
    }
}

