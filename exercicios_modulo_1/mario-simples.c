#include <stdio.h>
#include <cs50.h>

int main(void)
{   
    // rejetando numeros menor que 1 e maior que 8
    int height;
    do
    {
        height = get_int("height: ");
    }
    while(height < 1 || height > 8);

    //Percorre o valor da altura
    for(int i = 1; i <= height; i++)
    {
        int n = 0;
        
        // colocando espaço
        for(int j = 1; j <= height - i; j++)
        {
           printf(" ");
           n++;
        }

        //colocando hashes
        for(int x = 1; x <= height - n; x++) {
            printf("#");
        }
        printf("\n");
    }
}