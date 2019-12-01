#include <cs50.h>
#include <stdio.h>
#include <string.h>

int check_num(char s[]);

int main(int argc, string argv[])
{
    string txt;
    if (argc == 2 && argv[1] >= 0 && check_num(argv[1]))
    {
        txt = get_string("plaintext: ");
        int n = strlen(txt);
        for (int i = 0; i < n; i++)
        {
            //for lower_case alphabet
            if (txt[i] >= 'a' && txt[i] <= 'z')
            {
                txt[i] = (txt[i] - 'a' + atoi(argv[1])) % 26 + 'a';            
            }
            //for upper_case alphabet
            else if (txt[i] >= 'A' && txt[i] <= 'Z')
            {
                txt[i] = (txt[i] - 'A' + atoi(argv[1])) % 26 + 'A';                
            }
            //pass for other character(ex. , / . " ' etc.)
        }
        printf("ciphertxext: %s\n", txt);
    }        
    else
    {
        printf("Usage: ./caesar key\n");
    }
}

//check if the input is number or not
int check_num(char s[])
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] < '0' || s[i] > '9')
        {
            return 0;
        }
    }
    return 1;
}
