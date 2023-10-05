/*a) crie o tipo "aluno" (utilizando-se de struct) 
capaz de armazenar número de matrícula, idade e nome
b) crie um vetor com 5 elementos do tipo "aluno"
c) insira valores no vetor criado acima, 
de forma que os alunos estejam ordenados por ordem de matrícula
d) qual o tipo de busca ideal para encontrar um aluno 
pelo número de matrícula? implemente.
e) qual o tipo de busca ideal para encontrar um aluno pela idade? implemente.
f) refaça as implementações de busca acima retornando um 
ponteiro para o tipo "aluno", e não mais o índice do vetor.*/

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
    vet[0].nome[0]= 'a';

    vet[1].num_matricula = 15;
    vet[1].idade= 20;
    vet[1].nome[0]= 'b';

    vet[2].num_matricula= 65;
    vet[2].idade= 41;
    vet[2].nome[0]= 'c';

    vet[3].num_matricula= 85;
    vet[3].idade= 16;
    vet[3].nome[0]= 'd';

    vet[4].num_matricula= 123;
    vet[4].idade = 45;
    vet[4].nome[0]= 'e';
}

//buscar matricula por busca binária.
void BUSCAmatricula(aluno vet[], int tam, int busca_m, int *posicao_m)
{
    *posicao_m = tam-1;
    
    while(busca_m != vet[*posicao_m].num_matricula)
    {
        if(busca_m < vet[*posicao_m].num_matricula)
        {
            *posicao_m /= 2;
        }
        if(busca_m > vet[*posicao_m].num_matricula)
        {
            *posicao_m = (tam-1) - (*posicao_m/2);
        }
    }

    
}

//buscar idade por busca sequencial.
void BUSCAidade(aluno vet[], int tam, int busca_i, int *posicao_i)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(vet[i].idade == busca_i )
        {
            *posicao_i =  i;
        }
    }
}

int main (void)
{
    aluno vet[5];
    int busca_i = 41;
    int busca_m = 4;
    int posicao_i;
    int posicao_m;

    VALORESdoVETOR(vet);
    
    BUSCAmatricula(vet, 5, busca_m, &posicao_m);
    printf("Posi%c%co do aluno pela matr%ccula: %d\n", 135, 198, 161, posicao_m);

    BUSCAidade(vet, 5, busca_i, &posicao_i);
    printf("Posi%c%co do aluno pela idade: %d\n", 135, 198, posicao_i);
}