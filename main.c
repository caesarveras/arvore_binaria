#include <stdio.h>
#include <stdlib.h> // Para malloc, free, exit

// Definição da estrutura do nó da árvore
typedef struct Node {
    int data;          // Valor armazenado no nó
    struct Node *left; // Ponteiro para o filho esquerdo
    struct Node *right; // Ponteiro para o filho direito
} Node;

// Função para criar um novo nó
// Recebe um valor inteiro e retorna um ponteiro para o nó recém-criado
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        // Verifica se a alocação de memória foi bem-sucedida
        printf("Erro de alocação de memória!\n");
        exit(1); // Encerra o programa em caso de erro crítico
    }
    newNode->data = data;
    newNode->left = NULL; // Inicializa os ponteiros dos filhos como NULL
    newNode->right = NULL;
    return newNode;
}

// Função para inserir um nó na árvore binária de busca
// Recebe a raiz da árvore e o valor a ser inserido
// Retorna a nova raiz da árvore (pode ser a mesma se o nó não for o primeiro)
Node* insertNode(Node* root, int data) {
    // Se a árvore estiver vazia, o novo nó se torna a raiz
    if (root == NULL) {
        return createNode(data);
    }

    // Se o valor for menor que o dado da raiz, insere na subárvore esquerda
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    }
    // Se o valor for maior que o dado da raiz, insere na subárvore direita
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    // Se o dado já existe (data == root->data), não faz nada (árvores BST geralmente não permitem duplicatas)
    return root;
}

// Função auxiliar para encontrar o nó com o menor valor em uma subárvore
// Usado na remoção de nós com dois filhos para encontrar o sucessor in-order
Node* findMin(Node* node) {
    Node* current = node;
    // Percorre a subárvore esquerda até encontrar o nó mais à esquerda
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Função para remover um nó da árvore binária de busca
// Recebe a raiz da árvore e o valor a ser removido
// Retorna a nova raiz da árvore após a remoção
Node* removeNode(Node* root, int data) {
    // Caso base: Se a árvore estiver vazia, não há nada para remover
    if (root == NULL) {
        printf("Nó %d não encontrado na árvore.\n", data);
        return root;
    }

    // Se o valor a ser removido for menor que o dado da raiz, busca na subárvore esquerda
    if (data < root->data) {
        root->left = removeNode(root->left, data);
    }
    // Se o valor a ser removido for maior que o dado da raiz, busca na subárvore direita
    else if (data > root->data) {
        root->right = removeNode(root->right, data);
    }
    // Se o valor for igual ao dado da raiz, este é o nó a ser removido
    else {
        // Caso 1: Nó com nenhum ou apenas um filho
        if (root->left == NULL) {
            Node* temp = root->right; // O filho direito (ou NULL) se torna o substituto
            free(root); // Libera a memória do nó atual
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left; // O filho esquerdo se torna o substituto
            free(root); // Libera a memória do nó atual
            return temp;
        }

        // Caso 2: Nó com dois filhos
        // Encontra o sucessor in-order (o menor nó na subárvore direita)
        Node* temp = findMin(root->right);

        // Copia o dado do sucessor para o nó atual
        root->data = temp->data;

        // Remove recursivamente o sucessor da subárvore direita
        root->right = removeNode(root->right, temp->data);
    }
    return root;
}

// Função para realizar o percurso em pré-ordem (Raiz, Esquerda, Direita)
void preorderTraversal(Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);      // Visita a raiz
        preorderTraversal(root->left);  // Percorre a subárvore esquerda
        preorderTraversal(root->right); // Percorre a subárvore direita
    }
}

// Função para realizar o percurso em ordem (Esquerda, Raiz, Direita)
// Em uma BST, este percurso imprime os elementos em ordem crescente
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);   // Percorre a subárvore esquerda
        printf("%d ", root->data);      // Visita a raiz
        inorderTraversal(root->right);  // Percorre a subárvore direita
    }
}

// Função para realizar o percurso em pós-ordem (Esquerda, Direita, Raiz)
void postorderTraversal(Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);   // Percorre a subárvore esquerda
        postorderTraversal(root->right);  // Percorre a subárvore direita
        printf("%d ", root->data);       // Visita a raiz
    }
}

// Função para liberar toda a memória alocada pela árvore recursivamente
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);  // Libera a subárvore esquerda
        freeTree(root->right); // Libera a subárvore direita
        free(root);            // Libera o nó atual
    }
}

int main() {
    Node* root = NULL; // Inicializa a raiz da árvore como nula (árvore vazia)
    int choice;        // Variável para armazenar a opção do menu
    int data;          // Variável para armazenar o dado a ser inserido/removido

    do {
        // Exibe o menu de opções para o usuário
        printf("\n*** MENU DE OPÇÕES ***\n");
        printf("1. Incluir nó\n");
        printf("2. Remover nó\n");
        printf("3. Buscar pré-ordem\n");
        printf("4. Buscar em ordem\n");
        printf("5. Buscar pós-ordem\n");
        printf("0. Encerrar\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice); // Lê a opção escolhida pelo usuário

        switch (choice) {
            case 1:
                printf("Digite o valor a ser incluído: ");
                scanf("%d", &data);
                root = insertNode(root, data); // Chama a função de inserção
                printf("Nó %d incluído.\n", data);
                break;
            case 2:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &data);
                root = removeNode(root, data); // Chama a função de remoção
                break; // A mensagem de nó não encontrado é tratada dentro de removeNode
            case 3:
                printf("Busca Pré-ordem: ");
                if (root == NULL) {
                    printf("Árvore vazia.");
                } else {
                    preorderTraversal(root); // Chama a função de busca pré-ordem
                }
                printf("\n");
                break;
            case 4:
                printf("Busca Em Ordem: ");
                if (root == NULL) {
                    printf("Árvore vazia.");
                } else {
                    inorderTraversal(root); // Chama a função de busca em ordem
                }
                printf("\n");
                break;
            case 5:
                printf("Busca Pós-ordem: ");
                if (root == NULL) {
                    printf("Árvore vazia.");
                } else {
                    postorderTraversal(root); // Chama a função de busca pós-ordem
                }
                printf("\n");
                break;
            case 0:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 0); // O loop continua até que o usuário escolha '0' para encerrar

    // Libera toda a memória alocada dinamicamente pela árvore antes de finalizar o programa
    freeTree(root);

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
