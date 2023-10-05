#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>

typedef struct Tipcel
{
    int col;
    int lin;
    float num;
    struct Tipcel *lado;
    struct Tipcel *baixo;
}Tipcel;

typedef struct 
{
    Tipcel *linha;
    Tipcel *coluna;
    int Nlin;
    int Ncol;
}MatEsp;

Tipcel* criarCel(float val, int l, int c)
{
    Tipcel *cel = (Tipcel*)malloc(sizeof(Tipcel));
    cel->col = c;
    cel->lin = l;
    cel->lado =  NULL;
    cel->baixo = NULL;
    cel->num = val;
}

MatEsp* criarMatriz(int l, int c)
{
    printf("\n\n====== Criando matriz... =======\n");
    printf("Dimens%co: %dx%d\n", 198,l,c);
    MatEsp *mat = (MatEsp*)malloc(sizeof(MatEsp));
    mat->Nlin = l;
    mat->Ncol = c;
    mat->linha = criarCel(0,0,0);//celula matriz (0,0) 
    mat->coluna = mat->linha;//celula matriz (0,0)

    //criar colunas e linhas
    int i;
    Tipcel *linhas = mat->linha;
    Tipcel *colunas = mat->coluna;
    for(i=1; i<=l || i<=c; i++){ 
        //linhas (l,0)
        if(i <= l){ 
            linhas->baixo = criarCel(0,i,0);
            linhas = linhas->baixo;
            linhas->lado = linhas;
        }
        //colunas (0,c)
        if(i <= c){
            colunas->lado = criarCel(0,0,i);
            colunas = colunas->lado;
            colunas->baixo = colunas;
        }
    }
    linhas->baixo = mat->linha;
    colunas->lado = mat->coluna;
    
    printf("Matriz criada com sucesso!\n");
    return mat;
}

void Respostas(int aux)
{
    if(aux == 1)
    { printf("\nSucesso!!\n"); }
    else if(aux == 0)
    { printf("\nPosi%c%co n%co existe.\n", 135,198,198); }
    else if (aux == -1)
    { printf("\nPosi%c%co j%c ocupada.\n", 135,198,160); }
}

void Imprimir(MatEsp *mat)
{
    printf("\n======== Matriz =======\n");

    Tipcel *aux = mat->linha->baixo;
    while (aux->lin != 0){
        aux = aux->lado;
        int i=1;
        while (i <= mat->Ncol){ 
            if(aux->col != i)
            { printf("0\t"); }
            else{
               printf("%.2f\t", aux->num); 
               aux = aux->lado;   
            }
            i++;
        }
        printf("\n");
        aux = aux->baixo;
    }
}

void ImprimirCel (int lin, int col, MatEsp *mat)
{
    printf("\n=========== Imprimir c%clula pos:%dx%d =========", 130,lin,col);
    //posição não existe....
    if(lin > mat->Nlin || col > mat->Ncol){ 
        Respostas(0);
        return;
    }

    Tipcel *aux = mat->linha;
    //percorrer até linha...
    while(aux->lin != lin)
    { aux = aux->baixo; }

    //percorrer até coluna.....
    aux = aux->lado;
    while (aux->col != col){
        //col ou lin vazia....
        if(aux->col == 0){ 
            printf("\n0\n");
            return;
        }
        aux = aux->lado;
    }   
    printf("\n%.2f", aux->num);
}

void excluirMatriz (MatEsp *mat)
{ free(mat); }

