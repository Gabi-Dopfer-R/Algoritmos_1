/*1) Escreva uma função que divide uma fila em 2 novas filas: 
uma só com elementos pares e outra só com elementos ímpares.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 10 	//tamanho do vet

typedef struct 
{
    int id;
} elem;	

typedef struct
{
    int fim;
    elem vet[tam];
} tipFila;

void PRINTfila(elem vet[], int fim)
{
    int i;
    for(i=0; i<fim; i++)
    {
        printf("%d\t", vet[i].id);
    }
    printf("\n");
}

void inserir(elem *novos, tipFila *fila)
{
    if(fila->fim!=tam)
    {
        fila->vet[fila->fim] = *novos;
        fila->fim++;

        return;
    }
    return;
}

void dividirFILA(tipFila *fila, tipFila *fila2)
{
    int i;
    int j=0;
    int z=0;

    for(i=0; i<fila->fim; i++)
    {
        if(fila->vet[i].id %2 == 0)
        {
            fila2->vet[z] = fila->vet[i];
            z++;
        }
        else
        {
            fila->vet[j]= fila->vet[i];
            j++;
        }
    }
    fila2->fim= z;
    fila->fim= j;
}

int main(void)
{
    tipFila fila, fila2;
    int i;

    fila.fim=0;
    fila2.fim=0;

    srand(time(NULL));
    elem novos;

    for(i=0; i<5; i++)
    {    
        novos.id= rand()% 150;
        inserir(&novos, &fila);
    }

    printf("Fila orignial:\n");
    PRINTfila(fila.vet, fila.fim);
    
    dividirFILA(&fila, &fila2);

    printf("Fila 1 (%cmpar):\n", 161);
    PRINTfila(fila.vet, fila.fim);

    printf("Fila 2 (par):\n");
    PRINTfila(fila2.vet, fila2.fim);
}
