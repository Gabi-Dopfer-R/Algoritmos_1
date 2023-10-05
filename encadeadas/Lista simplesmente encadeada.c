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
    printf("\n===== LISTA =====\n");

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

int Inserir(tipNo *no, tipLista *lista, int pos)
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
    return 1;
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

int main(void)
{
    int i;
    int aux;
    int pos;
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
        printf("\nInserir elemento na lista.\n");
        no = CriarNo(i);
        aux = Inserir(no, lista, i);

        if(aux)
        { printf("Inserido com sucesso.\n"); }
        else
        { printf("Erro! Posi%c%co inv%clida\n", 135, 198, 160); }

    }

    ImprimirLista(lista);

    //Remover nós da lista em posições de 0 a 5.
    for(i=1; i<=5; i++)
    {
        pos = rand()% 5;

        printf("\nRemover elemento %d da lista:\n", pos);
        aux = Remover(lista, pos);

        if(aux == 1)
        {
            printf("Removido com sucesso.\n");
            printf("Restam %d elementos.\n", lista->quant);
        }
        else if(aux == 0)
        { printf("Erro! Lista vazia.\n"); }
        else
        {
            printf("Erro! Posi%c%co inv%clida\n", 135, 198, 160);
            printf("Restam %d elementos.\n", lista->quant);
        }

        ImprimirLista(lista);
    }

    //inserir um nó na posição 0.
    printf("\nInserir elemento na posi%c%co 0 lista.\n", 135, 198);
    no = CriarNo(0);
    aux = Inserir(no, lista, 0);

    if(aux)
    { printf("Inserido com sucesso.\n"); }
    else
    { printf("Erro! Posi%c%co inv%clida\n", 135, 198, 160); }

    //Tentar inserir em uma posição inexistente.
    printf("\nInserir elemento na posi%c%co 6 lista.\n", 135, 198);
    no = CriarNo(6);
    aux = Inserir(no, lista, 6);

    if(aux)
    { printf("Inserido com sucesso.\n"); }
    else
    { printf("Erro! Posi%c%co inv%clida\n", 135, 198, 160); }

    ImprimirLista(lista);
}
