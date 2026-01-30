#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "jogatina.h"

// Tamanho do tabuleiro
#define T 3

// --- Protótipos das funções internas (static para encapsulamento) ---
static void printarJogo(char (*m)[T][T]); //desenha o tabuleiro
static void preencherJogo(char (*m)[T][T]); //reseta o estado do tabuleiro para o inicial
static void melhorJogada(char (*m)[T][T], int *linha, int *coluna); //usa o algoritmo minimaxab para tomar a melhor decisC#o
static int statusJogo(char (*m)[T][T], char key); //avalia se o ha uma vitória do primeiro jogador ou do segundo
static int fazerJogada(char (*m)[T][T], char key, int linha, int coluna); //realiza as jogadas alterando a matriz original
static int validarJogada(char (*m)[T][T], int linha, int coluna); //valida as jogadas do jogador humano
static int minimaxab(char (*m)[T][T], int eoMax, int profundidadeArvore, int alfa, int beta); //avalia o estado do tabuleiro em condições favoraveis, desfavoraveis e neutras para o computador
static int tabuleiroCheio(char (*m)[T][T]); //verifica se o tabuleiro está completamente preenchido

// Vetor global para armazenar os símbolos (Tokens)
// tokens[0] = Humano, tokens[1] = Computador
char tokens[2] = {'X', 'O'};

void iniciar_jogo(char (*m)[T][T]) {
	setlocale(LC_ALL, "pt-br");
	srand(time(NULL)); // Semente para aleatoriedade (se fosse usada)

	int vitoria = 0, turno, contadorJogo = 0, linhaCOM, colunaCOM, linha, coluna;

	preencherJogo(m); // Limpa o tabuleiro

	printf("Quem comeC'a a partida? 1- Humano, 2- Computador\n> ");
	scanf("%d", &turno);
	// Validação simples: se for par (2), é PC. Senão Humano (1).
	turno = (turno % 2 == 0) ? 2 : 1;

	printarJogo(m);

	// Loop principal da partida
	while(vitoria != 1) {
		// 1. Verifica condições de fim de jogo
		if(statusJogo(m, tokens[0]) == 1) {
			printf("\nO jogador venceu! (Isso não deveria acontecer...)\n");
			vitoria = 1;
		} else if(statusJogo(m, tokens[1]) == 1) {
			printf("\nO computador venceu!\n");
			vitoria = 1;
		} else if(tabuleiroCheio(m) == 1) {
			printf("\nEmpate!\n");
			vitoria = 1;
		}

		if(vitoria == 1) break;

		// 2. Turno do Jogador Humano
		if(turno == 1) {
			printf("\nTurno do Jogador (%c):\n", tokens[0]);
			printf("Digite a linha e coluna (ex: 1 1 para o centro): ");
			scanf("%d %d", &linha, &coluna);

			// Ajusta para índices de matriz (0 a 2)
			linha--;
			coluna--;

			if(validarJogada(m, linha, coluna) == 1) {
				fazerJogada(m, tokens[0], linha, coluna);
				turno = 2; // Passa a vez
				contadorJogo++;
				printarJogo(m);
			} else {
				printf("Jogada invalida (posicao ocupada ou fora do tabuleiro)!\n");
			}
		}

		// 3. Turno do Computador
		else if(turno == 2) {
			printf("\nTurno do Computador (%c):\n", tokens[1]);
			printf("Pensando...\n");
			melhorJogada(m, &linhaCOM, &colunaCOM); // IA decide
			fazerJogada(m, tokens[1], linhaCOM, colunaCOM);
			turno = 1; // Passa a vez
			printarJogo(m);
		}
	}
}

// Função para o Grupo 3: Alterar os símbolos globais
void setTokens(char newTokens[2]) {
	tokens[0] = newTokens[0];
	tokens[1] = newTokens[1];
}

// Verifica se 'key' (X ou O) ganhou
static int statusJogo(char (*m)[T][T], char key) {
	// Linhas e Colunas
	for(int i = 0; i < T; i++) {
		if((*m)[i][0] == key && (*m)[i][1] == key && (*m)[i][2] == key) return 1;
		if((*m)[0][i] == key && (*m)[1][i] == key && (*m)[2][i] == key) return 1;
	}
	// Diagonais
	if((*m)[0][0] == key && (*m)[1][1] == key && (*m)[2][2] == key) return 1;
	if((*m)[2][0] == key && (*m)[1][1] == key && (*m)[0][2] == key) return 1;

	return 0;
}

// Valida se a posição está livre e dentro do tabuleiro
static int validarJogada(char (*m)[T][T], int linha, int coluna) {
	// CORREÇÃO: Usar >= T pois indices vão de 0 a T-1
	if(linha >= T || coluna >= T || linha < 0 || coluna < 0) {
		return 0;
	} else if((*m)[linha][coluna] != ' ') {
		return 0; // Já! ocupado
	} else {
		return 1; // Livre
	}
}

