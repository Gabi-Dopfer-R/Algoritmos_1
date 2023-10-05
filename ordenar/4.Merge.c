/*4) O algoritmo Merge Sort é baseado na ideia de "merge", ou seja, 
mesclar pedaços do vetor que já estão garantidamente ordenados. Por exemplo, 
v[ ] = {1,14,27,8,23,50}. O vetor "v" já está ordenado das posições 0 a 2 (1,14,27) 
e também das posições 3 a 5 (8,23,50). Escreva então a função "merge" que recebe este 
vetor e as posições iniciais e finais em que o vetor já está ordenado, 
e faça com que o vetor fique totalmente ordenado.

Exemplo de cabeçalho: merge(int vetor[], int ini, int meio, int fim) . 
Para o exemplo acima, chamaríamos merge(v,0,3,5) e devemos ao final obter o vetor já ordenado. 
Observe que o índice meio-1 é onde termina a primeira parte ordenada, 
e portanto não precisamos de mais um parâmetro para isso. Dica: utilize um vetor auxiliar.*/

#include<stdio.h>

void PRINTvet(int vetor[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d\t", vetor[i]);
    }
    printf("\n\n");
}

void merge(int vetor[], int ini, int meio, int fim)
{
    int vet[fim];
    int i=ini;
    int j=meio;
    int z=0;
    
    while(z<fim)
    {
        if(vetor[i] >= vetor[j] || i>=meio)
        { 
            vet[z]= vetor[j];
            j++;
        }
        else if(vetor[i] < vetor[j] || j>=fim)
        {
            vet[z] = vetor[i];
            i++;
        }

        z++;
    }

    for(i=0; i<fim; i++)
    { vetor[i] = vet[i]; }
}

int main(void)
{
    int vetor[6]={1,14,27,8,23,50};

    printf("Vetor original:\n");
    PRINTvet(vetor, 6);

    merge(vetor, 0, 3, 6);

    printf("Vetor ordenado:\n");
    PRINTvet(vetor, 6);
}