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
int t = 0;

void ler_testes();
void gerar_ordenacoes();
void gerar_ordenacoes_t(int n, int t);
int contem(int tam, int x);
void imprime_ordenacoes_t(int n);


int main() {
    t = 0;
    ler_testes();
    printf("\n");
    gerar_ordenacoes();

    return 0;
}

void ler_testes() {
    int n;
    for (;;) {
        scanf("%d", &n);
        if (n == 0) break;

        int f;
        figuras[t][0] = n;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &f);
            figuras[t][i] = f;
        }

        t++;
    }
}

void gerar_ordenacoes() {
    for (int i = 0; i < t; ++i) {
        gerar_ordenacoes_t(figuras[i][0], i);
        printf("\n");
    }
}

void gerar_ordenacoes_t(int n, int t) {
    int tamanho = figuras[t][0];
    if (n == 0) {
        imprime_ordenacoes_t(tamanho);
        return;
    }

    for (int i = 1; i <= tamanho; ++i) {
        if (!contem(figuras[t][0] + 1, figuras[t][i])) {
            ordenacoes[n] = figuras[t][i];
            gerar_ordenacoes_t(n-1, t);
            ordenacoes[n] = 0;
        }
    }
}

int contem(int tam, int x) {
    for (int i = 0; i < tam; ++i)
        if (ordenacoes[i] == x) return 1;
    return 0;
}

void imprime_ordenacoes_t(int n) {
    for (int i = 1; i <= n; ++i)
        printf("%d ", ordenacoes[i]);
    printf("\n");
}
