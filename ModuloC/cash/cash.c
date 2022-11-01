#include <stdio.h>
#include <math.h>
#include <cs50.h>

int main(void)
{
    float reais;
    int centavos, moedas;
    int cent25, cent10, cent5, cent1;
    do
    {
        //Solicita o valor do pagamento
        reais = get_float("Qual o valor do pagamento: ");
    }
    while (reais <= 0); //condição para o loop

    //Transformando o valor do troco em centavos
    centavos = round(reais * 100);

    //printf("O valor troco é: %i \n", centavos);

    cent25 = 25;
    cent10 = 10;
    cent5 = 5;
    cent1 = 1;
    moedas = 0;

    //Subtraindo o valor do troco e incrementado o contador
    while (centavos >= cent25)
    {
        moedas++;
        centavos = centavos - cent25;
    }
    while (centavos >= cent10)
    {
        moedas++;
        centavos = centavos - cent10;
    }
    while (centavos >= cent5)
    {
        moedas++;
        centavos = centavos - cent5;
    }
    while (centavos >= cent1)
    {
        moedas++;
        centavos = centavos - cent1;
    }
    //Quantidade de moedas utilizadas
    printf("%i \n", moedas);
}