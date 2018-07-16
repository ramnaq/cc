/*
 * Problema:
 * https://br.spoj.com/problems/TENTA/
 *
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_TESTES 8
#define MAX_FIGURAS 100
int figuras[MAX_TESTES][MAX_FIGURAS];
int ordenacoes[MAX_FIGURAS];
int t;


void ler_testes() {
    int num_figs;
    int entradaDados = 1;
    char figs[MAX_FIGURAS*2];

    while (entradaDados) {
        scanf ("%[^\n]%*c", figs);
        num_figs = figs[0] - (int) '0';

        if (num_figs == 0) {
            entradaDados = 0;
            continue;
        } else if (t > MAX_FIGURAS) {
            exit(-1);
        }

        int fig;
        figuras[t][0] = num_figs;
        for (int i = 1; i <= num_figs; ++i) {
            scanf("%d", fig);
            figuras[t][i] = fig;
        }

        t++;
    }
}

void imprime_ord(int num_figs, int ordenacao[num_figs]) {
    for (int i = 1; i <= num_figs; ++i)
        printf(ordenacao[i] + " ");
    printf("\n");
}

int contem(int len, int vec[len], int x) {
    for (int i = 0; i < len; ++i)
        if (vec[i] == x) return 1;
    return 0;
}

void gerar_tentativas_t(int teste, int n) {
    int tamanho = figuras[teste][0];
    if (n == 0) {
        imprime_ord(tamanho, ordenacoes);
        return;
    }

    for (int i = 1; i <= tamanho; i++) {
        if (!contem(tamanho, ordenacoes, figuras[teste][i])) {
            ordenacoes[n] = figuras[teste][i];
            gerar_tentativas_t(teste, n-1);
            ordenacoes[n] = 0;
        }
    }
}

void gerar_tentativas() {
    for (int i = 0; i < t; i++) {
        gerar_tentativas_t(i, figuras[i][0]);
        printf("\n");
    }
    printf("Pronto!\n");
}


int main() {
    t = 0;
    ler_testes();
    printf("\n");
    gerar_tentativas();

    return 0;
}
