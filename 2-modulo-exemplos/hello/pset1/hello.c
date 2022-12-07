#include <stdio.h>
#include <cs50.h> // Adicionar a biblioteca do CS50

int main(void)
{ 
    string name = get_string("What's you name? "); 
    printf("Hello, %s\n", name);
}

