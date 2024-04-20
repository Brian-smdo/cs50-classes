#include <stdio.h>

void credit_card_number_validator(long);
int luhn_algorithm(long);
int first_stage_luhn_alg(long);
int second_stage_luhn_alg(long);

int get_second_digit(long);
int add_products(int);
int digit_counter(long);
long decrement_last_digit(long);
int get_last_digit(long);
int decrement_two(int);

int main(void)
{
    long creditCardNumber = 343600000000014;

    credit_card_number_validator(creditCardNumber);
}

void credit_card_number_validator(long creditCardNumber)
{
    int creditCardNumberCode = luhn_algorithm(creditCardNumber);
    int validatorDigit = get_last_digit(creditCardNumberCode);

    if (validatorDigit > 0)
    {
        printf("Not valid \n");
    }
    else
    {
        printf("Valid \n");
    }
    printf("Credit card number code is: %i\n", creditCardNumberCode);
}

int luhn_algorithm(long creditCardNumber)
{
    int firstStageResult = first_stage_luhn_alg(creditCardNumber);
    int secondStageResult = second_stage_luhn_alg(creditCardNumber);
    int creditCardNumberCode = firstStageResult + secondStageResult;

    return creditCardNumberCode;
}

int first_stage_luhn_alg(long creditCardNumber)
{
    int counter = digit_counter(creditCardNumber);
    int stageResult = 0;

    while (counter > 0)
    {
        int extractDigit = get_second_digit(creditCardNumber);
        extractDigit = extractDigit * 2;
        extractDigit = add_products(extractDigit);
        stageResult = stageResult + extractDigit;

        creditCardNumber = decrement_last_digit(creditCardNumber);
        creditCardNumber = decrement_last_digit(creditCardNumber);
        counter = decrement_two(counter);
    }

    return stageResult;
}

int second_stage_luhn_alg(long creditCardNumber)
{
    int counter = digit_counter(creditCardNumber);
    int stageResult = 0;

    while (counter > 0)
    {
        int extractDigit = get_last_digit(creditCardNumber);
        stageResult = stageResult + extractDigit;

        creditCardNumber = decrement_last_digit(creditCardNumber);
        creditCardNumber = decrement_last_digit(creditCardNumber);
        counter = decrement_two(counter);
    }

    return stageResult;
}

int get_second_digit(long value)
{
    value = decrement_last_digit(value);
    int secondDigit = get_last_digit(value);

    return secondDigit;
}

int add_products(int value)
{
    if (value < 10)
    {
        int product = value;
        return product;
    }
    else
    {
        int product = get_last_digit(value);
        value = decrement_last_digit(value);
        product = product + value;

        return product;
    }
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

int decrement_two(int value)
{
    value = value - 2;

    return value;
}