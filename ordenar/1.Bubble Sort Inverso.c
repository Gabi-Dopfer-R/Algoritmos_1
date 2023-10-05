/*1) Implemente o Bubble Sort reverso, ou seja, ao final do algoritmo devemos 
ter um vetor ordenado de forma decrescente (e não crescente como na forma original).*/

#include <stdio.h>

void printVET(int vet[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d  ", vet[i]);
    }
    printf("\n");
}

void bubblesort(int vet[], int tam)
{
    int i, aux, j;

    for(i=0; i<tam; i++)
    {
        for(j=tam-1; j>0; j--)
        {
            if(vet[j] > vet[j-1])
            {
                aux = vet[j];
                vet[j] = vet[j-1];
                vet[j-1] = aux;
            }
        }
    }
}

int main (void)
{
    int vet[7]={10,16,9,4,7,92,-17};

    bubblesort(vet, 7);

    printVET(vet, 7);
}