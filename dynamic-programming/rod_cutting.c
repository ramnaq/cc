#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

void init_mem();
void resolver_min_moedas();

int t;  // testes
int n;  // tamanho da tora (array)
int precos[102];
int mem[1000];

void resolver() {
    mem[0] = 0;
    for (int i = 1; i <= n; ++i)
        mem[i] = precos[i];

    for (int i = 1; i <= n; ++i)
        for (int k = 0; k <= i; ++k)
            mem[i] = MAX(mem[i-k] + precos[k], mem[i]);

    printf("%d\n", mem[n]);
}

void main() {
    int p;
    scanf("%d ", &t);
    for(int i = 0; i < t; ++i) {
        scanf("%d ", &n);

        for (int j = 1; j <= n; ++j) {
            scanf("%d ", &p);
            precos[j] = p;
        }

        resolver();
    }
}
