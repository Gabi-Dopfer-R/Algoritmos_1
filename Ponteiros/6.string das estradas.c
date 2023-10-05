/*6) Você pretende fazer uma viagem de carro em Duckland, 
Sum país muito organizado em que todos os pedágios de uma 
mesma estrada estão organizados de maneira equidistante, 
a partir da capital Donald. Seu destino final é Scrooge, 
porém são 4 estradas possíveis entre Donald e Scrooge. Por consequência, 
cada estrada terá uma quilometragem total diferente, número de pedágios 
diferente e consumo de gasolina diferente devido às condições do asfalto. 
Suas opções são:

Estrada     Quilometragem total     Distância entre cada pedágio    Consumo (km/litro)

A           150                     20                              10
B           120                     15                              8,5
C           135                     20                              8,2
D           160                     30                              9,4

Implemente:
A. Um vetor de “structs” para armazenar os valores da tabela acima;
B. Uma função que recebe o vetor de structs criado em (a) e calcula 
o número de pedágios daquela estrada e a quantidade de litros de combustível gasta;
C. Um vetor de “structs” que armazene os valores computados em (b);
D. Uma função que calcule o custo da viagem para cada estrada, 
recebendo como parâmetros: uma struct (conforme criada em (c)), 
o preço de cada pedágio e o preço do combustível. 
Ex.: se cada pedágio custa 10 duckdollars e o combustível é vendido por 3 duckdollars, 
o custo da viagem em cada estrada seria:

A   115,00
B   122,35
C   109,39
D   101,06
Teste também com outros preços. A estrada D será sempre a mais vantajosa, 
mesmo baixando/aumentando o preço do pedágio ou do combustível?*/

#include <stdio.h>
#include <string.h>

struct str
{
    char estrada[2];
    int km_total;
    int dist_pedagio;
    int qtd_pedagio;
    float km_litro;
    float total_litros;
    float custo;
};

void atribuir_variaveis(struct str vet[])
{
    vet[0].estrada[0] = 'A';
    vet[0].km_total = 150;
    vet[0].dist_pedagio = 20;
    vet[0].km_litro = 10;

    vet[1].estrada[0] = 'B';
    vet[1].km_total = 120;
    vet[1].dist_pedagio = 15;
    vet[1].km_litro = 8.5;

    vet[2].estrada[0] = 'C';
    vet[2].km_total = 135;
    vet[2].dist_pedagio = 20;
    vet[2].km_litro = 8.2;

    vet[3].estrada[0] = 'D';
    vet[3].km_total = 160;
    vet[3].dist_pedagio = 30;
    vet[3].km_litro = 9.4;
}

//QUANTIDADE DE PEDÁGIOS E TOTAL DE LITROS.................
void PEDAGIOxLITROS(struct str vet[], int tam, int i)
{
    for(i=0; i<tam; i++)
    {
        vet[i].qtd_pedagio = vet[i].km_total / vet[i].dist_pedagio; 

        vet[i].total_litros = vet[i].km_total / vet[i].km_litro; 
    }
}

//CUSTOS TOTAIS DE CADA ESTRADA....................................
void custos(struct str vet[], int tam, int valor_pedagio, int valor_gasolina, int i)
{
    for(i=0; i<tam; i++)
    {
        vet[i].custo = (vet[i].qtd_pedagio * valor_pedagio) + (vet[i].total_litros * valor_gasolina); 
    }
}

int main(void)
{
    //VÁRIAVEIS......................
    struct str vet[4];
    float valor_pedagio=10;
    float valor_gasolina=3;
    int tam =4;
    int i;
    
    //FUNÇÕES..................
    atribuir_variaveis(vet);
    PEDAGIOxLITROS(vet, tam, 0);
    custos(vet, tam, valor_pedagio, valor_gasolina, 0);
    
    //PRINTAR RESPOSTAS.......................
    for(i=0; i<tam; i++)
    {
        printf("ESTRADA: %c\n", vet[i].estrada[0]);
        printf("N%cmeros de ped%cgios: %d\n", 163, 160, vet[i].qtd_pedagio);
        printf("Total de litros: %.2f\n\n", vet[i].total_litros);
    }

    for(i=0; i<tam; i++)
    {
        printf("ESTRADA: %c     CUSTO: %.2f\n", vet[i].estrada[0], vet[i].custo);
    }

    return 0;
}
    
