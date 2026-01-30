#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "jogatina.h" // Biblioteca personalizada com a lógica do jogo
#define T 3

// Prototipos das funçoẽs auxiliares de interface
void limparTela();
void esperarTecla();

int main()
{
	// Configura o idioma para permitir caracteres como acentos
	setlocale(LC_ALL, "pt-br");

	// Declaração das variáveis
	// jogo: matriz do tabuleiro
	// token: vetor com os Simbolos [0] = Jogador, [1] = Computador
	// temp: variável auxiliar para leitura
	char jogo[T][T], token[2] = {'X','O'}, temp ='Z';
	int opcao = 0; // Inicializado com 0 para garantir a entrada no loop

	// Loop principal do menu (Executa atC) o usuário escolher sair)
	while(opcao != 3) {
		limparTela();
		printf("JOGO DA VELHA\n\nDigite a opC'C#o que deseja acessar:\n");
		printf("1 - Iniciar Novo Jogo\n2 - Mudar Simbolos\n3 - Sair\n\n> ");
		scanf("%d", &opcao);

		printf("\n");
		limparTela();

		// Gerencia as opções do menu
		switch(opcao) {
		case 1:
			// Inicia a partida passando a matriz do jogo
			iniciar_jogo(&jogo);
			esperarTecla();
			limparTela();
			break;

		case 2:
			// DESAFIO GRUPO 3: Personalização de símbolos
			// Lê o novo caractere do Jogador
			printf("Gostaria de trocar X (jogador) por qual caractere?\n> ");
			scanf(" %c", &temp);
			token[0] = temp;

			// Lê o novo caractere do Computador
			printf("\nGostaria de trocar O (computador) por qual caractere?\n> ");
			scanf(" %c", &temp);
			token[1] = temp;

			// VALIDAÇÃO: Verifica se os símbolos são iguais
			if (token[0] == token[1]) {
				printf("\n[ERRO] Os simbolos nao podem ser iguais!\n");
				printf("Restaurando padrao (X vs O)...\n");
				token[0] = 'X';
				token[1] = 'O';
				setTokens(token); // Restaura o padrão na lógica
				esperarTecla();
			} else {
				// Se forem diferentes, aplica a mudança
				setTokens(token);
				printf("\nSimbolos alterados com sucesso!\n");
				esperarTecla();
			}

			limparTela();
			break;

		case 3:
			// Encerra o programa
			printf("Saindo do jogo...\n");
			break;

		default:
			// Tratamento de opção inválida
			printf("OPCÇÃO INVÁLIDA");
			esperarTecla();
			limparTela();
			break;
		}
	}
	return 0;
}

// Função para limpar a tela dependendo do Sistema Operacional
void limparTela() {
#ifdef _WIN32
	system("cls"); // Windows
#else
	system("clear"); // Linux/Mac
#endif
}

// Função para pausar a execução atC) o usuário pressionar ENTER
void esperarTecla() {
	int c;
	printf("\nPressione ENTER para continuar...");

	// Limpa o buffer do teclado e espera o enter
	while ((c = getchar()) != '\n' && c != EOF);
	getchar();
}