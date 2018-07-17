/*
 * https://br.spoj.com/problems/NLOGONIA/
 */

class Nlogonia {
    final int K = 1000;
    int[][] coords = new int[2][K];
    int[] ks = new int[K];
    int[] ns = new int[K];
    int[] ms = new int[K];
    int t = 0;  // teste

    void ler_entrada() {
        java.util.Scanner scan = new java.util.Scanner(System.in);
        int k = scan.nextInt();

        for (;;) {
            ks[t] = k;
            ns[t] = scan.nextInt();
            ms[t] = scan.nextInt();

            for (int i = 0; i < k; ++i) {
                coords[0][i] = scan.nextInt();
                coords[1][i] = scan.nextInt();
            }

            k = scan.nextInt();
            if (k == 0) break;
        }
    }

    void resolverCoords() {
    }

    public static void main(String[] args) {
        Nlogonia n = new Nlogonia();
        n.ler_entrada();
        n.resolverCoords();
    }
}
