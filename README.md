
# Jogo da Velha

Projeto desenvolvido como terceiro trabalho prático da disciplina **Introdução à Ciência da Computação**, ministrada pela **Prof.ª Dr.ª Simone Dornelas Costa**, componente curricular do curso de Bacharelado em Ciência da Computação da **Universidade Federal do Espírito Santo (UFES)**.

O programa foi implementado na linguagem C e consiste em um jogo da velha entre dois agentes:  
- um jogador humano  
- e um agente computacional, projetado para ser imbatível

Para o funcionamento do agente computacional foi usado o algoritmo **Minimax**, otimizado por **Alpha-Beta Pruning** e controle de **profundidade**, garantindo decisões ótimas em tempo viável.
## Autores

- Daniella Honório Rosa ([@octokatherine](https://www.github.com/octokatherine))
- Danielly N. dos S. Martins ([@octokatherine](https://www.github.com/octokatherine))
- Danillo de Paula Carvalho ([@octokatherine](https://www.github.com/octokatherine))
- Elis Vieira de Almeida ([@octokatherine](https://www.github.com/octokatherine))
## Funcionamento do Autômato
## Rodando localmente

### Obtenção do Projeto
Baixe o projeto anexado ao envio do grupo na plataforma Google Classroom ou por meio deste **[link](https://)**

### Execução no Windows
Abra o Prompt de Comando, entre no diretório do projeto:

```bash
  cd ...\jogodavelha
```

Execute o arquivo já compilado:

```bash
  jogodavelha.exe
```

Em caso de erro, gere um novo executavel:

```bash
  gcc main.c jogatina.c -o novoExecutavel.exe
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