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

void floydWarshall (matrix W, matrix * D, matrix * PI) {
    *D = matrix (W.size(), vector <double> (W.size(), INFINITE));
    *PI = matrix (W.size(), vector <double> (W.size(), NIL));
    for (int i = 0; i < (int) W.size(); i++) {
        for (int j = 0; j < (int) W.size(); j++) {
            (*D)[i][j] = W[i][j];
            if (i != j) {
                if (W[i][j] < INFINITE) {
                    (*PI)[i][j] = i;
                }
            } else {
                (*PI)[i][j] = NIL;
            }
        }
    }
    for (int k = 0; k < (int) W.size(); k++) {
        for (int i = 0; i < (int) W.size(); i++) {
            for (int j = 0; j < (int) W.size(); j++) {
                if ((*D)[i][j] > (*D)[i][k] + (*D)[k][j]) {
                    (*D)[i][j] = (*D)[i][k] + (*D)[k][j];
                    (*PI)[i][j] = (*PI)[k][j];
                }
            }
        }
    }
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE)), D, PI;
        for (int i = 0; i < n; i++) {
            W[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            W[u][v] = w;
        }
        floydWarshall (W, &D, &PI);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << D[i][j] << " ";
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
