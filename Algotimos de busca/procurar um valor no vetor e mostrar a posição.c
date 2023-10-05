#include <stdio.h>

int posicaoXemV(int vet[], int x, int tam)
{
    int i;

    for(i=0; i<tam; i++)
    {
        if(vet[i] == x)
        {
            return i;
        }
    }
    
    return -1;
}

int main (void)
{
    int vet[9]={8,5,1,4,7,3,2,1,9};
    int x=7; 
    
    int posicao = posicaoXemV(vet, x, 9);
    
    if(posicao == -1)
    {
        printf("O n%cmero n%co pertence ao vetor.", 163, 198);
    }
    else{ printf("Posi%c%co: %d", 135, 198, posicao); }

    return 0;
}