/*4) Escreva uma função que inverte a ordem das células de uma lista simplesmente
encadeada (a primeira passa a ser a última, a segunda passa a ser a penúltima etc.). Faça
isso sem usar espaço auxiliar; apenas altere os ponteiros.*/

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
}tipLista;

tipLista* CriarLista()
{
    tipLista *lista = (tipLista*) malloc(sizeof(tipLista));
    lista->quant = 0;
    lista->ini = NULL;
    return lista;
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

void ImprimirLista (tipLista *lista)
{
    tipNo *aux = lista->ini;

    if(aux == NULL)
    { printf("\nLista vazia.\n"); }

    while(aux != NULL)
    {
        printf("\nNome: %s\n", aux->nome);
        printf("Id: %d\n", aux->id);

        aux = aux->prox;
    }

    printf("\n===============\n");
}

void Inserir(tipNo *no, tipLista *lista, int pos)
{
    if(pos<0 || pos>lista->quant)
    { return 0;}

    if(pos == 0)
    { 
        no->prox = lista->ini;
        lista->ini = no;
    }
    
    else
    {
        tipNo *aux = lista->ini;
        
        int i=0;
        while(i < (pos-1))
        {
            aux = aux->prox;
            i++;
        } 

        no->prox = aux->prox;
        aux->prox = no;
    }

    lista->quant++;
}

int Remover(tipLista *lista, int pos)
{
    if(lista->quant == 0)
    { return 0; }

    if(pos >= lista->quant)
    { return -1; }

    else 
    {
        tipNo *aux = lista->ini;

        int i=0;
        while(i < (pos-1))
        {
            aux = aux->prox;
            i++;
        }

        tipNo *excluir = aux->prox;

        if(pos == 0)
        { 
            lista->ini = lista->ini->prox;
            free(aux);
        }    

        else if(pos == lista->quant-1)
        { aux->prox = NULL; }
        
        else
        {  aux->prox = excluir->prox; }

        free(excluir);
        lista->quant--;
        return 1;
    }

}

void InverterLista(tipLista *lista)
{
    tipNo *a,*b,*c;
    
    a = lista->ini;
    while(lista->ini->prox != NULL)
    {
        b = lista->ini->prox;
        c = lista->ini->prox->prox;
        b->prox = a;
        lista->ini->prox = c;
        a = b;
    }
    lista->ini = a;

}

int main(void)
{
    int i;
    tipNo *no;

    //criar uma lista.
    printf("Criar lista:\n");
    tipLista *lista = CriarLista();

    if(lista == NULL)
    { printf("Sem espa%co para lista.\n", 135); }
    else
    { printf("Lista criada com sucesso.\n"); }

    //criar e inserir nós no final da lista.
    srand(time(NULL));

    for(i=0; i<5; i++)
    {
        no = CriarNo(i);
        Inserir(no, lista, i);
    }

    printf("\n======== LISTA ORIGINAL =======\n");
    ImprimirLista(lista);

    InverterLista(lista);

    printf("\n======== LISTA INVERTIDA =======\n");
    ImprimirLista(lista);


}