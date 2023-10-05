/*2) Implemente o Selection Sort para o exercício de algoritmos de busca. 
Ele deve ser capaz de colocar o vetor do tipo "aluno" ordenado por idade, e não mais por matrícula.*/

#include <stdio.h>
#include <string.h>

typedef struct
{
    int num_matricula;
    int idade;
    char nome[100];

}aluno;

void VALORESdoVETOR(aluno vet[])
{
    vet[0].num_matricula = 4;
    vet[0].idade= 25;

    vet[1].num_matricula = 15;
    vet[1].idade= 20;

    vet[2].num_matricula= 65;
    vet[2].idade= 41;

    vet[3].num_matricula= 85;
    vet[3].idade= 16;

    vet[4].num_matricula= 123;
    vet[4].idade = 45;

    int i;
    for(i=0; i<5; i++)
    {
        printf("nome %d: ", i);
        gets(vet[i].nome);
    }
}

void printVET(aluno vet[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        printf("%d  ", vet[i].idade);
    }
    printf("\n");
}

void trocar(aluno vet[], int x, int y)
{
    aluno aux;
    
    aux = vet[x];
    vet[x] = vet[y];
    vet[y] = aux;
}

void selectionSORT(aluno vet[], int tam)
{
    int i, j, aux, menor;

    for(i=0; i<tam; i++)
    {
        menor=vet[i].idade;
        aux=i;
        
        for(j=i; j<tam; j++)
        {
            if(vet[j].idade < menor)
            {
                menor= vet[j].idade;
                aux = j;
            }
        }
        
        trocar(vet, aux, i);
    }
}


int main (void)
{
    aluno vet[5];
    
    VALORESdoVETOR(vet);
    
    selectionSORT(vet, 5);
    printVET(vet, 5);
}