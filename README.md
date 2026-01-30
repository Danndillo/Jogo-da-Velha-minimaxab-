
# Jogo da Velha

Projeto desenvolvido como terceiro trabalho prático da disciplina **Introdução à Ciência da Computação**, ministrada pela **Prof.ª Dr.ª Simone Dornelas Costa**, componente curricular do curso de Bacharelado em Ciência da Computação da **Universidade Federal do Espírito Santo (UFES)**.

O programa foi implementado na linguagem C e consiste em um jogo da velha entre dois agentes:  
- um jogador humano  
- e um agente computacional, projetado para ser imbatível

Para o funcionamento do agente computacional foi usado o algoritmo **Minimax**, otimizado por **Alpha-Beta Pruning** e controle de **profundidade**, garantindo decisões ótimas em tempo viável.
## Autores

- Daniella Honório Rosa 
- Danielly N. dos S. Martins 
- Danillo de Paula Carvalho 
- Elis Vieira de Almeida 
## Funcionamento do Autômato

O agente computacional do jogo da velha foi desenvolvido com base no algoritmo **Minimax**, uma técnica clássica de tomada de decisão em jogos determinísticos, de soma zero e com informação perfeita, como é o caso do jogo da velha.

### Algoritmo Minimax

O algoritmo Minimax modela o jogo como uma **árvore de estados**, na qual cada nó representa uma configuração possível do tabuleiro e cada aresta corresponde a uma jogada válida. Os níveis da árvore alternam entre dois tipos de jogadores:

- **Jogador Maximizador**: o agente computacional, que busca maximizar sua pontuação;
- **Jogador Minimizador**: o jogador humano, que busca minimizar a pontuação do computador.

Em cada estado terminal da árvore (vitória, derrota ou empate), é atribuída uma pontuação numérica:
- valores positivos indicam estados favoráveis ao computador;
- valores negativos indicam estados favoráveis ao jogador humano;
- o valor zero representa empate.

O algoritmo percorre recursivamente a árvore de decisões, propagando esses valores de baixo para cima. O computador escolhe, portanto, a jogada que **maximiza o pior cenário possível**, assumindo que o oponente sempre jogará de forma ótima.

### Controle de Profundidade

Para priorizar vitórias mais rápidas e evitar prolongar partidas desnecessariamente, o algoritmo considera a **profundidade da árvore de decisões**. Estados vencedores alcançados em menos jogadas recebem pontuações mais altas, enquanto derrotas tardias são penalizadas de forma menos severa. Esse controle torna o agente mais agressivo e eficiente na escolha de suas jogadas.

### Otimização com Alpha-Beta Pruning

Visando reduzir o custo computacional da busca, foi aplicada a técnica de **Alpha-Beta Pruning**, uma otimização do Minimax que elimina ramos da árvore que não influenciam o resultado final da decisão.

Durante a exploração da árvore:
- **α (alpha)** representa o melhor valor já encontrado para o jogador maximizador;
- **β (beta)** representa o melhor valor já encontrado para o jogador minimizador.

Sempre que se detecta que um determinado ramo não pode produzir um resultado melhor do que os já analisados, esse ramo é descartado, evitando avaliações desnecessárias. Essa estratégia mantém a correção do algoritmo, mas reduz significativamente o número de estados visitados.

### Organização do Código

A lógica do programa foi dividida em dois arquivos principais:
- `main.c`, responsável pela interação com o usuário, controle de fluxo do jogo e menu principal;
- `jogatina.c`, responsável pela lógica do jogo, incluindo verificação de vitória, validação de jogadas e implementação do algoritmo Minimax com poda Alpha-Beta.

Essa separação favorece a organização, legibilidade e manutenção do código.

### Personalização de Símbolos

O programa permite a personalização dos símbolos utilizados pelos jogadores. Embora o padrão utilize os caracteres `'X'` e `'O'`, o usuário pode substituí-los por outros símbolos de sua preferência durante a execução do programa, sem impacto no funcionamento do algoritmo de decisão.

## Rodando localmente

### Obtenção do Projeto
Baixe o arquivo .zip do projeto e extraia os arquivos.

### Execução no Windows
Abra o Prompt de Comando, entre no diretório do projeto:

```bash
  cd ...\jogodavelha
```

Gere um novo executavel:

```bash
  gcc main.c jogatina.c -o jogodavelha.exe
```

Execute o arquivo compilado:

```bash
  jogodavelha.exe
```

### Execução no Linux/macOS

No terminal, navegue até o diretório e compile com:

```bash
  gcc main.c jogatina.c -o novoExecutavel
```

Em seguida, execute:
```bash
  ./jogodavelha
```
## Referência

 - FELSTINER, C. **Alpha-beta pruning**. 2019. Acesso em 06 jan 2026. Disponível em: <https://www.whitman.edu/documents/Academics/Mathematics/2019/Felstiner-Guichard.pdf>
