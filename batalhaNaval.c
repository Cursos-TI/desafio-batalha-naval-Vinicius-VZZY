#include <stdio.h>

#define TAM_TABULEIRO 10
#define TAM_HABILIDADE 5

// Função para inicializar o tabuleiro
void inicializarTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;
        }
    }
}

// Função para posicionar um navio no tabuleiro
void posicionarNavios(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    tabuleiro[2][2] = 3;
    tabuleiro[2][3] = 3;
    tabuleiro[3][2] = 3;
}

// Função para sobrepor uma matriz de habilidade ao tabuleiro
void aplicarHabilidade(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO], int habilidade[TAM_HABILIDADE][TAM_HABILIDADE], int origemX, int origemY) {
    int meio = TAM_HABILIDADE / 2;
    
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            int x = origemX + (i - meio);
            int y = origemY + (j - meio);
            
            if (x >= 0 && x < TAM_TABULEIRO && y >= 0 && y < TAM_TABULEIRO && habilidade[i][j] == 1) {
                tabuleiro[x][y] = 5;
            }
        }
    }
}

// Função para exibir o tabuleiro
void exibirTabuleiro(int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO]) {
    for (int i = 0; i < TAM_TABULEIRO; i++) {
        for (int j = 0; j < TAM_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// Matrizes de habilidades
void definirHabilidadeCone(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (j >= TAM_HABILIDADE / 2 - i && j <= TAM_HABILIDADE / 2 + i) ? 1 : 0;
        }
    }
}

void definirHabilidadeCruz(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (i == TAM_HABILIDADE / 2 || j == TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

void definirHabilidadeOctaedro(int habilidade[TAM_HABILIDADE][TAM_HABILIDADE]) {
    for (int i = 0; i < TAM_HABILIDADE; i++) {
        for (int j = 0; j < TAM_HABILIDADE; j++) {
            habilidade[i][j] = (abs(i - TAM_HABILIDADE / 2) + abs(j - TAM_HABILIDADE / 2) <= TAM_HABILIDADE / 2) ? 1 : 0;
        }
    }
}

int main() {
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];
    inicializarTabuleiro(tabuleiro);
    posicionarNavios(tabuleiro);
    
    int habilidade[TAM_HABILIDADE][TAM_HABILIDADE];
    definirHabilidadeCone(habilidade);
    aplicarHabilidade(tabuleiro, habilidade, 4, 4); // Testando com habilidade Cone
    
    printf("Tabuleiro com habilidade aplicada:\n");
    exibirTabuleiro(tabuleiro);
    
    return 0;
}
