/*5) Crie um Quicksort "híbrido": caso o tamanho do vetor ou do pedaço do vetor 
(utilize "ini" e "fim" para calcular este tamanho) seja maior que 32, 
utilize o Quicksort normalmente; caso seja menor que 32, 
utilize um outro algoritmo (ex: insertion ou selection sort).*/

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

void selection(int vet[], int ini, int fim)
{
    int i, j, aux, menor;

    for(i=ini; i<=fim; i++)
    {
        menor=vet[i];
        aux=i;
        
        for(j=i; j<=fim; j++)
        {
            if(vet[j] < menor)
            {
                menor= vet[j];
                aux = j;
            }
        }
        vet[aux]= vet[i];
        vet[i]= menor;
    }
}

void quicksort(int vet[], int ini, int fim)
{
    int pivo = vet[fim];
    int posicao = ini;
    int i;

    if( ini < fim)//função de parada.
    {
        if((fim - ini)>= 32)
        {
            //ordenar os valores.
            for(i=ini; i<=fim-1; i++)
            {
                if(vet[i] <= pivo)
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

        }else{ selection(vet, ini, fim);}
    }
}


int main (void)
{
    srand(time(NULL));
    int vet[100], tam=100;
    int i;

    printf("Original:\n");
    for(i=0; i<tam; i++)
    {
        vet[i]= rand() % 150;
        printf("%d  ", vet[i]);
    }
    printf("\n\n");

    quicksort(vet, 0, tam-1);

    printVET(vet, tam);
}

