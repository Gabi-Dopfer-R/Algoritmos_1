/*2) Utilize uma fila para resolver o problema abaixo:
Sua arquitetura computacional é capaz de armazenar uma fila 
dos processos que querem fazer uso da CPU do mesmo. Entretanto, 
para evitar que um só processo utilize a CPU por muito tempo, 
deixando os demais ociosos, a arquitetura foi programada para que cada
processo só possa utilizar a CPU por, no máximo, 4 ms (milisegundos). 
Sendo assim, sempre que um processo necessitar de mais tempo de processamento, 
ele retorna ao final da fila. Suponha que este sistema está, no momento, 
com 5 processos A,B,C,D e E (que entraram na fila nesta exata ordem) 
e que eles necessitam de A=20 ms, B=7ms, C=10ms, D=4ms, E=9ms como tempos de processamento. 
Implemente as funções necessárias para mostrar a exata ordem que estes processos 
serão executados e por quanto tempo.*/

#include <stdio.h>
#include <string.h>

#define tam 100 //tamanho do vet
#define exe_time 4 	//tempo de execução pra cada programa

typedef struct 
{
    int time;
    char name[50];
}elem;	

typedef struct
{
    int fim;
    int ini;
    elem vet[tam];
}tipFila;

void InsertValue(tipFila *fila)
{
    ///valores da fila.
    fila->fim=5;
    fila->ini=0;
    //name.......
    fila->vet[0].name[0] = 'A';
    fila->vet[1].name[0] = 'B';
    fila->vet[2].name[0] = 'C';
    fila->vet[3].name[0] = 'D';
    fila->vet[4].name[0] = 'E';
    //time........
    fila->vet[0].time = 20;
    fila->vet[1].time = 7;
    fila->vet[2].time = 10;
    fila->vet[3].time = 4;
    fila->vet[4].time = 9;
}
void PRINTfila(elem vet[], int ini)
{
    printf("\t%c  \t\t", vet[ini].name[0]);

    if(vet[ini].time >= exe_time)
    { printf("%d ms\n", exe_time); }
    else
    { printf("%d ms\n",vet[ini].time); }   
}

void Insert(tipFila *fila)
{
    fila->vet[fila->fim] = fila->vet[fila->ini];
    
    if(fila->fim < tam)
    { fila->fim++; }
    else
    { fila->fim=0; }
}

int execute(tipFila *fila)
{
    while(fila->fim != fila->ini)
    {
        PRINTfila(fila->vet, fila->ini);

        if(fila->vet[fila->ini].time > exe_time)
        { 
            fila->vet[fila->ini].time -=4;
            Insert(fila); 
        }

        fila->ini++;
    }
}

int main(void)
{
    tipFila fila;

    InsertValue(&fila);
    printf("Programa executado / tempo de execu%c%co\n", 135, 198);
    execute(&fila);
}
