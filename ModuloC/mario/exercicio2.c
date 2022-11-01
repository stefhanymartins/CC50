#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int a, i, j;
    do
    {
        //Solicita a altura do usuario
        a = get_int("Altura: ");
    }
    while (a < 1 || a > 8); //condição para o loop
    //Criando a pirâmide doble
    for (i = 0; i < a; i++)
    {
        for (j = 0; j < a; j++)
        {
            //condição para os espaços em branco
            if (i + j < a - 1)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("  #");

        for (j = 0; j < a; j++)
        {
            if (i + j > a - 1)
            {
                printf("#");
            }
        }
        printf("\n");
    }
}
