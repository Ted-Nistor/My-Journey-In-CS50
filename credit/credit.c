#include <cs50.h>
#include <stdio.h>

long prompt_card(void);
int length(long x);
void check_sum(long x);

int main(void)
{
    long card = prompt_card();
    printf("Card Number: %li\n", card);
    int card_length = length(card);
    printf("Card Length: %i\n", card_length);
    check_sum(card);
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

void check_sum(long x)
{
    int num = 0;
    printf("Num: ");
    while (x > 0)
    {
        num = x%10;
        printf("%i ", num);
        num = 0;
        x/=10;
    }
    printf("\n");
}