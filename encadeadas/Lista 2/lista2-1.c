/*1. Batman acaba de receber a mensagem abaixo, claramente enviada pelo Coringa.
Conversando com o sr. Lucius Fox, seu fiel funcionário responsável pelo setor de tecnologia da
Wayne Enterprise, Batman descobre que cada um dos números (de 2 digitos) é facilmente
traduzido para uma letra através da Tabela ASCII. Entretanto, a forma como a mensagem foi
criada impede que o leitor saiba exatamente onde se inicia a mensagem.
a. Tendo aprendido programação em C ainda quando criança, Batman (ou Bruce Wayne)
resolve criar uma lista circular. Cada número será inserido como chave de um nó desta lista,
e iniciando a impressão destas chaves em todos nós possíveis, ao final imprimem-se todas as
possíveis mensagens.
b. O sr. Lucius gostou da solução, mas se deu conta que Bruce está testando apenas a
possibilidade dos números estarem dispostos em sentido horário. Então, ao mesmo tempo em
que o Batman faz sua implementação, Lucius resolve criar uma lista circular a fim de imprimir
todas possíveis mensagens no sentido anti-horário.
Quem conseguiu imprimir a mensagem do Coringa? Escreva códigos que sejam capazes de
executar exatamente o mesmo que os códigos de Batman e Lucius. Dica: assumindo que p é
um ponteiro para um determinado nó da lista circular ou da fila, você pode imprimir o número já
como uma letra através printf("%c", p->chave).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>

typedef struct tipNo
{
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

void ImprimirPROX (tipLista *lista, tipNo *aux)
{
    if(lista->quant == 0)//vazia
    { Respostas_do_programa(-1); }

    int i;
    for(i=0; i < lista->quant; i++)
    { 
        printf("%c  ", (char)aux->id);
        aux = aux->prox; 
    }
    printf("\n===========================================\n");
}

void ImprimirANT (tipLista *lista, tipNo *aux)
{
    if(lista->quant == 0)//vazia
    { Respostas_do_programa(-1); }

    int i;
    for(i=0; i < lista->quant; i++)
    { 
        printf("%c  ", (char)aux->id);
        aux = aux->ant; 
    }
    printf("\n==========================================\n");
}

int Inserir(tipNo *no, tipLista *lista, int pos)
{
    if(pos<0 || pos>lista->quant)//pos inexisente
    { return 0;}
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
            no->ant = lista->fim;
            lista->fim->prox = no;
        }
        else if(pos == lista->quant)//inserir no fim
        {  
            lista->fim->prox = no;
            no->ant = lista->fim;
            lista->fim = no; 
            no->prox = lista->ini; 
            lista->ini->ant = no;  
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
    printf("\nCriar lista:\n");
    tipLista *lista = CriarLista();
    if(lista == NULL)
    { printf("Sem espa%co para lista.\n", 135); }
    else
    { Respostas_do_programa(1); }

    //criar e inserir nós no final da lista.
    printf("\nInserir elementos na lista:\n");
    for(i=0; i<12; i++)
    {   
        no = CriarNo();
        scanf("%d", &no->id);
        aux = Inserir(no, lista, i);
    }

    printf("\nHor%crio:\n", 160);
    tipNo *auxNo = lista->ini;
    for(i=0; i < lista->quant; i++){
        printf("Posi%c%co %d:\t", 135, 198, i);
        ImprimirPROX(lista, auxNo);
        auxNo = auxNo->prox;
    }

    printf("\nAnti-hor%crio:\n", 160);
    auxNo = lista->ini;
    for(i=0; i < lista->quant; i++){
        printf("Posi%c%co %d:\t", 135, 198, i);
        ImprimirANT(lista, auxNo);
        auxNo = auxNo->ant;
    }
}
