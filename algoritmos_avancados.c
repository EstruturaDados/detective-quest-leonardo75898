#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura da sala (nó da árvore)
typedef struct Sala {
    char nome[30];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

// Cria nova sala
Sala* criarSala(const char* nome) {
    Sala* nova = (Sala*)malloc(sizeof(Sala));
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

// Permite o jogador explorar a mansão
void explorarSalas(Sala* atual) {
    char escolha;

    while (atual != NULL) {
        printf("\nVocê está na sala: %s\n", atual->nome);
        printf("Escolha o caminho: (e) Esquerda | (d) Direita | (s) Sair: ");
        scanf(" %c", &escolha);

        if (escolha == 'e') {
            if (atual->esquerda != NULL) {
                atual = atual->esquerda;
            } else {
                printf("🚪 Não há sala à esquerda. Fim do caminho!\n");
                break;
            }
        } else if (escolha == 'd') {
            if (atual->direita != NULL) {
                atual = atual->direita;
            } else {
                printf("🚪 Não há sala à direita. Fim do caminho!\n");
                break;
            }
        } else if (escolha == 's') {
            printf("🔚 Você saiu da exploração.\n");
            break;
        } else {
            printf("❌ Opção inválida.\n");
        }
    }
}

// Libera memória da árvore
void liberarArvore(Sala* raiz) {
    if (raiz == NULL) return;
    liberarArvore(raiz->esquerda);
    liberarArvore(raiz->direita);
    free(raiz);
}

int main() {
    // Criação estática do mapa (árvore binária)
    Sala* hall = criarSala("Hall de Entrada");
    hall->esquerda = criarSala("Sala de Estar");
    hall->direita = criarSala("Biblioteca");

    hall->esquerda->esquerda = criarSala("Cozinha");
    hall->esquerda->direita = criarSala("Sala de Jantar");

    hall->direita->esquerda = criarSala("Escritório");
    hall->direita->direita = criarSala("Quarto Secreto");

    printf("🔍 Bem-vindo ao Detective Quest - Mansão Misteriosa!\n");

    explorarSalas(hall);

    liberarArvore(hall); // libera memória

    return 0;
}
