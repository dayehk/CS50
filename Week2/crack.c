#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

char *get_salt(char *hash);
void rotate(char *str, int *l, char c);

int main(int argc, string argv[])
{
    char *key = malloc(3);
    
    if (argc == 2)
    {
        key = get_salt(argv[1]);
        char *pw = malloc(6);
        //only in lowercase
        pw[0] = 'a';
        for (int l = 0; strcmp(pw, "zzzzz") != 0; pw[l]++)
        {
            rotate(pw, &l, 'a');
            if (strcmp(crypt(pw, key), argv[1]) == 0)
            {
                printf("pw: %s\n", pw);
                return 0;
            }
        }
        //initializing
        for (int i = 0; i < 5; i++)
        {
            pw[i] = '\0';
        }
        //only in uppercase
        pw[0] = 'A';
        for (int l = 0; strcmp(pw, "ZZZZZ") != 0; pw[l]++)
        {
            rotate(pw, &l, 'A');
            if (strcmp(crypt(pw, key), argv[1]) == 0)
            {
                printf("pw: %s\n", pw);
                return 0;
            }
        }

        printf("wrong\n");
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
}


//function that gets salt from hash
char *get_salt(char *hash)
{
    char *salt = malloc(3);
    salt[0] = hash[0];
    salt[1] = hash[1];
    salt[2] = '\0';
    
    return salt;
}

void rotate(char *str, int *l, char c)
{
    if (str[*l] == c + 'z' - 'a' + 1)
    {
        for (int i = *l; i >= 0; i--)
        {
            if (str[i] == c + 'z' - 'a' + 1)
            {
                if (i != 0)
                {
                    str[i - 1]++;
                }
                else
                {
                    *l = *l + 1;
                    for (int j = 0; j <= *l; j++)
                    {
                        str[j] = c;
                    }
                }
            }
            else 
            {
                break;
            }
        }
    }   
}
