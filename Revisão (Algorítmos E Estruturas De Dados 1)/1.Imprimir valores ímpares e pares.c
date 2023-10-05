/*1) Implemente uma função que recebe um vetor de 
inteiros e imprime a quantidade de números pares e a quantidade 
de números ímpares neste vetor.*/

#include <stdio.h>
#include <math.h>
#include <time.h>

//funções
void imparXpar(int vet[], int aux);

int main(void)
{ 
    int vet[15], aux;
    srand(time(NULL)); 

    printf("Fun%c%co\n", 135, 198);
    for(aux=0; aux<15; aux++)
    {
        vet[aux]=0;
        vet[aux]= rand();
        printf("%d  ", vet[aux]);
    }

    imparXpar(vet, aux);

    return 0;
}

void imparXpar(int vet[], int aux)
{
    int par=0, impar=0;
    
    for(aux=0; aux<15; aux++)
    {
        if(vet[aux] %2 == 0)
        {
            par++;
        }
        else
        {
            impar++;
        }
    }

    printf("\n\nEsse vetor possui:\n");
    printf("%d valores %cmpares.\n", impar, 161);
    printf("%d valores pares.", par);

    return;
}

