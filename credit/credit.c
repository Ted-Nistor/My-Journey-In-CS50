#include <cs50.h>
#include <stdio.h>

long prompt_card(void);
int main(void)
{
    long card = prompt_card();
    printf("Card Number: %li\n", card);
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