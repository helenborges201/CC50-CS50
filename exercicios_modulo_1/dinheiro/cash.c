#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // Valor positivo
    float reais;
    do
    {
        reais = get_float("Change Owed: ");
    }
    while(reais < 0);

    // Arredondando o float
    int centavos = round(reais * 100);

    printf("%i\n", centavos);
    // 0.25 0.10 0.5 0.1


    // Verificando quantas moedas usar
    int moedas = 0;

    while(centavos != 0)
    {
        while(centavos >= 25)
        {
            centavos -= 25;
            moedas++;
        }
        while(centavos >= 10)
        {
            centavos -= 10;
            moedas++;
        }
        while(centavos >= 5)
        {
            centavos -= 5;
            moedas++;
        }
        while(centavos >= 1)
        {
            centavos -= 1;
            moedas++;
        }
    }
    printf("%i\n", moedas);

}