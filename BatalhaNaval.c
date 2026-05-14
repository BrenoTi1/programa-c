#include <stdio.h>
#include <stdlib.h>

#define TAM 10
#define HABILIDADE_TAM 5

int main() {

    // =========================
    // TABULEIRO
    // =========================
    int tabuleiro[TAM][TAM];

    // Inicializa com água
    for(int linha = 0; linha < TAM; linha++) {
        for(int coluna = 0; coluna < TAM; coluna++) {
            tabuleiro[linha][coluna] = 0;
        }
    }

    int tamanhoNavio = 3;

    // =========================
    // NAVIO HORIZONTAL
    // =========================
    int linhaH = 2;
    int colunaH = 4;

    if(colunaH + tamanhoNavio <= TAM) {

        int sobreposicao = 0;

        for(int i = 0; i < tamanhoNavio; i++) {
            if(tabuleiro[linhaH][colunaH + i] != 0) {
                sobreposicao = 1;
            }
        }

        if(!sobreposicao) {
            for(int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaH][colunaH + i] = 3;
            }
        }
    }

    // =========================
    // NAVIO VERTICAL
    // =========================
    int linhaV = 5;
    int colunaV = 7;

    if(linhaV + tamanhoNavio <= TAM) {

        int sobreposicao = 0;

        for(int i = 0; i < tamanhoNavio; i++) {
            if(tabuleiro[linhaV + i][colunaV] != 0) {
                sobreposicao = 1;
            }
        }

        if(!sobreposicao) {
            for(int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaV + i][colunaV] = 3;
            }
        }
    }

    // =========================
    // NAVIO DIAGONAL PRINCIPAL
    // =========================
    int linhaD1 = 0;
    int colunaD1 = 0;

    if(linhaD1 + tamanhoNavio <= TAM &&
       colunaD1 + tamanhoNavio <= TAM) {

        int sobreposicao = 0;

        for(int i = 0; i < tamanhoNavio; i++) {
            if(tabuleiro[linhaD1 + i][colunaD1 + i] != 0) {
                sobreposicao = 1;
            }
        }

        if(!sobreposicao) {
            for(int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaD1 + i][colunaD1 + i] = 3;
            }
        }
    }

    // =========================
    // NAVIO DIAGONAL SECUNDÁRIA
    // =========================
    int linhaD2 = 0;
    int colunaD2 = 9;

    if(linhaD2 + tamanhoNavio <= TAM &&
       colunaD2 - (tamanhoNavio - 1) >= 0) {

        int sobreposicao = 0;

        for(int i = 0; i < tamanhoNavio; i++) {
            if(tabuleiro[linhaD2 + i][colunaD2 - i] != 0) {
                sobreposicao = 1;
            }
        }

        if(!sobreposicao) {
            for(int i = 0; i < tamanhoNavio; i++) {
                tabuleiro[linhaD2 + i][colunaD2 - i] = 3;
            }
        }
    }

    // =====================================================
    // MATRIZES DAS HABILIDADES
    // =====================================================

    int cone[HABILIDADE_TAM][HABILIDADE_TAM];
    int cruz[HABILIDADE_TAM][HABILIDADE_TAM];
    int octaedro[HABILIDADE_TAM][HABILIDADE_TAM];

    // Inicializa tudo com 0
    for(int i = 0; i < HABILIDADE_TAM; i++) {
        for(int j = 0; j < HABILIDADE_TAM; j++) {

            cone[i][j] = 0;
            cruz[i][j] = 0;
            octaedro[i][j] = 0;
        }
    }

    // =====================================================
    // HABILIDADE CONE
    // =====================================================

    int meio = HABILIDADE_TAM / 2;

    for(int i = 0; i < HABILIDADE_TAM; i++) {

        for(int j = 0; j < HABILIDADE_TAM; j++) {

            // Expande para os lados conforme desce
            if(j >= meio - i && j <= meio + i) {
                cone[i][j] = 1;
            }
        }
    }

    // =====================================================
    // HABILIDADE CRUZ
    // =====================================================

    for(int i = 0; i < HABILIDADE_TAM; i++) {

        for(int j = 0; j < HABILIDADE_TAM; j++) {

            if(i == meio || j == meio) {
                cruz[i][j] = 1;
            }
        }
    }

    // =====================================================
    // HABILIDADE OCTAEDRO (LOSANGO)
    // =====================================================

    for(int i = 0; i < HABILIDADE_TAM; i++) {

        for(int j = 0; j < HABILIDADE_TAM; j++) {

            // Distância de Manhattan
            if((abs(i - meio) + abs(j - meio)) <= meio) {
                octaedro[i][j] = 1;
            }
        }
    }

    // =====================================================
    // POSIÇÕES DE ORIGEM DAS HABILIDADES
    // =====================================================

    int origemConeLinha = 1;
    int origemConeColuna = 5;

    int origemCruzLinha = 6;
    int origemCruzColuna = 2;

    int origemOctLinha = 7;
    int origemOctColuna = 7;

    // =====================================================
    // SOBREPOR CONE NO TABULEIRO
    // =====================================================

    for(int i = 0; i < HABILIDADE_TAM; i++) {

        for(int j = 0; j < HABILIDADE_TAM; j++) {

            int linhaTab =
                origemConeLinha + (i - meio);

            int colunaTab =
                origemConeColuna + (j - meio);

            // Verifica limites
            if(linhaTab >= 0 && linhaTab < TAM &&
               colunaTab >= 0 && colunaTab < TAM) {

                if(cone[i][j] == 1 &&
                   tabuleiro[linhaTab][colunaTab] == 0) {

                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

    // =====================================================
    // SOBREPOR CRUZ
    // =====================================================

    for(int i = 0; i < HABILIDADE_TAM; i++) {

        for(int j = 0; j < HABILIDADE_TAM; j++) {

            int linhaTab =
                origemCruzLinha + (i - meio);

            int colunaTab =
                origemCruzColuna + (j - meio);

            if(linhaTab >= 0 && linhaTab < TAM &&
               colunaTab >= 0 && colunaTab < TAM) {

                if(cruz[i][j] == 1 &&
                   tabuleiro[linhaTab][colunaTab] == 0) {

                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

    // =====================================================
    // SOBREPOR OCTAEDRO
    // =====================================================

    for(int i = 0; i < HABILIDADE_TAM; i++) {

        for(int j = 0; j < HABILIDADE_TAM; j++) {

            int linhaTab =
                origemOctLinha + (i - meio);

            int colunaTab =
                origemOctColuna + (j - meio);

            if(linhaTab >= 0 && linhaTab < TAM &&
               colunaTab >= 0 && colunaTab < TAM) {

                if(octaedro[i][j] == 1 &&
                   tabuleiro[linhaTab][colunaTab] == 0) {

                    tabuleiro[linhaTab][colunaTab] = 5;
                }
            }
        }
    }

// =====================================================
// EXIBIÇÃO DO TABULEIRO
// =====================================================

char letras[10] =
    {'A','B','C','D','E','F','G','H','I','J'};

printf("    ");

for(int coluna = 1; coluna <= TAM; coluna++) {
    printf("%2d ", coluna);
}

printf("\n");

for(int linha = 0; linha < TAM; linha++) {

    printf("%c   ", letras[linha]);

    for(int coluna = 0; coluna < TAM; coluna++) {

        printf("%d  ", tabuleiro[linha][coluna]);
    }

    printf("\n");
}

    return 0;
}
