/*2) Implemente uma função que imprima a quantidade de 0s e 1s dado um vetor de inteiros. 
Assuma que este vetor possui apenas 0s e 1s.*/

#include <stdio.h>
#include <math.h>
#include <time.h>

//variáveis
int vet[15], aux;

//funções
void contabilizar(void);

int main(void)
{ 
    srand(time(NULL)); 

    printf("Fun%c%co\n", 135, 198);
    for(aux=0; aux<15; aux++)
    {
        vet[aux]=0;
        vet[aux]= rand() % 2;
        printf("%d   ", vet[aux]);
    }

    contabilizar();

    return 0;
}

void contabilizar(void)
{
    int zero=0, um=0;

    for(aux=0; aux<15; aux++)
    {
        if(vet[aux] == 0)
        {
            zero++;
        }
        else
        {
            um++;
        }
    }

    printf("\n\nEsse vetor possui:\n");
    printf("%d valores zeros.\n", zero);
    printf("%d valores uns.", um);
}