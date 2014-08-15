#include <iostream>
#include <vector>

#ifndef INFINITE
#define INFINITE 15 << 25
#endif

#ifndef NIL
#define NIL - (15 << 25)
#endif

using namespace std;

typedef vector < vector <double> > matrix;

void extendShortestPaths (matrix L, matrix PI, matrix W, matrix * L1, matrix * PI1) {
    *L1 = matrix (L.size(), vector <double> (L.size(), INFINITE));
    *PI1 = matrix (L.size(), vector <double> (L.size(), NIL));
    for (int i = 0; i < (int) L.size(); i++) {
        for (int j = 0; j < (int) L.size(); j++) {
            (*L1)[i][j] = L[i][j]; /* l'ij ← ∞ */
            (*PI1)[i][j] = PI[i][j];
            for (int k = 0; k < (int) L.size(); k++) {
                /* l'ij ← min(l'ij, lik + wkj) */
                if ((*L1)[i][j] > L[i][k] + W[k][j]) {
                    (*L1)[i][j] = L[i][k] + W[k][j];
                    (*PI1)[i][j] = k;
                }
            }
        }
    }
}

void slowAllPairsShortestPaths (matrix W, matrix * L, matrix * PI) {
    *L = matrix (W.size(), vector <double> (W.size(), INFINITE));
    *PI = matrix (W.size(), vector <double> (W.size(), NIL));
    for (int i = 0; i < (int) W.size(); i++) {
        for (int j = 0; j < (int) W.size(); j++) {
            (*L)[i][j] = W[i][j];
            if (i != j) {
                (*PI)[i][j] = i;
            } else {
                (*PI)[i][j] = NIL;
            }
        }
    }
    for (int m = 2; m < (int) W.size(); m++) {
        matrix L1, PI1;
        extendShortestPaths(*L, *PI, W, &L1, &PI1);
        *L = L1;
        *PI = PI1;
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE)), L, PI;
        for (int i = 0; i < n; i++) {
            W[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            W[u][v] = w;
        }
        slowAllPairsShortestPaths (W, &L, &PI);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << L[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << PI[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
