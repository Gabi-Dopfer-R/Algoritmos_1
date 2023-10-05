#include <stdio.h>

void selection(int vet[], int tam)
{
    int i, j, aux, menor;

    for(i=0; i<tam; i++)
    {
        menor=vet[i];
        aux=i;
        
        for(j=i; j<tam; j++)
        {
            if(vet[j] < menor)
            {
                menor= vet[j];
                aux = j;
            }
        }
        vet[aux]= vet[i];
        vet[i]= menor;
    }
}

int main (void)
{
    int vet[5]= {5,4,6,1,9};
    int i;

    selection(vet, 5);

    for(i=0; i<5; i++)
    {
        printf("%d  ", vet[i]);
    }

    return 0;
}