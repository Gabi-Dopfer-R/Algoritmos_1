/*2. Faça uma função recursiva que receba uma string e imprima 
todos os seus caracteres em ordem inversa (do final para o começo).*/

#include <stdio.h>

void PRINTcaracteresSTRING(int i, char string[])
{
    if(string[i] != '\0')
    {
        PRINTcaracteresSTRING(i+1, string);
        
        printf("%c", string[i]);
    } 
}

int main (void)
{
    char string[25]="cove flor com jabuticaba";
    
    PRINTcaracteresSTRING(0, string);

    return 0;
}