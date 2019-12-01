#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // get positie number between 1 and 8
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1 || n > 8);
    //line by line
    for(int i = 0; i < n; i++)
    {
        //space in front of each line
        for(int j = i; j < n - 1; j++)
            printf(" ");
        //1st pyramid in that line
        for(int k = n - i; k <= n; k++)
            printf("#");
        printf("  ");
        //2nd pyramin in that line
        for(int k = n - i; k <= n; k++)
            printf("#");
        printf("\n");
    }  
}
