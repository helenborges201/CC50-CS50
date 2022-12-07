#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Verificar se não tem uma Chave
    if(argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
        return 1;
    }

    int caracteres = strlen(argv[1]);

    // Se chave  não tem 26 caracters
    if(caracteres != 26)
    {
        printf("Key must contain 26 characters");
        return 1;
    }

    // Verificar se todos os caracteres são letras
    for(int i = 0; i < caracteres; i++)
    {
        //se caractere não for letra
        if(!isalpha(argv[1][i]))
        {
            printf("Usage: ./substitution KEY\n");
            return 1;
        }
    }
    string str = argv[1];
    char key[26];

    // Verificar se um caractere se repete
    for (int i = 0; i < 26; ++i) {
        key[i] = toupper(str[i]);
       for(int l = i + 1; l < 26; l++)
        {
            if (str[i] == str[l]) {
                printf("Key must not contain repeated characters\n");
                return 1;
            }
        }
    }


    string plaintext =  get_string("plaintext: ");
    char alfabetoMinus[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alfabetoMaius[26] = "abcdefghijklmnopqrstuvwxyz";
    int n = strlen(plaintext);
    int indice[n];

    // indice do alfabeto
    for(int i = 0; i < n; i++)
    {
        for(int l = 0; l < 26; l++)
        {
            //letra minúscula
            if(plaintext[i] == alfabetoMinus[l]) {
                indice[i] = l;
            }

            // letra maiúscula
            if(plaintext[i] == alfabetoMaius[l]) {
                indice[i] = l;
            }
        }
        // vai signficar espaço
        if(isspace(plaintext[i])) {
            indice[i] = 26;
        }

        // pontuação
        if(ispunct(plaintext[i])) {
            indice[i] = (int) plaintext[i];
        }

        // digito
        if(isdigit(plaintext[i])) {
            indice[i] = (int) plaintext[i];
        }
    }

    char ciphertext[n];
    printf("ciphertext: ");
    // criptografar o texto
    for(int i = 0; i < n; i++) {
        if(islower(plaintext[i]))
        {
            ciphertext[i] = tolower(key[indice[i]]);
        }
        else if(isupper(plaintext[i]))
        {
            ciphertext[i]= key[indice[i]];
        }
        else if (indice[i] == 26)
        {
           ciphertext[i] = ' ';
        }
        else {
            ciphertext[i] = indice[i];
        }
        printf("%c", ciphertext[i]);
    }
    printf("\n");
}