int Inserir (Tipcel *cel, MatEsp *mat)
{  
    printf("\nPos: %dx%d", cel->lin,cel->col); 
    //posição não existe....
    if(cel->lin > mat->Nlin || cel->col > mat->Ncol)
    { return 0; }

    Tipcel *l = mat->linha;
    Tipcel *c = mat->coluna;
    //percorrer até linha/coluna da célula....
    while(l->lin != cel->lin || c->col != cel->col){
        if(c->col != cel->col)
        { c = c->lado; }
        if(l->lin != cel->lin)
        { l = l->baixo; } 
    }
    //procurar célula anterior na linha/
    int cont=0;
    while (cont != 5){
        //célula ja ocupada.....
        if(l->col == cel->col || c->lin == cel->lin)
        { return - 1; }
        //inserir entre (linha)....
        if(l->lado->col == 0 || l->lado->col > cel->col){
            cel->lado = l->lado;
            l->lado = cel;
            cont += 2;
        }
        //inserir entre (coluna).....
        if(c->baixo->lin == 0 || c->baixo->lin > cel->lin){
            cel->baixo = c->baixo;
            c->baixo = cel;
            cont += 3;
        }

        if(cont != 2)
        { l = l->lado; }
        if(cont != 3)
        { c = c->baixo; }
    }
    return 1;
}

int Remover(MatEsp *mat, int linha, int coluna)
{
    //posição não existe....
    if(linha > mat->Nlin || coluna > mat->Ncol)
    { return 0; }

    Tipcel *l = mat->linha;
    Tipcel *c = mat->coluna;
    //percorrer até linha/coluna da célula....
    while(l->lin != linha || c->col != coluna){
        if(c->col != coluna)
        { c = c->lado; }
        if(l->lin != linha)
        { l = l->baixo; } 
    }
    //procurar célula anterior na linha/coluna
    while (l->lado->col != coluna || c->baixo->lin != linha){
        //se col ou linha da celula vazia retorna erro....
        if(l->lado->col == 0 || c->baixo->lin == 0){
            return -1;
        }
        if(l->lado->col != coluna)
        { l = l->lado; }
        if(c->baixo->lin != linha)
        { c = c->baixo; }
    }
    Tipcel *aux = l->lado;
    l->lado = l->lado->lado;
    c->baixo = c->baixo->baixo;
    free(aux);
    return 1;
}

MatEsp* Somar(MatEsp *mat1, MatEsp *mat2) 
{
    //matrizes de ordem diferentes....
    if(mat1->Ncol != mat2->Ncol || mat1->Nlin != mat2->Nlin)
    { return NULL; }
    
    //gerar matrix resposta....
    MatEsp *resp = criarMatriz(mat1->Nlin, mat1->Ncol);//criar matriz
    Tipcel *l = mat1->linha->baixo;//percorrre linha matriz 1
    Tipcel *l2 = mat2->linha->baixo;//percorre linha matriz 2
    Tipcel *lr = resp->linha->baixo;//percorre linha resposta
    Tipcel *cr = resp->coluna->lado;//percorre coluna resposta
    Tipcel *cel; //celulas novas para matriz resposta
    
    while (lr->lin != 0){
        l = l->lado;
        l2 = l2->lado;
        while (l->col!=0 || l2->col != 0){ 
            cel = criarCel(1,1,1);
            if((l->col < l2->col && l->col !=0)||l2->col==0){ 
                *cel = *l;
                l = l->lado;
            }    
            else if((l->col >= l2->col && l2->col !=0)||l->col==0){ 
                *cel = *l2;
                if(l->col == l2->col){
                    cel->num += l->num;
                    l = l->lado; 
                }
                l2 = l2->lado;  
            }
            cel->lado = lr->lado;
            lr->lado = cel;
            lr = lr->lado;

            //achar col
            while(cr->col != cel->col)
            { cr = cr->lado; }
            //achar linha
            while(cr->baixo->lin < cel->lin && cr->baixo->lin !=0)
            { cr = cr->baixo; }
            cel->baixo = cr->baixo;
            cr->baixo = cel;
            //volta a linha 0
            while(cr->lin != 0)
            { cr = cr->baixo; }
        }
        l = l->baixo;
        l2 = l2->baixo;
        lr = lr->lado->baixo;
    }
    return resp;
}

