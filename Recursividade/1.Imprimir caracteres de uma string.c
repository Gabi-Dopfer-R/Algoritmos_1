/*1. Faça uma função recursiva que receba uma 
string e imprima todos os seus caracteres.*/

#include <stdio.h>

void PRINTcaracteresSTRING(int i, char string[])
{
    if(string[i] != '\0')
    {
        printf("%c", string[i]);

        return(PRINTcaracteresSTRING(i+1, string));
    } 
}

int main (void)
{
    char string[25]="cove flor com jabuticaba";
    
    PRINTcaracteresSTRING(0, string);

    return 0;
}