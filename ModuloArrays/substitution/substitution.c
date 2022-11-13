#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void substitution(string key);
void substitution_value(char position, string key);

int main(int argc, string argv[])
{
    if (argc == 2)//checks if there is only 2 strings
    {
        if (strlen(argv[1]) == 26) //checks if the argument contain only 26 characters
        {
            for (int i = 0; i < strlen(argv[1]); i++)//loop through the argument string
            {
                if (!isalpha(argv[1][i]))//checks if there is only alphabetical characters in the key string
                {
                    printf("Key must contain 26 characters.\n");
                    return 1;
                }

                //checks if the key contains repeated characters
                for (int j = i + 1; j < strlen(argv[1]); j++)
                {
                    if (toupper(argv[1][i]) == toupper(argv[1][j]))
                    {
                        printf("Key must not contain repeated characters.\n");
                        return 1;
                    }
                }
            }

            //execute the substitution function
            substitution(argv[1]);

        }
        else
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

}

//substitution function
void substitution(string key)
{
    //get plaintext and store it in plaintext string
    string plaintext = get_string("plaintext: ");

    //get the length of the plaintext and store it in an integer
    int plaintext_length = strlen(plaintext);

    printf("ciphertext: ");
    //iterate through the plaintext string
    for (int k = 0; k < plaintext_length; k++)
    {
        //checks if the plantext has only alphabatical characters
        if (isalpha(plaintext[k]))
        {
            char plaintext_character = plaintext[k];
            if (islower(plaintext_character))
            {
                substitution_value(tolower(plaintext_character), key);
            }
            else
            {
                substitution_value(toupper(plaintext_character), key);
            }
        }
        else
        {
            printf("%c", plaintext[k]);
        }
    }
    printf("\n");
}

void substitution_value(char position, string key)
{
    string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    for (int i = 0; i < strlen(abc); i++)
    {
        if (islower(position))
        {
            if (position == tolower(abc[i]))
            {
                printf("%c", tolower(key[i]));
            }
        }
        else
        {
            if (position == toupper(abc[i]))
            {
                printf("%c", toupper(key[i]));
            }
        }
    }
}