/*6) Escreva um método para ordenar uma lista.
A escolha entre simplesmente ou duplamente
encadeada é sua. A escolha de qual método também.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

typedef struct tipNo
{
    char nome[10];
    int id;
    struct tipNo *prox;
    struct tipNo *ant;
}tipNo;

typedef struct
{
    int quant;
    tipNo *ini;
    tipNo *fim;
}tipLista;

tipLista* CriarLista()
{
    tipLista *lista = (tipLista*) malloc(sizeof(tipLista));
    lista->quant = 0;
    lista->ini = NULL;
    lista->fim = NULL;
    return lista;
}

tipNo* CriarNo ()
{
    tipNo *no = (tipNo*) malloc(sizeof(tipNo));
    no->nome[0] = (char)(rand()% 26 + 97);
    no->nome[1] = (char)(rand()% 26 + 97);
    no->nome[2] = (char)(rand()% 26 + 97);
    no->nome[3] = '\0';
    no->id = rand()% 200;
    no->prox = NULL;
    no->ant = NULL;
    return no;
}

void Respostas_do_programa(int i)
{
    if(i==1)
    { printf("A%c%co realizada com sucesso.\n", 135, 198); }
    else if(i==0)
    { printf("Erro! Posi%c%co inv%clida\n", 135, 198, 160); }
    else
    { printf("Erro! Lista vazia.\n"); }
}

void ImprimirPROX (tipLista *lista)
{
    printf("\n===== LISTA CRESCENTE =====\n");

    tipNo *aux = lista->ini;

    if(lista->quant == 0)//vazia
    { Respostas_do_programa(-1); }

    int i;
    for(i=0; i < lista->quant; i++)
    {
        printf("\nNome: %s\n", aux->nome);
        printf("Id: %d\n", aux->id);
        aux = aux->prox;
    }
    printf("\n===============\n");
}

void ImprimirANT (tipLista *lista)
{
    printf("\n===== LISTA DECRESCENTE =====\n");

    tipNo *aux = lista->fim;

    if(lista->quant == 0)//vazia
    { Respostas_do_programa(-1); }

    int i;
    for(i=0; i < lista->quant; i++)
    {
        printf("\nNome: %s\n", aux->nome);
        printf("Id: %d\n", aux->id);
        aux = aux->ant;
    }
    printf("\n===============\n");
}

void printPOS (int pos, tipLista *lista)
{
    tipNo *aux;
    int i;

    printf("\n===== POSI%c%cO %d =====\n", 128,199,pos);
    if(lista->quant == 0)//vazia
    { Respostas_do_programa(-1); }
    else if(pos < 0)
    { pos = lista->quant + pos; }

    if(pos > lista->quant)//não existe
    { Respostas_do_programa(0); }

    else
    {
        if(pos > (lista->quant/2))//percorre do fim.
        {
            aux = lista->fim;
            for(i=lista->quant; i > pos; i--)
            { aux = aux->ant; }
        }
        else//percorre do inicio.
        {
            aux = lista->ini;
            for(i=0; i < pos; i++)
            { aux = aux->prox; }
        }
        printf("Nome: %s\n", aux->nome);
        printf("Id: %d\n", aux->id);
    }
    printf("===============\n");
}

void Inserir(tipNo *no, tipLista *lista, int pos)
{
    if(pos<0 || pos>lista->quant)//pos inexisente
    { return;}
    else//pode inserir
    {
        if(lista->quant == 0)//lista vazia
        {
            lista->ini = no;
            lista->fim = no;
        }
        else if(pos==0)//inserir no inicio
        {
            lista->ini->ant = no;
            no->prox = lista->ini;
            lista->ini = no;
        }
        else if(pos == lista->quant)//inserir no fim
        {
            lista->fim->prox = no;
            no->ant = lista->fim;
            lista->fim = no;
        }
        else//inserir no meio
        {
            int i;
            tipNo *aux;

            if(pos > (lista->quant/2))//percorre do fim.
            {
                aux = lista->fim;
                for(i=lista->quant; i > pos; i--)
                { aux = aux->ant; }
            }
            else//percorre do inicio.
            {
                aux = lista->ini;
                for(i=0; i < pos; i++)
                { aux = aux->prox; }
            }

            no->prox = aux;
            no->ant = aux->ant;
            aux->ant->prox = no;
            aux->ant = no;

        }
        lista->quant++;
        return;
    }
}

int Remover(tipLista *lista, int pos)
{
    if(lista->quant == 0)//lista vazia
    { return -1; }

    if(pos >= lista->quant)//pos inválida
    { return 0; }

    else
    {
        if(pos == 0)//remover primeiro elemento
        {
            lista->ini = lista->ini->prox;
            free(lista->ini->ant);
        }
        else if(pos == lista->quant-1)//remover ultimo elemento
        {
            lista->fim = lista->fim->ant;
            free(lista->fim->prox);
        }
        else//remover meio
        {
            tipNo *aux;
            int i;

            if(pos < lista->quant/2)//se elemento menor que metade
            {
                aux = lista->ini;
                for(i=0; i < pos; i++)
                { aux = aux->prox; }
            }
            else//se elemento maior que metade
            {
                aux = lista->fim;
                for(i=lista->quant-1; i > pos; i--)
                { aux = aux->ant; }
            }
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
            free(aux);
        }

        lista->quant--;
        return 1;
    }

}

void blubbleSORT(tipLista *lista)
{
    int i, j;
    tipNo *pos;
    tipNo *aux;
    do{
        j=0;
        pos = lista->ini;
        for(i=0; i<lista->quant-1; i++)
        {
            if(pos->id > pos->prox->id)
            {
                aux = pos->prox;

                if(pos->ant == NULL)
                { lista->ini = aux; }
                else { pos->ant->prox = aux; }

                if(aux->prox == NULL)
                { lista->fim = pos; }
                else { aux->prox->ant = pos; }
                
                pos->prox = aux->prox;
                aux->prox = pos;
                aux->ant = pos->ant;
                pos->ant = aux;
                j=1;
            }
            else{ pos = pos->prox; }
        }
    }while(j==1);
}

int main(void)
{
    //criar uma lista.
    printf("Criar lista:\n");
    tipLista *lista = CriarLista();
    if(lista == NULL)
    { printf("Sem espa%co para lista.\n", 135); }
    else
    { Respostas_do_programa(1); }

    //criar e inserir nós no final da lista.
    srand(time(NULL));
    int i;
    for(i=0; i<5; i++)
    {
        tipNo *no = CriarNo();
        Inserir(no, lista, i);
    }

    ImprimirPROX(lista);
    printf("\nOrdenada:");
    blubbleSORT(lista);
    ImprimirPROX(lista);
}
