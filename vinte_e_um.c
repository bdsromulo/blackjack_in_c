#include "functions.h"

#define N_CARTAS 52

/***RÔMULO BARBOSA DA SILVA - RA: 2306409 - CSF20 - UTFPR***/
/***PROJETO BLACKJACK(VINTE E UM)***/
int main()
{
    int cartas[52];
    int turno[3];

    int v_interaction = 0; int game_over = 0;
    int skip_turn1 = 0; int skip_turn2 = 0; int skip_turn3 = 0;
    int score_player = 0;int score_pc = 0;int score_pc2 = 0;
    int bust_player = 0; int bust_pc = 0; int bust_pc2 = 0;
    int player_win = 0;
    int pc_win = 0;
    int pc_win2 = 0;
    printf("Bem-vindo ao jogo de Vinte e Um!!\n");
    printf("Jogo iniciado\n");
    int i;

    Deck* mesa = createDeck();
    Deck* monte_player = createDeck();
    Deck* monte_pc = createDeck();
    Deck* monte_pc2 = createDeck();
    create_vetor(cartas, N_CARTAS);
    shuffle_vetor(cartas, N_CARTAS);
    mesa = list_insertion(mesa, cartas, N_CARTAS);
    //Sorteio de qual será a ordem de jogo dos jogadores
    create_vetor(turno, 3);
    shuffle_vetor(turno, 3);
    for(i = 0; i < 3; i++)
    {
        if(turno[i] == 0)
        {
            if(bust_pc && bust_pc2)
            {
                game_over = 1;
                player_win = 1;
            }
            else
            {
                delay(1);
                printf("/////Sua vez!!!/////\n");

                monte_player = push_card(mesa, monte_player);
                mesa = pull_card(mesa);

                printf("/////Monte atual://///\n");
                print_deck(monte_player);


                printf("Sua pontuacao:\n");
                score_player = pontos_monte(monte_player);
                printf("%d\n", score_player);

                delay(1);
                printf("Chance de Blackjack:\n");
                printf("%.2f porcento\n", stat_blackjack(mesa, score_player));


                printf("Chance de Bust:\n");
                printf("%0.2f porcento\n", stat_bust(mesa, score_player));


                printf("Chance de High Score (19 ou 20)\n");
                printf("%0.2f porcento\n", stat_highscore(mesa, score_player));
                while(!skip_turn1)
                {
                    printf("/////Insira sua acao: 1 para pedir uma carta, 2 para encerrar pontua�o./////\n");
                    scanf("%d", &v_interaction);
                    if(v_interaction == 1)
                    {
                        monte_player = push_card(mesa, monte_player);
                        mesa = pull_card(mesa);
                        printf("/////Monte atual://///\n");
                        print_deck(monte_player);
                        delay(1);
                        printf("Sua pontuacao:\n");
                        score_player = pontos_monte(monte_player);
                        printf("%d\n", score_player);
                        if(score_player <= 21)
                        {
                            delay(1);
                            printf("Chance de Blackjack:\n");
                            printf("%0.2f porcento\n", stat_blackjack(mesa, score_player));

                            printf("Chance de Bust:\n");
                            printf("%0.2f porcento\n", stat_bust(mesa, score_player));

                            printf("Chance de High Score (19 ou 20)\n");
                            printf("%0.2f porcento\n", stat_highscore(mesa, score_player));
                        }
                        if(score_player > 21)
                        {
                            delay(1);
                            printf("/////Bust! Voce passou de 21!!!/////\n");
                            score_player = 0;
                            skip_turn1 = 1;
                            player_win = 0;
                            bust_player = 1;

                        }
                        else if(score_player == 21)
                        {
                            delay(1);
                            printf("/////Blackjack!! Voce atingiu 21!!/////\n");
                            skip_turn1 = 1;
                            game_over = 1;
                            player_win = 1;
                        }
                    }
                    if(v_interaction == 2)
                    {
                        delay(1);
                        printf("/////Voce escolheu parar/////\n");
                        printf("Sua pontuacao:\n");
                        score_player = pontos_monte(monte_player);
                        printf("%d\n", score_player);
                        skip_turn1 = 1;
                }
            }
            if(game_over)
                break;
            if(skip_turn1)
                continue;
            }
        }
        if(turno[i] == 1)
        {
            if(bust_player && bust_pc2)
            {
                game_over = 1;
                pc_win = 1;
            }
            else
            {
                delay(1);
                printf("/////Vez do computador(1)://///\n");
                monte_pc = push_card(mesa, monte_pc);
                mesa = pull_card(mesa);
                printf("/////Monte atual://///\n");
                print_deck(monte_pc);
                printf("Pontuacao do PC(1):\n");
                score_pc = pontos_monte(monte_pc);
                printf("%d\n", score_pc);
                while(!skip_turn2)
                {
                    if(score_pc == 21)
                    {
                        printf("/////Blackjack!!!O PC(1) atingiu 21!!!/////\n");
                        game_over = 1;
                        skip_turn2 = 1;
                        pc_win = 1;

                    }
                    else if(score_pc > 21)
                    {
                        printf("/////Bust!!!O PC(1) passou de 21!!!/////\n");
                        skip_turn2 = 1;
                        pc_win = 0;
                        score_pc = 0;
                        bust_pc = 1;
                    }
                    else if(score_pc >= 18 && score_pc <=20)
                    {
                        printf("/////PC(1) travou o seu score em %d!!!/////\n", score_pc);
                        skip_turn2 = 1;
                    }
                    else if(stat_blackjack(mesa, score_pc) > 8)
                    {
                        monte_pc = push_card(mesa, monte_pc);
                        mesa = pull_card(mesa);
                        delay(1);
                        printf("/////Monte atual://///\n");
                        print_deck(monte_pc);
                        printf("Pontuacao do PC(1):\n");
                        score_pc = pontos_monte(monte_pc);
                        printf("%d\n", score_pc);
                    }
                    else if(stat_highscore(mesa, score_pc) > 40)
                    {
                        monte_pc = push_card(mesa, monte_pc);
                        mesa = pull_card(mesa);
                        delay(1);
                        printf("/////Monte atual://///\n");
                        print_deck(monte_pc);
                        printf("Pontuacao do PC(1):\n");
                        score_pc = pontos_monte(monte_pc);
                        printf("%d\n", score_pc);
                    }
                    else
                    {
                        monte_pc = push_card(mesa, monte_pc);
                        mesa = pull_card(mesa);
                        delay(1);
                        printf("/////Monte atual://///\n");
                        print_deck(monte_pc);
                        printf("Pontuacao do PC(1):\n");
                        score_pc = pontos_monte(monte_pc);
                        printf("%d\n", score_pc);
                    }
                }
            }
            if(game_over)
                break;
            if(skip_turn2)
                continue;
        }
        if(turno[i] == 2)
        {
            if(bust_pc && bust_pc2)
            {
                game_over = 1;
                pc_win2 = 1;
            }
            else
            {
                delay(1);
                printf("/////Vez do computador(2)://///\n");
                monte_pc2 = push_card(mesa, monte_pc2);
                mesa = pull_card(mesa);
                printf("/////Monte atual://///\n");
                print_deck(monte_pc2);
                delay(1);
                printf("Pontuacao do PC(2):\n");
                score_pc2 = pontos_monte(monte_pc2);
                printf("%d\n", score_pc2);
                while(!skip_turn3)
                {
                    if(score_pc2 == 21)
                    {
                        printf("/////Blackjack!!!O PC(2) atingiu 21!!!/////\n");
                        game_over = 1;
                        skip_turn3 = 1;
                        pc_win2 = 1;
                    }
                    else if(score_pc2 > 21)
                    {
                        printf("/////Bust!!!O PC(2) passou de 21!!!/////\n");
                        skip_turn3 = 1;
                        pc_win2 = 0;
                        score_pc2 = 0;
                        bust_pc2 = 1;
                    }
                    else if(score_pc2 >= 17 && score_pc2 <=20)
                    {
                        skip_turn3 = 1;
                        printf("/////PC(2) travou o seu score em %d/////\n", score_pc2);
                    }
                    else if(stat_blackjack(mesa, score_pc2) > 8)
                    {
                        monte_pc2 = push_card(mesa, monte_pc2);
                        mesa = pull_card(mesa);
                        delay(1);
                        printf("/////Monte atual://///\n");
                        print_deck(monte_pc2);
                        printf("Pontuacao do PC(2):\n");
                        score_pc2 = pontos_monte(monte_pc2);
                        printf("%d\n", score_pc2);
                    }
                    else if(stat_highscore(mesa, score_pc2) > 40)
                    {
                        monte_pc2 = push_card(mesa, monte_pc2);
                        mesa = pull_card(mesa);
                        delay(1);
                        printf("/////Monte atual://///\n");
                        print_deck(monte_pc2);
                        printf("Pontuacao do PC(2):\n");
                        score_pc2 = pontos_monte(monte_pc2);
                        printf("%d\n", score_pc2);
                    }
                    else
                    {
                        monte_pc2 = push_card(mesa, monte_pc2);
                        mesa = pull_card(mesa);
                        delay(1);
                        printf("/////Monte atual://///\n");
                        print_deck(monte_pc2);
                        printf("Pontuacao do PC(2):\n");
                        score_pc2 = pontos_monte(monte_pc2);
                        printf("%d\n", score_pc2);
                    }
                }
            }
            if(game_over)
                break;
            if(skip_turn3)
                continue;
        }
    }
    if(player_win)
        printf("Parabens, voce venceu!!!\n");
    else if(pc_win)
        printf("Que pena, voce perdeu. O PC(1) venceu. Mais sorte da proxima!!!\n");
    else if(pc_win2)
        printf("Que pena, voce perdeu. O PC(2) venceu. Mais sorte da proxima!!!\n");
    else if(pc_win == 0 && player_win == 0 && pc_win2 == 0)
    {
        if(score_pc > score_player && score_pc > score_pc2)
            printf("Que pena, voce perdeu. O PC(1) venceu por score. Mais sorte da proxima!!!\n");
        else if(score_player > score_pc && score_player > score_pc2)
            printf("Parabens, voce venceu por score!!!\n");
        else if(score_pc2 > score_player && score_pc2 > score_pc)
            printf("Que pena, voce perdeu. O PC(2) venceu por score. Mais sorte da proxima!!!\n");
        else if(score_pc == score_player && score_pc > score_pc2)
            printf("Uau, isso e raro, mas voce empatou com o PC(1)\n");
        else if(score_pc2 == score_player && score_pc2 > score_pc)
            printf("Uau, isso e raro, mas voce empatou com o PC(2)\n");
        else if(score_pc2 == score_pc && score_pc2 > score_player)
            printf("Uau, isso e raro, mas os 2 PCs empataram\n");
        else if(score_pc2 == score_pc && score_pc2 == score_player)
            printf("Uau, isso e extremamente raro, mas os 3 empataram\n");
        else
            printf("Caso nao observado");
    }
    free(mesa);
    free(monte_player);
    free(monte_pc);
    free(monte_pc2);
    return 0;
}
