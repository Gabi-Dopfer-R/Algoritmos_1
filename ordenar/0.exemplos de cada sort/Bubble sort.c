#include <stdio.h>

void blubbleSORT(int tam, int i, int vet[])
{
    int aux, j;

    for(i=0; i<tam; i++)
    {
        if(vet[i] > vet[i+1])
        {
            aux = vet[i];
            vet[i] = vet[i+1];
            vet[i+1] = aux;
            j=1;
        }
    }
    
    if(j==0)
    {
        return;
    }else{ blubbleSORT(tam, i, vet); }  
}

int main (void)
{
    int vet[5]={7,2,3,1,4};
    int i;

    blubbleSORT(5, i, vet);

    for(i=0; i<5; i++)
    {
        printf("%d   ", vet[i]);
    }
}