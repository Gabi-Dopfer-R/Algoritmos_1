/*3) Implemente uma função que imprime uma string 
(array de caracteres) em ordem inversa. 
Exemplo: "pablo" -> "olbap"*/

#include <stdio.h>

//variáveis.
char frase[100], frase2[100];
int i, j;

//funções.
void ORDEMinversa(void);

int main(void)
{
    printf("Insira uma frase:");
    fflush(stdin);
    gets(frase);

    i=0;
    while(frase[i]!='\0')
    {
        i++;
    }

    ORDEMinversa();

    return 0;
}

void ORDEMinversa(void)
{
    for(j=0, i=i-1; i>=0; j++, i--)
    {
        frase2[j] = frase[i];
    }
    frase2[j] = '\0';

    printf("O inverso da frase %c: %s", 130, frase2);
    return;
}