#include <stdio.h>
#include <stdbool.h>

#define TAMANHO_NAVIO 3       // Tamanho dos navios
#define TAMANHO_TABULEIRO 10  // Tamanho do tabuleiro real
#define NAVIO_HORIZONTAL 'H'  // Representação do navio horizontal
#define NAVIO_VERTICAL 'V'    // Representação do navio vertical
#define NAVIO_DIAGONAL 'D'    // Representação do navio diagonal
#define AGUA '.'              // Representação da água

// Verifica se a posição está dentro dos limites do tabuleiro
bool dentro_do_limite(int x, int y) {
    return (x >= 0 && x < TAMANHO_TABULEIRO && y >= 0 && y < TAMANHO_TABULEIRO);
}

// Verifica se um navio pode ser colocado sem sobreposição
bool pode_posicionar(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coordenadas[TAMANHO_NAVIO][2]) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int x = coordenadas[i][0];
        int y = coordenadas[i][1];
        if (!dentro_do_limite(x, y) || tabuleiro[x][y] != AGUA) {
            return false;
        }
    }
    return true;
}

// Posiciona um navio no tabuleiro
void posicionar_navio(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int coordenadas[TAMANHO_NAVIO][2], char tipo) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[coordenadas[i][0]][coordenadas[i][1]] = tipo;
    }
}

// Exibe o tabuleiro com coordenadas
void exibir_tabuleiro(char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("\n    A B C D E F G H I J\n"); // Cabeçalho das colunas
    printf("  +---------------------+\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d | ", i + 1); // Índice das linhas
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("|\n");
    }

    printf("  +---------------------+\n");
}

int main() {
    // Inicializa o tabuleiro com água
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Coordenadas dos navios
    int navio_vertical[TAMANHO_NAVIO][2] = {{2, 3}, {3, 3}, {4, 3}}; // VERTICAL
    int navio_horizontal[TAMANHO_NAVIO][2] = {{5, 1}, {5, 2}, {5, 3}}; // HORIZONTAL
    int navio_diagonal1[TAMANHO_NAVIO][2] = {{0, 0}, {1, 1}, {2, 2}}; // DIAGONAL PRINCIPAL
    int navio_diagonal2[TAMANHO_NAVIO][2] = {{7, 9}, {8, 8}, {9, 7}}; // DIAGONAL SECUNDÁRIA

    // Posiciona os navios após validação
    if (pode_posicionar(tabuleiro, navio_vertical)) {
        posicionar_navio(tabuleiro, navio_vertical, NAVIO_VERTICAL);
    }
    if (pode_posicionar(tabuleiro, navio_horizontal)) {
        posicionar_navio(tabuleiro, navio_horizontal, NAVIO_HORIZONTAL);
    }
    if (pode_posicionar(tabuleiro, navio_diagonal1)) {
        posicionar_navio(tabuleiro, navio_diagonal1, NAVIO_DIAGONAL);
    }
    if (pode_posicionar(tabuleiro, navio_diagonal2)) {
        posicionar_navio(tabuleiro, navio_diagonal2, NAVIO_DIAGONAL);
    }

    // Exibe o tabuleiro
    exibir_tabuleiro(tabuleiro);

    return 0;
}
