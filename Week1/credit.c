#include <stdio.h>
#include <cs50.h>

long get_right_num(string prompt);
long ten_ntimes(int n);
int company(long num);
int if_valid(long num);

int main(void)
{
    long num = get_right_num("Number: ");
    if (company(num) == 1)
    {
        printf("AMEX\n");
    }
    else if (company(num) == 2)
    {
        printf("MASTERCARD\n");
    }
    else if (company(num) == 3)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");        
    }
}

//input n will be 10^n as output
long ten_ntimes(int n)
{
    long ten = 1;
    for (int i = 0; i < n; i++)
    {
        ten *= 10;
    }
    return ten;
}

//get number from user until right input comes
long get_right_num(string prompt)
{
    long n;
    do
    {
        n = get_long("%s", prompt);
    }
    while (n < 0);
    return n;
}

//check validation and a kind of company
int company(long num)
{
    long check = num / ten_ntimes(14);
    if ((num / ten_ntimes(13) == 34 || num / ten_ntimes(13) == 37) && if_valid(num))
    {
        return 1;
    }
    else if ((check == 51 || check == 52 || check == 53 || check == 54 || check == 55) && if_valid(num))
    {
        return 2;
    }
    else if ((num / ten_ntimes(12) == 4 || num / ten_ntimes(15) == 4) && if_valid(num))
    {
        return 3;
    }
    else
    {
        return 0;        
    }
}

//check validation(sum should be n times 10)
int if_valid(long num)
{
    int n1 = 0, n2 = 0;
    for (int i = 1; i < 16; i += 2)
    {
        n1 += (num / ten_ntimes(i) % 10 * 2) / 10 + (num / ten_ntimes(i) % 10 * 2) % 10;
    }
    for (int i = 0; i < 16; i += 2)
    {
        n2 += (num / ten_ntimes(i) % 10) / 10 + (num / ten_ntimes(i) % 10) % 10;        
    }
    if (((n1 + n2) % 10) == 0)
    {
        return 1;        
    }
    return 0;
}
