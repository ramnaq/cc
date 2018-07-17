#include <stdio.h>
#include <stdlib.h>

#define MIN(a, b) (((a) < (b)) ? (a) : (b))

size_t MAX = 100000000;
int K[100];  // moedas
int mem[50002];  // valores salvos
int M;  // valor do produto
int N;  // número de moedas

void init_mem();
void resolver_min_moedas();

void main() {
  int k;  // uma moeda

  int m;
  for(;;) {
	init_mem();
	scanf("%d ", &m);
	if (m == 0) break;
	M = m;

	scanf("%d ", &N);
	for (int i = 0; i < N; ++i) {
	  scanf("%d ", &k);
	  K[i] = k;
	}
	resolver_min_moedas();
  }
}

void init_mem() {
  for (int i = 0; i < 50002; ++i)
	mem[i] = MAX;
}

void resolver_min_moedas() {
  mem[0] = 0;
  for (int i = 1; i <= M; ++i)
	for (int k = 0; k < N; ++k)
	  if (i - K[k] >= 0)
		mem[i] = MIN(mem[i-K[k]] + 1, mem[i]);

  if (mem[M] != MAX)
	printf("%d\n", mem[M]);
  else
	printf("Impossivel\n");
}
