#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    // TO DO: Solicite o valor inicial ao usuário
    int start;
    do
    {
        start = get_int("Start Size: ");
    }
    while (start < 9);

    // TO DO: Solicite o valor final ao usuário
    int end;
    do
    {
        end = get_int("End Size: ");
    }
    while (start > end);

    // TO DO: Calcule o número de anos até o limite
    int current = start;
    int year = 0;
    while (current < end)
    {
        current = round(current + current / 3 - current / 4);
        year++;
    }

    // TO DO: Imprima o número de anos
    printf("Years: %i", year);
}