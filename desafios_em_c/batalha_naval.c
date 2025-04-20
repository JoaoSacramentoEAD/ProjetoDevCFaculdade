#include <stdio.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define AGUA 0
#define NAVIO 3

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int navioHorizontal[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    
    if (coluna + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for(int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = navioHorizontal[i];
        }
    }
}

void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    int navioVertical[TAMANHO_NAVIO] = {NAVIO, NAVIO, NAVIO};
    
    if (linha + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for(int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = navioVertical[i];
        }
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  ");
    // Imprime letras das colunas (A até J)
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        // Imprime números das linhas
        printf("%d ", i);
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    inicializarTabuleiro(tabuleiro);
    
    posicionarNavioHorizontal(tabuleiro, 2, 3);
    posicionarNavioVertical(tabuleiro, 4, 7);
    
    printf("Tabuleiro de Batalha Naval:\n");
    printf("0 = Água, 3 = Navio\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
