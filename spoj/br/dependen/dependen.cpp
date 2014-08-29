#include <cstdio>
#include <vector>

using namespace std;

typedef vector < vector <int> > matrix;

int main () {
    int n;
    while (scanf(" %d", &n) == 1 && n > 0) {
        matrix W (n, vector <int> (n, 0));
        for (int u = 0; u < n; u++) {
            int t;
            for (scanf(" %d", &t); t > 0; t--) {
                int v;
                scanf(" %d", &v);
                v--;
                W[u][v] = 1;
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    W[i][j] |= W[i][k] & W[k][j];
                }
            }
        }
        vector <int> dependen (n, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dependen[i] += W[i][j];
            }
        }
        int uMax = 0;
        for (int u = 1; u < n; u++) {
            if (dependen[uMax] < dependen[u]) {
                uMax = u;
            }
        }
        printf("%d\n", ++uMax);
    }
    return 0;
}
