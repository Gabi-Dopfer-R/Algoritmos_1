#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

typedef struct tipNo
{
    int id;
    char nome[10];
    struct tipNo *ant;
}tipNo;

typedef struct
{
    int quant;
    tipNo *fim;
}tipPilha; 

tipPilha* CriarPilha()
{
    tipPilha *pilha = (tipPilha*) malloc(sizeof(tipPilha));
    pilha->quant = 0;
    pilha->fim = NULL;
    return pilha;
}

tipNo* CriarNo (int pos)
{
    tipNo *no = (tipNo*) malloc(sizeof(tipNo));

    no->id = pos;
    no->nome[0] = (char)(rand()% 26 + 97);
    no->nome[1] = '\0';
    no->ant = NULL;
    return no;
}

void ImprimirPilha (tipPilha *pilha)
{
    tipNo *aux = pilha->fim;

    if(aux == NULL)
    { printf("\nPilha vazia.\n"); }

    while(aux != NULL)
    {
        printf("\nNome: %s\n", aux->nome);
        printf("Id: %d\n", aux->id);

        aux = aux->ant;
    }
}

void Empilhar(tipNo *no, tipPilha *pilha)
{
    if(pilha->quant!=0)
    { no->ant = pilha->fim; }

    pilha->fim = no;
    pilha->quant++;
}

int Desempilhar(tipPilha *pilha)
{
    if(pilha->quant ==0)
    { return 0; }

    tipNo *aux = pilha->fim;
    pilha->fim = pilha->fim->ant;
    free(aux);
    pilha->quant--;
    return 1;
}

int main(void)
{
    printf("Criar pilha:\n");
    tipPilha *pilha = CriarPilha();
    
    if(pilha == NULL)
    { printf("Sem espa%co para pilha.\n", 135); }
    else
    { printf("Pilha criada com sucesso.\n"); }

    srand(time(NULL));

    int i;
    for(i=1; i<=5; i++)
    {
        tipNo *no = CriarNo(i);
        Empilhar(no, pilha);
    }

    ImprimirPilha(pilha);

    for(i=pilha->quant; i>=0; i--)
    {
        printf("\nDesempilhar elemento:\n");
        int aux = Desempilhar(pilha);

        if(aux)
        { 
            printf("Desempilhado com sucesso.\n");
            printf("Restam %d elementos.\n", pilha->quant);
        }
        else
        { printf("Erro! Pilha vazia.\n"); }
    }
}