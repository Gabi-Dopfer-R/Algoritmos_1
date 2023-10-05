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

int exluir(tipFila *fila)
{
    if(fila->fim > 0)
    {
        int i;

        for(i=0; i<=fila->fim-1; i++)
        {
            fila->vet[i] = fila->vet[i+1];
        }

        return 1;
    }
    return 0;
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
    aux = exluir(&fila);
    
    if(aux)
    { printf("Primeira posi%c%co excluida com sucesso.", 135, 198); }
    else
    { printf("Sem elementos para ecluir.\n\n"); }
}
