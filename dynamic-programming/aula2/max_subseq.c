#include <stdio.h>

#define MAX(a, b) (((a) >= (b)) ? (a) : (b))

int t;
int n;
int v[1002];
int mem[1002];

int max_subseq() {
  for (int i = 0; i < n; ++i)
	mem[i] = 1;

  for (int i = 1; i < n; ++i)
	for (int j = 0; j < i; ++j)
	  if (v[j] < v[i])
		mem[i] = MAX(mem[i], mem[j] + 1);

  int max = 0;
  for (int i = 0; i < n; ++i)
	if (mem[i] > max)
	  max = mem[i];

  return max;
}

void main() {
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
	scanf("%d", &n);

	for (int j = 0; j < n; ++j)
	  scanf("%d", &v[j]);

	printf("%d\n", max_subseq());
  }
}
