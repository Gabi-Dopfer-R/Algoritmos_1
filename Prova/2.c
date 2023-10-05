/*2. (2,0) Crie uma função recursiva capaz de esvaziar uma fila de números inteiros. Antes de
desenfileirar, imprima o valor do elemento que está sendo retirado.
Caso a solução não seja recursiva, o peso é (0,5).*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define tam 10 	//tamanho do vet

typedef struct 
{
    int id;
    char nome[50];
} elem;	

typedef struct
{
    int fim;
    elem vet[tam];
} tipFila;

void PRINTposicao(elem posicao)
{
    printf("Elemento a ser excluido:\n");
    printf("Id: %d\n", posicao.id); 
    printf("Nome: %s\n\n", posicao.nome);   
}

int inserir(elem *novos, tipFila *fila)
{
    if(fila->fim!=tam)
    {
        fila->vet[fila->fim] = *novos;
        fila->fim++;

        return 1;
    }
    return 0;
}

int exluir_recursiva(tipFila *fila)
{
    int j;

    if(fila->fim > 0)
    { 
        PRINTposicao(fila->vet[0]);

        for(j=0; j<fila->fim; j++)
        { fila->vet[j] = fila->vet[j+1]; }
        
        fila->fim--;

        exluir_recursiva(fila);
    } 
    else 
    { return; }
    
}

int main(void)
{
    tipFila fila;
    fila.fim=0;
    int i, aux;
    
    srand(time(NULL));
    elem novos; 

    for(i=0; i<5; i++)
    {
        //gerar id aleatório.
        novos.id= rand()% 150;
        printf("ID: %d\n", novos.id);

        //gerar nome aleatório com uma letra.
        novos.nome[0]= (char)(rand()% 26 +97);
        printf("NOME: %s\n", novos.nome);

        aux = inserir(&novos, &fila);

        if(aux)
        { printf("Inserido com sucesso.\n\n"); }
        else
        { printf("Sem espa%co na fila.\n\n", 135); }
    }
    
    //excluir a primeira posição
    printf("========= EXCLUIR ===========\n");
    aux = exluir_recursiva(&fila);
}
