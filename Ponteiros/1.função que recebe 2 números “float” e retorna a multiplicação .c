/*1) Implemente uma função que recebe 2 números “float” e retorna a multiplicação 
e a divisão entre eles. Trate possíveis erros. Imprima esses valores calculados 
fora do escopo da função (na main).*/

#include <stdio.h>

int PRINTdivisaoXmultiplicacao(float *pmultiplicacao, float *pdivisao)
{
    printf("Multiplica%c%co: %.2f\n", 135, 198, *pmultiplicacao);
    printf("Divis%co: %.2f", 198, *pdivisao);
}

void divisaoXmultiplicacao(float num1, float num2)
{
    float divisao;
    float multiplicacao;

    if(num2 != 0)
    {
        divisao = num1 / num2;
    }
    else {printf ("divis%co imposs%cvel", 198, 161);}

    multiplicacao = num1 * num2;

    PRINTdivisaoXmultiplicacao(&multiplicacao, &divisao);

    return;
}

int main (void)
{
    float num1= 20.5;
    float num2 = 25.25;

    divisaoXmultiplicacao(num1, num2);

    return 0;
}