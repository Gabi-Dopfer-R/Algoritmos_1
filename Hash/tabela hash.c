#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define tam 31

typedef struct
{
    float nota;
    char nome[50];
}elem;

typedef struct
{
    elem aluno[tam];
}tipeHash;

void DEFINEhash (tipeHash *hash)
{
    int i;
    for(i=0; i<tam; i++)
    { hash->aluno[i].nota = -1; }
}

int FuncaoHash (elem *novo)
{
    int pos = 0;
    int i;
    for(i=0; novo->nome[i] != '\0'; i++)
    { pos += (int)novo->nome[i]; }
    pos %= tam; 
    return pos;
}

int inserir(tipeHash *hash, elem *novo)
{
    int pos = FuncaoHash(novo);
    while(hash->aluno[pos].nota != -1)
    { pos++; }

    if(pos == tam)
    { return 0; }
    else
    { 
        hash->aluno[pos].nota = novo->nota;
        strcpy(hash->aluno[pos].nome, novo->nome);
        return 1;
    }
}

float obter(tipeHash *hash, elem *pessoa)
{
    int pos = FuncaoHash(pessoa);
    int i;
    for(i=pos; i<tam; i++)
    {
        if(strcmp(pessoa->nome, hash->aluno[i].nome)==0)
        { return hash->aluno[pos].nota; }
    }
    
    return -1;
}

int main (void)
{
    tipeHash hash;
    DEFINEhash(&hash);
    int i;
    int aux;

    srand(time(NULL));
    elem novo;

    for(i=0; i<tam/2; i++)
    {
        //gerar nota aleatória.
        novo.nota = rand() % 100;
        novo.nota /= 10;

        //gerar nome aleatório.
        int j;
        for(j=0; j<=7; j++)
        { novo.nome[j]= (char)(rand()% 16 + 97); }
        novo.nome[j]= '\0';

        aux = inserir(&hash, &novo);

        printf("Aluno: %s.\n", novo.nome);/////////////
        printf("Nota: %.1f\n", novo.nota);//////////////

        if(!aux)
        { printf("Colis%co\n\n", 198); }
        else
        { printf("Inserido com sucesso\n\n"); }
    }

    printf("==== Obter ======\n\n");
    //Obter nota de aluno não cadastrado.
    elem pessoa;
    
    pessoa.nome[0] = 'g';
    pessoa.nome[1] = 'a';
    pessoa.nome[2] = 'b';
    pessoa.nome[3] = 'i';
    pessoa.nome[4] = '\0';
    printf("Obter aluno: %s\n", pessoa.nome);
    pessoa.nota = obter(&hash, &pessoa);
    if(pessoa.nota >= 0)
    { printf("Nota:%.1f\n\n", pessoa.nota); }
    else
    { printf("Aluno n%co registrado.\n\n", 198); }

    //obter nota de aluno cadastrado.
    i = 4;
    while(hash.aluno[i].nota < 0)
    { i++; }
    
    strcpy(pessoa.nome, hash.aluno[i].nome);
    printf("Obter aluno: %s\n", pessoa.nome);
    
    pessoa.nota = obter(&hash, &pessoa);
    if(pessoa.nota >= 0)
    { printf("Nota:%.1f\n\n", pessoa.nota); }
    else
    { printf("Aluno n%co registrado.\n\n", 198); }
}