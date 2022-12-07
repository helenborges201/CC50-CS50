#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>


int main(int numeroDeArgumentos, string argumento[])
{
    if(numeroDeArgumentos != 2)
    {
        printf("User: ./caesar key\n");
        return 1;
    }
    for(int i = 0, n = strlen(argumento[1]); i < n; i++)
    {
        if(!isdigit(argumento[1][i]))
        {
            printf("User: ./caesar key\n");
            return 1;
        }
    }

    int key = atoi(argumento[1]);
    string plainText = get_string("plaintext: ");
    string alfabetoMin = "abcdefghijklmnopqrstuvwxyz";
    string alfabetoMaiu = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int n = strlen(plainText);
    int plainTextIndex[n];
    int index = 0;

    // convertendo os texto para o index de alfabetico
    for(int i = 0; i < n; i++)
    {
        if(isdigit(plainText[i]) || ispunct(plainText[i])|| isspace(plainText[i]))
        {
            //ascii de simbolos os numeros
            plainTextIndex[index] = plainText[i];
            index++;

        }
       for(int l = 0; l < 26; l++)
       {
            if(islower(plainText[i]) && plainText[i] == alfabetoMin[l])
            {
                plainTextIndex[index] = l;
                index++;
            }

            else if(isupper(plainText[i]) && plainText[i] == alfabetoMaiu[l])
            {
                plainTextIndex[index] = l;
                index++;
            }
       }
    }
    int ciphertext[n];
    // criptografar e imprimir
    printf("ciphertext: ");
    for(int i = 0; i < n; i++)
    {
        if(plainTextIndex[i] < 26)
        {
            int cesar = (plainTextIndex[i] + key) % 26;

            if(isupper(plainText[i]))
            {
                cesar += 65;
                ciphertext[i] = cesar;

            }

            if(islower(plainText[i]))
            {
                cesar += 97;
                ciphertext[i] = cesar;
            }
        }
        else
        {
            ciphertext[i] = plainTextIndex[i];
        }
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}
