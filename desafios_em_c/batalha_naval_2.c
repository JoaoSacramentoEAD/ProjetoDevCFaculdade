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

int verificarPosicaoValida(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna) {
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO) {
        return 0;
    }
    return tabuleiro[linha][coluna] == AGUA;
}

int verificarEspacoLivre(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    int i;
    
    switch(direcao) {
        case 'H': // Horizontal
            for(i = 0; i < TAMANHO_NAVIO; i++) {
                if (!verificarPosicaoValida(tabuleiro, linha, coluna + i)) return 0;
            }
            break;
        case 'V': // Vertical
            for(i = 0; i < TAMANHO_NAVIO; i++) {
                if (!verificarPosicaoValida(tabuleiro, linha + i, coluna)) return 0;
            }
            break;
        case 'D': // Diagonal para baixo
            for(i = 0; i < TAMANHO_NAVIO; i++) {
                if (!verificarPosicaoValida(tabuleiro, linha + i, coluna + i)) return 0;
            }
            break;
        case 'U': // Diagonal para cima
            for(i = 0; i < TAMANHO_NAVIO; i++) {
                if (!verificarPosicaoValida(tabuleiro, linha - i, coluna + i)) return 0;
            }
            break;
    }
    return 1;
}

void posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, char direcao) {
    int i;
    
    if (!verificarEspacoLivre(tabuleiro, linha, coluna, direcao)) {
        printf("Não é possível posicionar o navio nesta posição!\n");
        return;
    }
    
    switch(direcao) {
        case 'H': // Horizontal
            for(i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha][coluna + i] = NAVIO;
            }
            break;
        case 'V': // Vertical
            for(i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna] = NAVIO;
            }
            break;
        case 'D': // Diagonal para baixo
            for(i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha + i][coluna + i] = NAVIO;
            }
            break;
        case 'U': // Diagonal para cima
            for(i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linha - i][coluna + i] = NAVIO;
            }
            break;
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
    
    // Posicionando navios em diferentes direções
    posicionarNavio(tabuleiro, 2, 3, 'H');  // Horizontal na linha 2, coluna 3
    posicionarNavio(tabuleiro, 4, 7, 'V');  // Vertical na linha 4, coluna 7
    posicionarNavio(tabuleiro, 1, 1, 'D');  // Diagonal para baixo, começando em (1,1)
    posicionarNavio(tabuleiro, 8, 1, 'U');  // Diagonal para cima, começando em (8,1)
    
    printf("Tabuleiro de Batalha Naval:\n");
    printf("0 = Água, 3 = Navio\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}