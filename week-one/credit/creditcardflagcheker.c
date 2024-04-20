#include <stdio.h>

void credit_card_flag_checker(long);
void card_flag_visa(long);
void card_flag_master_card(long);
void card_flag_american_express(long);

int get_first_two_digits(long);
int digit_counter(long);
long decrement_last_digit(long);
int get_last_digit(long);
int decrement_two(int);

int main(void)
{
    long creditCardNumber = 5603600000000014;

    credit_card_flag_checker(creditCardNumber);
}

void credit_card_flag_checker(long creditCardNumber)
{
        card_flag_visa(creditCardNumber);
        card_flag_master_card(creditCardNumber);
        card_flag_american_express(creditCardNumber);
}

void card_flag_visa(long creditCardNumber)
{
    int numberOfDigits = digit_counter(creditCardNumber);
    int firstTwoDigits = get_first_two_digits(creditCardNumber);

    if ((numberOfDigits == 13 || numberOfDigits == 16) &&
        (firstTwoDigits > 39 && firstTwoDigits < 50))
    {
        printf("VISA \n");
    }
}

void card_flag_master_card(long creditCardNumber)
{
    int numberOfDigits = digit_counter(creditCardNumber);
    int firstTwoDigits = get_first_two_digits(creditCardNumber);

    if (numberOfDigits == 16 && (firstTwoDigits > 50 && firstTwoDigits < 56))
    {
        printf("MASTERCARD \n");
    }
}

void card_flag_american_express(long creditCardNumber)
{
    int numberOfDigits = digit_counter(creditCardNumber);
    int firstTwoDigits = get_first_two_digits(creditCardNumber);

    if (numberOfDigits == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
    {
        printf("AMERICANEXPRESS \n");
    }
}

int get_first_two_digits(long value)
{
    long firstTwoDigits = value;
    int amount = digit_counter(firstTwoDigits);

    while (amount > 2)
    {
        firstTwoDigits = decrement_last_digit(firstTwoDigits);
        amount = digit_counter(firstTwoDigits);
    }

    return firstTwoDigits;
}

int digit_counter(long value)
{
    int counter = 0;

    while (value > 0)
    {
        value = decrement_last_digit(value);
        counter++;
    }

    return counter;
}

long decrement_last_digit(long value)
{
    long valueMinusLastDigit = value / 10;

    return valueMinusLastDigit;
}

int get_last_digit(long value)
{
    int lastDigit = value % 10;

    return lastDigit;
}