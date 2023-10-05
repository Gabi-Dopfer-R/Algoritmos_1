/*1) Utilize uma pilha para escrever uma função que inverte uma string. 
Ex: se a função recebe a string "PABLO", ao final da execução esta mesma string deve conter "OLBAP".*/

#include <stdio.h>
#include <string.h>

#define tam 50 	//tamanho do vet

typedef struct
{
    int fim;
    char name[tam];
}tipPilha;

void PRINTpilha(char str[])
{
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void stack(char *str, tipPilha *pilha)
{
    int i;
    for(i=0; str[i] != '\0'; i++)
    {  
        pilha->name[i] = str[i];
        pilha->fim++; 
    }
}

void unstack(char *str, tipPilha *pilha)
{
    int i, j=0;
    for(i=pilha->fim-1; i>=0; i--)
    {
        str[j] = pilha->name[i];
        j++;
        pilha->fim--;
    }
    str[j]='\0';
}

int main(void)
{ 
    tipPilha pilha;
    pilha.fim=0;

    char str[tam]=("gabriela");

    printf("Original: ");
    PRINTpilha(str);

    stack(&str, &pilha);
    unstack(&str, &pilha);

    printf("Inverso: ");
    PRINTpilha(str);
}
