# blackjack_in_c

PT:

Projeto para a matéria de Estruturas de Dados I,do Professor Minetto, utilizando a linguagem C básica e mecanismos da matéria para reproduzir o jogo de Blackjack (Vinte e Um) em terminal. O jogo consiste no saque aleatório de cartas, empilhadas e embaralhadas, que somadas, têm que resultar no valor de 21 ou próximo. As cartas tem que ser estrategicamente sacadas de maneira a não estourar o teto de 21 pontos, senão o jogador perde. No display das cartas já sacadas, há um cálculo de probabilidade de saque para estourar, resultar em pontuação alta ou resultar em Blackjack, para que assim o player possa decidir se quer manter travar a pontuação ou continuar jogando. Junto ao jogador, há 2 bots programados para realizar jogadas de acordo com as chances estatísticas para fechar em 21 ou com pontuação alta, similar ao do jogador, de acordo com as cartas que ainda restam no bolo.

O arquivo é dividido entre os arquivos de funções "functions.h" e "functions.c" e o arquivo de jogo. As funções são declaradas no intuito de realizar as operações de atribuir valores às cartas, movimentar e embaralhar pilhas, embaralhamento. cálculo de probabilidades e suboperações necessárias para as citadas anteriormente. No arquivo "vinte_e_um.c", é onde se dá a organização e execução do jogo, incluindo critérios de probabilidade para execução dos bots, definição de ganhador esorteio de início e de cartas.

Para execução do jogo, tendo todos os arquivos na mesma pasta, basta executar o script em vinte_e_um.c, e divirta-se
