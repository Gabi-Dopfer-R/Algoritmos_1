/*6) Adicione o Quicksort implementado em aula e o Quicksort "híbrido" ao exercício 3. 
A partir de que tamanho de vetor o quicksort é realmente mais rápido que os demais? 
E o híbrido?*/

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

void selection(int vet[], int ini, int tam)
{
    int i, j, aux, menor;

    for(i=ini; i<tam; i++)
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

void quicksort2(int vet[], int ini, int fim)
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
            quicksort2(vet, ini, posicao-1);
            quicksort2(vet, posicao+1, fim); 

        }else{ selection(vet, ini, fim);}
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

    //blubbleSORT(tam, 0, vet);
    insertion(vet, tam, 0);
    //selection(vet, 0, tam);
    //quicksort(vet, 0, tam-1);
    //quicksort2(vet, 0, tam-1);


    printVET(vet, tam);

    time_t tDecorrido = time(NULL) - start;

    printf("Tempo decorrido %d", tDecorrido);
}