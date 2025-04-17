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

    return 0;
}
