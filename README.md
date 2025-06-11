# Árvore Binária de Busca em C
Este projeto implementa uma Árvore Binária de Busca (ABB) em linguagem C, conforme os requisitos da Empresa Renalf S/A. A aplicação permite a manipulação de uma árvore binária, incluindo a inserção e remoção de nós, bem como a realização de três tipos de percursos em profundidade (pré-ordem, em ordem e pós-ordem) através de um menu interativo.

## Funcionalidades
O programa oferece as seguintes opções através de um menu:

```
Incluir nó: Adiciona um novo valor à árvore, mantendo a propriedade da Árvore Binária de Busca (valores menores à esquerda, maiores à direita).

Remover nó: Remove um valor existente da árvore. Lida com casos de nós folhas, nós com um filho e nós com dois filhos.

Buscar pré-ordem: Realiza um percurso em pré-ordem na árvore (Raiz -> Esquerda -> Direita) e imprime os valores.

Buscar em ordem: Realiza um percurso em ordem na árvore (Esquerda -> Raiz -> Direita) e imprime os valores. Para uma ABB, este percurso sempre retorna os elementos em ordem crescente.

Buscar pós-ordem: Realiza um percurso em pós-ordem na árvore (Esquerda -> Direita -> Raiz) e imprime os valores.

Encerrar: Sai do programa e libera toda a memória alocada dinamicamente para a árvore.
```
## Estrutura da Árvore
Cada nó da árvore é definido pela seguinte estrutura:
```
typedef struct Node {
    int data;          // O valor armazenado no nó
    struct Node *left; // Ponteiro para o filho esquerdo
    struct Node *right; // Ponteiro para o filho direito
} Node;
```
## Como Compilar e Executar
Para compilar e executar este programa, você precisará de um compilador C (como o GCC).

Salve o código:
Salve o código C fornecido em um arquivo chamado arvore_binaria.c (ou qualquer outro nome com extensão .c).

Compile o programa:
Abra um terminal ou prompt de comando e navegue até o diretório onde você salvou o arquivo. Em seguida, execute o comando de compilação:
```
gcc arvore_binaria.c -o arvore_binaria
```
Este comando criará um arquivo executável chamado arvore_binaria (ou arvore_binaria.exe no Windows).

Execute o programa:
Após a compilação, execute o programa a partir do terminal:
```
./arvore_binaria
```
O programa exibirá o menu de opções, e você poderá interagir com a árvore binária de busca.

Exemplo de Uso
Ao executar o programa, você verá o seguinte menu:
```
*** MENU DE OPÇÕES ***
1. Incluir nó
2. Remover nó
3. Buscar pré-ordem
4. Buscar em ordem
5. Buscar pós-ordem
0. Encerrar
Escolha uma opção:
```
Você pode, por exemplo:

Digitar 1 e inserir alguns números (ex: 50, 30, 70, 20, 40, 60, 80).

Digitar 4 para ver a árvore em ordem crescente.

Digitar 2 e remover um nó (ex: 30).

Digitar 4 novamente para ver a árvore após a remoção.

Digitar 0 para encerrar o programa.

## Considerações Adicionais
Tratamento de Duplicatas: A implementação atual não insere valores duplicados na árvore. Se um valor já existe, a função insertNode simplesmente retorna a raiz sem fazer alterações.

Gerenciamento de Memória: O programa faz uso de malloc para alocar memória para novos nós e free para liberar a memória dos nós removidos e da árvore completa ao encerrar, prevenindo vazamentos de memória.