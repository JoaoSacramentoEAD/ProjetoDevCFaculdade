#include <stdio.h>

// Função recursiva para a Torre
void MovimentoTorreRecursivo(int movimentos) {
    if (movimentos > 0) {
        printf("Direita\n");
        MovimentoTorreRecursivo(movimentos - 1);
    }
}

// Função que combina recursividade e loops aninhados para o Bispo
void MovimentoBispo(int movimentos) {
    if (movimentos > 0) {
        // Loop aninhado para controlar movimento vertical e horizontal
        for (int vertical = 0; vertical < 1; vertical++) {
            printf("Cima\n");
            for (int horizontal = 0; horizontal < 1; horizontal++) {
                printf("Direita\n");
            }
        }
        // Chamada recursiva para o próximo movimento
        MovimentoBispo(movimentos - 1);
    }
}

// Função recursiva para a Rainha
void MovimentoRainhaRecursivo(int movimentos) {
    if (movimentos > 0) {
        printf("Esquerda\n");
        MovimentoRainhaRecursivo(movimentos - 1);
    }
}

// Função com loops complexos para o Cavalo
void MovimentoCavaloLoop(int movimentos) {
    int passos_vertical = 0;
    int passos_horizontal = 0;
    
    while (movimentos > 0) {
        for (int i = 0; i < 2; i++) {
            printf("Cima\n");
            passos_vertical++;
            if (passos_vertical >= 2) {
                break;
            }
        }
        
        if (passos_horizontal == 0) {
            printf("Direita\n");
            passos_horizontal++;
        }
        
        movimentos--;
    }
}

int main() {
    // Definindo as constantes para o número de movimentos
    const int MOVIMENTOS_TORRE = 5;
    const int MOVIMENTOS_BISPO = 5;
    const int MOVIMENTOS_RAINHA = 8;
    const int MOVIMENTOS_CAVALO = 1;

    // Simulando movimento da Torre (usando recursão)
    printf("\n=== Movimento da Torre (Recursivo) ===\n");
    MovimentoTorreRecursivo(MOVIMENTOS_TORRE);

    // Simulando movimento do Bispo (usando recursão com loops aninhados)
    printf("\n=== Movimento do Bispo (Recursivo + Loops Aninhados) ===\n");
    MovimentoBispo(MOVIMENTOS_BISPO);

    // Simulando movimento da Rainha (usando recursão)
    printf("\n=== Movimento da Rainha (Recursivo) ===\n");
    MovimentoRainhaRecursivo(MOVIMENTOS_RAINHA);

    // Simulando movimento do Cavalo (usando loops complexos)
    printf("\n=== Movimento do Cavalo (Loops Complexos) ===\n");
    MovimentoCavaloLoop(MOVIMENTOS_CAVALO);

    return 0;
}
