#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height;
    // Define altura maior que 1 e menor que 8
    do
    {
        height = get_int("height: ");

    }
    while (height < 1 || height > 8);

    // Escada do lado esquerdo
    for (int i = 1; i <= height; i++)
    {
        int EspaçoOuHashes = 0;
        for (int h = 1; h <= height - i; h++)
        {
            printf(" ");
            EspaçoOuHashes++;
        }
        for (int h = 1; h <= height - EspaçoOuHashes; h++)
        {
            printf("#");
        }

        printf("  ");

        //Escada do lado direito
        for (int h = 1; h <= height - EspaçoOuHashes; h++)
        {
            printf("#");
        }

        printf("\n");
    }
}