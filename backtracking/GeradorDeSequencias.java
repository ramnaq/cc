class GeradorDeSequencias {

    char[] sequencia = new char[100];
    int qtd_caracteres;
    int possibilidades;

    char[] letras = {
        'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
    };


    void gerarSequencias(int n) {
        if (n == 0) {
            mostrarResultados();
            possibilidades++;
            return;
        }

        // gera números
        for (int i = 0; i <= 9; ++i) {
            sequencia[n] = (char) (i + (int)'0');
            gerarSequencias(n - 1);
        }

        // gera letras
        for (int i = 0; i < letras.length; ++i) {
            sequencia[n] = letras[i];
            gerarSequencias(n - 1);
        }
    }

    void mostrarResultados() {
        for (int i = 1; i <= qtd_caracteres; ++i)
            System.out.print(sequencia[i]);
        System.out.print(", ");
    }


    public static void main(String args[]) {
        GeradorDeSequencias g = new GeradorDeSequencias();
        g.qtd_caracteres = 4;
        g.gerarSequencias(g.qtd_caracteres);
        System.out.println(g.possibilidades);
    }
}
