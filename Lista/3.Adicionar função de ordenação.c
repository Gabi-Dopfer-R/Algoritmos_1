/*3) Adicionar a TAD uma função que implemente um algoritmo de ordenação.*/

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
        lista->vet[lista->NUMelem]= *novo;
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

void trocar(elem vet[], int x, int y)
{
    elem aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
}

void quicksort(elem vet[], int ini, int fim)
{
    int pivo = vet[fim].id;
    int posicao = ini;
    int i;

    if( ini <= fim)//função de parada.
    {
        //ordenar os valores.
        for(i=ini; i<=fim-1; i++)
        {
            if(vet[i].id <= pivo)
            {
                if(posicao!=i)
                { trocar(vet, i, posicao); }

                posicao++;
            }
        }
        trocar(vet, posicao, i);

        //chamar função recursiva.
        quicksort(vet, ini, posicao-1);
        quicksort(vet, posicao+1, fim); 
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

    //Obter id da posição 4 da lista
    printf("Obter id do aluno 4:\n");
    elem *aluno = obter(&lista, 4);

    if(aluno == NULL)
    { printf("Posi%c%co n%co existe\n\n", 135,198,198); }
    else
    { printf("O aluno %s tem matricula %d.\n\n", aluno->nome, aluno->id); }

    //remover posicao
    printf("Remover aluno 3:\n");
    aux= remover(&lista, 3);

    if(!aux)
    { printf("Lista fazia.\n\n"); }
    else if(aux)
    { printf("Aluno posi%c%co 3 Removido com sucesso\n\n", 135, 198); }
    else
    { printf("Posi%c%co n%co existe\n\n", 135,198,198); }

    //ordenar por id.
    printf("Ordenar por ID:\n");
    quicksort(lista.vet, 0, lista.NUMelem-1);

    //printf lista
    printLISTA(lista.vet, lista.NUMelem);
}