/*3) Implemente uma função que recebe um vetor de inteiros V e um número 
inteiro N e calcula o menor e o maior índice que N ocorre em V. Exemplo: 
V={0,1,3,4,1,7,2} e N = 1, o resultado será menor = 1 e maior = 5.*/

/*4) Implemente o exercício 3 de forma recursiva.*/

#include <stdio.h>

void POSICAOmenorXmaior(int n, int vet[], int tam, int *pmenor, int *pmaior, int i)
{
    if(vet[i]==n && i <= *pmenor)
    {
        *pmenor = i;
    }
    if(vet[i]==n && i >= *pmaior)
    {
        *pmaior = i;
    }
    if(i != tam-1)
    {   
        POSICAOmenorXmaior(n, vet, tam, pmenor, pmaior, i+1);
    }

    return;
}

int main (void)
{
    int vet[10]={0,12,-5,6,0,65,25,-14,0,-80};
    int n=0;
    int menor=10;
    int maior=0;

    POSICAOmenorXmaior(n, vet, 10, &menor, &maior, 0);

    printf("Maior: %d\n", maior);
    printf("Menor: %d", menor);
}