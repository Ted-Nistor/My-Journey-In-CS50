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
{   int sum = 0;
    int num = 0;
    int above_ten = 0;
    printf("First_Set: ");
    for (int i = 0 ; i < x ; i++)
    {
        num = (x/10)%10;
        printf("%i", num);
        if(num * 2 >= 10)
        {
         above_ten=(num*2)%10 + num/10;
         sum+=above_ten;
         above_ten = 0;
        }
        else{
            sum+=num;
        }
        num = 0;
        x/=100;
    }
    printf("\n");
    printf("Sum= %i\n",sum);
}