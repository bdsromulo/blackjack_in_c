# 🃏 Blackjack in C (Vinte e Um)

<div align="center">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
  <img src="https://img.shields.io/badge/Estrutura_de_Dados-UTFPR-green?style=for-the-badge" />
</div>

<br>

Projeto para a matéria de **Estruturas de Dados I**, ministrada pelo Professor Minetto (UTFPR), utilizando a linguagem C básica e os mecanismos aprendidos para reproduzir o clássico jogo de **Blackjack (Vinte e Um)** diretamente no terminal.

---

## 🎲 Como Funciona o Jogo

O jogo consiste no saque aleatório de cartas (empilhadas e embaralhadas) que, somadas, devem resultar no valor de **21** ou o mais próximo possível disso. 
As cartas devem ser sacadas estrategicamente para não estourar o limite de 21 pontos (o famoso *Bust*), caso contrário, o jogador perde.

### 🤖 Inteligência e Bots
Junto ao jogador, há **2 bots** programados para realizar jogadas de acordo com as chances estatísticas de fechar em 21 ou obter uma pontuação alta (semelhante às decisões de um jogador humano), com base nas cartas que ainda restam no baralho.

### 📊 Estatísticas em Tempo Real
A cada saque de cartas, o jogo exibe na tela um cálculo matemático de probabilidade para auxiliar na sua decisão (manter a pontuação ou continuar jogando):
- **Chance de Estourar (Bust)**
- **Chance de Pontuação Alta (19 ou 20)**
- **Chance de Blackjack (21 exato)**

---

## 📁 Estrutura do Código

Para manter a organização e a clareza, o projeto foi modularizado em diferentes arquivos:

- `functions.h` e `functions.c`: Contêm as declarações e implementações das operações principais, como atribuir valores às cartas, criar, movimentar e embaralhar pilhas (usando listas encadeadas), além do cálculo matemático de probabilidades.
- `vinte_e_um.c`: Arquivo principal onde ocorre o loop, a organização e a execução do jogo. Inclui os critérios de tomada de decisão dos bots, controle de rodadas, sorteio inicial e definição do ganhador.

---

## 🚀 Como Executar

Para rodar o jogo, você precisará de um compilador de C (como o `gcc`) instalado em sua máquina.

1. Faça o clone do repositório ou baixe os arquivos.
2. Certifique-se de que todos os arquivos (`vinte_e_um.c`, `functions.c` e `functions.h`) estejam na mesma pasta.
3. Abra o terminal na pasta do projeto e compile os arquivos com o comando:
   ```bash
   gcc vinte_e_um.c functions.c -o blackjack
   ```
4. Execute o jogo recém compilado:
   - No Windows: `blackjack.exe` ou `.\blackjack.exe`
   - No Linux/Mac: `./blackjack`

**Divirta-se jogando!**

---

### 👨‍💻 Autor

- **Rômulo Barbosa da Silva**
- RA: 2306409 - CSF20 - UTFPR