MatEsp* Subtrair(MatEsp *mat1, MatEsp *mat2) 
{
    //matrizes de ordem diferentes....
    if(mat1->Ncol != mat2->Ncol || mat1->Nlin != mat2->Nlin)
    { return NULL; }
    
    //gerar matrix resposta....
    MatEsp *resp = criarMatriz(mat1->Nlin, mat1->Ncol);//criar matriz
    Tipcel *l = mat1->linha->baixo;//percorrre linha matriz 1
    Tipcel *l2 = mat2->linha->baixo;//percorre linha matriz 2
    Tipcel *lr = resp->linha->baixo;//percorre linha resposta
    Tipcel *cr = resp->coluna->lado;//percorre coluna resposta
    Tipcel *cel; //celulas novas para matriz resposta
    
    while (lr->lin != 0){
        l = l->lado;
        l2 = l2->lado;
        while (l->col!=0 || l2->col != 0){ 
            cel = criarCel(1,1,1);
            if((l->col <= l2->col && l->col !=0)||l2->col==0){ 
                *cel = *l;
                if(l->col == l2->col){
                    cel->num -= l2->num;
                    l2 = l2->lado; 
                }
                l = l->lado;
            }    
            else if((l->col > l2->col && l2->col !=0)||l->col==0){ 
                *cel = *l2;
                cel->num *= (-1);
                l2 = l2->lado;  
            }
            cel->lado = lr->lado;
            lr->lado = cel;
            lr = lr->lado;

            //achar col
            while(cr->col != cel->col)
            { cr = cr->lado; }
            //achar linha
            while(cr->baixo->lin < cel->lin && cr->baixo->lin !=0)
            { cr = cr->baixo; }
            cel->baixo = cr->baixo;
            cr->baixo = cel;
            //volta a linha 0
            while(cr->lin != 0)
            { cr = cr->baixo; }
        }
        l = l->baixo;
        l2 = l2->baixo;
        lr = lr->lado->baixo;
    }
    return resp;
}

MatEsp* Multiplicar(MatEsp *mat, MatEsp *mat2)
{
    if(mat->Ncol!=mat2->Nlin)
    { return NULL; }

    MatEsp *resp = criarMatriz(mat->Nlin, mat2->Ncol);//criar matriz
    Tipcel *l = mat->linha->baixo;//linhas da primeira
    Tipcel *c = mat2->coluna;//colunas da segunda
    Tipcel *r = resp->linha->baixo;
    Tipcel *cel;
    //determinar linha de mat.....
    while(r->lin != 0){
        c = c->lado;
        //determinar coluna de mat2.....
        while(c->col != 0){
            //percorrer multiplicando....
            c = c->baixo;
            l = l->lado;
            cel = criarCel(0, l->lin,c->col); 
            while(c->lin!=0 || l->col!=0){
                if(c->lin == l->col){ 
                    cel->num +=  (c->num * l->num); 
                    c = c->baixo;
                    l = l->lado;
                }
                else if((c->lin < l->col && c->lin!=0)||l->col==0)
                { c = c->baixo; }
                else if((c->lin > l->col && l->col!=0)||c->lin==0)
                { l = l->lado; }
            }
            if(cel->num == 0)
            { free(cel);}
            else{
                cel->lado = r->lado;
                r->lado = cel;
                r = r->lado;
            }
            c = c->lado;
        }
        r = r->lado->baixo;
        l = l->baixo;
    }
    return resp;
}

