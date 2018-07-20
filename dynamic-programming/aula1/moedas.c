/*
 * https://br.spoj.com/problems/MOEDAS/
 */

#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define INF 100000000
#define MAX 50002
int K[100];      // moedas
int mem[MAX];    // valores salvos, moedas necessárias p/ determinado preço

void init_mem();
int min_moedas(int m, int n);

void main() {
    int m;  // valor da mercadoria
    int n;  // número de moedas existentes
    int k;  // uma moeda
    for(;;) {
        init_mem();
        scanf("%d", &m);
        if (m == 0) break;

        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &k);
            K[i] = k;
        }
        int x = min_moedas(m, n);
        if (x > 0) printf("%d\n", x);
        else printf("Impossivel\n");
    }
}

void init_mem() {
    for (int i = 0; i < MAX; ++i)
        mem[i] = INF;
}

int min_moedas(int m, int n) {
    mem[0] = 0;
    for (int i = 1; i <= m; ++i)
        for (int k = 0; k < n; ++k)
            if (i - K[k] >= 0)
                mem[i] = MIN(mem[i-K[k]] + 1, mem[i]);

    if (mem[m] != INF) return mem[m];
    else return -1;
}
