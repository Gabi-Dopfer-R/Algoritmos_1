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

int inserir(elem *novos, tipFila *fila)
{
    if(fila->NUMelem == tam)
    { return 0; }
    else
    {
        if(fila->fim == tam)
        { fila->fim=0; }

        fila->vet[fila->fim] = *novos;
        fila->NUMelem++;
        fila->fim++;
  
        return 1;
    }
    
}

int exluir(tipFila *fila)
{
    if(fila->NUMelem == 0)
    { return 0;}
    else
    {
        if(fila->ini == tam)
        { fila->ini=0; }
        else
        { fila->ini++; }
        fila->NUMelem--;
        
        return 1;
    }
    
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
    { printf("Primeira posi%c%co excluida com sucesso.\n\n", 135, 198); }
    else
    { printf("Sem elementos para excluir.\n\n"); }
}
