#include <stdio.h>
#include<stdbool.h>
#include <cs50.h>

bool validarCartao(long ccnumero) ;
int ccQuantidadeDeNumeros(long ccnumero) ;
bool calculandocc(long ccnumero) ;
void mostrarBandeiraDoCartao(long ccnumero) ;

int main(void)
{
    long ccnumero;
    do
    {
        ccnumero = get_long("Enter your credit card number: ") ;
    }
    while (ccnumero <= 0) ;

    if (validarCartao(ccnumero))
    {
        mostrarBandeiraDoCartao(ccnumero) ;
    }
    else
    {
        printf("INVALID\n") ;
    }
}

//Função que VERIFICA a quantidade de números do cartão
int ccQuantidadeDeNumeros(long ccnumero)
{
    int quantidade = 0 ;
    while (ccnumero != 0)
    {
        ccnumero = ccnumero / 10 ;
        quantidade++ ;
    }
    return quantidade ;
}

//Função que VALIDA a quantidade de números do cartão
bool validarCartao(long ccnumero)
{
    int quantidade = ccQuantidadeDeNumeros(ccnumero) ;
    return ((quantidade == 13 || quantidade == 15 || quantidade == 16) && calculandocc(ccnumero));

}

bool calculandocc(long ccnumero)
{
    int soma = 0 ;
    long tempccnumero = ccnumero ;

    //Case-01 (Não foram multiplicados por 2): iniciará seu trabalho a partir do último
    while (tempccnumero > 0)
    {
        int ultimoDigito = tempccnumero % 10; //Pegando o último dígito
        soma = soma + ultimoDigito;
        tempccnumero = tempccnumero / 100;
    }

    //Caso-02 (Multiplicação a cada dois dígitos por 2):
    tempccnumero = ccnumero / 10 ; // Removendo o último digito
    while (tempccnumero > 0)
    {
        int segundoDigito = (tempccnumero % 10);
        int tempmultiplique = segundoDigito * 2;
        //Esta expressão nos dá sua soma individual e soma com a soma total de ccnumero
        soma = soma + (tempmultiplique % 10) + (tempmultiplique / 10);
        tempccnumero = tempccnumero / 100;
    }
    return (soma % 10) == 0;
}

void mostrarBandeiraDoCartao(long ccnumero)  //Verificação qual a bandeira do cartão
{
    // 34e13 são os primeiros dois dígitos e seguidos por 13 zeros, pois AMEX tem 15 dígitos
    if ((ccnumero >= 34e13 && ccnumero < 35e13) || (ccnumero >= 37e13 && ccnumero < 38e13))
    {
        printf("AMEX\n") ;
    }

    else if (ccnumero >= 51e14 && ccnumero < 56e14)
    {
        printf("MASTERCARD\n") ;
    }

    else if ((ccnumero >= 4e12 && ccnumero < 5e12) || (ccnumero >= 4e15 && ccnumero < 5e15))
    {
        printf("VISA\n") ;
    }

    else
    {
        printf("INVALID\n") ;
    }
}