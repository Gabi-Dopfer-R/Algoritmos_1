#include <stdio.h>

void MENOReMAIOR(int *pMAIOR, int *pMENOR, int i, int vet[], int tam)
{
    if(i < tam)
    {
        if(vet[i] > *pMAIOR)
        {
            *pMAIOR = vet[i];
        }
        if (vet[i] < *pMENOR)
        {
            *pMENOR = vet[i];
        }

        MENOReMAIOR(pMAIOR, pMENOR, i+1, vet, 5);
    }
}

int main (void)
{
    int vet[5] = {1, 5, 6, 8, 10};
    int maior = vet[0];
    int menor = vet[0]; 

    MENOReMAIOR(&maior, &menor, 1, vet, 5);

    printf("Menor: %d\n", menor);
    printf("Maior: %d", maior);

    return 0;
}