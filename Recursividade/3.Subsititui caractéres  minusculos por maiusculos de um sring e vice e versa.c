/*3. Implemente uma função recursiva que recebe uma string e 
substitui as letras minúsculas por maiúsculas e vice-versa.*/

#include <stdio.h>

void PRINTcaracteresSTRING(int i, char string[])
{
    if(string[i] != '\0')
    {
        if(string[i] >= 65 && string[i] <= 90)
        {
            string[i] = (int) string[i] + 32;
        }
        else if(string[i] >= 97 && string[i] <= 122)
        {
            string[i] = (int) string[i] - 32;
        }

        printf("%c", string[i]);
        PRINTcaracteresSTRING(i+1, string);
    } 
}

int main (void)
{
    char string[25]="cove FLOR com JABUTICABA";
    
    PRINTcaracteresSTRING(0, string);

    return 0;
}