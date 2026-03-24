#include <stdio.h>

#define MAX 50

// Função para inserir de forma ordenada
void inserirOrdenado(int v[], int *n, int valor) {
    if (*n >= MAX) {
        printf("Vetor cheio! Nao e possivel inserir.\n");
        return;
    }

    int i = *n - 1;

    // desloca elementos maiores para a direita
    while (i >= 0 && v[i] > valor) {
        v[i + 1] = v[i];
        i--;
    }

    v[i + 1] = valor;
    (*n)++;
}

// Busca binária
int buscaBinaria(int v[], int n, int valor) {
    int inicio = 0, fim = n - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (v[meio] == valor)
            return meio;
        else if (v[meio] < valor)
            inicio = meio + 1;
        else
            fim = meio - 1;
    }

    return -1;
}

// Remover elemento
void removerElemento(int v[], int *n, int valor) {
    int pos = buscaBinaria(v, *n, valor);

    if (pos == -1) {
        printf("Elemento nao encontrado.\n");
        return;
    }

    // desloca para a esquerda
    for (int i = pos; i < *n - 1; i++) {
        v[i] = v[i + 1];
    }

    (*n)--;
    printf("Elemento removido com sucesso.\n");
}

// Imprimir vetor
void imprimirVetor(int v[], int n) {
    if (n == 0) {
        printf("Vetor vazio.\n");
        return;
    }

    printf("Vetor: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main() {
    int v[MAX];
    int n = 0;
    int tamanho;

    // Solicitar tamanho inicial
    do {
        printf("Digite o tamanho do vetor (3 a 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > 50);

    // Preencher vetor com inserção ordenada
    printf("Digite %d valores inteiros:\n", tamanho);
    for (int i = 0; i < tamanho; i++) {
        int valor;
        scanf("%d", &valor);
        inserirOrdenado(v, &n, valor);
    }

    int opcao;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Imprimir vetor\n");
        printf("2. Buscar elemento (busca binaria)\n");
        printf("3. Remover elemento\n");
        printf("4. Inserir elemento\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(v, n);
                break;

            case 2: {
                int valor;
                printf("Digite o valor a buscar: ");
                scanf("%d", &valor);

                int pos = buscaBinaria(v, n, valor);
                printf("Posicao: %d\n", pos);
                break;
            }

            case 3: {
                int valor;
                printf("Digite o valor a remover: ");
                scanf("%d", &valor);

                removerElemento(v, &n, valor);
                break;
            }

            case 4: {
                int valor;
                printf("Digite o valor a inserir: ");
                scanf("%d", &valor);

                inserirOrdenado(v, &n, valor);
                break;
            }

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);

    return 0;
}