/*5) Goofy é fã do programa de auditório Apagando e Ganhando. 
Neste programa, o jogo começa quando o apresentador escreve 
um número N em uma lousa. O participante então deve apagar exatamente 
D dígitos do número que está na lousa. O número formado pelos dígitos 
que restarem será o prêmio do participante. 
Goofy finalmente foi selecionado para participar do programa, 
e pediu que você escrevesse um programa que, dados o número que o 
apresentador escreveu na lousa e quantos dígitos devem ser apagados, 
determina o valor do maior prêmio que Goofy pode ganhar. Exs.: 
N = 2318 e D = 1, resposta = 318; 
N = 3759 e D = 2, resposta = 79; 
N = 123123 e D = 3, resposta = 323; 
N= 22313 e D=2, resposta = 313; 
N = 1000000 e D = 4, resposta = 100.*/

#include <stdio.h>
#include <math.h>

void definirNUMfinal(int digMAIOR, int digNUM, int num, int d, int maior)
{
    int j = maior;
    int i;
    int cont;
    int numFINAL;

    if(digNUM - digMAIOR <= d)
    {
        numFINAL = num% (int)ceil(pow(10, digMAIOR));
        
        if(digNUM - digMAIOR < d)
        {
            i = d - (digNUM - digMAIOR);

            numFINAL = numFINAL / pow(10, i);
        }

        printf("%d", numFINAL);
    }
    else
    { 
        for(i=num, cont=0; i != 0; i=i/10, cont++)
        {
            if(i%10 > maior && i%10 < j)
            {
                maior = i%10;
                digMAIOR = cont;
            }   
        }

        definirNUMfinal(digMAIOR, digNUM, num, d, maior); 
    }

}

int main (void)
{
    int num= 1912;
    int d=2;
    int i; 
    int maior=0;
    int digNUM=0;
    int digMAIOR;

    for(i=num; i > 0; i=i/10, digNUM++)
    {
        if(i%10 >= maior)
        {
            maior = i%10;
            digMAIOR = digNUM;
        }   
    }
    digMAIOR++;

    definirNUMfinal(digMAIOR, digNUM, num, d, maior); 

    return 0;
}

