/*6.  Escreva uma função recursiva que determine quantas vezes 
um dígito K ocorre em um número natural N. 
Por exemplo, o dígito 2 ocorre 3 vezes em 762021192.*/

#include <stdio.h>

int ocorrencia (int num, int digito, int contDig)
{ 
    if(num % 10 != 0)
    {
        if(num % 10 == digito)
        {
            contDig++; 
        }
        
        num = num/10;
        return (ocorrencia(num, digito, contDig));
    }  

    return contDig;
}

int main (void)
{
    int num = 218981;
    int digito = 1;
    int contDig = ocorrencia(num, digito, 0);

    printf("%d", contDig);
    return 0;
}