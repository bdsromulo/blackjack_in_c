#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


/***RÔMULO BARBOSA DA SILVA - RA: 2306409 - CSF20 - UTFPR***/
/***PROJETO BLACKJACK(VINTE E UM)***/
//Naipes e N�meros:
//Copas, Espadas, Ouros e Paus
//Valora�es:
//1 a 12
//Cartas e Valores no Deck: 52 (total)
//A(Valor 1),2,3,4,5,6,7,8,9 - 4 cartas cada (36 total)
//10,J (Valor 10) - 4 cartas cada (8 total)
//Q (Valor 11), K(Valor 12) - 4 cartas cada(8 total)




typedef struct deck {
  int valor;
  struct deck *prox;
  struct deck *ant;
} Deck;

//Criar um montinho de cartas
Deck* createDeck ();

//Inserir carta em cima do montinho
Deck* insert_front(Deck* monte, int c);

//Troca 2 variáveis de valor
void troca(int *a, int *b);

//Monta e embaralha o monte de cartas inicial da mesa
void create_vetor(int *vetor, int n_elementos);

void shuffle_vetor(int vetor[], int n_cartas);

Deck* list_insertion(Deck* monte, int *vetor, int n_elements);

//Retira a carta de onde ela foi sacada
Deck* pull_card(Deck* mesa);

//Insere a carta em um monte do jogador
Deck* push_card(Deck* mesa, Deck* monte);

//Realiza o pull e push por completo
void draw_card(Deck* mesa, Deck* monte);

//Mostra as cartas no monte do jogador até então
Deck* show_cards(Deck* monte);

//Mostra a pontua�o do jogador em rel�o ao 21
Deck* show_score(Deck* monte);

//Chance de se atingir um blackjack na pr�xima jogada
Deck* calc_blackjack(Deck* monte);

//Chance de estourar a conta de 21 na pr�xima jogada
Deck* calc_bust(Deck* monte);

//Chance de se atingir uma pontua�o alta
Deck* calc_highscore(Deck* monte);

//Fun�o de teste pra imprimir vetores e listas
void print_array (int vetor[], int n);

//Retorna quantos pontos o monte do jogador j� acumulou
int pontos_monte(Deck* monte);

//Retorna o simbolo da carta (de A at� K)
char* return_simbolo(int valor);

//Retorna qual o naipe da carta
char* return_naipe(int valor);

//Imprime a lista ligada de cartas
void print_deck(Deck* mesa);

//Calcula chance de Blackjack em um próximo saque de cartas
double stat_blackjack(Deck* mesa, int pontos);

//Calcula chance de Bust(estouro do 21)em um próximo saque de cartas
double stat_bust(Deck* mesa, int pontos);

//Calcula chance de se obter valor de 19 ou 20 em um próximo saque de cartas
double stat_highscore(Deck* mesa, int pontos);
//Cria uma pequena margem de tempo entre ações para não sobrecarregar a leitura do usuário no terminal
void delay(int time);
