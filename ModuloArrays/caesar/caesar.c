#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

void cipher_text(string plaintext, int key);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //check if argv[1] is a positive digit
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            if (isdigit(argv[1][i]) == false)
            {
                printf("no argument or empty");
                return 1;
            }
        }

        //convert argv[1] to a int
        int key = atoi(argv[1]);

        //prompt user
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");

        //encipher
        //output ciphertext
        cipher_text(plaintext, key);
    }
    else
    {
        //not is a decimal digit
        printf("Use: ./caesar key\n");
        return 1;
    }
    printf("\n");
}

void cipher_text(string plaintext, int key)
{
    //preserving uppercase and lowercase letters:
    for (int i = 0; i < strlen(plaintext); i++)
    {
        //lowercase letters
        if (plaintext[i] >= 'a' && plaintext[i] <= 'z')
        {
            printf("%c", ((plaintext[i] - 'a' + key) % 26) + 'a');
        }
        //uppercase letters
        if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c", ((plaintext[i] - 'A' + key) % 26) + 'A');
        }
        //is alphabetic
        else if (isalpha(plaintext[i]) == false)
        {
            printf("%c", plaintext[i]);
        }
    }
}