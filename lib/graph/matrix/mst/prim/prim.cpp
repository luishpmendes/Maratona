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

typedef struct {
    int u; /* edge source */
    int v; /* edge destination */
    double w; /* edge weight */
} Edge;

vector <Edge> prim (matrix W, int r) {
    vector <Edge> result;
    vector <bool> Q (W.size(), true);
    vector <int> key (W.size(), INFINITE);
    vector <int> pi (W.size(), NIL);

    for (int u = 0; u < (int) W.size(); u++) {
        Q[u] = true;
        key[u] = INFINITE;
        pi[u] = NIL;
    }

    key[r] = 0; 

    for (int i = 0; i < (int) W.size(); i++) {
        int u = -1;
        for (int j = 0; j < (int) W.size(); j++) {
            if (Q[j] && (u < 0 || key[u] > key[j])) {
                u = j;
            }
        }
        Q[u] = false;
        for (int v = 0; v < (int) W.size(); v++) {
            if (u != v && W[u][v] < INFINITE) {
                if (Q[v] && W[u][v] < key[v]) {
                    pi[v] = u;
                    key[v] = W[u][v];
                }
            }
        }
    }

    for (int u = 0; u < (int) W.size(); u++) {
        if (pi[u] >= 0 && pi[u] < (int) W.size()) {
            Edge e;
            e.u = pi[u];
            e.v = u;
            e.w = key[u];
            result.push_back(e);
        }
    }

    return result;
}

int main () {
    int n, m;
    while (cin >> n >> m) {
        matrix W (n, vector <double> (n, INFINITE));
        for (int i = 0; i < m; i++) {
            int u, v;
            double w;
            cin >> u >> v >> w;
            W[u][v] = w;
            W[v][u] = w;
        }
        int r;
        cin >> r;
        vector <Edge> A = prim (W, r);
        for (int i = 0; i < (int) A.size(); i++) {
            Edge e = A[i];
            cout << e.u << " " << e.v << " " << e.w << endl;
        }
    }
    return 0;
}