void CelulasTeste(MatEsp *mat)
{
    Tipcel *cel;
    int aux;

    //sucesso...
    printf("\nInserir: ");
    cel = criarCel(8,1,3);
    aux = Inserir(cel, mat);
    Respostas(aux);
    //erro maior que matriz....
    printf("\nInserir: ");
    cel = criarCel(1.2,6,3);
    aux = Inserir(cel, mat);
    Respostas(aux);
    //sucesso....
    printf("\nInserir: ");
    cel = criarCel(5.1,4,1);
    aux = Inserir(cel, mat);
    Respostas(aux);
    //erro ja tem na matriz....
    printf("\nInserir: ");
    cel = criarCel(7.6,4,1);
    aux = Inserir(cel, mat);
    Respostas(aux);
    //sucesso....
    printf("\nInserir: ");
    cel = criarCel(7.6,1,4);
    aux = Inserir(cel, mat);
    Respostas(aux);
    //sucesso
    printf("\nInserir: ");
    cel = criarCel(6,3,3);
    aux = Inserir(cel, mat);
    Respostas(aux);

    //aux = Remover(mat, 1,3); 

    //sucesso
    printf("\nInserir: ");
    cel = criarCel(1,4,4);
    aux = Inserir(cel, mat);
    Respostas(aux);

}

void CelulasTeste2(MatEsp *mat2)
{
    Tipcel *cel;
    int aux;

    //inserir 3 células....
    printf("\nInserir: ");
    cel = criarCel(2,1,4);
    aux = Inserir(cel, mat2);
    Respostas(aux);

    printf("\nInserir: ");
    cel = criarCel(3,3,3);
    aux = Inserir(cel, mat2);
    Respostas(aux);

    /*printf("\nInserir: ");
    cel = criarCel(3,2,3);
    aux = Inserir(cel, mat2);
    Respostas(aux);*/

    //sucesso
    printf("\nInserir: ");
    cel = criarCel(1,4,4);
    aux = Inserir(cel, mat2);
    Respostas(aux);
}

int main (void)
{
    MatEsp *mat = criarMatriz(4,4);
    //inserir celulas...
    CelulasTeste(mat);
    Imprimir(mat);

    //imprimir células de mat....
    ImprimirCel(1,7, mat);
    ImprimirCel(1,2, mat);
    ImprimirCel(4,1, mat);
    
    //criar uma segunda matriz...
    MatEsp *mat2 = criarMatriz(4,4);
    //inserir 3 células....
    CelulasTeste2(mat2);
    Imprimir(mat2);

    //somar as duas matrizes.....
    printf("\n\n===== SOMAR DUAS MATRIZES ======");
    MatEsp *soma =  Somar(mat, mat2);
    Imprimir(mat);
    Imprimir(mat2);
    if(soma == NULL){ 
        printf("\nErro!! Matrizes de ordem diferente.\n"); 
        excluirMatriz(soma);
    }
    else
    { Imprimir(soma); }
    
    //subtrair as duas matrizes.....
    printf("\n\n==== SUBTRAIR DUAS MATRIZES =====");
    MatEsp *sub =  Subtrair(mat, mat2);
    Imprimir(mat);
    Imprimir(mat2);
    if(sub == NULL){ 
        printf("\nErro!! Matrizes de ordem diferente.\n");
        excluirMatriz(sub);
    }
    else
    { Imprimir(sub); }

    //multiplicar as duas matrizes.....
    printf("\n\n==== MULTIPLICAR DUAS MATRIZES =====");
    MatEsp *mult =  Multiplicar(mat, mat2);
    Imprimir(mat);
    Imprimir(mat2);
    if(mult == NULL){ 
        printf("\nOrdem das matrixes n%co satisfaz a regra.\n",198); 
        excluirMatriz(mult);    
    }
    else
    { Imprimir(mult); }

    //multiplicar as duas matrizes.....
    printf("\n\n==== MULTIPLICAR DUAS MATRIZES =====");
    MatEsp *mult2 =  Multiplicar(mat2, mat);
    Imprimir(mat2);
    Imprimir(mat);
    if(mult2 == NULL){ 
        printf("\nOrdem das matrixes n%co satisfaz a regra.\n",198);
        excluirMatriz(mult2); 
    }
    else
    { Imprimir(mult2); }
}
