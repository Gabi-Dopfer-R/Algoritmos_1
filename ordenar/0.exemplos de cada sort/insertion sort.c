#include <stdio.h>

void insertion(int vet[], int tam, int i)
{
    int j;
    int valor;

    //percorrer todos os valores do vetor.
    for(i=0; i<tam; i++)
    {
        j=tam-1;

        //se valor está no lugar ir pro próx.
        while(vet[j] > vet[j-1])
        { j--; }

        valor = vet[j];

        while(valor <= vet[j] && j!=0)
        {
            vet[j] = vet[j-1];
            j--;
        }

        vet[j] = valor;
    }
}

int main (void)
{
    int vet[5]={6,2,3,5,1};
    int i;

    insertion(vet, 5, 0);

    for(i=0; i<5; i++)
    {
        printf("%d  ", vet[i]);
    }

    return 0;
}