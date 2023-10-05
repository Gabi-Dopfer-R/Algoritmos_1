/*3. (2,5) Crie uma função que utiliza uma pilha para verificar se uma frase é palíndroma. Esta
função deve retornar 1 caso a frase seja palíndroma, e -1 caso não seja. Obs.:
a) frases palíndromas são iguais se lidas tanto do início pro fim quanto do fim pro início.
Ex: “roma me tem amor”.
b) os espaços em branco devem ser ignorados e você pode assumir que a frase só tem
caracteres minúsculos.
c) pode existir um caractere que não se repete exatamente no meio da frase. Ex: “a
grama é amarga”.
d) você pode utilizar a função “strlen” ou outra para verificar o tamanho da string.
Caso a solução não utilize pilha, o peso é (1,0).*/

#include <stdio.h>
#include <string.h>

#define tam 50 	//tamanho do vet

typedef struct
{
    int fim;
    char name[tam];
}tipPilha;

void PRINTpilha(char str[])
{
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n");
}

void stack(char str[], tipPilha *pilha)
{
    int i;
    for(i=0; str[i] != '\0'; i++)
    {  
        pilha->name[i] = str[i];
        pilha->fim++; 
    }
}

int comparar(char str[], tipPilha *pilha)
{
    int i;
    int j;
    for(i=0, j=pilha->fim-1; str[i]!='\0' ; i++, j--)
    {
        if(pilha->name[j]==' ')
        { j--;}
        if(str[i]==' ')
        { i++; }

        //printf("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n\n");
        if(pilha->name[j] != str[i])
        { return -1; }
    }
    return 1;
}

int main(void)
{ 
    tipPilha pilha;
    pilha.fim=0;
    
    char str[tam]=("A GRAMA E AMARGA");

    printf("Frase: ");
    PRINTpilha(str);

    stack(&str, &pilha);

    int aux;
    aux = comparar(&str, &pilha);
    if(aux == 1)
    { printf("A frase %c pal%cndroma", 130, 161); }
    else
    { printf("A frase n%co %c pal%cndroma", 198, 130, 161); }

}

