#include <cstdio>
#include <vector>

using namespace std;

typedef vector < vector <int> > matrix;

int main () {
    int m, n, t = 0;
    while (scanf(" %d", &m) == 1 && scanf(" %d", &n) == 1 && (n > 0 || m > 0)) {
        matrix tv (m, vector <int> (n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf(" %d", &tv[i][j]);
            }
        }
        int x, y, somaX = 0, somaY = 0;
        while (scanf(" %d", &x) == 1 && scanf(" %d", &y) == 1 && (x != 0 || y != 0)) {
            somaX += x;
            somaY += y;
        }
        while (somaX < 0) {
            somaX += n*n;
        }
        somaX %= n;
        while (somaY < 0) {
            somaY += m*m;
        }
        somaY %= m;
        printf("Teste %d\n", ++t);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d", tv[(i + somaY) % m][(j + n - somaX) % n]);
                if(j < n-1) {
                    printf(" ");
                }
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
