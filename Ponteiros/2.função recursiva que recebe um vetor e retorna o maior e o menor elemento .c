/*2) Implemente uma função recursiva que recebe um vetor com 10 
diferentes números e retorna o maior e o menor dentre estes números. 
Imprima esses valores fora do escopo da função (na main).*/

#include <stdio.h>

int PRINtmaiorXmenor(int *pmaior, int *pmenor)
{
    printf("Maior: %d\n", *pmaior);
    printf("Menor: %d", *pmenor);
}

void maiorXmenor(int vet[], int tam, int aux, int maior, int menor)
{
    if(aux < tam)
    {
        if(vet[aux]> maior)
        {
            maior = vet[aux];
        }
        if(vet[aux]< menor)
        {
            menor = vet[aux];
        }

        maiorXmenor(vet, tam, aux+1, maior, menor);
    }
    else{PRINtmaiorXmenor(&maior, &menor);}
    
    return;
}

int main (void)
{
    int vet[10]={0, 210, -315, 450, 2, 76, -80, 64, -21, 9};

    maiorXmenor(vet, 10, 0, vet[0], vet[0]);

    return 0;
}