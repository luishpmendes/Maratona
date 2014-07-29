#include <cstdio>
#include <vector>

using namespace std;

typedef vector < vector <int> > matrix;

int main () {
    int n, somaDiagonalPrincipal = 0, somaDiagonalSecundaria = 0;
    scanf(" %d", &n);
    matrix quadrado (n, vector <int> (n, 0));
    vector <int> contador (n * n, 0);
    vector <int> somasLinhas (n, 0);
    vector <int> somasColunas (n, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf(" %d", &quadrado[i][j]);
            if (quadrado[i][j] < 1 || quadrado[i][j] > n * n) {
                printf("0\n");
                return 0;
            }
            contador[quadrado[i][j] - 1]++;
            if (contador[quadrado[i][j] - 1] > 1) {
                printf("0\n");
                return 0;
            }
            somasLinhas[i] += quadrado[i][j];
            somasColunas[j] += quadrado[i][j];
            if (i == j) {
                somaDiagonalPrincipal += quadrado[i][j];
            }
            if (i + j == n - 1) {
                somaDiagonalSecundaria += quadrado[i][j];
            }
        }
    }
    if (somaDiagonalPrincipal != somaDiagonalSecundaria) {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n; i++) {
        if (somasLinhas[i] != somaDiagonalPrincipal || somasColunas[i] != somaDiagonalPrincipal) {
            printf("0\n");
            return 0;
        }
    }
    printf("%d\n", somaDiagonalPrincipal);
    return 0;
}
