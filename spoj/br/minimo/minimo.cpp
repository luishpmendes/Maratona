#include <cstdio>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

using namespace std;

typedef vector < vector <int> > matrix;

vector <matrix> floydWarshall (matrix W) {
    vector <matrix> result (W.size()+1, matrix (W.size(), vector <int> (W.size(), INFINITE)));
    for (int i = 0; i < (int) W.size(); i++) {
        for (int j = 0; j < (int) W.size(); j++) {
            result[0][i][j] = W[i][j];
        }
    }
    for (int k = 1; k <= (int) W.size(); k++) {
        for (int i = 0; i < (int) W.size(); i++) {
            for (int j = 0; j < (int) W.size(); j++) {
                if (result[k-1][i][j] < result[k-1][i][k-1] + result[k-1][k-1][j]) {
                    result[k][i][j] = result[k-1][i][j];
                } else {
                    result[k][i][j] = result[k-1][i][k-1] + result[k-1][k-1][j];
                }
            }
        }
    }
    return result;
}

int main () {
    int n, m, instancia = 0;
    while (scanf(" %d", &n) == 1 && scanf(" %d", &m) == 1) {
        matrix W (n, vector <int> (n, INFINITE));
        for (int i = 0; i < n; i++) {
            W[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v, w;
            scanf(" %d", &u);
            scanf(" %d", &v);
            scanf(" %d", &w);
            u--;
            v--;
            if (W[u][v] > w) {
                W[u][v] = w;
            }
        }
        vector <matrix> D = floydWarshall (W);
        printf("Instancia %d\n", ++instancia);
        int c;
        scanf(" %d", &c);
        for (int i = 0; i < c; i++) {
            int o, d, t;
            scanf(" %d", &o);
            scanf(" %d", &d);
            scanf(" %d", &t);
            o--;
            d--;
            printf("%d\n", D[t][o][d] < INFINITE ? D[t][o][d] : -1);
        }
        printf("\n");
    }
    return 0;
}
