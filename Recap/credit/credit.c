#include <cs50.h>
#include <stdio.h>



long prompt_card(void);
int first_sum(long card);
int second_sum(long card);
int first_digits(long card);
int card_length(long card);


int main(void)
{
    long card = prompt_card();
    int a = first_sum(card);
    int b = second_sum(card);
    int check_sum = a + b;
    if (check_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    int digits = first_digits(card);
    int length = card_length(card);
    if ((digits / 10 == 5) && (0 < digits % 10 && digits % 10 < 6) && (length == 16))
    {
        printf("MASTERCARD\n");
    }
    else if ((digits / 10 == 3) && (digits % 10 == 4 || digits % 10 == 7) && (length == 15))
    {
        printf("AMEX\n");
    }
    else if ((digits / 10 == 4) && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }

}

long prompt_card(void)
{
    long card;
    do
    {
        card = get_long("Enter your card number: ");

    }
    while (card < 1);
    return card;
}

int first_sum(long card)
{
    int sum = 0;
    int product;
    while (card > 0)
    {
        product = 2 * ((card / 10) % 10);
        if (product >= 10)
        {
            product = ((product % 10) + (product / 10) );
            sum += product;
        }
        else
        {
            sum += product;
        }


        product = 0;
        card /= 100;

    }
    printf("Sum: %i\n", sum);
    return sum;
}

int second_sum(long card)
{
    int sum = 0;
    while (card > 0)
    {
        sum += card % 10;
        card /= 100;
    }
    printf("Second Sum: %i\n", sum);
    return sum;
}



int first_digits(long card)
{
    int first_digits = 0;
    while (card > 99)
    {
        first_digits = card /= 10;
    }
    return first_digits;
}
int card_length(long card)
{
    int length = 0;
    while (card > 0)
    {
        card /= 10;
        length++;
    }
    return length;

}






