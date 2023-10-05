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
} tipPilha;

int inserir(elem *novos, tipPilha *pilha)
{
    if(pilha->fim!=tam)
    {
        pilha->vet[pilha->fim] = *novos;
        pilha->fim++;

        return 1;
    }
    
    return 0;
}

int exluir(tipPilha *pilha)
{
    if(pilha->fim > 0)
    {
        pilha->fim--;
        
        return 1;
    }
    
    return 0;
}

int main(void)
{
    tipPilha pilha;
    pilha.fim=0;
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

        //inserir vlores na pilha.
        aux = inserir(&novos, &pilha);
        if(aux)
        { printf("Inserido com sucesso.\n\n"); }
        else
        { printf("Sem espa%co na Pilha.\n\n", 135); }
    }
    
    //excluir ultimoo valor da pilha.
    printf("Excluir %cltima posi%c%co da pilha:\n", 163, 135, 198);
    aux = exluir(&pilha);
    if(aux)
    { printf("Excluido com sucesso.\n\n"); }
    else
    { printf("Sem elementos para ecluir.\n\n"); }
}
