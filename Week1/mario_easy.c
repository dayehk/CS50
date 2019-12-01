#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    //get positive # between 1 and 8
    do
        n = get_int("Height: ");
    while (n <1 || n > 8);
    //repeat line by line
    for (int i = 0; i < n; i++)
    {
        //space before blocks(#)
        for (int j = i + 1; j < n; j++)
            printf(" ");
        //the part of pyramid
        for (int k = n - i; k <= n; k++)
            printf("#");
        printf("\n");
    }
}
