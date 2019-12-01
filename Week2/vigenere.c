#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_word(char *s);
int shift(char c);

int main(int argc, string argv[])
{
    if (argc == 2 && check_word(argv[1]))
    {
        string txt = get_string("plaintext: ");
        int n1 = strlen(txt);
        int n2 = strlen(argv[1]);
        for (int i = 0, j = 0; i < n1; i++)
        {
            //for lower_Case alphabet
            if (txt[i] >= 'a' && txt[i] <= 'z')
            {
                txt[i] = ((txt[i] + shift(argv[1][j++ % n2]) - 'a') % 26 + 'a');
            }
            //for upper_case alphabet
            else if (txt[i] >= 'A' && txt[i] <= 'Z')
            {
                txt[i] = ((txt[i] + shift(argv[1][j++ % n2]) - 'A') % 26 + 'A');
            }
        }
        printf("ciphertext: %s\n", txt);
    }
    else
    {
        printf("Usage: ./vigenere keyword\n");
        return 1;
    }

}

//check if the key is alphabet or not
int check_word(char s[])
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if ((s[i] < 'a' || s[i] > 'z') && (s[i] < 'A' || s[i] > 'Z'))
        {
            return 0;
        }
    }
    return 1;
}

// shift alphabet to key(number)
int shift(char c)
{
    int n = tolower(c) - 'a';
    return n;
}

