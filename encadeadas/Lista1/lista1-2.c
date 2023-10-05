/*2) Joãozinho e Juquinha gostam muito de jogar bafo. Para quem não sabe, este jogo inicia
com uma pilha de figurinhas. A cada jogada, um dos jogadores terá a chance de bater na
pilha, tentando virar algumas figurinhas. As que forem viradas passam a pertencer a este
jogador.
Joãozinho tem uma técnica apurada, que às vezes é capaz de virar 4 figurinhas com uma só
jogada. Entretanto, quando esta técnica falha, nenhuma se vira.
Já a técnica de Juquinha garantidamente vira sempre no mínimo 1 figurinha, mas no máximo
2.
Simule computacionalmente partidas entre Joãozinho e Juquinha, iniciando com 20
figurinhas na pilha e Joãozinho como 1º jogador. Se a técnica dos 2 funcionar ao máximo em
todas jogadas, quantas jogadas serão no total? Imprima quantas figuras terá Joãozinho e
quantas terá Juquinha. E no caso das técnicas de ambas falharem em todas as jogadas?
Imprima também.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <time.h>
#include <math.h>

typedef struct tipNo
{
    int id;
    char nome[10];
    struct tipNo *ant;
}tipNo;

typedef struct
{
    int quant;
    tipNo *fim;
}tipPilha; 

void PRINTresult (tipPilha *joao, tipPilha *juca, int jogadas)
{
    printf("=================== Resultado ==================\n");
    printf("Quantidade de jogadas: %d\n", jogadas);
    printf("Figurinhas do Juquinha: %d\n", juca->quant);
    printf("Figurinhas do Jo%cozinho: %d\n", 198, joao->quant);
}

tipPilha* CriarPilha()
{
    tipPilha *pilha = (tipPilha*) malloc(sizeof(tipPilha));
    pilha->quant = 0;
    pilha->fim = NULL;
    return pilha;
}

tipNo* CriarNo (int pos)
{
    tipNo *no = (tipNo*) malloc(sizeof(tipNo));

    no->id = pos;
    no->nome[0] = (char)(rand()% 26 + 97);
    no->nome[1] = '\0';
    no->ant = NULL;
    return no;
}

LimparPilha(tipPilha *pilha)
{
    while(pilha->quant != 0)
    { Desempilhar(pilha);}
}

void Empilhar(tipNo *no, tipPilha *pilha)
{
    if(pilha->quant!=0)
    { no->ant = pilha->fim; }

    pilha->fim = no;
    pilha->quant++;
}

void Desempilhar(tipPilha *pilha)
{
    tipNo *aux = pilha->fim;
    pilha->fim = pilha->fim->ant;
    free(aux);
    pilha->quant--;
}

int Simular(tipPilha *pilha, int prob, tipPilha *joao, tipPilha *juca)
{
    int jogadas =0;
    int play1, play2;
    if(prob){   
        play1 = 4;
        play2 = 2;  
    }else{
        play1 = 0;
        play2 = 1;  
    }

    int i;
    int player = 1;
    while (pilha->quant != 0){
        if(player == 1)
        {
            for(i=0; i<play1 && pilha->quant!=0; i++)
            {
                Empilhar(pilha->fim, joao);  
                Desempilhar(pilha);   
            }
            player=2;
        }else{
            for(i=0; i<play2 && pilha->quant!=0; i++)
            {   
                Empilhar(pilha->fim, juca);
                Desempilhar(pilha);
            }
            player=1;
        }
        jogadas++;
    }
    jogadas = (ceil)((float)jogadas/2);
    return jogadas;
}

int main(void)
{
    printf("Criar pilha:\n");
    tipPilha *pilha = CriarPilha();
    
    if(pilha == NULL)
    { printf("Sem espa%co para pilha.\n", 135); }
    else
    { printf("Pilha criada com sucesso.\n"); }

    //inserir valores na pilha......
    srand(time(NULL));
    int i;
    for(i=0; i<20; i++)
    {
        tipNo *no = CriarNo(i);
        Empilhar(no, pilha);
    }

    //inserir jogadores........
    tipPilha *joao = CriarPilha();
    tipPilha *juca = CriarPilha();
    int jogadas;

    //se os pontos forem mínimos....
    printf("\nPontos min. por jogadas:\n");
    jogadas = Simular(pilha, 0, joao, juca);
    PRINTresult(joao, juca, jogadas);

    //limpar lixo de memória e repor pilha.....
    LimparPilha(joao);
    LimparPilha(juca);
    for(i=0; i<20; i++)
    {
        tipNo *no= CriarNo(i);
        Empilhar(no, pilha); 
    }

    //se os pontos forem máximos....
    printf("\nPontos max. por jogadas:\n");
    jogadas = Simular(pilha, 1, joao, juca);
    PRINTresult(joao, juca, jogadas);
}