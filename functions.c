#include "functions.h"

#define CARTAS 52

/***RÔMULO BARBOSA DA SILVA - RA: 2306409 - CSF20 - UTFPR***/
/***PROJETO BLACKJACK(VINTE E UM)***/

Deck* createDeck()
{
    return NULL;
}
Deck* insert_front(Deck *monte, int c)//Insercao pela frente do baralho
{
    Deck* novo = (Deck*)malloc(sizeof(Deck));
    novo->valor = c;
    novo->prox = monte;
    novo->ant = NULL;

    if(monte == NULL)
    {
        monte = novo;
    }
    return novo;
}
//Funcao que embaralha e insere cartas na lista ligada, o deck de cartas da mesa
//Algoritmo de Embaralhamento Fisher-Yates (ou o mais próximo que eu consegui dele)
void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}
//Gera o vetor preenchido de inteiros para necessidades de embaralhamento
void create_vetor(int *vetor, int n_elementos)
{
    int i;
    for(i = 0; i < n_elementos; i++)
        vetor[i] = i;
}
void shuffle_vetor(int vetor[], int n_cartas)
{
    int i,j;
    srand(time(NULL));
    for(i = n_cartas - 1; i > 0;i--)
    {
        j = rand() % (i+1);
        troca(&vetor[i], &vetor[j]);
    }
}
Deck* list_insertion(Deck* monte, int *vetor, int n_elements)
{
    int i;
    for(i = 0; i < n_elements; i++)
    {
        monte = insert_front(monte, vetor[i]);
    }

    return monte;
}
void print_deck(Deck* mesa)
{
    int i;
    for(i = 0;mesa != NULL; i++)
    {
        if(mesa->prox == NULL)
            delay(1);
        printf("%s de %s\n", return_simbolo(mesa->valor), return_naipe(mesa->valor));
        mesa = mesa->prox;
    }
}
Deck* pull_card(Deck* mesa)
{
    Deck* prox = (Deck*)malloc(sizeof(Deck));
    prox = mesa->prox;
    return prox;
}
Deck* push_card(Deck* mesa, Deck* monte)
{
    int card = mesa->valor;
    monte = insert_front(monte, card);
    mesa = pull_card(mesa);
    return monte;
}

void print_array (int vetor[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

char* return_simbolo(int valor)
{
    char *simbolos[] = {"A","2", "3", "4", "5", "6", "7", "8", "9","10", "J", "Q", "K"};
    char* simbolo = simbolos[valor/4];
    return simbolo;
}
char* return_naipe(int valor)
{
    char *naipes[] = {"ouros","espadas","copas","paus"};
    char *naipe = naipes[valor%4];
    return naipe;
}
int return_valor(int carta)
{
    int valores[] = {1,2,3,4,5,6,7,8,9,10,10,11,12};
    int valor = valores[carta/4];
    return valor;
}
int pontos_monte(Deck* monte)
{
    int i; int soma = 0;
    for(i = 0;monte != NULL; i++)
    {
        soma += return_valor(monte->valor);
        monte = monte->prox;
    }
    return soma;
}
double stat_blackjack(Deck* mesa, int pontos)
{
    int carta_chave = 21 - pontos;
    double i;
    double blackjack_stat = 0;
    double q_cartas_chave = 0;
    for(i = 0; mesa != NULL; i++)
    {
        if(return_valor(mesa->valor) == carta_chave)
            q_cartas_chave++;
        mesa = mesa->prox;
    }
    //i realiza a contagem total de cartas e serve para tirar a propor�o e an�lise estat�stica
    blackjack_stat = q_cartas_chave/i*100;
    return blackjack_stat;
}
double stat_bust(Deck* mesa, int pontos)
{
    int carta_chave = 21 - pontos;
    double i;
    double bust_stat = 0;
    double q_cartas_acima = 0;
    for(i = 0; mesa != NULL; i++)
    {
        if(return_valor(mesa->valor) > carta_chave)
            q_cartas_acima++;
        mesa = mesa->prox;
    }
    //i realiza a contagem total de cartas e serve para tirar a propor�o e an�lise estat�stica
    bust_stat = q_cartas_acima/i*100;
    return bust_stat;
}
double stat_highscore(Deck* mesa, int pontos)
{
    int carta_chave = 21 - pontos;
    double i;
    double high_stat = 0;
    double q_cartas_boas = 0;
    if(pontos < 19)
    {
        for(i = 0; mesa != NULL; i++)
        {
            if(return_valor(mesa->valor) < carta_chave && return_valor(mesa->valor) > carta_chave - 2)
                q_cartas_boas++;
            mesa = mesa->prox;
        }
        //i realiza a contagem total de cartas e serve para tirar a propor�o e an�lise estat�stica
        high_stat = q_cartas_boas/i*100;
        return high_stat;
    }
    else
    {
        high_stat = 100;
        return high_stat;
    }

}
void delay(int time)
{
    int i;
    for(i = time; i > 0; i--)
        sleep(1);

}
