/*1. (3,5) Implemente a estrutura de dados do tipo DEQUE de forma circular. Maiores
detalhes:
a) O nome DEQUE vem do inglês Double Ended Queue, que normalmente é traduzido
como Fila duplamente terminada.
b) A estrutura do tipo DEQUE é uma estrutura de dados na qual os elementos podem
ser tanto inseridos quanto excluídos de qualquer uma de suas extremidades (do
início/esquerda ou do fim/direita).
c) Sua implementação deve conter as definições de tipo e, no mínimo, as seguintes
funções: definir, inserir à direita, inserir à esquerda, remover à direita, remover à
esquerda e imprimir (do início/esquerda até o fim/direita).
d) Repito: a implementação deve ser circular, ou seja, as duas funções de inserir
devem ser capazes de ocupar a outra extremidade do vetor, caso seja necessário e
caso existam espaços vagos.
Se desejar enviar uma implementação não circular, o peso desta questão é (2,0).*/

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
    int NUMelem;
    int fim;
    int ini;
    elem vet[tam];
} tipFila;

int inserir_esquerda(elem *novos, tipFila *fila);
int inserir_direita(elem *novos, tipFila *fila);

void PRINTfila(tipFila *fila)
{
    int i;
    for(i=fila->ini; i<fila->fim || i<fila->ini; i++)
    {
        if(fila->fim == tam && i== tam)
        { i=0;}

        printf("NOME: %c\n", fila->vet[i].nome[0]);
        printf("ID: %d\n", fila->vet[i].id);
    }
    printf("\n");
}

void gerar(elem *novos)
{
    //gerar id aleatório.
    novos->id= rand()% 150;
    printf("ID: %d\n", novos->id);

    //gerar nome aleatório com uma letra.
    novos->nome[0]= (char)(rand()% 26 +97);
    printf("NOME: %c\n", novos->nome[0]);
}

int inserir_esquerda(elem *novos, tipFila *fila)
{
    if(fila->NUMelem == tam)
    { return 0; }
    else if(fila->ini == 0)
    { inserir_direita(novos, fila); }
    else
    {
        fila->vet[fila->ini-1] = *novos;
        fila->NUMelem++;
        fila->ini--;
  
        return 1;
    }
    
}

int inserir_direita(elem *novos, tipFila *fila)
{
    if(fila->NUMelem == tam)
    { return 0; }
    else if(fila->fim!=tam)
    {
        fila->vet[fila->fim] = *novos;
        fila->fim++;
        fila->NUMelem++;

        return 1;
    }
    else
    { inserir_esquerda(novos, fila); }
}

int exluir_esquerda(tipFila *fila)
{
    if(fila->NUMelem > 0)
    {
        fila->ini++;
        fila->NUMelem--;

        return 1;
    }
    return 0;
}

int exluir_direita(tipFila *fila)
{
    if(fila->NUMelem > 0)
    {
        fila->fim--;
        
        return 1;
    }
    return 0;
}

int main(void)
{
    tipFila fila;
    fila.fim=0;
    fila.ini=0;
    fila.NUMelem=0;
    
    int i, aux;

    srand(time(NULL));
    elem novos; 

    for(i=0; i<5; i++)
    {
        gerar(&novos);

        aux = inserir_direita(&novos, &fila);
        if(aux)
        { printf("Inserido com sucesso.\n\n"); }
        else
        { printf("Sem espa%co na fila.\n\n", 135); }
    }
    
    PRINTfila(&fila);

    //inserir pela direita
    printf("Inserir pela direita.\n\n");
    gerar(&novos);
    aux = inserir_direita(&novos, &fila);
    if(aux)
    { printf("Inserido com sucesso.\n\n"); }
    else
    { printf("Sem espa%co na fila.\n\n", 135); }

    //inserir pela esquerda
    printf("Inserir pela esquerda.\n\n");
    gerar(&novos);
    aux = inserir_esquerda(&novos, &fila);
    if(aux)
    { printf("Inserido com sucesso.\n\n"); }
    else
    { printf("Sem espa%co na fila.\n\n", 135); }

    PRINTfila(&fila);

    //excluir a primeira posição.
    printf("Excluir primeira posi%c%co\n\n", 135, 198);
    aux = exluir_esquerda(&fila);
    if(aux)
    { printf("Primeira posi%c%co excluida com sucesso.\n\n", 135, 198); }
    else
    { printf("Sem elementos para excluir.\n\n"); }

    //excluir ultima posição.
    printf("Excluir %cltima posi%c%co\n\n", 163, 135, 198);
    aux = exluir_direita(&fila);
    if(aux)
    { printf("Ultima posi%c%co excluida com sucesso.\n\n", 135, 198); }
    else
    { printf("Sem elementos para excluir.\n\n"); }

    //inserir pela esquerda
    printf("Inserir pela esquerda.\n\n");
    gerar(&novos);
    aux = inserir_esquerda(&novos, &fila);
    if(aux)
    { printf("Inserido com sucesso.\n\n"); }
    else
    { printf("Sem espa%co na fila.\n\n", 135); }
}

