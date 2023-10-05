/*3) Um supermercado possui 3 caixas, os quais podem ter filas de no máximo 3 clientes (o
que está sendo atendido mais 2). Além desses, todos demais clientes devem formar uma
única fila (veja figura abaixo). A medida que um dos caixas libera um cliente, o primeiro da
"fila do povão" é encaminhado para uma das filas específicas. Simule o funcionamento
destas filas computacionalmente. A liberação dos clientes deve ser feita de forma aleatória
(sorteio de 1 a 3, por exemplo).*/

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
    for(i=0; i<15; i++)
    {
        tipNo *no = CriarNo(i);
        Inserir(no, fila);
    }

    //simular caixas.....
    tipFila *c1 = CriarFila();
    tipFila *c2 = CriarFila(); 
    tipFila *c3 = CriarFila();

    int sorteio;
    tipFila *caixa;
    while(fila->quant!=0 || c1->quant!=0 || 
        c2->quant!=0 || c3->quant!=0)
    {
        sorteio = rand()% 3 +1;
        switch(sorteio){
            case 1: caixa = c1; break;
            case 2: caixa = c2; break;
            default: caixa = c3;
        }
       
        if(caixa->quant==3 || fila->quant == 0)
        { Remover(caixa); }

        if(fila->quant != 0){
            Inserir(fila->ini, caixa);
            Remover(fila);
        }

        printf("\nfila = %d\n", fila->quant);
        printf("c1 = %d\n", c1->quant);
        printf("c2 = %d\n", c2->quant);
        printf("c3 = %d\n", c3->quant);
        printf("=====================");
    }
    ImprimirFila(fila);
}
