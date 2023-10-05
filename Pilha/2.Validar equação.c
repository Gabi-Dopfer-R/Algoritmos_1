/*2) Utilize uma pilha para verificar se uma equação matemática está balanceada. Exemplos:

{ [ ( a + b ) * c ] - [ d ] }   -> retorna 1

( [ ( a + b ] * c ] - [ d ]      -> retorna -1

Dica: os únicos caracteres que devem resultar em "pushs" e "pops" são { [ ( ) ] }. 
Os demais podem ser "ignorados".*/

#include <stdio.h>
#include <string.h>

#define tam 20 	//tamanho do vet

typedef struct
{
    int fim;
    char elem[tam];
}tipPilha;

void PRINTpilha(char eq[])
{
    int i;
    for(i=0; eq[i]!='\0'; i++)
    {
        printf("%c", eq[i]);
    }
    printf("\n");
}

void stack(char *eq, tipPilha *pilha)
{
    int i;
    for(i=0; eq[i] != '\0'; i++)
    {  
        switch(eq[i])
        {
            case '[':
            case ']':
            case '{':
            case '}':
            case '(':
            case ')':
                pilha->elem[pilha->fim] = eq[i];
                pilha->fim++;
            break;
        }  
    }
}

int validate(tipPilha *pilha)
{
    int i, j;
    
    if(pilha->fim%2 != 0)
    { return -1; }

    for(i=pilha->fim-1; i>0; i--)
    {
        switch(pilha->elem[i])
        {
            case ']':
            case '}':
            case ')':
                for(j=i-1; j>=0; j--)
                {
                    if((pilha->elem[j]=='[' && pilha->elem[i]==']')||(
                        pilha->elem[j]=='{' && pilha->elem[i]=='}')||(
                        pilha->elem[j]=='(' && pilha->elem[i]==')'))
                    { 
                        pilha->fim--; 
                        break;
                    }

                    if(j==0)
                    { return -1; }
                }
            break;
        }
        
    }

    return 1;
    
}

int main(void)
{ 
    tipPilha pilha;
    pilha.fim=0;

    //char eq[tam]=("{[(a+b)*c]-[d]}");
    char eq[tam]=("([(a+b]*c]-[d]");

    printf("Equa%c%co: ", 135,198);
    PRINTpilha(eq);
    
    stack(eq, &pilha);
    int aux = validate(&pilha);

    if(aux == 1)
    {
        printf("A equa%c%co est%c balan%ceada", 135,198,160,135);
    }
    else
    { 
        printf("A equa%c%co n%co est%c balan%ceada", 135,198,198,160,135);
    }

}