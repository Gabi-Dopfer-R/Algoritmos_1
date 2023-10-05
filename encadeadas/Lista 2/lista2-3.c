/*3. Um grupo de sobreviventes do apocalipse zumbi está circundado por uma horda de zumbis.
Não existe esperança de vitória contra essa horda e os sobreviventes planejam uma fuga a
cavalo. A questão principal nesse momento é que o grupo só dispõe de um único cavalo. É
necessário estabelecer um critério de sorteio para ver qual sobrevivente fará uso desse cavalo
para escapar do massacre. Regras do sorteio:
o É sorteado um número N e o nome de um sobrevivente;
o Iniciando no sobrevivente eles começam a contar no sentido horário;
o O sobrevivente no qual a contagem N é finalizada é retirado do circulo;
o Todo sobrevivente que sair do circulo não entra mais no processo;
o O último sobrevivente é o felizardo para escapar com o cavalo.
Implemente o sorteio utilizando uma lista encadeada circular.*/

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
    no->id = rand()% 50;
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
    printf("\n=== LISTA CRESCENTE ===\n");

    tipNo *aux = lista->ini;

    if(lista->quant == 0)//vazia
    { Respostas_do_programa(-1); }

    int i;
    for(i=0; i < lista->quant; i++)
    { 
        printf("\nId: %d\n", aux->id);
        aux = aux->prox; 
    }
    printf("\n====================\n");
}

void ImprimirANT (tipLista *lista)
{
    printf("\n=== LISTA DECRESCENTE ===\n");

    tipNo *aux = lista->fim;

    if(lista->quant == 0)//vazia
    { Respostas_do_programa(-1); }

    int i;
    for(i=0; i < lista->quant; i++)
    { 
        printf("\nId: %d\n", aux->id);
        aux = aux->ant; 
    }
    printf("\n====================\n");
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
        return;
    }
}

void Remover(tipLista *lista, int pos)
{
    if(lista->quant == 0)//lista vazia
    { return; }

    if(pos >= lista->quant)//pos inválida
    { return; }

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
        return;
    }

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
    { Respostas_do_programa(1); }

    //criar e inserir nós no final da lista.
    srand(time(NULL));
    for(i=0; i<10; i++)
    {
        no = CriarNo();
        Inserir(no, lista, i);
    }
    ImprimirPROX(lista);

    while(lista->quant >1)
    {
        int num = rand();
        if(num<0)
        { num = (-1)*num; }
        
        printf("\nNUM = %d", num);
        printPOS(num%lista->quant, lista);
        Remover(lista, num%lista->quant);    
    }
    printf("\nSobrevivente:");
    ImprimirPROX(lista);
}
