/*5) Implemente uma função que recebe um inteiro N e retorna o fatorial de N. 
Imprima o valor retornado na "main".*/

#include <stdio.h>

//funçoes...
void fatorial (int num);

int main(void)
{
    int num;

    printf("Insira um n%cmero inteiro:", 163);
    fflush(stdin);
    scanf("%d", &num);

    fatorial (num);

    return 0;
}

void fatorial (int num)
{
    int fat=1, i;
    
    printf("%d! =", num);

    for (i=1; i<=num; i++)
    {
        fat *= i;
        printf(" %d ", i);

        if(i != num)
        {
            printf("*");
        }
        else
        {
            printf("= %d", fat);
        }
    }

   return;
}