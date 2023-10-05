/*5. Implemente uma função recursiva que imprima o número de 0s e 
1s dado um vetor de inteiros. Assuma que este vetor possui apenas 0s e 1s.*/

#include <stdio.h>

int CONTzeroUM (int i, int vet[], int tam, int um)
{ 
    if(i < tam)
    {
        um = um + vet[i];
        
        return (CONTzeroUM(i+1, vet, tam, um));
    }

    return um;
}

int main (void)
{
    int tam = 5;
    int vet[5] = {0, 0, 1, 1, 0};
    int um = CONTzeroUM(0, vet, tam, 0);

    printf("Uns: %d\n", um);
    printf("Zeros: %d", tam-um);

    return 0;
}