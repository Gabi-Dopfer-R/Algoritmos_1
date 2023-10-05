/*6) Resolva:
a) Defina uma struct capaz de armazenar o nome, peso e idade de diferentes pessoas;
b) Implemente uma função que recebe e armazena informações necessárias para a struct definida acima. 
Assuma um número máximo de 100 pessoas;
c) Implemente uma função que imprime o nome de todas as pessoas cadastradas 
com idade entre 20 e 30 anos e peso acima de 50kg.*/

#include <stdio.h>
#include <string.h>

//dados da struct....
struct dados
{
    char nome[100];
    float peso;
    int idade;
};

//variáveis.........
struct dados pessoa[100];
int i;

//funções.......
void info (void);
void cadastradas (void);

int main (void)
{
    info ();
    cadastradas ();
}

void info (void)
{
    printf("Insira os dados pedidos, em seguida precione 0 para continuar\n");
    for(i=0; i<100; i++)
    {
        printf("Nome:");
        fflush(stdin);
        gets(pessoa[i].nome);
        
        if(pessoa[i].nome[0] == '0')
        {
            printf("\n");
            break;
        }

        printf("Peso:");
        fflush(stdin);
        scanf("%f", &pessoa[i].peso);

        printf("Idade:");
        fflush(stdin);
        scanf("%d", &pessoa[i].idade);
        printf("\n");
    }

    return;
}

//mostrar apenas as pessoas pedidas no exercício...
void cadastradas (void)
{
    for(i=0; i<100; i++)
    {
        if(pessoa[i].idade >= 20 && pessoa[i].idade <= 30 && pessoa[i].peso > 50)
        {
            printf("%s\n", pessoa[i].nome);
        }
    }

    return;
}
