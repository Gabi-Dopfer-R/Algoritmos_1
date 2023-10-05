#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

typedef struct tipNo
{
    int id;
    char nome[10];
    struct tipNo *prox;
}tipNo;

typedef struct
{
    int quant;
    tipNo *ini;
    tipNo *fim;
}tipFila; 

tipFila* CriarFila()
{
    tipFila *fila = (tipFila*) malloc(sizeof(tipFila));
    fila->quant = 0;
    fila->ini = NULL;
    fila->fim = NULL;
    return fila;
}

tipNo* CriarNo (int pos)
{
    tipNo *no = (tipNo*) malloc(sizeof(tipNo));

    no->id = pos;
    no->nome[0] = (char)(rand()% 26 + 97);
    no->nome[1] = '\0';
    no->prox = NULL;
    return no;
}

void ImprimirFila (tipFila *fila)
{
    tipNo *aux = fila->ini;

    if(aux == NULL)
    { printf("\nFila vazia.\n"); }

    while(aux != NULL)
    {
        printf("\nNome: %s\n", aux->nome);
        printf("Id: %d\n", aux->id);

        aux = aux->prox;
    }
}

void Inserir(tipNo *no, tipFila *fila)
{
    if(fila->quant==0)
    { fila->ini = no; }
    else
    { fila->fim->prox = no; }

    fila->fim = no;
    fila->quant++;
}

int Remover(tipFila *fila)
{
    if(fila->quant ==0)
    { return 0; }

    tipNo *aux = fila->ini;
    fila->ini = fila->ini->prox;
    free(aux);
    fila->quant--;
    return 1;
}

int main(void)
{
    printf("Criar fila:\n");
    tipFila *fila = CriarFila();
    
    if(fila == NULL)
    { printf("Sem espa%co para fila.\n", 135); }
    else
    { printf("Fila criada com sucesso.\n"); }

    srand(time(NULL));

    int i;
    for(i=1; i<=5; i++)
    {
        tipNo *no = CriarNo(i);
        Inserir(no, fila);
    }

    ImprimirFila(fila);

    for(i=fila->quant; i>=0; i--)
    {
        printf("\nRemover elemento da fila:\n");
        int aux = Remover(fila);

        if(aux)
        { 
            printf("Removido com sucesso.\n");
            printf("Restam %d elementos.\n", fila->quant);
        }
        else
        { printf("Erro! Fila vazia.\n"); }
    }
}