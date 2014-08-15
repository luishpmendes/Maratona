#include <iostream>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

using namespace std;

typedef vector < vector <double> > matrix;

matrix extendShortestPaths (matrix L, matrix W) {
    matrix result (L.size(), vector <double> (L.size(), INFINITE));
    for (int i = 0; i < (int) L.size(); i++) {
        for (int j = 0; j < (int) L.size(); j++) {
            result[i][j] = L[i][j]; /* l'ij ← ∞ */
            for (int k = 0; k < (int) L.size(); k++) {
                /* l'ij ← min(l'ij, lik + wkj) */
                if (result[i][j] > L[i][k] + W[k][j]) {
                    result[i][j] = L[i][k] + W[k][j];
                }
            }
        }
    }
    return result;
}

matrix fasterAllPairsShortestPaths (matrix W) {
    matrix result (W.size(), vector <double> (W.size(), INFINITE));
    for (int i = 0; i < (int) W.size(); i++) {
        for (int j = 0; j < (int) W.size(); j++) {
            result[i][j] = W[i][j];
        }
    }
    for (int m = 1; m < (int) W.size(); m *= 2) {
        result = extendShortestPaths(result, result);
    }
    return result;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE)), L;
        for (int i = 0; i < n; i++) {
            W[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            W[u][v] = w;
        }
        L = fasterAllPairsShortestPaths (W);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << L[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
