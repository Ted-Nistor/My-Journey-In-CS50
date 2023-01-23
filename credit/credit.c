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
    int times_two = 0;
    printf("First_Set: \n");
    for (int i = 0 ; i < x ; i++)
    {
        num = (x/10)%10;
        printf("%i\n", num);
        times_two= num*2;
        printf("%i * 2 = %i\n",num,times_two);
        if(times_two >= 10)
        {
         above_ten=times_two%10 + num/10;
         sum+=above_ten;

        }
        else{
            sum+=(num*2);
        }
        num = 0;
        x/=100;
    }
    printf("\n");
    printf("Sum= %i\n",sum);
}