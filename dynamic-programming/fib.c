#include <stdio.h>

#define MAX 1000
int f[MAX];

int fib(int n) {
    if (n <= 1) return n;
    if (f[n] != 0) return f[n];
    f[n] = fib(n-1) + fib(n-2);
    return f[n];
}

void main() {
    int n;
    scanf("%d", &n);

    f[0] = 0;
    f[1] = 1;
    fib(n);

    if (n == 0) {
        printf("0\n");
    } else {
        for (int i = 0; i < n-1; ++i)
            printf("%d ", f[i]);
            printf("%d\n", f[n-1]);
    }
}
