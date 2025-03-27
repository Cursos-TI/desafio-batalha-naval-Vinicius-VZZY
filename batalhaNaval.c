#include <stdio.h>

#define TAMANHO_NAVIO 3 // Definindo o tamanho dos navios
#define TAMANHO_TABULEIRO 10 // Tamanho do tabuleiro

int main() {
    // Definição das coordenadas dos navios
    int navio_vertical[TAMANHO_NAVIO][2] = {{2, 3}, {3, 3}, {4, 3}}; // Navio vertical
    int navio_horizontal[TAMANHO_NAVIO][2] = {{5, 1}, {5, 2}, {5, 3}}; // Navio horizontal
    
    // Exibição das coordenadas dos navios
    printf("Coordenadas do Navio Vertical:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Parte %d: (%d, %d)\n", i + 1, navio_vertical[i][0], navio_vertical[i][1]);
    }
    
    printf("\nCoordenadas do Navio Horizontal:\n");
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        printf("Parte %d: (%d, %d)\n", i + 1, navio_horizontal[i][0], navio_horizontal[i][1]);
    }
    
    // Criando o tabuleiro e posicionando os navios
    char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Inicializando o tabuleiro com água (~)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = '~';
        }
    }
    
    // Posicionando os navios no tabuleiro
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[navio_vertical[i][0]][navio_vertical[i][1]] = 'V';
        tabuleiro[navio_horizontal[i][0]][navio_horizontal[i][1]] = 'H';
    }
    
    // Exibindo o tabuleiro
    printf("\nTabuleiro:\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%c ", tabuleiro[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}
