#include <stdio.h>

int main() {
    // Definindo as constantes para o número de movimentos
    const int MOVIMENTOS_TORRE = 5;
    const int MOVIMENTOS_BISPO = 5;
    const int MOVIMENTOS_RAINHA = 8;

    // Simulando movimento da Torre (usando for)
    printf("\n=== Movimento da Torre ===\n");
    for (int i = 0; i < MOVIMENTOS_TORRE; i++) {
        printf("Direita\n");
    }

    // Simulando movimento do Bispo (usando while)
    printf("\n=== Movimento do Bispo ===\n");
    int movimentos_bispo = 0;
    while (movimentos_bispo < MOVIMENTOS_BISPO) {
        printf("Cima, Direita\n");
        movimentos_bispo++;
    }

    // Simulando movimento da Rainha (usando do-while)
    printf("\n=== Movimento da Rainha ===\n");
    int movimentos_rainha = 0;
    do {
        printf("Esquerda\n");
        movimentos_rainha++;
    } while (movimentos_rainha < MOVIMENTOS_RAINHA);

    // Simulando movimento do Cavalo (usando loop aninhado)
    printf("\n=== Movimento do Cavalo ===\n");
    int MOVIMENTOS_CAVALO = 1;
    while (MOVIMENTOS_CAVALO--) {
        for (int i = 0; i < 2; i++) { 
            printf("Baixo\n");
        }
    printf("Esquerda\n");
    }

    return 0;
}
