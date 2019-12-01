#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_positive_input(string prompt);
void coin(int *a, int *b, int n);

int main(void)
{
    float input = get_positive_input("Change Owed: ");
    int total = 0, num = round(input * 100);
    coin(&num, &total, 25);
    coin(&num, &total, 10);
    coin(&num, &total, 5);
    coin(&num, &total, 1);
    printf("%i\n", total);
}

// get only positive number as input
float get_positive_input(string prompt)
{
    float input;
    do
    {
        input = get_float("%s", prompt);        
    }
    while (input < 0);
    return input;
}

//With n(25, 10, 5, or 1), get # of n_cents coin and substract it from total
void coin(int *a, int *b, int n)
{
    if (*a / n >= 1)
    {
        *b += *a / n;
        *a -= (*a / n) * n;
    }
}
