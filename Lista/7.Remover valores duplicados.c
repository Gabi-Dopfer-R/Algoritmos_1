/*7) Crie uma função que remove elementos duplicados de uma lista, ou seja, 
se existirem 2 ou mais elementos com o mesmo "id" na lista, 
apenas um deles deve permanecer após a execução desta função.*/

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
        printf("ID: %d\n", vet[i].id);
        printf("NOME: %s\n\n", vet[i].nome);  
    }
}

void inserir(tipeL *lista, elem *novo)
{
    if(lista->NUMelem >= tam)
    { return; }
    else//inserir
    { 
        lista->vet[lista->NUMelem]= *novo;
        lista->NUMelem++;

        return;
    }
}

void excluirDUPLICADOS (tipeL *lista)
{
    int i, j, z;

    for(i=0; i<lista->NUMelem; i++)
    {
        for(j=i+1, z=j; j<lista->NUMelem; j++)
        {
            if(lista->vet[j].id != lista->vet[i].id)
            {
                lista->vet[z] = lista->vet[j];
                z++;
            }
        }
        lista->NUMelem = z;
    }
}

int main (void)
{
    tipeL lista;
    lista.NUMelem=0;
    int i;
    
    srand(time(NULL));
    elem novo;

    for(i=0; i<5; i++)
    {
        //gerar id aleatório.
        novo.id= rand()% 4;

        //gerar nome aleatório com uma letra.
        novo.nome[0]= (char)(rand()% 26 +97);

        inserir(&lista, &novo);    
    }
    printf("Lista original:\n");
    printLISTA(lista.vet, lista.NUMelem);
    printf("\n");

    printf("Sem valores duplicados:\n");
    excluirDUPLICADOS (&lista);

    printLISTA(lista.vet, lista.NUMelem);
}