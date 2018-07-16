/*
https://br.spoj.com/problems/TENTA/
*/

import java.util.Scanner;

class Tentativas {

    final int MAX_FIGS = 10000000;
    final int MAX_TESTES = 8;
    int[][] figuras =  new int[MAX_TESTES][MAX_FIGS];
    int[] ordenacoes = new int[MAX_FIGS];
    int t = 0;

    void lerTestes() {
        Scanner scan = new Scanner(System.in);

        for (;;) {
           int n = scan.nextInt();
           if (n == 0) break;

           figuras[t][0] = n;
           for (int i = 1; i <= n; ++i)
               figuras[t][i] = scan.nextInt();

           t++;
        }
    }

    void gerarOrdenacoes() {
        for (int i = 0; i < t; i++) {
            gerarOrdenacoes(i, figuras[i][0]);
            System.out.println();
        }
    }

    void gerarOrdenacoes(int teste, int n) {
        int tamanho = figuras[teste][0];
        if (n == 0) {
            mostraOrdenacao(ordenacoes, tamanho);
            return;
        }

        for (int i = 1; i <= tamanho; i++) {
            if (!contains(ordenacoes, figuras[teste][i])) {
                ordenacoes[n] = figuras[teste][i];
                gerarOrdenacoes(teste, n-1);
                ordenacoes[n] = 0;
            }
        }
    }

    void mostraOrdenacao(int[] ordenacao, int num_figs) {
        for (int i = 1; i <= num_figs; ++i)
            System.out.print(ordenacao[i] + " ");
        System.out.println();
    }

    boolean contains(int[] vector, int x) {
        for (int i = 0; i < vector.length; ++i)
            if (vector[i] == x) return true;
        return false;
    }

    public static void main(String[] args) {
        Tentativas t = new Tentativas();
        t.lerTestes();
        System.out.println();
        t.gerarOrdenacoes();
    }
}
