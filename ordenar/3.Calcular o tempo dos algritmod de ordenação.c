/*3) Crie vetores com grande quantidade de elementos inteiros 
(ex: um milhão de elementos) de forma aleatória (use a função rand).  
A seguir, verifique o tempo que cada algoritmo de ordenação leva para ordenar este vetor. 
Utilize a biblioteca <time.h> para isso. Exemplo de como fazer isso abaixo:

#include <time.h>
clock_t tInicio, tFim, tDecorrido;
tInicio = clock();
//seu codigo vem aqui
tFim = clock();
//calcula aproximadamente o tempo em milisegundos gasto entre as duas chamadas de clock()
tDecorrido = ((tFim - tInicio) / (CLOCKS_PER_SEC / 1000));

Para usuários windows, usar desta forma:
#include <time.h>
time_t start = time(NULL); 
//tempo em segundos desde um momento no passado ()
time_t tDecorrido = time(NULL) - start;
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void gerarVETOR(int vet[], int tam)
{
    srand(time(NULL));

    int i;
    for(i=0; i<tam; i++)
    {
        vet[i] = rand();  
    }
}

void printVET(int vet[], int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        printf("%d\t ", vet[i]);
    }
    printf("\n\n");
}

void trocar(int vet[], int x, int y)
{
    int aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
}

void blubbleSORT(int tam, int i, int vet[])
{
    int j;

    for(i=0; i<tam; i++)
    {
        if(vet[i] > vet[i+1])
        {
            trocar(vet, i, i+1);
            j=1;
        }
    }
    
    if(j==0)
    {
        return;
    }else{ blubbleSORT(tam, i, vet); }  
}

void insertion(int vet[], int tam, int i)
{
    int j;
    int valor;

    //percorrer todos os valores do vetor.
    for(i=0; i<tam; i++)
    {
        j=tam-1;

        //se valor está no lugar ir pro próx.
        while(vet[j] > vet[j-1])
        { j--; }

        valor = vet[j];

        while(valor <= vet[j] && j!=0)
        {
            vet[j] = vet[j-1];
            j--;
        }

        vet[j] = valor;
    }
}

void selection(int vet[], int tam)
{
    int i, j, aux, menor;

    for(i=0; i<tam; i++)
    {
        menor=vet[i];
        aux=i;
        
        for(j=i; j<tam; j++)
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
    }
}


int main(void)
{
    time_t start = time(NULL);

    int vet[10000];
    int tam = 10000;

    gerarVETOR(vet, tam);
    printVET(vet, tam);
    printf("\n\n\n");

    blubbleSORT(tam, 0, vet);
    //insertion(vet, tam, 0);
    //selection(vet, tam);
    //quicksort(vet, 0, tam-1);


    printVET(vet, tam);

    time_t tDecorrido = time(NULL) - start;

    printf("Tempo decorrido %d", tDecorrido);
}