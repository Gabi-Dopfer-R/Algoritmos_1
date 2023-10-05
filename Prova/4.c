/*4. (2,0) Implemente o Quicksort reverso, ou seja, ao final o vetor deve estar ordenado de
maneira decrescente (e não crescente, como aprendemos em aula).
Se outro algoritmo de ordenação, o peso é (0,5).*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void trocar(int vet[], int x, int y)
{
    int aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
}

void printVET(int vet[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("%d  ", vet[i]);
    }
    printf("\n\n");
}

void quicksort(int vet[], int ini, int fim)
{
    int pivo = vet[fim];
    int posicao = ini;
    int i;

    if( ini < fim)//função de parada.
    {
        //ordenar os valores.
        for(i=ini; i<=fim-1; i++)
        {
            if(vet[i] >= pivo)
            {
                if(posicao!=i)
                { trocar(vet, i, posicao); }

                posicao++;
            }
        }
        trocar(vet, posicao, i);

        //chamar função recursiva.
        quicksort(vet, ini, posicao-1);
        quicksort(vet, posicao+1, fim); 
    }
}

int main (void)
{
    srand(time(NULL));
    int vet[15], tam=15;
    int i;

    printf("Original:\n");
    for(i=0; i<tam; i++)
    {
        vet[i]= rand() % 150;
        printf("%d  ", vet[i]);
    }
    printf("\n\n");

    quicksort(vet, 0, tam-1);

    printf("Ordenado decrescente:\n");
    printVET(vet, tam);
}