#include <stdbool.h>
#include <stdio.h>

void credit_card_flag_checker(long long);
void card_flag_visa(long long);
void card_flag_master_card(long long);
void card_flag_american_express(long long);

int credit_card_number_validator(long long);
int luhn_algorithm(long long);
int first_stage_luhn_alg(long long);
int second_stage_luhn_alg(long long);

int get_first_two_digits(long long);
int get_second_last_digit(long long);
int add_products(int);
int digit_counter(long long);
long long decrement_last_digit(long long);
int get_last_digit(long long);
int decrement_two(int);
void invalid_input_message(void);

int main(void)
{
    long long creditCardNumber = 373600000000014;

    bool creditCardNumberValid = credit_card_number_validator(creditCardNumber);

    if (creditCardNumberValid)
    {
        credit_card_flag_checker(creditCardNumber);
    }
    else
    {
        invalid_input_message();
    }
}

void credit_card_flag_checker(long long creditCardNumber)
{
        card_flag_visa(creditCardNumber);
        card_flag_master_card(creditCardNumber);
        card_flag_american_express(creditCardNumber);
}

void card_flag_visa(long long creditCardNumber)
{
    int numberOfDigits = digit_counter(creditCardNumber);
    int firstTwoDigits = get_first_two_digits(creditCardNumber);

    if ((numberOfDigits == 13 || numberOfDigits == 16) &&
        (firstTwoDigits > 39 && firstTwoDigits < 50))
    {
        printf("VISA \n");
    }
}

void card_flag_master_card(long long creditCardNumber)
{
    int numberOfDigits = digit_counter(creditCardNumber);
    int firstTwoDigits = get_first_two_digits(creditCardNumber);

    if (numberOfDigits == 16 && (firstTwoDigits > 50 && firstTwoDigits < 56))
    {
        printf("MASTERCARD \n");
    }
}

void card_flag_american_express(long long creditCardNumber)
{
    int numberOfDigits = digit_counter(creditCardNumber);
    int firstTwoDigits = get_first_two_digits(creditCardNumber);

    if (numberOfDigits == 15 && (firstTwoDigits == 34 || firstTwoDigits == 37))
    {
        printf("AMEX \n");
    }
}

int credit_card_number_validator(long long creditCardNumber)
{
    int validator = 0;
    int creditCardNumberCode = luhn_algorithm(creditCardNumber);
    int validatorDigit = get_last_digit(creditCardNumberCode);

    if (validatorDigit > 0)
    {
        return validator;
    }
    else
    {
        validator++;
        return validator;
    }
}

int luhn_algorithm(long long creditCardNumber)
{
    int firstStageResult = first_stage_luhn_alg(creditCardNumber);
    int secondStageResult = second_stage_luhn_alg(creditCardNumber);
    int creditCardNumberCode = firstStageResult + secondStageResult;

    return creditCardNumberCode;
}

int first_stage_luhn_alg(long long creditCardNumber)
{
    int counter = digit_counter(creditCardNumber);
    int stageResult = 0;

    while (counter > 0)
    {
        int extractDigit = get_second_last_digit(creditCardNumber);
        extractDigit = extractDigit * 2;
        extractDigit = add_products(extractDigit);
        stageResult = stageResult + extractDigit;

        creditCardNumber = decrement_last_digit(creditCardNumber);
        creditCardNumber = decrement_last_digit(creditCardNumber);
        counter = decrement_two(counter);
    }

    return stageResult;
}

int second_stage_luhn_alg(long long creditCardNumber)
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

int get_second_last_digit(long long value)
{
    value = decrement_last_digit(value);
    int secondDigit = get_last_digit(value);

    return secondDigit;
}

int add_products(int value)
{
    int product = get_last_digit(value);

    value = decrement_last_digit(value);
    product = product + value;

    return product;
}

int get_first_two_digits(long long value)
{
    long long firstTwoDigits = value;
    int amount = digit_counter(firstTwoDigits);

    while (amount > 2)
    {
        firstTwoDigits = decrement_last_digit(firstTwoDigits);
        amount = digit_counter(firstTwoDigits);
    }

    return firstTwoDigits;
}

int digit_counter(long long value)
{
    int counter = 0;

    while (value > 0)
    {
        value = decrement_last_digit(value);
        counter++;
    }

    return counter;
}

long long decrement_last_digit(long long value)
{
    long long valueMinusLastDigit = value / 10;

    return valueMinusLastDigit;
}

int get_last_digit(long long value)
{
    int lastDigit = value % 10;

    return lastDigit;
}

int decrement_two(int value)
{
    value = value - 2;

    return value;
}

void invalid_input_message(void)
{
    printf("INVALID\n");
}