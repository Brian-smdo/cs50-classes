#include <stdio.h>

int coin_counter(int);
int converter_cents_int(float);
int amount_coins(float);
float get_limited_float(void);

int main(void)
{
    float money = get_limited_float();
    int amountCoins = amount_coins(money);

    printf("Amount of coins: %i\n", amountCoins);
}

float get_limited_float(void)
{
    float value;

    do
    {
        value = 54.45;
    }
    while (value < 0 || value > 9000);

    return value;
}

int amount_coins(float value)
{
    int cents = converter_cents_int(value);
    int amountCoins = coin_counter(cents);

    return amountCoins;
}

int converter_cents_int(float moneyWithCents)
{
    int moneyWithoutCents = moneyWithCents;
    float centsValue = moneyWithCents - moneyWithoutCents;
    centsValue = centsValue * 100.09;
    int centsValueInt = centsValue;

    return centsValueInt;
}

int coin_counter(int cents)
{
    int amount = 0;

    do
    {
        if (cents >= 25)
        {
            cents = cents - 25;
            amount++;
        }
        else if (cents >= 10 && cents < 25)
        {
            cents = cents- 10;
            amount++;
        }
        else if (cents >= 5 && cents < 10)
        {
            cents = cents - 5;
            amount++;
        }
        else if (cents >= 1 && cents <5)
        {
            cents = cents - 1;
            amount++;
        }
    }
    while (cents > 0);

    return amount;
}