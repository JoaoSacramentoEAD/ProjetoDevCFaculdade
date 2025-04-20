#include <stdio.h>
#include <stdlib.h>
#define TAMANHO_TABULEIRO 10
#define TAMANHO_HABILIDADE 5
#define AGUA 0
#define NAVIO 3
#define AREA_AFETADA 5

// Estrutura para armazenar uma habilidade
typedef struct {
    int matriz[TAMANHO_HABILIDADE][TAMANHO_HABILIDADE];
    char nome[20];
} Habilidade;

void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

void criarHabilidadeCone(Habilidade *habilidade) {
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cria um padrão de cone
            if (j >= (TAMANHO_HABILIDADE/2 - i) && j <= (TAMANHO_HABILIDADE/2 + i)) {
                habilidade->matriz[i][j] = 1;
            } else {
                habilidade->matriz[i][j] = 0;
            }
        }
    }
    sprintf(habilidade->nome, "Cone");
}

void criarHabilidadeCruz(Habilidade *habilidade) {
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cria um padrão de cruz
            if (i == TAMANHO_HABILIDADE/2 || j == TAMANHO_HABILIDADE/2) {
                habilidade->matriz[i][j] = 1;
            } else {
                habilidade->matriz[i][j] = 0;
            }
        }
    }
    sprintf(habilidade->nome, "Cruz");
}

void criarHabilidadeOctaedro(Habilidade *habilidade) {
    int centro = TAMANHO_HABILIDADE/2;
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            // Cria um padrão de octaedro (losango)
            if (abs(i - centro) + abs(j - centro) <= centro) {
                habilidade->matriz[i][j] = 1;
            } else {
                habilidade->matriz[i][j] = 0;
            }
        }
    }
    sprintf(habilidade->nome, "Octaedro");
}

void aplicarHabilidade(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], 
                      Habilidade *habilidade, int linha, int coluna) {
    int offset = TAMANHO_HABILIDADE/2;
    
    printf("\nAplicando habilidade %s na posição (%d,%d)\n", habilidade->nome, linha, coluna);
    
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            int tabLinha = linha - offset + i;
            int tabColuna = coluna - offset + j;
            
            // Verifica se a posição está dentro do tabuleiro
            if (tabLinha >= 0 && tabLinha < TAMANHO_TABULEIRO && 
                tabColuna >= 0 && tabColuna < TAMANHO_TABULEIRO) {
                if (habilidade->matriz[i][j] == 1) {
                    tabuleiro[tabLinha][tabColuna] = AREA_AFETADA;
                }
            }
        }
    }
}

void exibirHabilidade(Habilidade *habilidade) {
    printf("\nÁrea de efeito da habilidade %s:\n", habilidade->nome);
    for(int i = 0; i < TAMANHO_HABILIDADE; i++) {
        for(int j = 0; j < TAMANHO_HABILIDADE; j++) {
            printf("%d ", habilidade->matriz[i][j]);
        }
        printf("\n");
    }
}

void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n  ");
    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n");

    for(int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for(int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    Habilidade cone, cruz, octaedro;
    
    // Inicializa o tabuleiro
    inicializarTabuleiro(tabuleiro);
    
    // Posiciona alguns navios para teste
    tabuleiro[2][3] = NAVIO;
    tabuleiro[2][4] = NAVIO;
    tabuleiro[2][5] = NAVIO;
    tabuleiro[5][7] = NAVIO;
    tabuleiro[6][7] = NAVIO;
    tabuleiro[7][7] = NAVIO;
    
    // Cria as habilidades
    criarHabilidadeCone(&cone);
    criarHabilidadeCruz(&cruz);
    criarHabilidadeOctaedro(&octaedro);
    
    // Exibe as áreas de efeito das habilidades
    exibirHabilidade(&cone);
    exibirHabilidade(&cruz);
    exibirHabilidade(&octaedro);
    
    printf("\nTabuleiro inicial:\n");
    exibirTabuleiro(tabuleiro);
    
    // Aplica cada habilidade em diferentes posições
    aplicarHabilidade(tabuleiro, &cone, 3, 3);
    printf("\nApós aplicar Cone:\n");
    exibirTabuleiro(tabuleiro);
    
    aplicarHabilidade(tabuleiro, &cruz, 5, 5);
    printf("\nApós aplicar Cruz:\n");
    exibirTabuleiro(tabuleiro);
    
    aplicarHabilidade(tabuleiro, &octaedro, 7, 7);
    printf("\nApós aplicar Octaedro:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