static int fazerJogada(char (*m)[T][T], char key, int linha, int coluna) {
	if(validarJogada(m, linha, coluna) == 1) {
		(*m)[linha][coluna] = key;
		return 1;
	}
	return 0;
}

static void printarJogo(char (*m)[T][T]) {
	printf("\n\n");
	for(int i = 0; i < T; i++) {
		// Espaçamento para centralizar visualmente
		printf("\t\t");
		for(int j = 0; j < T; j++) {
			printf(" %c ", (*m)[i][j]); // Imprime o token real da matriz
			if(j != 2) printf("|");
		}
		printf("\n");
		if(i != 2) printf("\t\t---|---|---\n");
	}
	printf("\n");
}

static void preencherJogo(char (*m)[T][T]) {
	for(int i = 0; i < T; i++) {
		for(int j = 0; j < T; j++) {
			(*m)[i][j] = ' ';
		}
	}
}

static int tabuleiroCheio(char (*m)[T][T]) {
	for(int i = 0; i < T; i++) {
		for(int j = 0; j < T; j++) {
			if((*m)[i][j] == ' ') return 0; // Ainda tem espaC'o vazio
		}
	}
	return 1; // Cheio
}

 /*
 * Algoritmo MINIMAX com Poda Alfa-Beta
 * Esta função recursiva simula todas as jogadas possíveis para determinar o melhor caminho.
 * eoMax = 1: Turno do Computador (Tenta Maximizar a pontuação)
 * eoMax = 0: Turno do Humano (Tenta Minimizar a pontuação do PC)
 */
static int minimaxab(char (*m)[T][T], int eoMax, int profundidadeArvore, int alfa, int beta) {
	// 1. Casos Base (Fim da simulação)
	if(statusJogo(m, tokens[1]) == 1) {
		return (10 - profundidadeArvore); // PC Ganhou: Pontuação alta (prefere ganhar rápido)
	} else if(statusJogo(m, tokens[0]) == 1) {
		return (profundidadeArvore - 10); // Humano Ganhou: Pontuação baixa
	} else if(tabuleiroCheio(m) == 1) {
		return 0; // Empate
	}

	// 2. Turno do Computador (Maximizador)
	if(eoMax == 1) {
		int melhorScore = -1000;

		for(int i = 0; i < T; i++) {
			for(int j = 0; j < T; j++) {
				if((*m)[i][j] == ' ') {
					(*m)[i][j] = tokens[1]; // Simula jogada do PC
					int scoreMomento = minimaxab(m, 0, profundidadeArvore+1, alfa, beta);
					(*m)[i][j] = ' ';       // Desfaz jogada (Backtracking)

					// Maximiza o score
					melhorScore = (scoreMomento > melhorScore) ? scoreMomento : melhorScore;
					alfa = (alfa > melhorScore) ? alfa : melhorScore; // Atualiza Alfa

					if(beta <= alfa) return melhorScore; // Poda Beta
				}
			}
		}
		return melhorScore;

		// 3. Turno do Humano (Minimizador)
	} else {
		int piorScore = 1000;

		for(int i = 0; i < T; i++) {
			for(int j = 0; j < T; j++) {
				if((*m)[i][j] == ' ') {
					(*m)[i][j] = tokens[0]; // Simula jogada do Humano
					int scoreMomento = minimaxab(m, 1, profundidadeArvore+1, alfa, beta);
					(*m)[i][j] = ' ';       // Desfaz jogada

					// Minimiza o score (Humano joga para vencer o PC)
					piorScore = (scoreMomento < piorScore) ? scoreMomento : piorScore;
					beta = (beta < piorScore) ? beta : piorScore; // Atualiza Beta

					if(beta <= alfa) return piorScore; // Poda Alfa
				}
			}
		}
		return piorScore;
	}
}

// Função wrapper que chama o Minimax para decidir a jogada real
static void melhorJogada(char (*m)[T][T], int *linha, int *coluna) {
	int melhorScore = -1000, linhaTemp = -1, colunaTemp = -1;

	// Varre o tabuleiro buscando a jogada que retorna o maior valor do Minimax
	for(int i = 0; i < T; i++) {
		for(int j = 0; j < T; j++) {
			if((*m)[i][j] == ' ') {
				(*m)[i][j] = tokens[1]; // Testa jogar aqui
				// Chama minimax para o oponente (0), com alfa/beta iniciais
				int scoreMomento = minimaxab(m, 0, 0, -1000, 1000);
				(*m)[i][j] = ' ';       // Limpa

				if(scoreMomento > melhorScore) {
					melhorScore = scoreMomento;
					linhaTemp = i;
					colunaTemp = j;
				}
			}
		}
	}
	*linha = linhaTemp;
	*coluna = colunaTemp;
}