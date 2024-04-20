#include <stdio.h>

int get_height_pyramid(void);
void build_pyramid(int);
void build_double_pyramid(int);

int calculate_empty_space(int, int);
void empty_space(int);
void laying_brick(int);
void to_descend(void);

int main(void)
{
    int height = get_height_pyramid();

    build_pyramid(height);
    build_double_pyramid(height);
}

void build_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        int amount = calculate_empty_space(height, i);

        empty_space(amount);
        laying_brick(i);
        to_descend();
    }
}

void build_double_pyramid(int height)
{
    for (int i = 0; i < height; i++)
    {
        int amount = calculate_empty_space(height, i);
        int SPACEBETWEENPYRAMIDS = 2;

        empty_space(amount);
        laying_brick(i);
        empty_space(SPACEBETWEENPYRAMIDS);
        laying_brick(i);
        to_descend();
    }
}

int calculate_empty_space(int subtracted, int subtraction)
{
    subtraction++;
    int difference = subtracted - subtraction;
    return difference;
}

void empty_space(int amount)
{
    for (int i = 0; i < amount; i++)
    {
        printf(" ");
    }
}

void laying_brick(int amount)
{
    printf("#");
    for (int i = 0; i < amount; i++)
    {
        printf("#");
    }
}

void to_descend(void)
{
    printf("\n");
}

int get_height_pyramid(void)
{
    int heightPyramid;
    do
    {
        heightPyramid = 6;
    }
    while (heightPyramid < 1 || heightPyramid > 8);

    return heightPyramid;
}