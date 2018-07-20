/*
 * https://practice.geeksforgeeks.org/problems/rod-cutting/0
 */


#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))
#define LIM 102

void init_mem();
void resolver_min_moedas();

int t;            // number of tests
int len;          // length of the rod
int precos[LIM];  // prices of the ith rod
int mem[LIM];     // maximum income of the ith rod

void init_mem() {
    mem[0] = 0;
    for (int i = 1; i <= len; ++i)
        mem[i] = precos[i];
}

int max_income() {
    for (int i = 1; i <= len; ++i)
        for (int k = 0; k <= i; ++k)
            mem[i] = MAX(mem[i-k] + precos[k], mem[i]);

    return mem[len];
}

void main() {
    scanf("%d ", &t);
    for(int i = 0; i < t; ++i) {
        scanf("%d ", &len);

        for (int j = 1; j <= len; ++j)
            scanf("%d ", &precos[j]);

        init_mem();
        printf("%d\n", max_income());
    }
}
