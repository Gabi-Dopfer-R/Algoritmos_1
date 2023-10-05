/*5) Adicionar a TAD uma função "InserirOrdenado", 
que ao invés de inserir o novo elemento baseado no parâmetro de posição, 
é capaz de automaticamente encontrar a posição correta para o novo elemento 
de forma a manter a lista ordenada por RAs.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define tam 100

typedef struct
{
    int id;
    char nome[50];
}elem;

typedef struct
{
    int NUMelem;
    elem vet[tam];
}tipeL;

void printLISTA(elem vet[], int NUMelem)
{
    int i;

    for(i=0; i<NUMelem; i++)
    {
        printf("NOME: %s\n", vet[i].nome);
        printf("ID: %d\n\n", vet[i].id);
        
    }
}

int inserir(tipeL *lista, elem *novo)
{
    if(lista->NUMelem >= tam)//lista cheia
    { return 0; }
    else//inserir
    { 
        int j;
    
        j=lista->NUMelem;

        while(novo->id < lista->vet[j].id && j>=0)
        {
            lista->vet[j+1] = lista->vet[j];
            j--;    
        }

        lista->vet[j+1] = *novo;
        lista->NUMelem++;

        return 1;
    }

}

elem* obter(tipeL *lista, int posicao)
{
    if(posicao > lista->NUMelem || posicao <0)
    { return NULL; }
    else
    { return &(lista->vet[posicao]); }
}

int remover(tipeL *lista, int posicao)
{
    int i;

    if(lista->NUMelem<=0)//lista fazia
    { return 0; }
    else if(posicao > lista->NUMelem || posicao <0)//posicao nao existe
    { return -1; }
    else
    {
        for(i=posicao; i<lista->NUMelem; i++)
        {
            lista->vet[i]= lista->vet[i+1];
        }

        lista->NUMelem--;

        return 1;
    }       
}

int main (void)
{
    tipeL lista;
    lista.NUMelem=0;
    int i, aux;
    
    srand(time(NULL));
    elem novo;

    for(i=0; i<5; i++)
    {    
        //gerar id aleatório.
        novo.id= rand()% 25;
        printf("ID: %d\n", novo.id);

        //gerar nome aleatório com uma letra.
        novo.nome[0]= (char)(rand()% 26 +97);
        printf("NOME: %s\n", novo.nome);
        
        aux = inserir(&lista, &novo);
        
        if(!aux)
        { printf("Lista cheia\n\n"); }
        else
        { printf("Inserido com sucesso\n\n"); }
    }

    printf("\n====Lista=====\n\n");
    printLISTA(lista.vet, lista.NUMelem);

    //Obter id da posição 4 da lista
    printf("Obter id do aluno 4:\n");
    elem *aluno = obter(&lista, 4);

    if(aluno == NULL)
    { printf("Posi%c%co n%co existe\n\n", 135,198,198); }
    else
    { printf("O aluno %s tem matricula %d.\n\n", aluno->nome, aluno->id); }

    //remover posicao
    aux= remover(&lista, 3);

    if(!aux)
    { printf("Lista fazia.\n\n"); }
    else if(aux == 1)
    { printf("Aluno posi%c%co 3 Removido com sucesso\n\n", 135, 198); }
    else
    { printf("Posi%c%co n%co existe\n\n", 135,198,198); }

    //printf lista
    printLISTA(lista.vet, lista.NUMelem);
}