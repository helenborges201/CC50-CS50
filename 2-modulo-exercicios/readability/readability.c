#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int letras = 0;
    int palavras = 1;
    int frase = 0;

    for(int i = 0; i < length; i++)
    {

        if(islower(text[i]) || isupper(text[i]))
        {
            letras++;
        }
        if(isspace(text[i]))
        {
            palavras++;
        }

        if(text[i] == '?' || text[i] == '!' || text[i] == '.')
        {
            frase++;
        }
    }

    float L =(letras / (float) palavras) * 100;
    float S = (frase /  (float)palavras) * 100;

    float indice =  0.0588 * L - 0.296 * S - 15.8;

    indice = round(indice);

    if(indice < 1)
    {
        printf("Before Grade 1\n");
    }
    else if(indice >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n",(int) indice);
    }
}