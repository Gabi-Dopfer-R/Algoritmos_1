/*4. Implemente uma função recursiva que calcula o valor máximo de um vetor de inteiros.*/

#include <stdio.h>

int MAIORvalorVET (int i, int vet[], int tam, int maior)
{
    if(i == tam)
    {
        return;
    }
    else
    {
        if(vet[i] > maior)
        {
            maior = vet[i];
        }

        return(MAIORvalorVET(i+1, vet, 5, maior));
    }
}

int main (void)
{
    
    int vet[5] = {8, 90, 150, 40, 11};
    
    int maior = MAIORvalorVET(1, vet, 5, vet[0]);
    
    printf("%d", maior);

    return 0;
}