/*
 * https://br.spoj.com/problems/NLOGONIA/
 */

class Nlogonia {
    final int K = 1000;
    int[][] coords = new int[2][K];
    int k;  // número de coordenadas: coords[][k]
    int m;  // x do ponto divisor
    int n;  // y do ponto divisor
    int t = 0;  // teste

    void ler_entrada() {
        java.util.Scanner scan = new java.util.Scanner(System.in);

        for (;;) {
            k = scan.nextInt();
            if (k == 0) break;

            m = scan.nextInt();
            n = scan.nextInt();

            for (int i = 0; i < k; ++i) {
                coords[0][i] = scan.nextInt();
                coords[1][i] = scan.nextInt();
            }

            resolverCoords();
        }
    }

    void resolverCoords() {
        for (int i = 0; i < k; ++i) {
            if (coords[1][i] > n)
                resolverPontoEmNorte(i);
            else if (coords[1][i] < n)
                resolverPontoEmSul(i);
            else
                System.out.println("divisa");
        }
    }

    void resolverPontoEmNorte(int i) {
        if (coords[0][i] > m)
            System.out.println("NE");
        else if (coords[0][i] < m)
            System.out.println("NO");
        else
            System.out.println("divisa");
    }

    void resolverPontoEmSul(int i) {
        if (coords[0][i] > m)
            System.out.println("SE");
        else if (coords[0][i] < m)
            System.out.println("SO");
        else
            System.out.println("divisa");
    }


    public static void main(String[] args) {
        Nlogonia n = new Nlogonia();
        n.ler_entrada();
        n.resolverCoords();
    }
}
