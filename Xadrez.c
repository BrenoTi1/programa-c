#include <stdio.h>

/// =======================
/// ♜ TORRE (Recursividade)
/// =======================
void torre(int casas) {
    if (casas == 0) return;

    printf("Torre: move para cima\n");

    torre(casas - 1);
}

/// =======================
/// ♝ BISPO (Recursivo + Loops Aninhados)
/// =======================
void bispo(int casas) {
    if (casas == 0) return;

    // Loop externo (vertical)
    for (int i = 0; i < 1; i++) {

        // Loop interno (horizontal)
        for (int j = 0; j < 1; j++) {
            printf("Bispo: move na diagonal (cima-direita)\n");
        }
    }

    bispo(casas - 1);
}

/// =======================
/// ♛ RAINHA (Recursividade)
/// =======================
void rainha(int casas) {
    if (casas == 0) return;

    printf("Rainha: move na diagonal (direita)\n");

    rainha(casas - 1);
}

/// =======================
/// ♞ CAVALO (Loops Complexos)
/// =======================
void cavalo() {
    for (int i = 0; i < 3; i++) {

        // 2 movimentos para cima
        if (i < 2) {
            printf("Cavalo: move para cima\n");
            continue;
        }

        // 1 movimento para direita
        printf("Cavalo: move para direita\n");
        break;
    }
}

/// =======================
/// 🔧 FUNÇÃO PRINCIPAL
/// =======================
int main() {

    printf("=== Movimento da Torre ===\n");
    torre(5);

    printf("\n=== Movimento do Bispo ===\n");
    bispo(5);

    printf("\n=== Movimento da Rainha ===\n");
    rainha(8);

    printf("\n=== Movimento do Cavalo ===\n");
    cavalo();

    return 0;
}


