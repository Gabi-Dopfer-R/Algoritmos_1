/*4) Implemente uma função que recebe uma string e 
imprime a quantidade de vogais e a quantidade de consoantes.*/

#include <stdio.h>

//funções.
void vogaisXconsoantes(char frase[], int aux);

int main(void)
{
    char frase[100];
    int aux;

    printf("Insira uma frase:");
    fflush(stdin);
    gets(frase);

    vogaisXconsoantes(frase, aux);

    return 0;
}

void vogaisXconsoantes(char frase[], int aux)
{
    int vogal=0, consoante=0;

    for(aux=0; frase[aux]!='\0'; aux++)
    {
        switch(frase[aux])
        {
            case 'A':
            case 'a':
            case 'E':
            case 'e':
            case 'I':
            case 'i':
            case 'O':
            case 'o':
            case 'U': 
            case 'u':
                vogal++; break;
            case ' ': break;
            default: consoante++;
        }
    }

    printf("\nEssa frase possui:\n");
    printf("%d vogais.\n", vogal);
    printf("%d consoantes", consoante);

    return;
}