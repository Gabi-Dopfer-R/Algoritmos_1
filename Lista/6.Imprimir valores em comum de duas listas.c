/*6) Crie uma função que recebe duas variáveis L1 e L2 do tipo 
lista estática e imprime todos elementos de L1 que também estão em L2.*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define tam 100

typedef struct
{
    int id;
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
    }
}

int printELEMENTOScomuns(tipeL *l1, tipeL *l2)
{
    int i, j, aux=0;

    for(i=0; i<l1->NUMelem; i++)
    {
        for(j=0; j<l2->NUMelem; j++)
        {
            if(l1->vet[i].id == l2->vet[j].id)
            {
                printf("ID: %d\n", l1->vet[i].id);
                aux=1;
                break;
            }  
        }
    }

    if(!aux)
    { return 0; }
}

void inserir(tipeL *lista, elem *novo)
{
    if(lista->NUMelem == tam)//lista cheia
    { return; }
    else//inserir
    { 
        lista->vet[lista->NUMelem]= *novo;
        lista->NUMelem++;

        return;
    }

}

int main (void)
{ 
    tipeL l1, l2;
    l1.NUMelem=0;
    l2.NUMelem=0;
    int i, aux;
    
    srand(time(NULL));
    elem novo;

    for(i=0;i<10;i++)
    {    
        novo.id= rand()% 25;
        inserir(&l1, &novo);

        novo.id= rand()% 30; 
        inserir(&l2, &novo);
    }

    printf("l1:\n");
    printLISTA(l1.vet, l1.NUMelem);

    printf("\nl2:\n");
    printLISTA(l2.vet, l2.NUMelem);

    printf("\nElementos em commum:\n");
    aux = printELEMENTOScomuns(&l1, &l2);
    if(!aux)
    { printf("\n\nl1 e l2 n%co possuem nenhum elemento em comum.\n", 198); }
}